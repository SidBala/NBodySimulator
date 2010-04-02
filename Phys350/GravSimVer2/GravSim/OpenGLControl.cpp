#include "stdafx.h"
#include "OpenGLControl.h"
#include ".\openglcontrol.h"
#include "SOIL\SOIL.h"




COpenGLControl::COpenGLControl(void)
{
	m_fPosX = 0.0f;		// X position of model in camera view
	m_fPosY = 0.0f;		// Y position of model in camera view
	m_fZoom = 10.0f;	// Zoom on model in camera view
	m_fRotX = 0.0f;		// Rotation on model in camera view
	m_fRotY	= 0.0f;		// Rotation on model in camera view
	m_bIsMaximized = false;
}

COpenGLControl::~COpenGLControl(void)
{
}

BEGIN_MESSAGE_MAP(COpenGLControl, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void COpenGLControl::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	ValidateRect(NULL);
}

void COpenGLControl::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	if (0 >= cx || 0 >= cy || nType == SIZE_MINIMIZED) return;

	// Map the OpenGL coordinates.
	glViewport(0, 0, cx, cy);

	// Projection view
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	// Set our current view perspective
	gluPerspective(35.0f, (float)cx / (float)cy, 0.01f, 2000.0f);

	// Model view
	glMatrixMode(GL_MODELVIEW);

	SetWindowPos(NULL,10,10,cx,cy,0);
	/*switch (nType)
	{
		// If window resize token is "maximize"
		case SIZE_MAXIMIZED:
		{
			// Get the current window rect
			GetWindowRect(m_rect);

			// Move the window accordingly
			MoveWindow(6, 6, cx - 14, cy - 14);

			// Get the new window rect
			GetWindowRect(m_rect);

			// Store our old window as the new rect
			m_oldWindow = m_rect;

			break;
		}

		// If window resize token is "restore"
		case SIZE_RESTORED:
		{
			// If the window is currently maximized
			if (m_bIsMaximized)
			{
				// Get the current window rect
				GetWindowRect(m_rect);

				// Move the window accordingly (to our stored old window)
				MoveWindow(m_oldWindow.left, m_oldWindow.top - 18, m_originalRect.Width() - 4, m_originalRect.Height() - 4);

				// Get the new window rect
				GetWindowRect(m_rect);

				// Store our old window as the new rect
				m_oldWindow = m_rect;
			}
		
			break;
		}
	}*/
}

int COpenGLControl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1) return -1;

	oglInitialize();

	return 0;
}

void COpenGLControl::OnDraw(CDC *pDC)
{
	// If the current view is perspective...
/*	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -m_fZoom);
	glTranslatef(m_fPosX, m_fPosY, 0.0f);
	glRotatef(m_fRotX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_fRotY, 0.0f, 1.0f, 0.0f);*/
}

void COpenGLControl::OnTimer(UINT nIDEvent)		//Deprecated Could just remove this
{
	switch (nIDEvent)
	{
		case 1:
		{
			// Clear color and depth buffer bits
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Draw OpenGL scene
			//oglDrawScene();

			// Swap buffers
			SwapBuffers(hdc);

			break;
		}

		default:
			break;
	}

	CWnd::OnTimer(nIDEvent);
}
	
void COpenGLControl::OnMouseMove(UINT nFlags, CPoint point)
{
	int diffX = (int)(point.x - m_fLastX);
	int diffY = (int)(point.y - m_fLastY);
	m_fLastX  = (float)point.x;
	m_fLastY  = (float)point.y;

	// Left mouse button
	if (nFlags & MK_LBUTTON)
	{
		m_fRotX += (float)0.5f * diffY;

		if ((m_fRotX > 360.0f) || (m_fRotX < -360.0f))
		{
			m_fRotX = 0.0f;
		}

		m_fRotY += (float)0.5f * diffX;

		if ((m_fRotY > 360.0f) || (m_fRotY < -360.0f))
		{
			m_fRotY = 0.0f;
		}
	}

	// Right mouse button
	else if (nFlags & MK_RBUTTON)
	{
		m_fZoom -= (float)0.1f * diffY;
	}

	// Middle mouse button
	else if (nFlags & MK_MBUTTON)
	{
		m_fPosX += (float)0.05f * diffX;
		m_fPosY -= (float)0.05f * diffY;
	}

	OnDraw(NULL);

	CWnd::OnMouseMove(nFlags, point);
}

