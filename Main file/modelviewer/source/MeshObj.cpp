#include "MeshObj.h"


MeshObj::MeshObj()
{
	m_pszGLVertLst = NULL;
	m_pszGLNrmlLst = NULL;
	m_pszGLUVLst = NULL;
	m_pszGLTriLst = NULL;
	m_pMaterialPtr = NULL;
	m_nTris=0;
}

MeshObj::~MeshObj()
{
	if(m_pszGLVertLst)
		delete [] m_pszGLVertLst;
	m_pszGLVertLst=NULL;
	if(m_pszGLNrmlLst)
		delete [] m_pszGLNrmlLst;
	m_pszGLNrmlLst=NULL;
	if(m_pszGLUVLst)
		delete [] m_pszGLUVLst;
	m_pszGLUVLst=NULL;
	if(m_pszGLTriLst)
		delete [] m_pszGLTriLst;
	m_pszGLTriLst=NULL;
	m_pMaterialPtr=NULL;
}

void MeshObj::Load(OBJObject* objObj)
{
	//create the buffers
	m_nTris=objObj->m_pszTriLst.size();
	m_pszGLVertLst = new float[objObj->m_pszTriLst.size()*3*3];
	if(objObj->m_bHasUV)
		m_pszGLUVLst = new float[objObj->m_pszTriLst.size()*3*2];
	if(objObj->m_bHasNrml)
		m_pszGLNrmlLst = new float[objObj->m_pszTriLst.size()*3*3];
	m_pszGLTriLst = new unsigned int[objObj->m_pszTriLst.size()*3];

	//create the vertex buffer
	for(int x=0;x<objObj->m_pszTriLst.size();x++)
	{
		ObjTriangle* tri=objObj->m_pszTriLst[x];
		
		//v0
		m_pszGLVertLst[x*9+0]=objObj->m_pszVertLst[tri->v[0].x-1]->x;
		m_pszGLVertLst[x*9+1]=objObj->m_pszVertLst[tri->v[0].x-1]->y;
		m_pszGLVertLst[x*9+2]=objObj->m_pszVertLst[tri->v[0].x-1]->z;
		m_pszGLTriLst[x*3+0]=x*3+0;
		//v1
		m_pszGLVertLst[x*9+3]=objObj->m_pszVertLst[tri->v[0].y-1]->x;
		m_pszGLVertLst[x*9+4]=objObj->m_pszVertLst[tri->v[0].y-1]->y;
		m_pszGLVertLst[x*9+5]=objObj->m_pszVertLst[tri->v[0].y-1]->z;
		m_pszGLTriLst[x*3+1]=x*3+1;

		//v2
		m_pszGLVertLst[x*9+6]=objObj->m_pszVertLst[tri->v[0].z-1]->x;
		m_pszGLVertLst[x*9+7]=objObj->m_pszVertLst[tri->v[0].z-1]->y;
		m_pszGLVertLst[x*9+8]=objObj->m_pszVertLst[tri->v[0].z-1]->z;
		m_pszGLTriLst[x*3+2]=x*3+2;

		if(objObj->m_bHasUV)
		{
			//uv0
			m_pszGLUVLst[x*6+0]=objObj->m_pszUVLst[tri->v[1].x-1]->x;
			m_pszGLUVLst[x*6+1]=objObj->m_pszUVLst[tri->v[1].x-1]->y;

			//uv1
			m_pszGLUVLst[x*6+2]=objObj->m_pszUVLst[tri->v[1].y-1]->x;
			m_pszGLUVLst[x*6+3]=objObj->m_pszUVLst[tri->v[1].y-1]->y;

			//uv2
			m_pszGLUVLst[x*6+4]=objObj->m_pszUVLst[tri->v[1].z-1]->x;
			m_pszGLUVLst[x*6+5]=objObj->m_pszUVLst[tri->v[1].z-1]->y;
		}

		if(objObj->m_bHasNrml)
		{
			//vn0
			m_pszGLNrmlLst[x*9+0]=objObj->m_pszNrmlLst[tri->v[2].x-1]->x;
			m_pszGLNrmlLst[x*9+1]=objObj->m_pszNrmlLst[tri->v[2].x-1]->y;
			m_pszGLNrmlLst[x*9+2]=objObj->m_pszNrmlLst[tri->v[2].x-1]->z;

			//vn1
			m_pszGLNrmlLst[x*9+3]=objObj->m_pszNrmlLst[tri->v[2].y-1]->x;
			m_pszGLNrmlLst[x*9+4]=objObj->m_pszNrmlLst[tri->v[2].y-1]->y;
			m_pszGLNrmlLst[x*9+5]=objObj->m_pszNrmlLst[tri->v[2].y-1]->z;

			//vn2
			m_pszGLNrmlLst[x*9+6]=objObj->m_pszNrmlLst[tri->v[2].z-1]->x;
			m_pszGLNrmlLst[x*9+7]=objObj->m_pszNrmlLst[tri->v[2].z-1]->y;
			m_pszGLNrmlLst[x*9+8]=objObj->m_pszNrmlLst[tri->v[2].z-1]->z;
		}
	}
}


MeshGrp::MeshGrp()
{

}

MeshGrp::~MeshGrp()
{
	for(int x=0;x<m_pMeshObjLst.size();x++)
		delete m_pMeshObjLst[x];
	m_pMeshObjLst.clear();
}

MeshLoader::MeshLoader()
{
	m_pMeshGrp=NULL;
}

MeshLoader::~MeshLoader()
{
	Reset();
}

void MeshLoader::Reset()
{
	if(m_pMeshGrp)
		delete m_pMeshGrp;
	m_pMeshGrp=NULL;
	for(int x=0;x<m_pMaterialLst.size();x++)
		delete m_pMaterialLst[x];
	m_pMaterialLst.clear();
}

MeshGrp* MeshLoader::Load(const char* objfile)
{
	OBJReader objReader;
	objReader.Load(objfile);

	m_pMeshGrp=new MeshGrp();

	//add material to material list
	for(int x=0;x<objReader.m_pszMaterialLst.size();x++)
	{
		Material* newmat=new Material(*objReader.m_pszMaterialLst[x]);
		if(strlen(newmat->m_szKd_mapname))
		{
			CTextureLoader1 texloader;
			CTextureLoader1::stTexture texturePack;
			//DDSLoader ddsLoader;
			//newmat->m_iGLTexID=ddsLoader.loadCompressedTexture(newmat->m_szKd_mapname);
			texloader.LoadTexture(&texturePack, newmat->m_szKd_mapname);
			newmat->m_iGLTexID=texturePack.TextureID;
		}
		m_pMaterialLst.push_back(newmat);
	}
	//

	for(int x=0;x<objReader.m_pszOBJObjectLst.size();x++)
	{
		OBJObject* objObj=objReader.m_pszOBJObjectLst[x];
		if(objObj->m_pszTriLst.size() && objObj->m_pszTriLst[0]->v[0].x<0)	//relative face list
			continue;

		MeshObj* meshObj=new MeshObj();
		meshObj->Load(objObj);
		//assign material
		for(int m=0;m<m_pMaterialLst.size();m++)
		{
			if(strcmp(objObj->m_szMaterialName, m_pMaterialLst[m]->m_szMaterialName)==0)
			{
				//chk if this material already
				meshObj->m_pMaterialPtr=m_pMaterialLst[m];
				break;
			}
		}
		m_pMeshGrp->m_pMeshObjLst.push_back(meshObj);
	}

	objReader.Reset();

	return m_pMeshGrp;
}


