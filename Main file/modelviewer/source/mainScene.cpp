#include "mainScene.h"
bool rswitch;
mainScene::mainScene()
{
	m_fZoomOutTime=0.0f;
}

mainScene::~mainScene()
{
}

void mainScene::init(int oglWidth, int oglHeight)
{
	//m_cCamera = new Camera();
	m_cCamera.initCamera();
	m_cCamera.setUpViewPort(oglWidth, oglHeight);
	m_cCamera.setUpCameraPerspective(oglWidth, oglHeight);

	//m_cCamera.updateLocalPositionf(0, -100, 100);

	//vector3f camDir(0, -1.0f, 0);
	//m_cCamera.setDir(&camDir);
	m_cCamera.updatePositionf(0, -50, 50);
	m_cCamera.lookAt(vector3f(0, 0, 0));

	m_cLightPos.set(100.0f, 100.0f, 100.0f);
	setUpLights();

	m_fZoomOutTime=0.0f;
}

void mainScene::update(float dt)
{
	if(m_fZoomOutTime>0.0f)
	{
		m_cCamera.updateLocalPositionf(0, 0.0f, 5.0f);
		m_fZoomOutTime-=dt;
	}
	if(m_fZoominTime>0.0f)
	{
		m_cCamera.updateLocalPositionf(0, 0.0f, -5.0f);
		m_fZoominTime-=dt;
	}
	if(m_fRotate>0.0f)
	{
		m_cCamera.rotateWorldYf(.5);//.updateLocalPositionf(0, 5.0f, 0.0f);
		m_fRotate-=dt;
		
	}

}

void mainScene::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
	m_cCamera.updateCamera();
	m_cCamera.processCamera(NULL);

	drawGrid(500, 10, 10);
//	drawMeshGroup();
	if (m_bWireframe ==true )
		{	drawMeshGroupWireFrame();	}
	if (m_bTexture ==true )
		{	drawMeshGroup();	}

	if (m_bMesh ==true )
	{	m_bTexture=false; 		drawMeshGroup();	}
	
	drawGizmo(5.0f);

	//draw light gizmo
	glPushMatrix();
		glTranslatef(m_cLightPos.x, m_cLightPos.y, m_cLightPos.z);
		drawGizmo(3.0f);
	glPopMatrix();
}