void COpenGLControl::oglCreate(CRect rect, CWnd *parent)
{
	CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_OWNDC, NULL, (HBRUSH)GetStockObject(BLACK_BRUSH), NULL);

	CreateEx(0, className, "OpenGL", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, parent, 0);

	// Set initial variables' values
	m_oldWindow	   = rect;
	m_originalRect = rect;

	hWnd = parent;
}

void COpenGLControl::oglInitialize(void)
{
	// Initial Setup:
	//
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32, // bit depth
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		16, // z-buffer depth
		0, 0, 0, 0, 0, 0, 0,
	};

	// Get device context only once.
	hdc = GetDC()->m_hDC;
	
	// Pixel format.
	m_nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, m_nPixelFormat, &pfd);

	// Create the OpenGL Rendering Context.
	hrc = wglCreateContext(hdc);
	wglMakeCurrent(hdc, hrc);

	// Basic Setup:
	//
	// Set color to use when clearing the background.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping ( NEW )
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	// Build Textures
	oglLoadSkyBoxTextures();

	// Send draw request
	OnDraw(NULL);
}

void COpenGLControl::oglDrawScene(std::vector<CGravObject*> *ObjList)
{
	// Wireframe Mode
	
	glMatrixMode (GL_MODELVIEW);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
	glLoadIdentity ();											// Reset The Modelview Matrix
	
	

		glTranslatef(0.0f, 0.0f, -m_fZoom);			//	Camera Controls - Zoom
		//glTranslatef(m_fPosX, m_fPosY, 0.0f);		//	Camera Controls - Pan
		glTranslatef(m_fPosX, m_fPosY, 0.0f);		//	Camera Controls - Pan
		glRotatef(m_fRotX, 1.0f, 0.0f, 0.0f);		//	Camera Controls - Rotation X
		glRotatef(m_fRotY, 0.0f, 1.0f, 0.0f);		//	Camera Controls - Rotation Y

		//Draw Rulers
		oglRenderSkybox(CVec3(0,0,0),CVec3(1000,1000,1000));

		glBegin(GL_LINES);
		glColor3f(0,0,1); glVertex3f(-10,0,0); glVertex3f(10,0,0);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(0,1,0); glVertex3f(0,-10,0); glVertex3f(0,10,0);
		glEnd();

		glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,-10); glVertex3f(0,0,10);
		glEnd();

		


		//glLoadIdentity();

		//glTranslatef(0.0f, 0.0f, -m_fZoom);			//	Camera Controls - Zoom
		//glTranslatef(m_fPosX, m_fPosY, 0.0f);		//	Camera Controls - Pan
		//glRotatef(m_fRotX, 1.0f, 0.0f, 0.0f);		//	Camera Controls - Rotation X
		//glRotatef(m_fRotY, 0.0f, 1.0f, 0.0f);		//	Camera Controls - Rotation Y


	std::vector<CGravObject*>::iterator	i;

	for(i = ObjList->begin(); i != ObjList->end() ; i++)
	{

		glPushMatrix();
		(*i)->DrawObject();
		glPopMatrix();
	}

	//glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
	//glLoadIdentity ();		
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//glbegin(gl_quads);

	//
	//		 front side
	//		glcolor3f(0,0,1);	glvertex3f( 1.0f,  1.0f, 1.0f);
	//		glcolor3f(0,1,0);	glvertex3f(-1.0f,  1.0f, 1.0f);
	//		glcolor3f(0,1,1);	glvertex3f(-1.0f, -1.0f, 1.0f);
	//		glcolor3f(1,0,0);	glvertex3f( 1.0f, -1.0f, 1.0f);

	//		 back side
	//		glcolor3f(1,0,1);	glvertex3f(-1.0f, -1.0f, -1.0f);
	//		glcolor3f(1,1,0);	glvertex3f(-1.0f,  1.0f, -1.0f);
	//		glcolor3f(0,0,1);	glvertex3f( 1.0f,  1.0f, -1.0f);
	//		glcolor3f(0,1,0);	glvertex3f( 1.0f, -1.0f, -1.0f);

	//		 top side
	//		glcolor3f(0,1,1);	glvertex3f( 1.0f, 1.0f,  1.0f);
	//		glcolor3f(1,0,0);	glvertex3f( 1.0f, 1.0f, -1.0f);
	//		glcolor3f(1,0,1);	glvertex3f(-1.0f, 1.0f, -1.0f);
	//		glcolor3f(1,1,0);	glvertex3f(-1.0f, 1.0f,  1.0f);

	//		 bottom side
	//		glcolor3f(0,0,1);	glvertex3f(-1.0f, -1.0f, -1.0f);
	//		glcolor3f(0,1,0);	glvertex3f( 1.0f, -1.0f, -1.0f);
	//		glcolor3f(0,1,1);	glvertex3f( 1.0f, -1.0f,  1.0f);
	//		glcolor3f(1,0,0);	glvertex3f(-1.0f, -1.0f,  1.0f);

	//		 right side
	//		glcolor3f(1,0,1);	glvertex3f( 1.0f,  1.0f,  1.0f);
	//		glcolor3f(1,1,0);	glvertex3f( 1.0f, -1.0f,  1.0f);
	//		glcolor3f(0,0,1);	glvertex3f( 1.0f, -1.0f, -1.0f);
	//		glcolor3f(0,1,0);	glvertex3f( 1.0f,  1.0f, -1.0f);

	//		 left side
	//		glcolor3f(0,1,1);	glvertex3f(-1.0f, -1.0f, -1.0f);
	//		glcolor3f(1,0,0);	glvertex3f(-1.0f, -1.0f,  1.0f);
	//		glcolor3f(1,0,1);	glvertex3f(-1.0f,  1.0f,  1.0f);
	//		glcolor3f(1,1,0);	glvertex3f(-1.0f,  1.0f, -1.0f);
	//glend();

	SwapBuffers(hdc);
}
/*
void COpenGLControl::oglRenderSkybox(CVec3 position,CVec3 size)
{	

	// Begin DrawSkyTex
	glColor4f(1.0, 1.0, 1.0,1.0f);
 
	// Save Current Matrix
	
	glPushMatrix();

	
	//glEnable(GL_TEXTURE_CUBE_MAP);
	// Second Move the render space to the correct position (Translate)
	glTranslatef(position.x,position.y,position.z);
 

	// First apply scale matrix
	//glScalef(size.x,size.y,size.z);
 
	float cz = -0.0f,cx = 1.0f;
	float r = 1.0f; // If you have border issues change this to 1.005f

//	glBindTexture(GL_TEXTURE_CUBE_MAP ,SkyTex[0]);


	//GLfloat params[] = {0,0,0,1};
	//glTexGenfv(GL_S, GL_OBJECT_PLANE, params);
	//glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	//glEnable(GL_TEXTURE_GEN_S);

	//glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR); 
	//glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR); 
	//glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR); 

	//glEnable(GL_TEXTURE_GEN_S); 
	//glEnable(GL_TEXTURE_GEN_T); 
	//glEnable(GL_TEXTURE_GEN_R);
	    	

	// Common Axis Z - UP Side
	glBindTexture(GL_TEXTURE_2D,SkyTex[4]);
	glBegin(GL_QUADS);	
	//glNormal3f( 0.0f, 0.5f, 0.0f);	
		glTexCoord2f(cx, cz); 
		glVertex3f(-r ,1.0f,-r); 
		glTexCoord2f(cx,  cx);
		glVertex3f(-r,1.0f,r);
		glTexCoord2f(cz,  cx);
		glVertex3f( r,1.0f,r); 
		glTexCoord2f(cz, cz);
		glVertex3f( r ,1.0f,-r);
	glEnd();
 
	// Common Axis Z - DN side
	glBindTexture(GL_TEXTURE_2D,SkyTex[5]);
	glBegin(GL_QUADS);		
		glTexCoord2f(cx,cz); 
		glVertex3f(-r,-1.0f,-r);
		glTexCoord2f(cx,cx); 
		glVertex3f(-r,-1.0f, r);
		glTexCoord2f(cz,cx); 
		glVertex3f( r,-1.0f, r); 
		glTexCoord2f(cz,cz); 
		glVertex3f( r,-1.0f,-r);
	glEnd();
 
	// Common Axis X - LT
	glBindTexture(GL_TEXTURE_2D,SkyTex[3]);
	glBegin(GL_QUADS);		
		glTexCoord2f(cx,cx);
		glVertex3f(-1.0f, -r, r);	
		glTexCoord2f(cz,cx);
		glVertex3f(-1.0f,  r, r); 
		glTexCoord2f(cz,cz);
		glVertex3f(-1.0f,  r,-r);
		glTexCoord2f(cx,cz);
		glVertex3f(-1.0f, -r,-r);		
	glEnd();
 
	// Common Axis X - RT
	glBindTexture(GL_TEXTURE_2D,SkyTex[2]);
	glBegin(GL_QUADS);		
		glTexCoord2f( cx,cx); 
		glVertex3f(1.0f, -r, r);	
		glTexCoord2f(cz, cx); 
		glVertex3f(1.0f,  r, r); 
		glTexCoord2f(cz, cz); 
		glVertex3f(1.0f,  r,-r);
		glTexCoord2f(cx, cz);
		glVertex3f(1.0f, -r,-r);
	glEnd();
 
	// Common Axis Y - BK
	glBindTexture(GL_TEXTURE_2D,SkyTex[1]);
	glBegin(GL_QUADS);
		glTexCoord2f(cz, cz); 
		glVertex3f( r, -r,1.0f);
		glTexCoord2f(cx, cz); 
		glVertex3f( r,  r,1.0f); 
		glTexCoord2f(cx, cx);
		glVertex3f(-r,  r,1.0f);
		glTexCoord2f(cz, cx);
		glVertex3f(-r, -r,1.0f);
	glEnd();
 
	// Common Axis Y - FT


	glBindTexture(GL_TEXTURE_2D,SkyTex[0]);
	glBegin(GL_QUADS);		
		glTexCoord2f(cz,cz);
		glVertex3f( r, -r,-1.0f);
		glTexCoord2f( cx,cz);
		glVertex3f( r,  r,-1.0f); 
		glTexCoord2f( cx,cx);
		glVertex3f(-r,  r,-1.0f);
		glTexCoord2f(cz, cx);
		glVertex3f(-r, -r,-1.0f);
	glEnd();


 
	// Load Saved Matrix

	//glBindTexture(GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT ,NULL);
	glBindTexture(GL_TEXTURE_2D,NULL);
	glPopMatrix();

 
}*/

