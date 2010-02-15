/****************************************
*   Nehe MFC by Yvo van Dillen based on *
*   Jeff Molofee's Basecode Example     *
*          nehe.gamedev.net             *
*             2001/2004                 *
*                                       *
*****************************************/

#include "stdafx.h"
#include "GravSimApp.h"
#include "DisplayWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CDisplayWindow

CDisplayWindow::CDisplayWindow()
{	
}

CDisplayWindow::~CDisplayWindow()
{
}


BEGIN_MESSAGE_MAP(CDisplayWindow, CWnd)
	//{{AFX_MSG_MAP(CDisplayWindow)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_MESSAGE( WM_TOGGLEFULLSCREEN , OnToggleFullScreen )
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDisplayWindow message handlers

void CDisplayWindow::OnSysCommand(UINT nID, LPARAM lParam) 
{
	// TODO: Add your message handler code here and/or call default
	switch (lParam)													// Check System Calls
	{
			case SC_SCREENSAVE:										// Screensaver Trying To Start?
			case SC_MONITORPOWER:									// Monitor Trying To Enter Powersave?
			return;													// Prevent From Happening
	}

	CWnd::OnSysCommand(nID, lParam);
}

void CDisplayWindow::OnClose() 
{		
	CWnd::CloseWindow();
	theApp.TerminateApplication();
}

void CDisplayWindow::OnSize(UINT nType, int cx, int cy) 
{	
	switch (nType)											// Evaluate Size Action
	{
		case SIZE_MINIMIZED:								// Was Window Minimized?
			theApp.m_isVisible = FALSE;						// Set isVisible To False
		return;												// Return

		case SIZE_MAXIMIZED:								// Was Window Maximized?
			theApp.m_isVisible = TRUE;						// Set isVisible To True
			theApp.ReshapeGL (cx,cy);						// Reshape Window - LoWord=Width, HiWord=Height
		return;												// Return

		case SIZE_RESTORED:									// Was Window Restored?
			theApp.m_isVisible = TRUE;					    // Set isVisible To True
			theApp.ReshapeGL (cx,cy);						// Reshape Window - LoWord=Width, HiWord=Height
		return;												// Return
	}
}

void CDisplayWindow::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{	
	if ((nChar >= 0) && (nChar <= 255))						// Is Key (nChar) In A Valid Range?
	{
		theApp.keyDown [nChar] = TRUE;						// Set The Selected Key (wParam) To True
		return;												// Return
	}	
}

void CDisplayWindow::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if ((nChar >= 0) && (nChar <= 255))						// Is Key (nChar) In A Valid Range?
	{
		theApp.keyDown [nChar] = FALSE;						// Set The Selected Key (wParam) To True
		return;												// Return
	}	
}

 void CDisplayWindow::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON)
	{
		printf("\n Mouse Moved on LButton x:%d y:%d",point.x,point.y);

		

	}
	CWnd::OnMouseMove(nFlags, point);
}

void CDisplayWindow::OnLButtonDown(UINT nFlags, CPoint point)
{}
 void CDisplayWindow::OnLButtonUp(UINT nFlags, CPoint point){}


LRESULT CDisplayWindow::OnToggleFullScreen(WPARAM w,LPARAM l)
{
	theApp.ToggleFullScreen();								// somebody (app/you) want to toggle fullscreen
	return 1;
}


BOOL CDisplayWindow::OnEraseBkgnd(CDC* pDC) 
{
	//Disable that irritating flicker thingy
	return FALSE;	
}
