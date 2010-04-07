// GravSimDlg.h : header file
//
#pragma once

#include "OpenGLControl.h"
#include "ObjectSim.h"
#include "SceneManager.h"
#include "TextureLoader.h"
#include "afxwin.h"


// CGravSimDlg dialog
class CGravSimDlg : public CDialog
{
private:
	
	bool IsProcessing;

	COpenGLControl m_oglWindow;
	CObjectSim	m_objSim;
	CTextureLoader m_texLoader;

	//std::vector <CGravObject*> m_objList;

	CSceneManager m_SceneMgr;

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

	void UpdateSceneList();
	void UpdatePlanetList();
	void Deinitialize();

protected:
	virtual void OnCancel();
	virtual void OnOK();
public:
	afx_msg void OnBnClickedPausebutton();
	CButton ButtonPause;
	CComboBox m_SceneListCombo;
	afx_msg void OnCbnSelchangeScenelistcombo();
	afx_msg void OnBnClickedSceneresetbutton();
	CComboBox m_PlanetListCombo;
	afx_msg void OnBnClickedRemoveplanetbutton();
};
