
#pragma once

// MainWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDisplayWindow window

class CDisplayWindow : public CWnd
{
// Construction
public:
	CDisplayWindow();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplayWindow)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDisplayWindow();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDisplayWindow)
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);	
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags,CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags,CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	
	//}}AFX_MSG
	afx_msg LRESULT OnToggleFullScreen(WPARAM w,LPARAM l);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

