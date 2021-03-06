

#include "stdafx.h"
#include "GravSimApp.h"
#include "DisplayWindow.h"
#include "AppMain.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static float angle=0,rot1,rot2;

CMain::CMain()
{
	fTransX = fTransY = fTransZ = 0;
	fRotX = fRotY = fRotZ = 0;
	// Start Of User Initialization	
}

CMain::~CMain()
{

}

// Function name	: CMain::KeyPressed
// Description	    : Checks for a key press
//                    if( KeyPressed(VK_ESCAPE) ) { ... Escape was pressed ... }
// Return type		: BOOL 
// Argument         : int nCode
BOOL CMain::KeyPressed(int nCode)
{
	if( nCode >= 0 && nCode <= 255 )
	{
		return theApp.keyDown[ nCode ];
	}
	return FALSE;
}


// Function name	: CMain::Initialize
// Description	    : This function will initialize your opengl application
//					  Put in what you need
// Return type		: BOOL 
//					  return TRUE on success or FALSE on error (example :texture/model not found = FALSE)
BOOL CMain::Initialize()
{
	angle		= 0.0f;											// Set Starting Angle To Zero

	glClearColor (0.0f, 0.0f, 0.0f, 0.5f);						// Black Background
	glClearDepth (1.0f);										// Depth Buffer Setup
	glDepthFunc (GL_LEQUAL);									// The Type Of Depth Testing (Less Or Equal)
	glEnable (GL_DEPTH_TEST);									// Enable Depth Testing
	glShadeModel (GL_SMOOTH);									// Select Smooth Shading
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Set Perspective Calculations To Most Accurate

	return TRUE;
}


// Function name	: CMain::Deinitialize
// Description	    : This function will Deinitialize your opengl application
//					  destroy all objects here
// Return type		: void 
void CMain::Deinitialize()
{

}


// Function name	: CMain::Update
// Description	    : this function will be called every xx milliseconds
//					  update your variables through milliseconds
// Return type		: void 
// Argument         : DWORD milliseconds
void CMain::Update(DWORD milliseconds)
{	
	//	Process The Gravity Objects here




	if (KeyPressed(VK_ESCAPE) == TRUE)						// Is ESC Being Pressed?
	{
		theApp.TerminateApplication ();						// Terminate The Program
	}

	if (KeyPressed(VK_F1) == TRUE)							// Is F1 Being Pressed?
	{		
		theApp.ToggleFullScreen ();							// Toggle Fullscreen Mode
	}

	angle += (float)(milliseconds) / 20.0f;					// Update angle Based On The Clock
}


// Function name	: CMain::Draw
// Description	    : this function will draw (blt) your opengl scene to the window
// Return type		: void 
void CMain::Draw(std::vector<CGravObject*> *ObjList)
{
	glMatrixMode (GL_MODELVIEW);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
	glLoadIdentity ();											// Reset The Modelview Matrix
	
	//glTranslatef (0.0f, 0.0f, -12.0f);							// Translate 6 Units Into The Screen
	//glRotatef (angle, 0.0f, 1.0f, 0.0f);						// Rotate On The Y-Axis By angle


	std::vector<CGravObject*>::iterator	i;

	for(i = ObjList->begin(); i != ObjList->end() ; i++)
	{
		glLoadIdentity ();	
		//glTranslatef(fTransX,fTransY,fTransZ);
		glTranslatef(0,0,-12);
		(*i)->DrawObject();
	}
	/*for (rot1=0; rot1<2; rot1++)								// 2 Passes
	{
		glRotatef(90.0f,0.0f,1.0f,0.0f);						// Rotate 90 Degrees On The Y-Axis
		glRotatef(180.0f,1.0f,0.0f,0.0f);						// Rotate 180 Degress On The X-Axis
		for (rot2=0; rot2<2; rot2++)							// 2 Passes
		{
			glRotatef(180.0f,0.0f,1.0f,0.0f);					// Rotate 180 Degrees On The Y-Axis
			glBegin (GL_TRIANGLES);								// Begin Drawing Triangles
				glColor3f (1.f, 0.f, 0.f);	glVertex3f( 0.0f, 1.0f, 0.0f);
				glColor3f (0.f, 1.f, 0.f);	glVertex3f(-1.0f,-1.0f, 1.0f);
				glColor3f (0.f, 0.f, 1.f);	glVertex3f( 1.0f,-1.0f, 1.0f);
			glEnd ();
			// Done Drawing Triangles
		}
	}*/

	// Draw a 2D surface For UI Elements
	glMatrixMode (GL_MODELVIEW);
	glPushMatrix ();
	glLoadIdentity ();

	glMatrixMode (GL_PROJECTION);
	glPushMatrix ();
	glLoadIdentity ();
	gluOrtho2D(0,theApp.m_Width,0,theApp.m_Height);
	glBegin(GL_QUADS);
			glColor3f (1.f, 0.f, 0.f);
				glVertex3f (0,0,0);
				glVertex3f (100,0,0);
				glVertex3f (100,100,0);
				glVertex3f (0,100,0);
	glEnd();


	glPopMatrix();
	glMatrixMode (GL_MODELVIEW);
	glPopMatrix();

	glFlush ();													// Flush The GL Rendering Pipeline
}