void COpenGLControl::oglRenderSkybox(CVec3 position,CVec3 size)
{	

	// Begin DrawSkyTex
	glColor4f(1.0, 1.0, 1.0,1.0f);
 
	// Save Current Matrix
	
	glPushMatrix();

	
	// Second Move the render space to the correct position (Translate)
	glTranslatef(position.x,position.y,position.z);
 

	// First apply scale matrix
	glScalef(size.x,size.y,size.z);
 
	float cz = -0.0f,cx = 1.0f;
	float r = 1.0f; // If you have border issues change this to 1.005f

	//	Setup the Texture parameters
	glBindTexture(GL_TEXTURE_CUBE_MAP ,SkyTex[0]);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//	Setup the Automatic Texture coordinate generation
	float SplaneCoefficients[] = { 1, 0, 0, 0 };
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_EYE_PLANE, SplaneCoefficients);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, SplaneCoefficients);

	float TplaneCoefficients[] = { 0, 1, 0, 0 };
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_EYE_PLANE, TplaneCoefficients);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, TplaneCoefficients);

	float RplaneCoefficients[] = { 0, 0, 1, 0 };
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_R, GL_EYE_PLANE, RplaneCoefficients);
	glTexGenfv(GL_R, GL_OBJECT_PLANE, RplaneCoefficients);

	//	Begin auto texture coordinate generation
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	
	// Common Axis Z - UP Side
	glBegin(GL_QUADS);	
		glNormal3f(0,1.0f,0);
		glVertex3f(-r ,1.0f,-r); 
		glVertex3f(-r,1.0f,r);
		glVertex3f( r,1.0f,r); 
		glVertex3f( r ,1.0f,-r);
	glEnd();
 
	// Common Axis Z - DN side

	glBegin(GL_QUADS);	
		glNormal3f(0,-1.0f,0);
		glVertex3f(-r,-1.0f,-r);
		glVertex3f(-r,-1.0f, r);
		glVertex3f( r,-1.0f, r); 
		glVertex3f( r,-1.0f,-r);
	glEnd();
 
	// Common Axis X - LT

	glBegin(GL_QUADS);		
		glNormal3f(-1.0f,0,0);
		glVertex3f(-1.0f, -r, r);	
		glVertex3f(-1.0f,  r, r); 
		glVertex3f(-1.0f,  r,-r);
		glVertex3f(-1.0f, -r,-r);		
	glEnd();
 
	// Common Axis X - RT
	glBegin(GL_QUADS);
		glNormal3f(1.0f,0,0);
		glVertex3f(1.0f, -r, r);	
		glVertex3f(1.0f,  r, r); 
		glVertex3f(1.0f,  r,-r);
		glVertex3f(1.0f, -r,-r);
	glEnd();
 
	// Common Axis Y - BK
	glBegin(GL_QUADS);
		glNormal3f(0,0,1.0f);
		glVertex3f( r, -r,1.0f);
		glVertex3f( r,  r,1.0f); 
		glVertex3f(-r,  r,1.0f);
		glVertex3f(-r, -r,1.0f);
	glEnd();
 
	// Common Axis Y - FT
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1.0f);
		glVertex3f( r, -r,-1.0f);
		glVertex3f( r,  r,-1.0f); 
		glVertex3f(-r,  r,-1.0f);
		glVertex3f(-r, -r,-1.0f);
	glEnd();

	//	Disable the auto texture coordinate generation
	glDisable(GL_TEXTURE_GEN_S);		
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);

	//	Unbind the texture
	glBindTexture(GL_TEXTURE_CUBE_MAP,NULL);

 
	// Load Saved Matrix
	glPopMatrix();

 
}

