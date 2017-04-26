#include "OBJReader.h"

OBJObject::OBJObject()
{
	m_bHasUV = false;
	m_bHasNrml = false;
}

OBJObject::~OBJObject()
{
	for(int x=0;x<m_pszVertLst.size();x++)
		delete m_pszVertLst[x];
	m_pszVertLst.clear();
	for(int x=0;x<m_pszUVLst.size();x++)
		delete m_pszUVLst[x];
	m_pszUVLst.clear();
	for(int x=0;x<m_pszNrmlLst.size();x++)
		delete m_pszNrmlLst[x];
	m_pszNrmlLst.clear();
	for(int x=0;x<m_pszTriLst.size();x++)
		delete m_pszTriLst[x];
	m_pszTriLst.clear();
}

//===================================OBJREADER=====================================
OBJReader::OBJReader()	{	}

OBJReader::~OBJReader()	{	Reset();	}

void OBJReader::Reset()
{
	for(int x=0;x<m_pszOBJObjectLst.size();x++)
		delete m_pszOBJObjectLst[x];
	m_pszOBJObjectLst.clear();
	for(int x=0;x<m_pszMaterialLst.size();x++)
		delete m_pszMaterialLst[x];
	m_pszMaterialLst.clear();
}

void OBJReader::Load(const char* filename)
{
	char filepath[256];
	strcpy(filepath, filename);
	for(int x=strlen(filename)-1;x>=0;x--)
	{
		if(filename[x]==47 || filename[x]==92)
		{
			filepath[x+1]='\0';
			break;
		}
	}

	FILE* fp = fopen(filename, "r");
	
	OBJObject* objObject = NULL;

	bool bUseUV=false;
	bool bUseNormal=false;
	bool bStartedReadingVertexInfo=false;
	bool bStartedReadingFaceInfo=false;

	int nVerts=0;
	int nUVs=0;
	int nNrmls=0;

	char mtllib[256];
	memset(mtllib, 0, 256);

	while(!feof(fp))
	{
		//read first char
		char tag[64];
		char ch=0;
		int tag_len=0;
		while(ch!=32 && ch!=10 && ch!=35)
		{
			fread((void*)&ch, 1, 1, fp);
			tag[tag_len++]=ch;
			if(feof(fp))
				break;
		}
		tag[tag_len]='\0';

		//--chk the mesh end condition
		if(bStartedReadingFaceInfo && strcmp(tag, "f ")!=0)
		{
			bStartedReadingFaceInfo=false;
			objObject->m_bHasNrml=bUseNormal;
			objObject->m_bHasUV=bUseUV;
			m_pszOBJObjectLst.push_back(objObject);	//append the mesh here

			nVerts+=objObject->m_pszVertLst.size();
			nUVs+=objObject->m_pszUVLst.size();
			nNrmls+=objObject->m_pszNrmlLst.size();
		}

		if(bStartedReadingVertexInfo && strcmp(tag, "v ")!=0)
			bStartedReadingVertexInfo=false;
		//--

		if(strcmp(tag, "\n")==0)
		{
			ch=0;
		}
		else if(strcmp(tag, " ")==0)
		{
			ch=0;
		}
		else if(strcmp(tag, "#")==0)
		{
			char comment[256];
			fscanf(fp, "%[^\n]\n", comment);
			ch=0;
		}
		else if(strcmp(tag, "mtllib ")==0)
		{
			fscanf(fp, "%[^\n]", mtllib);
		}
		else if(strcmp(tag, "v ")==0)
		{
			if(!bStartedReadingVertexInfo)
			{
				objObject = new OBJObject();	//create the mesh here
				bStartedReadingVertexInfo=true;
			}
			Point3f* pt=new Point3f();
			fscanf(fp, "%f %f %f\n", &pt->x, &pt->y, &pt->z);
			objObject->m_pszVertLst.push_back(pt);
			//reset the flags
			bUseUV=false;
			bUseNormal=false;
		}
		else if(strcmp(tag, "vt ")==0)
		{
			Point3f* pt=new Point3f();
			fscanf(fp, "%f %f\n", &pt->x, &pt->y);
			pt->z=1.0f;	//default to 1.0f
			objObject->m_pszUVLst.push_back(pt);
			bUseUV=true;
		}
		else if(strcmp(tag, "vn ")==0)
		{
			Point3f* pt=new Point3f();
			fscanf(fp, "%f %f %f\n", &pt->x, &pt->y, &pt->z);
			objObject->m_pszNrmlLst.push_back(pt);
			bUseNormal=true;
		}
		else if(strcmp(tag, "s ")==0)
		{
			char comment[256];
			fscanf(fp, " %[^\n]", comment);
			ch=0;
		}
		else if(strcmp(tag, "g ")==0)
		{
			char comment[256];
			fscanf(fp, " %[^\n]", comment);
			ch=0;
		}
		else if(strcmp(tag, "usemtl ")==0)
		{
			fscanf(fp, " %[^\n]", objObject->m_szMaterialName);
			ch=0;
		}
		else if(strcmp(tag, "f ")==0)
		{
			ObjTriangle* tri=new ObjTriangle();
			
			if(bUseUV && bUseNormal)
			{
				fscanf(fp, "%d/%d/%d ", &tri->v[0].x, &tri->v[1].x, &tri->v[2].x);
				fscanf(fp, "%d/%d/%d ", &tri->v[0].y, &tri->v[1].y, &tri->v[2].y);
				fscanf(fp, "%d/%d/%d\n", &tri->v[0].z, &tri->v[1].z, &tri->v[2].z);
				tri->v[0].x=tri->v[0].x-nVerts;	tri->v[0].y=tri->v[0].y-nVerts;	tri->v[0].z=tri->v[0].z-nVerts;
				tri->v[1].x=tri->v[1].x-nUVs;	tri->v[1].y=tri->v[1].y-nUVs;	tri->v[1].z=tri->v[1].z-nUVs;
				tri->v[2].x=tri->v[2].x-nNrmls;	tri->v[2].y=tri->v[2].y-nNrmls;	tri->v[2].z=tri->v[2].z-nNrmls;
			}
			else if(bUseUV && !bUseNormal)
			{
				fscanf(fp, "%d/%d ", &tri->v[0].x, &tri->v[1].x);
				fscanf(fp, "%d/%d ", &tri->v[0].y, &tri->v[1].y);
				fscanf(fp, "%d/%d\n", &tri->v[0].z, &tri->v[1].z);
				tri->v[0].x=tri->v[0].x-nVerts;	tri->v[0].y=tri->v[0].y-nVerts;	tri->v[0].z=tri->v[0].z-nVerts;
				tri->v[1].x=tri->v[1].x-nUVs;	tri->v[1].y=tri->v[1].y-nUVs;	tri->v[1].z=tri->v[1].z-nUVs;
			}
			if(!bUseUV && bUseNormal)
			{
				fscanf(fp, "%d//%d ", &tri->v[0].x, &tri->v[2].x);
				fscanf(fp, "%d//%d ", &tri->v[0].y, &tri->v[2].y);
				fscanf(fp, "%d//%d\n", &tri->v[0].z, &tri->v[2].z);
				tri->v[0].x=tri->v[0].x-nVerts;	tri->v[0].y=tri->v[0].y-nVerts;	tri->v[0].z=tri->v[0].z-nVerts;
				tri->v[2].x=tri->v[2].x-nNrmls;	tri->v[2].y=tri->v[2].y-nNrmls;	tri->v[2].z=tri->v[2].z-nNrmls;
			}
			else if(!bUseUV && !bUseNormal)
			{
				fscanf(fp, "%d %d %d\n", &tri->v[0].x, &tri->v[0].y, &tri->v[0].z);
				tri->v[0].x=tri->v[0].x-nVerts;	tri->v[0].y=tri->v[0].y-nVerts;	tri->v[0].z=tri->v[0].z-nVerts;
			}
			bStartedReadingFaceInfo=true;

			objObject->m_pszTriLst.push_back(tri);
		}
	}

	if(bStartedReadingFaceInfo)
		m_pszOBJObjectLst.push_back(objObject);	//append the last mesh here

	fclose(fp);

	//load the mtllib
	if(strlen(mtllib))
	{
		char mtllibfile[256];
		sprintf(mtllibfile, "%s%s", filepath, mtllib);
		FILE* fp=fopen(mtllibfile, "r");
		if(fp)
		{
			Material* material=NULL;

			while(!feof(fp))
			{
				//read first char
				char tag[64];
				char ch=0;
				int tag_len=0;
				while(ch!=32 && ch!=10/* && ch!=35*/)
				{
					fread((void*)&ch, 1, 1, fp);
					tag[tag_len++]=ch;
					if(feof(fp))
						break;
				}
				tag[tag_len]='\0';

				if(strcmp(tag, "\n")==0)
				{
					ch=0;
				}
				else if(strcmp(tag, " ")==0)
				{
					ch=0;
				}
				else if(strcmp(tag, "newmtl ")==0)
				{
					if(material)
						m_pszMaterialLst.push_back(material);
					material=new Material();
					fscanf(fp, "%[^\n]\n", material->m_szMaterialName);
					ch=0;
				}
				else if(strcmp(tag, "Kd ")==0)
				{
					fscanf(fp, "%f %f %f\n", &material->m_cKd.x, &material->m_cKd.y, &material->m_cKd.z);
				}
				else if(strcmp(tag, "illum ")==0)
				{
					fscanf(fp, "%d\n", &material->m_iIllum);
					ch=0;
				}
				else if(strcmp(tag, "Ka ")==0)
				{
					fscanf(fp, "%f %f %f\n", &material->m_cKa.x, &material->m_cKa.y, &material->m_cKa.z);
				}
				else if(strcmp(tag, "Tf ")==0)
				{
					fscanf(fp, "%f %f %f\n", &material->m_cTf.x, &material->m_cTf.y, &material->m_cTf.z);
				}
				else if(strcmp(tag, "map_Kd ")==0)
				{
					char mapname[256];
					fscanf(fp, "%[^\n]\n", mapname);
					sprintf(material->m_szKd_mapname, "%s%s", filepath, mapname);
					ch=0;
				}
				else if(strcmp(tag, "Ni ")==0)
				{
					fscanf(fp, "%f\n", &material->m_Ni);
				}
			}
			fclose(fp);

			if(material)
				m_pszMaterialLst.push_back(material);
		}
	}
}
