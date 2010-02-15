// Main Header for the Grav Sim Application
//



#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGravSimApp:
// 
//
#include "DisplayWindow.h"
#include "AppMain.h"

class CGravSimApp : public CWinApp
{
public:
	void ToggleFullScreen();
	void TerminateApplication ();
	void DestroyOpenGLWindow();
	void ReshapeGL (int width, int height);
	BOOL ChangeScreenResolution (int width, int height, int bitsPerPixel);
	BOOL RegisterWindowClass ();
	BOOL CreateOpenGLWindow();
	CGravSimApp();


	CDisplayWindow	m_wndMain;
	CMain		m_appMain;
	BOOL		m_isProgramLooping;
	BOOL		m_createFullScreen;

	int					m_Width;						// Width
	int					m_Height;						// Height
	int					m_bitsPerPixel;					// Bits Per Pixel
	BOOL				m_isFullScreen;					// FullScreen?
	BOOL				m_isVisible;

	CDC*				m_pDC;
	HGLRC				m_hRC;

	DWORD				m_lastTickCount;
	char				keyDown [256];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGravSimApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGravSimApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

