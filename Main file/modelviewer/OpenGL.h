#pragma once
#define Grid_X 10
#define Grid_Y 10

#include"source\glIncludes.h"
#include "source\matrix4x4.h"
#include "source\vector3.h"
#include "source\mainScene.h"

using namespace System::Windows::Forms;

namespace OpenGLForm 
{
	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei ix, GLsizei iy,GLsizei iWidth, GLsizei iHeight, mainScene* pMainScenePtr);

		//System::Void Render(LONG mx,LONG my)
		//{
		//	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
		//	gldrawing();
		//}
		System::Void SwapOpenGLBuffers(System::Void)	{	SwapBuffers(m_hDC) ;		}

		//GLvoid ReSizeGLScene(GLsizei width, GLsizei height);		// Resize and initialise the gl window
		GLvoid GetOGLPos(int x, int y);								//get mouse x y z cordinates
		GLvoid COpenGL::Update(float dt);

	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		mainScene* m_pMainScenePtr;

	protected:
		~COpenGL(System::Void){	this->DestroyHandle();	}

		bool InitGL(GLvoid);										// All setup for opengl goes here
		GLint MySetPixelFormat(HDC hdc);
		

	   virtual void WndProc( Message %m ) override
	   {
		  // Listen for operating system messages 
		  switch ( m.Msg )
		  {
			 case WM_CREATE:
				 {
				// Notify the form that this message was received. 
				// Application is activated or deactivated, 
				// based upon the WParam parameter.
				//parent->ApplicationActived( ((int)m.WParam != 0) );
				 }
				break;

			case WM_SIZE:
			{
				//Scene::getCommonData()->setScreenSize(LOWORD(lParam), HIWORD(lParam));
				//m_cSceneManager.resize(LOWORD(lParam), HIWORD(lParam));
				m_pMainScenePtr->reSize(LOWORD((int)m.LParam), HIWORD((int)m.LParam));

			}
			break;
		

		//case WM_MOUSEWHEEL:
		//{
		//	int zDelta=GET_WHEEL_DELTA_WPARAM((int)m.WParam);
		//	m_pMainScenePtr->mouseWheel(zDelta);

		//	/*
		//	int zDelta=GET_WHEEL_DELTA_WPARAM(wParam);
		//	int dir = (zDelta<0)?1:-1;
		//	vector3f aCamForwardDir(engine->getCurrentCamera()->getZAxis());
		//	float d=engine->getCurrentCamera()->getPosition().length();
		//	float factor=20.0f;
		//	//if(nFlags&MK_SHIFT)
		//	//	factor=500.0f;
		//	aCamForwardDir.x=aCamForwardDir.x*(d/factor)*(dir);
		//	aCamForwardDir.y=aCamForwardDir.y*(d/factor)*(dir);
		//	aCamForwardDir.z=aCamForwardDir.z*(d/factor)*(dir);
		//	//aTM->m[12] = aTM->m[12]+aCamForwardDir.x;
		//	//aTM->m[13] = aTM->m[13]+aCamForwardDir.y;
		//	//aTM->m[14] = aTM->m[14]+aCamForwardDir.z;
		//	engine->getCurrentCamera()->updatePositionf(aCamForwardDir.x, aCamForwardDir.y, aCamForwardDir.z);
		//	//aCam->UpdateCamera();
		//	*/
		//}
		//break;
	case WM_MOUSEMOVE:
		{
			int nFlags=LOWORD((int)m.WParam);
			int xx=LOWORD((int)m.LParam);
			int yy=HIWORD((int)m.LParam);

			m_pMainScenePtr->mouseMove(xx, yy, nFlags);
			/*
			int nFlags=LOWORD(wParam);
			int xx=LOWORD(lParam);
			int yy=HIWORD(lParam);

			int xPos = xx;
			int yPos = yy;
			int Pos_dx	= abs(xPos-m_cMousePrevPos.x);
			int Pos_dy	= abs(yPos-m_cMousePrevPos.y);

			int aDirX=-1;
			int aDirY=1;
			if(m_cMousePrevPos.x>xPos)		aDirX=1;
			if(m_cMousePrevPos.y>yPos)		aDirY=-1;


			if(nFlags&MK_MBUTTON && !(nFlags&MK_CONTROL))
			{
				float d=engine->getCurrentCamera()->getPosition().length();
				if(nFlags&MK_SHIFT)
					engine->getCurrentCamera()->updateLocalPositionf((d/5000.0f)*Pos_dx*aDirX, (d/5000.0f)*Pos_dy*aDirY, 0);
				else
					engine->getCurrentCamera()->updateLocalPositionf((d/500.0f)*Pos_dx*aDirX, (d/500.0f)*Pos_dy*aDirY, 0);
			}
			else if(nFlags&MK_MBUTTON && nFlags&MK_CONTROL)
			{

				vector3f aUP(0, 0, 1);
				vector3f aVect(0, 0, 0);
				//aVect=engine->getCurrentCamera()->getPosition();
				engine->getCurrentCamera()->rotateArb(0.5f*Pos_dx*aDirX, &aUP.x, aVect);
				vector3f left=engine->getCurrentCamera()->getXAxis();
				engine->getCurrentCamera()->rotateArb(0.5f*Pos_dy*-aDirY, &left.x, aVect);
			}

			//DEBUG_PRINT("%f, %f\n", delta.x, delta.y);
			m_cMousePrevPos.x=xx;
			m_cMousePrevPos.y=yy;
			*/
		}
		break;
		  }
		  NativeWindow::WndProc( m );
	   }//get mouse x y


	};//end of class COpenGL
	
	COpenGL::COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei ix, GLsizei iy,GLsizei iWidth, GLsizei iHeight, mainScene* pMainScenePtr)
	{
		m_pMainScenePtr=pMainScenePtr;


		CreateParams^ cp = gcnew CreateParams;// System.Windows.Forms (in System.Windows.Forms.dll)

		//CREATING OPENGL CONTROL IN THE SPECIFIED STRUCTURE
		// Set the position on the form
		cp->X = ix;
		cp->Y = iy;
		cp->Height = iHeight;
		cp->Width = iWidth;

		// Specify the form as the parent.
		cp->Parent = parentForm->Handle;

		// Create as a child of the specified parent and make OpenGL compliant (no clipping)
		cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN |WS_THICKFRAME;
		//cp->Caption="viewport";

		// Create the actual window
		this->CreateHandle(cp);

		m_hDC = GetDC((HWND)this->Handle.ToPointer());

		if(m_hDC)
		{
			MySetPixelFormat(m_hDC);
			InitGL();
			//ReSizeGLScene(iWidth, iHeight);
		}

		//
		m_pMainScenePtr->init(iWidth, iHeight);
	}

	bool COpenGL::InitGL(GLvoid)							// All setup for opengl goes here
	{
		glShadeModel(GL_SMOOTH);							// Enable smooth shading
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);				// Black background
		glClearDepth(1.0f);									// Depth buffer setup
		glEnable(GL_DEPTH_TEST);							// Enables depth testing
		glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
		glEnable(GL_CULL_FACE);
		return TRUE;										// Initialisation went ok
	}
	GLint COpenGL:: MySetPixelFormat(HDC hdc)
	{
		static	PIXELFORMATDESCRIPTOR pfd=					// pfd Tells Windows How We Want Things To Be
		{
			sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
			1,											// Version Number
			PFD_DRAW_TO_WINDOW |						// Format Must Support Window
			PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
			PFD_DOUBLEBUFFER,							// Must Support Double Buffering
			PFD_TYPE_RGBA,								// Request An RGBA Format
			16,											// Select Our Color Depth
			0, 0, 0, 0, 0, 0,							// Color Bits Ignored
			0,											// No Alpha Buffer
			0,											// Shift Bit Ignored
			0,											// No Accumulation Buffer
			0, 0, 0, 0,									// Accumulation Bits Ignored
			16,											// 16Bit Z-Buffer (Depth Buffer)  
			0,											// No Stencil Buffer
			0,											// No Auxiliary Buffer
			PFD_MAIN_PLANE,								// Main Drawing Layer
			0,											// Reserved
			0, 0, 0										// Layer Masks Ignored
		};

		GLint  iPixelFormat; 

		// get the device context's best, available pixel format match 
		if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
		{
			MessageBox::Show("ChoosePixelFormat Failed");
			return 0;
		}

		// make that match the device context's current pixel format 
		if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
		{
			MessageBox::Show("SetPixelFormat Failed");
			return 0;
		}

		if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
		{
			MessageBox::Show("wglCreateContext Failed");
			return 0;
		}

		if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}


		return 1;
	}
		
	GLvoid COpenGL::GetOGLPos(int x, int y)														//get mouse x y z cordinates
		{
			
		}
	GLvoid COpenGL::Update(float dt)
	{
		m_pMainScenePtr->update(dt);
		m_pMainScenePtr->render();
	}
}// end of name space OpenGLForm