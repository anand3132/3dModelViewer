////#include"OpenGL.h"
////float x=.051,y=.051,z=.51;
////glLoadIdentity();									// Reset the current modelview matrix
//			//glTranslatef(-1.5f,0.0f,-12.0f);						// Move left 1.5 units and into the screen 6.0
//			
//			//for(int i=0;i<Grid_X;i++)
//			//	for(int j=0;j<Grid_y;j++)
//			/*glBegin(GL_LINE_STRIP);
//				glColor3f(0.0f,1.0f,0.0f);
//				glVertex3f( -1.0f, 0.0f, -1.0f);
//				glVertex3f( 1.0f, 0.0f, -1.0f);
//				glColor3f(1.0f,0.0f,0.0f);	
//				glVertex3f( 0.0f, -10.0f, -1.0f);
//				glVertex3f( 0.0f, 1.0f, -1.0f);
//			glEnd();// Done drawing the quad
//				glVertex3f( 1.0f, 1.0f, 1.0f);
//				glVertex3f( 1.0f, 1.0f, 1.0f);*/
//		
////glRotatef(rtri,mx+0.1f,my+0.1f,0.0f);						// Rotate the triangle on the y axis 
//			//glBegin(GL_TRIANGLES);								// Start drawing a triangle
//			//	glColor3f(1.0f,0.0f,0.0f);						// Red
//			//	glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (front)
//			//	glColor3f(0.0f,1.0f,0.0f);						// Green
//			//	glVertex3f(-1.0f,-1.0f, 1.0f);					// Left of triangle (front)
//			//	glColor3f(0.0f,0.0f,1.0f);						// Blue
//			//	glVertex3f( 1.0f,-1.0f, 1.0f);					// Right of triangle (front)
//			//	glColor3f(1.0f,0.0f,0.0f);						// Red
//			//	glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (right)
//			//	glColor3f(0.0f,0.0f,1.0f);						// Blue
//			//	glVertex3f( 1.0f,-1.0f, 1.0f);					// Left of triangle (right)
//			//	glColor3f(0.0f,1.0f,0.0f);						// Green
//			//	glVertex3f( 1.0f,-1.0f, -1.0f);					// Right of triangle (right)
//			//	glColor3f(1.0f,0.0f,0.0f);						// Red
//			//	glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (back)
//			//	glColor3f(0.0f,1.0f,0.0f);						// Green
//			//	glVertex3f( 1.0f,-1.0f, -1.0f);					// Left of triangle (back)
//			//	glColor3f(0.0f,0.0f,1.0f);						// Blue
//			//	glVertex3f(-1.0f,-1.0f, -1.0f);					// Right of triangle (back)
//			//	glColor3f(1.0f,0.0f,0.0f);						// Red
//			//	glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of triangle (left)
//			//	glColor3f(0.0f,0.0f,1.0f);						// Blue
//			//	glVertex3f(-1.0f,-1.0f,-1.0f);					// Left of triangle (left)
//			//	glColor3f(0.0f,1.0f,0.0f);						// Green
//			//	glVertex3f(-1.0f,-1.0f, 1.0f);					// Right of triangle (left)
//			//glEnd();											// Done drawing the pyramid
//
//			//					// Move right 1.5 units and into the screen 7.0
//			//glRotatef(rquad,1.0f,1.0f,1.0f);					// Rotate the quad on the x axis 
//			//glBegin(GL_QUADS);									// Draw a quad
//			//	glColor3f(0.0f,1.0f,0.0f);						// Set The color to green
//			//	glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right of the quad (top)
//			//	glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left of the quad (top)
//			//	glVertex3f(-1.0f, 1.0f, 1.0f);					// Bottom left of the quad (top)
//			//	glVertex3f( 1.0f, 1.0f, 1.0f);					// Bottom right of the quad (top)
//			//	glColor3f(1.0f,0.5f,0.0f);						// Set The color to orange
//			//	glVertex3f( 1.0f,-1.0f, 1.0f);					// Top Right of the quad (bottom)
//			//	glVertex3f(-1.0f,-1.0f, 1.0f);					// Top Left of the quad (bottom)
//			//	glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom left of the quad (bottom)
//			//	glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom right of the quad (bottom)
//			//	glColor3f(1.0f,0.0f,0.0f);						// Set The color to red
//			//	glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Right of the quad (front)
//			//	glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Left of the quad (front)
//			//	glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom left of the quad (front)
//			//	glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom right of the quad (front)
//			//	glColor3f(1.0f,1.0f,0.0f);						// Set The color to yellow
//			//	glVertex3f( 1.0f,-1.0f,-1.0f);					// Top Right of the quad (back)
//			//	glVertex3f(-1.0f,-1.0f,-1.0f);					// Top Left of the quad (back)
//			//	glVertex3f(-1.0f, 1.0f,-1.0f);					// Bottom left of the quad (back)
//			//	glVertex3f( 1.0f, 1.0f,-1.0f);					// Bottom right of the quad (back)
//			//	glColor3f(0.0f,0.0f,1.0f);						// Set The color to blue
//			//	glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Right of the quad (left)
//			//	glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left of the quad (left)
//			//	glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom left of the quad (left)
//			//	glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom right of the quad (left)
//			//	glColor3f(1.0f,0.0f,1.0f);						// Set The color to violet
//			//	glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right of the quad (right)
//			//	glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Left of the quad (right)
//			//	glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom left of the quad (right)
//			//	glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom right of the quad (right)
//			//glEnd();											// Done drawing the quad
//			//glLoadIdentity();									// Reset the current modelview matrix
//			//glTranslatef(1.5f,0.0f,-7.0f);	
//			//glBegin(GL_QUADS_STRIP);
//			//	glColor3f(1.0f,0.0f,1.0f);						// Set The color to violet
//			//	glVertex3f( 0.0f, 0.0f,-1.0f);	
//			//	glVertex3f( 0.0f, 1.0f,-1.0f);	
//			//	glVertex3f( 1.0f, 1.0f,-1.0f);
//			//	glVertex3f( 1.0f, 0.0f,-1.0f);	
//			//glEnd();		
//			/*glColor3f(.3,.3,.3);
//			glBegin(GL_QUADS);
//			glVertex3f( 0,-0.001, 0);
//			glVertex3f( 0,-0.001,10);
//			glVertex3f(10,-0.001,10);
//			glVertex3f(10,-0.001, 0);
//			glEnd();
//
//			glBegin(GL_LINES);
//			for(int i=0;i<=10;i++) {
//				if (i==0) { glColor3f(.6,.3,.3); } else { glColor3f(.25,.25,.25); };
//				glVertex3f(i,0,0);
//				glVertex3f(i,0,10);
//				if (i==0) { glColor3f(.3,.3,.6); } else { glColor3f(.25,.25,.25); };
//				glVertex3f(0,i,0);
//				glVertex3f(10,i,0);*/
//			/*};*/
//glColor3f(.3,.3,.3);
//glBegin(GL_QUADS);
//glVertex3f( 0,-0.001, 0);
//glVertex3f( 0,-0.001,10);
//glVertex3f(10,-0.001,10);
//glVertex3f(10,-0.001, 0);
//glEnd();
//
//glBegin(GL_LINES);
//for(int i=0;i<=10;i++) {
//    if (i==0) { glColor3f(.6,.3,.3); } else { glColor3f(.25,.25,.25); };
//    glVertex3f(i,0,0);
//    glVertex3f(i,0,10);
//    if (i==0) { glColor3f(.3,.3,.6); } else { glColor3f(.25,.25,.25); };
//    glVertex3f(0,0,i);
//    glVertex3f(10,0,i);
//};
//glEnd();
//
//float x=.051,y=.051,z=.51;
//	void gldrawing()
//	{
//		glLoadIdentity();	
//		//glTranslatef(-1.5f,0.0f,-12.0f);
//		glRotatef(.5,1.0f,1.0f,1.0f);
//		glBegin(GL_LINE_STRIP);
//		glColor3f(0.0f,1.0f,0.0f);
//		glVertex3f( -1.0f, 0.0f, -1.0f);
//		glVertex3f( 1.0f, 0.0f, -1.0f);
//		glColor3f(1.0f,0.0f,0.0f);	
//		glVertex3f( 0.0f, -10.0f, -1.0f);
//		glVertex3f( 0.0f, 1.0f, -1.0f);
//		//	glVertex3f( 1.0f, 1.0f, 1.0f);
//		//	glVertex3f( 1.0f, 1.0f, 1.0f);
//		glEnd();
//		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//	
//		for (int i=0;i<Grid_X;i++)
//			for(int j=0;j<Grid_Y;j++)
//			{
//		glBegin(GL_QUADS);
//			glColor3f(1.0f,.0f,0.5f);
//			glVertex3f( -x*i,y*j, -z);
//			glVertex3f( x*i,y*j, -z);
//			//glColor3f(1.0f,1.0f,1.0f);	
//			glVertex3f( x*i, -y*j, -z);
//			glVertex3f( -x*i, -y*j, -z);
//		glEnd();
//			}
//
//	}