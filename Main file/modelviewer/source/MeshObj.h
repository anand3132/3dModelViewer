#ifndef MESHOBJ_H
#define MESHOBJ_H

//#include "../OBJFormat/OBJReader.h"
#include "OBJReader.h"
//#include "DDSLoader.h"
#include "TextureLoader1.h"

class MeshObj
{
public:
	MeshObj();
	~MeshObj();

	void Load(OBJObject* objObj);

	int		m_nTris;
	float* m_pszGLVertLst;
	float* m_pszGLNrmlLst;
	float* m_pszGLUVLst;
	Material* m_pMaterialPtr;
	unsigned int*	m_pszGLTriLst;
};

class MeshGrp
{
public:
	MeshGrp();
	~MeshGrp();

	std::vector<MeshObj*> m_pMeshObjLst;
};

class MeshLoader
{
public:
	MeshLoader();
	~MeshLoader();

	void Reset();
	MeshGrp* Load(const char* objfile);
	MeshGrp* m_pMeshGrp;

	std::vector<Material*> m_pMaterialLst;
};
#endif