#ifndef CAMERA_H
#define CAMERA_H

#include "object3d.h"
#include "glIncludes.h"

class Camera : public object3d
{
public:
	Camera();
	~Camera();

	void transformationChangedf();
	void		resetCamera();
	void		initCamera(/*rendererBase* renderer*/);
	void		processCamera(matrix4x4f* matrix=NULL);
	void		updateCamera();
	void		setUpViewPort(int aWidth=1, int aHeight=1);
	void		setUpCameraPerspective(float cx=1.0f, float cy=1.0f);
	virtual void		calculateAABB();
	void		drawFrustum();

    virtual void render(const matrix4x4f* parentTM) {  /*objectBase::render();*/    }
    
				

	const matrix4x4f*	getProjectionMatrix()		{	return &m_cProjMatrix;		}
	const matrix4x4f*	getInverseTMViewMatrix()	{	return &m_cInvTranfMatrix;	}

private:
	
	matrix4x4f	m_cProjMatrix;
	matrix4x4f	m_cInvTranfMatrix;
	matrix4x4f	m_cViewProjectionMatrix;
};

#endif

//	void		setCamera(gxCamera* aCamera);
	//	gxCamera*	getCameraStructure()			{	return m_pCurrentCamPtr;	}
	//	void		extractFrustumPlanes();

	//virtual void		transformationChangedf();
	//vector3f	getCameraSpaceLoc(const vector3f& point);
	//gxFrustumf&	getFrustum()	
//---------------------------------------------------------------private
	//rendererBase* m_pRendererPtr;	//must not delete this pointer
	//gxCamera*	m_pCurrentCamPtr;	//must not delete this pointer
	//gxFrustumf	m_cFrustum; 	{	return m_cFrustum;			}
	