void mainScene::drawMeshGroup()
{
	MeshLoader& cMeshLoader=m_cMeshLoader;
	if(!cMeshLoader.m_pMeshGrp)
	{
		return;
	}

	glEnable(GL_LIGHTING);
	//glPolygonMode(GL_FRONT, GL_LINE);
	glColor3f(0.8f, 0.8f, 0.8f);
	glEnableClientState(GL_VERTEX_ARRAY);
	for(int x=0;x<cMeshLoader.m_pMeshGrp->m_pMeshObjLst.size();x++)
	{
		MeshObj* meshObj=cMeshLoader.m_pMeshGrp->m_pMeshObjLst[x];

		glVertexPointer(3, GL_FLOAT, 0, meshObj->m_pszGLVertLst);

		//normal
		if(meshObj->m_pszGLNrmlLst)
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, 0, meshObj->m_pszGLNrmlLst);
		}

		//uv
		if(m_bTexture ==true){

		if(meshObj->m_pszGLUVLst && meshObj->m_pMaterialPtr /*&& m_eRenderState==ESTATE_TEXTURED*/)
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, 0, meshObj->m_pszGLUVLst);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, meshObj->m_pMaterialPtr->m_iGLTexID);
		}
		}

		//if(m_bCycleMeshCombo && GetDocument()->m_CycleMeshIterator==x)
		//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//glPushMatrix();
		glDrawElements(GL_TRIANGLES, meshObj->m_nTris * 3, GL_UNSIGNED_INT, meshObj->m_pszGLTriLst);
		//glPopMatrix();

		//if(m_bCycleMeshCombo && GetDocument()->m_CycleMeshIterator==x && m_eRenderState!=ESTATE_WIREFRAME)
		//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		if(meshObj->m_pszGLUVLst && meshObj->m_pMaterialPtr /*&& m_eRenderState==ESTATE_TEXTURED*/)
		{
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisable(GL_TEXTURE_2D);
		}

		if(meshObj->m_pszGLNrmlLst)
			glDisableClientState(GL_NORMAL_ARRAY);
		}
		//texture functions
		//m_bTexture ==false
	

	glDisableClientState(GL_VERTEX_ARRAY);
	//m_cCamera.rotateWorldZf(1.0f);
	glDisable(GL_LIGHTING);
}
void mainScene::drawMeshGroupWireFrame()
{
	MeshLoader& cMeshLoader=m_cMeshLoader;
	if(!cMeshLoader.m_pMeshGrp)
	{
		return;
	}

	glDisable(GL_LIGHTING);
	//glPolygonMode(GL_FRONT, GL_LINE);
	glColor4f(0.373f, 0.4549f, 0.58823f, 1.0f);
	glEnableClientState(GL_VERTEX_ARRAY);

	glLineWidth(1.6f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for(int x=0;x<cMeshLoader.m_pMeshGrp->m_pMeshObjLst.size();x++)
	{
		MeshObj* meshObj=cMeshLoader.m_pMeshGrp->m_pMeshObjLst[x];

		glVertexPointer(3, GL_FLOAT, 0, meshObj->m_pszGLVertLst);
		//if(m_bCycleMeshCombo && GetDocument()->m_CycleMeshIterator==x)
		//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//glPushMatrix();
		glDrawElements(GL_TRIANGLES, meshObj->m_nTris * 3, GL_UNSIGNED_INT, meshObj->m_pszGLTriLst);
		//glPopMatrix();

		//if(m_bCycleMeshCombo && GetDocument()->m_CycleMeshIterator==x && m_eRenderState!=ESTATE_WIREFRAME)
		//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glLineWidth(1.0f);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void mainScene::reSize(int cx, int cy)
{
	m_cCamera.setUpViewPort(cx, cy);
	m_cCamera.setUpCameraPerspective(cx, cy);
}

void mainScene::mouseDown(int x, int y, int flag)
{
	//if(rswitch=TRUE)
	//{
	//vector3f aUP(0, 0, 1);
	//vector3f aVect(0, 0, 0);
	////aVect=engine->getCurrentCamera()->getPosition();
	//m_cCamera.rotateArb(0.5f*Pos_dx*aDirX, &aUP.x, aVect);
	//vector3f left=m_cCamera.getXAxis();
	//m_cCamera.rotateArb(0.5f*Pos_dy*-aDirY, &left.x, aVect);
	//}
}

void mainScene::mouseUp(int x, int y, int flag)
{
}

void mainScene::mouseMove(int x, int y, int flag)
{
	int xPos = x;
	int yPos = y;
	int Pos_dx	= abs(xPos-m_cMousePrevPos.x);
	int Pos_dy	= abs(yPos-m_cMousePrevPos.y);

	int aDirX=-1;
	int aDirY=1;
	if(m_cMousePrevPos.x>xPos)		aDirX=1;
	if(m_cMousePrevPos.y>yPos)		aDirY=-1;


	if(flag&MK_MBUTTON && !(flag&MK_CONTROL))
	{
		float d=m_cCamera.getPosition().length();
		if(flag&MK_SHIFT)
			m_cCamera.updateLocalPositionf((d/5000.0f)*Pos_dx*aDirX, (d/5000.0f)*Pos_dy*aDirY, 0);
		else
			m_cCamera.updateLocalPositionf((d/500.0f)*Pos_dx*aDirX, (d/500.0f)*Pos_dy*aDirY, 0);
	}
	else if(flag&MK_RBUTTON )
	{
		vector3f aUP(0, 0, 1);
		vector3f aVect(0, 0, 0);
		//aVect=engine->getCurrentCamera()->getPosition();
		m_cCamera.rotateArb(0.5f*Pos_dx*aDirX, &aUP.x, aVect);
		vector3f left=m_cCamera.getXAxis();
		m_cCamera.rotateArb(0.5f*Pos_dy*-aDirY, &left.x, aVect);
	}
	else if(flag&MK_LBUTTON)
	{
		vector3f diff(vector3f(xPos, yPos, 0.0f)-m_cMousePrevPos);
		if(diff.y<0.0f)
			mouseWheel(-1);
		else
			mouseWheel(1);
	}

	//DEBUG_PRINT("%f, %f\n", delta.x, delta.y);
	m_cMousePrevPos.x=x;
	m_cMousePrevPos.y=y;
}

void mainScene::mouseWheel(int zDelta)
{
	//int zDelta=GET_WHEEL_DELTA_WPARAM(wParam);
	int dir = (zDelta<0)?1:-1;
	vector3f aCamForwardDir(m_cCamera.getZAxis());
	float d=m_cCamera.getPosition().length();
	float factor=20.0f;
	//if(nFlags&MK_SHIFT)
	//	factor=500.0f;
	aCamForwardDir.x=aCamForwardDir.x*(d/factor)*(dir);
	aCamForwardDir.y=aCamForwardDir.y*(d/factor)*(dir);
	aCamForwardDir.z=aCamForwardDir.z*(d/factor)*(dir);
	//aTM->m[12] = aTM->m[12]+aCamForwardDir.x;
	//aTM->m[13] = aTM->m[13]+aCamForwardDir.y;
	//aTM->m[14] = aTM->m[14]+aCamForwardDir.z;
	m_cCamera.updatePositionf(aCamForwardDir.x, aCamForwardDir.y, aCamForwardDir.z);
	//aCam->UpdateCamera();
}

void mainScene::drawGrid(float size, int big_grids, int small_grids)
{
	glDisable(GL_LIGHTING);

	float big_dx=size/big_grids;
	float small_dx=big_dx/small_grids;

	float start_x=-size;

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -1.0f);
	//draw horiz lines
	glBegin(GL_LINES);
	for(int x=0;x<big_grids*2/*+1*/;x++)
	{
		for(int m=0;m<small_grids;m++)
		{
			(m)?glColor3f(0.4f, 0.4f, 0.4f):glColor3f(0.3f, 0.3f, 0.3f);
			float yy=start_x+ (float)x*big_dx+(float)m*small_dx;
			glVertex3f(-size, yy, 0.0f);
			glVertex3f(size, yy, 0.0f);
		}
	}
	//draw the last thick line
	float last_yy=start_x+ (float)(big_grids*2)*big_dx;
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-size, last_yy, 0.0f);
	glVertex3f(size, last_yy, 0.0f);
	glEnd();

	//draw vert lines
	glBegin(GL_LINES);
	for(int x=0;x<big_grids*2/*+1*/;x++)
	{
		for(int m=0;m<small_grids;m++)
		{
			(m)?glColor3f(0.4f, 0.4f, 0.4f):glColor3f(0.3f, 0.3f, 0.3f);
			float xx=start_x+ (float)x*big_dx+(float)m*small_dx;
			glVertex3f(xx, -size, 0.0f);
			glVertex3f(xx, size, 0.0f);
		}
	}
	//draw the last thick line
	last_yy=start_x+ (float)(big_grids*2)*big_dx;
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(last_yy, -size, 0.0f);
	glVertex3f(last_yy, size, 0.0f);
	glEnd();

	glPopMatrix();
}

void mainScene::drawGizmo(float scale)
{
	glDisable(GL_LIGHTING);

	glDisable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);			//x - axis
	glVertex3f(10.0f*scale, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);			//y - axis
	glVertex3f(0.0f, 10.0f*scale, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);			//z - axis
	glVertex3f(0.0f, 0.0f, 10.0f*scale);
	glEnd();

	////glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glBegin(GL_LINE_LOOP);
	//glColor3f(1, 0, 0); glVertex3f(1, 1, 1);
	//glColor3f(0, 1, 0); glVertex3f(-1, 1,-1);
	//glColor3f(0, 0, 1); glVertex3f(1, -1, -1);
	//glColor3f(0, 0, 1); glVertex3f(-1, -1, 1);
	//glEnd();
	////glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glEnable(GL_DEPTH_TEST);
}

void mainScene::loadObjFile(const char* filename)
{
	m_cMeshLoader.Reset();
	MeshGrp* meshGroup = m_cMeshLoader.Load(filename);
}

void mainScene::setUpLights()
{
	glEnable(GL_LIGHTING);
	GLfloat diffuse[]	=	{	1.0f, 1.0f, 1.0f, 1.0f	};
	GLfloat specular[]	=	{	0.0f, 0.0f, 0.0f, 1.0f	};
	GLfloat position[]	=	{	m_cLightPos.x, m_cLightPos.y,	m_cLightPos.z,	1.0f};
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}