inline void ConvertToInterleave(unsigned char * Input, unsigned char *Output, int Width, int Height)
{

	for(int j=0; j<Height; j++)
	{
		for(int i=0; i<Width; i++)
		{
			Output[3*(j*Width + i) + 0] = Input[(0*Width*Height) + ((Width * j) +i)];
			Output[3*(j*Width + i) + 1] = Input[(1*Width*Height) + ((Width * j) +i)];
			Output[3*(j*Width + i) + 2] = Input[(2*Width*Height) + ((Width * j) +i)];
		}
	}

}

/*void COpenGLControl::oglLoadSkyBoxTextures()
{
	//First Load the 6 texture Images for the Skybox

	glEnable(GL_TEXTURE_2D);
	
	glGenTextures(6, SkyTex);
	CImg<unsigned char> SkyTexImg[6];

	//Load the images
	SkyTexImg[0].load_bmp("Textures\\SkyBox\\FT.bmp");
	SkyTexImg[1].load_bmp("Textures\\SkyBox\\BK.bmp");
	SkyTexImg[2].load_bmp("Textures\\SkyBox\\RT.bmp");

	SkyTexImg[3].load_bmp("Textures\\SkyBox\\LT.bmp");
	SkyTexImg[4].load_bmp("Textures\\SkyBox\\UP.bmp");
	SkyTexImg[5].load_bmp("Textures\\SkyBox\\DN.bmp");

	unsigned char * TexImage = new unsigned char[SkyTexImg[0].width()*SkyTexImg[0].height()*3];

	for(int i=0; i<6; i++)
	{
		memset(TexImage,0,(SkyTexImg[i].width()*SkyTexImg[i].height()*3) );
		ConvertToInterleave(SkyTexImg[i].data(),TexImage,SkyTexImg[i].width(), SkyTexImg[i].height());

		glBindTexture(GL_TEXTURE_2D, SkyTex[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, SkyTexImg[i].width(), SkyTexImg[i].height(), 0, GL_RGB, GL_UNSIGNED_BYTE, TexImage);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtering
	}

	delete [] TexImage;
	

	//printf("\n Loading Textures");

	//SkyTex[0] = SOIL_load_OGL_single_cubemap ("SkyBox.png","EWUDNS",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_DDS_LOAD_DIRECT);

	//printf("\n Loading Textures: %s, ",SOIL_last_result()); 

								
}*/

void COpenGLControl::oglLoadSkyBoxTextures()
{
	glEnable(GL_TEXTURE_CUBE_MAP);

	printf("\n Loading Textures");

	SkyTex[0] = SOIL_load_OGL_single_cubemap ("Textures\\Skybox\\SkyBoxDark.png",SOIL_DDS_CUBEMAP_FACE_ORDER,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_DDS_LOAD_DIRECT);

	glBindTexture(GL_TEXTURE_CUBE_MAP ,SkyTex[0]);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	glBindTexture(GL_TEXTURE_CUBE_MAP ,NULL);

	printf("\n Loading Textures: %s, ",SOIL_last_result()); 

								
}