#ifndef OBJREADER_H
#define OBJREADER_H

#include <vector>
#include <fstream>

class Point3f
	{
	public:
		Point3f()	{	x=y=z=0.0f;		}
		~Point3f()	{}

		float x,y,z;
	};

class Point3i
	{
	public:
		Point3i()	{	x=y=z=0;		}
		~Point3i(){}

		int x,y,z;
	};

class ObjTriangle
	{
	public:
		ObjTriangle()		{	}

		~ObjTriangle()		{	}

		Point3i v[3];
	};

class Material
{
public:
	Material()
	{
		m_iIllum=0;
		m_Ni=0.0f;
		m_iGLTexID=0;
		memset(m_szMaterialName, 0, 256);
		memset(m_szKd_mapname, 0, 256);
	}

	Material(const Material& mat)
	{
		strcpy(m_szMaterialName, mat.m_szMaterialName);
		strcpy(m_szKd_mapname, mat.m_szKd_mapname);
		m_iIllum=mat.m_iIllum;
		m_Ni=mat.m_Ni;
		m_cKd.x=mat.m_cKd.x; m_cKd.y=mat.m_cKd.y; m_cKd.z=mat.m_cKd.z;
		m_cKa.x=mat.m_cKa.x; m_cKa.y=mat.m_cKa.y; m_cKa.z=mat.m_cKa.z;
		m_cTf.x=mat.m_cTf.x; m_cTf.y=mat.m_cTf.y; m_cTf.z=mat.m_cTf.z;
		m_iGLTexID=0;
	}

	~Material()	{	}

	char m_szMaterialName[256];
	char m_szKd_mapname[256];

	Point3f m_cKd;
	Point3f m_cKa;
	Point3f m_cTf;
	int		m_iIllum;
	float	m_Ni;
	unsigned int m_iGLTexID;
};

class OBJObject
{
public:
	OBJObject();
	~OBJObject();

	char	m_pszName[256];
	char	m_szMaterialName[256];
	std::vector<Point3f*> m_pszVertLst;
	std::vector<Point3f*> m_pszUVLst;
	std::vector<Point3f*> m_pszNrmlLst;
	std::vector<ObjTriangle*> m_pszTriLst;

	bool m_bHasUV;
	bool m_bHasNrml;
};

class OBJReader
{
public:
	OBJReader();
	~OBJReader();
	void Reset();

	void Load(const char* filename);

	std::vector<OBJObject*> m_pszOBJObjectLst;
	std::vector<Material*> m_pszMaterialLst;
};
#endif