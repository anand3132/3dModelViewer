#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "Camera.h"
#include "MeshObj.h"

class mainScene
{
public:
	mainScene();
	~mainScene();

	void init(int oglWidth, int oglHeight);
	void update(float dt);
	void render();
	void reSize(int cx, int cy);
	void mouseDown(int x, int y, int flag);
	void mouseUp(int x, int y, int flag);
	void mouseMove(int x, int y, int flag);
	void mouseWheel(int zDelta);

	void drawGrid(float size, int big_grids, int small_grids);
	void drawGizmo(float scale);

	void drawMeshGroup();
	void drawMeshGroupWireFrame();

	void loadObjFile(const char* filename);
	void setUpLights();

	void startZoomOut()		{	m_fZoomOutTime=0.5f;	}
	void startZoomin()		{	m_fZoominTime=0.5f;	}
	void startRotate()		{	m_fRotate=0.5f;	}

	void enableWireframe()	{	m_bWireframe=true;	}
	void disableWireframe()	{	m_bWireframe=false;	}

	void enableTexture()	{	m_bTexture=true;	}
	void disableTexture()	{	m_bTexture=false;	}

	void enableMesh()		{	m_bMesh=true;	}
	void disableMesh()		{	m_bMesh=false;	}
	void axis(int a[6]){	}

	//void textureToggle()	{	m_bTextureSwitch;	}
	//void WireFrameToggle()	{	m_bWireFrameSwitch;}
	 

private:
	Camera m_cCamera;
	vector3f m_cMousePrevPos;

	MeshLoader m_cMeshLoader;
	vector3f m_cLightPos;

	BOOL m_bWireframe;
	BOOL m_bTexture;
	BOOL m_bMesh;

	BOOL m_bXaxis;
	BOOL m_bYaxis;
	BOOL m_bZaxis;
	BOOL m_bInverseAxis;
	//BOOL m_bWireFrameSwitch=FALSE;

	float m_fZoomOutTime;
	float m_fZoominTime;
	float m_fRotate;
};

#endif