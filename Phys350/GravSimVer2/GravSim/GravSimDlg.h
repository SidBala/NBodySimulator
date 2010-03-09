// GravSimDlg.h : header file
//
#pragma once

#include "OpenGLControl.h"
#include "ObjectSim.h"


// CGravSimDlg dialog
class CGravSimDlg : public CDialog
{
private:
	COpenGLControl m_oglWindow;
	bool IsProcessing;
	
	CObjectSim	m_objSim;

	std::vector <CGravObject*> m_objList;

// Construction
public:
	CGravSimDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GRAVSIM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();

	void Deinitialize();

protected:
	virtual void OnCancel();
	virtual void OnOK();
};