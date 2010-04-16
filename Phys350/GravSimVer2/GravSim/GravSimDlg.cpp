// GravSimDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GravSim.h"
#include "GravSimDlg.h"
#include "PlanetDefs.h"
#include <string>
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGravSimDlg dialog

static int EdgeOffset = 0;
extern CTextureLoader* TexLoad = 0;



CGravSimDlg::CGravSimDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGravSimDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGravSimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PAUSEBUTTON, ButtonPause);
	DDX_Control(pDX, IDC_SceneListCombo, m_SceneListCombo);
	DDX_Control(pDX, IDC_PlanetListCombo, m_PlanetListCombo);
}

BEGIN_MESSAGE_MAP(CGravSimDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_PAUSEBUTTON, &CGravSimDlg::OnBnClickedPausebutton)
	ON_CBN_SELCHANGE(IDC_SceneListCombo, &CGravSimDlg::OnCbnSelchangeScenelistcombo)
	ON_BN_CLICKED(IDC_SCENERESETBUTTON, &CGravSimDlg::OnBnClickedSceneresetbutton)
	ON_BN_CLICKED(IDC_RemovePlanetButton, &CGravSimDlg::OnBnClickedRemoveplanetbutton)
	ON_BN_CLICKED(IDC_SPEEDDECREASEBUTTON, &CGravSimDlg::OnBnClickedSpeeddecreasebutton)
	ON_BN_CLICKED(IDC_SPEEDINCREASEBUTTON, &CGravSimDlg::OnBnClickedSpeedincreasebutton)
	ON_BN_CLICKED(IDC_FocusButton, &CGravSimDlg::OnBnClickedFocusbutton)
	ON_BN_CLICKED(IDC_AddPlanetButton, &CGravSimDlg::OnBnClickedAddplanetbutton)
	ON_BN_CLICKED(IDC_UnFocusButton, &CGravSimDlg::OnBnClickedUnfocusbutton)
END_MESSAGE_MAP()


// CGravSimDlg message handlers

BOOL CGravSimDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CRect rect;
	//CRect oglrect;

	
	GetClientRect(rect);
	//ScreenToClient(rect);

	//GetDlgItem(IDC_OPENGL)->GetWindowRect(oglrect);

	//EdgeOffset = oglrect.left;

	// Create OpenGL Control window
	m_oglWindow.oglCreate(CRect(0,0,rect.right,rect.bottom), this);

	m_texLoader.LoadTextures("Textures\\Planets");

	TexLoad = &m_texLoader;

	// Setup the OpenGL Window's timer to render


	
	//	Setup Scenes here
	
	
	m_SceneMgr.Init(&m_objSim,&m_oglWindow);



	//	Now Update the UI Elements
	UpdateSceneList();
	m_SceneListCombo.SetCurSel(0);
	UpdatePlanetList();

	

	//Do Allocation of Planets here
/*	m_objList.push_back(new CPlanetEarth);
	m_objList.push_back(new CPlanetSun);
	m_objList.push_back(new CPlanetNemesis);
	m_objList.push_back(new CPlanetMoon);
	m_objList.push_back(new CPlanetVenus);*/

	//	Setup the render timer
	SetTimer(1,20,0);

	LOG("\nStarting Simulation loop");
	IsProcessing = false;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGravSimDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGravSimDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGravSimDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
  
	m_oglWindow.MoveWindow(0,0,cx,cy,true);
	m_oglWindow.OnSize(nType, cx, cy);
}

void CGravSimDlg::OnTimer(UINT_PTR nIDEvent)
{

	//	Main Loop

	if(IsProcessing) return;
	IsProcessing = true;


	//	Scene manager calls the processing and the draw 
	m_SceneMgr.RunScene();

	//Finished Processing Everything
	IsProcessing = false;

	CDialog::OnTimer(nIDEvent);
}

void CGravSimDlg::OnClose()
{
	Deinitialize();
	CDialog::OnClose();
}

void CGravSimDlg::Deinitialize()
{
	KillTimer(1);				//	Kill the Process Loop
	while(IsProcessing);		//	Wait for processing to finish

	

	//Delete planets here
/*	std::vector<CGravObject*>::iterator	i;
	printf("\nDeleting Objects Now");
	for(i = m_objList.begin(); i != m_objList.end() ; i++)				//	Delete all planet objects
	{
		CGravObject * CurrentObj = *i;
		delete CurrentObj;
		*i = 0;
	}
	m_objList.empty();
	*/
}

void CGravSimDlg::OnCancel()
{
	Deinitialize();
	CDialog::OnCancel();
}

void CGravSimDlg::OnOK()
{
	Deinitialize();
	CDialog::OnOK();
}


void CGravSimDlg::UpdateSceneList()
{
	//Add all the Scene names into the drop down list

	std::vector<std::string>::iterator i;

	
	for(i = m_SceneMgr.SceneNames.begin(); i != m_SceneMgr.SceneNames.end(); i++)
	{
		m_SceneListCombo.InsertString(-1,i->c_str());		
	}
}

void CGravSimDlg::UpdatePlanetList()
{
	m_PlanetListCombo.ResetContent();

	
	std::vector<std::string>::iterator i;
	
	
	for(i = m_SceneMgr.CurrentScene->NodeNames.begin(); i != m_SceneMgr.CurrentScene->NodeNames.end(); i++)
	{
		m_PlanetListCombo.InsertString(-1,i->c_str());		
	}
	
	m_PlanetListCombo.SetCurSel(0);

}


void CGravSimDlg::OnBnClickedPausebutton()
{
	m_SceneMgr.TogglePause();
}

void CGravSimDlg::OnBnClickedSpeeddecreasebutton()
{
	m_SceneMgr.HalveSpeed();
}

void CGravSimDlg::OnBnClickedSpeedincreasebutton()
{
	m_SceneMgr.DoubleSpeed();
}



void CGravSimDlg::OnCbnSelchangeScenelistcombo()
{
	m_SceneMgr.ChangeScene(m_SceneListCombo.GetCurSel());
	UpdatePlanetList();
}

void CGravSimDlg::OnBnClickedSceneresetbutton()
{
	m_SceneMgr.ResetCurrentScene();
	UpdatePlanetList();
}

void CGravSimDlg::OnBnClickedRemoveplanetbutton()
{
	m_SceneMgr.DeleteNode(m_PlanetListCombo.GetCurSel());
	UpdatePlanetList();
}


void CGravSimDlg::OnBnClickedFocusbutton()
{
	m_SceneMgr.SetCameraFocus(m_PlanetListCombo.GetCurSel());
}

void CGravSimDlg::OnBnClickedAddplanetbutton()
{
/*	CVec3 Pos = m_SceneMgr.CurrentScene->NodeList[m_PlanetListCombo.GetCurSel()]->v3Pf; 
	CVec3 Vel = m_SceneMgr.CurrentScene->NodeList[m_PlanetListCombo.GetCurSel()]->v3Pi;
	UpdateData();
	
	CVec3 Pos(EditPosX.get,EditPosY,EditPosZ);
	CVec3 Vel(EditVelX,EditVelY,EditVelZ);
	float Mass = EditMass;
	float Radius = EditRadius;
	float Trails = 100;

	CVec3 Pos(10,10,10);
	CVec3 Vel(-3,-3,-3);
	float Mass = 10000;
	float Radius = 10;

	m_SceneMgr.AddNode(new CGravObject("AddedObject",Pos,Vel,Mass,Radius,Trails));
	UpdatePlanetList();

*/
}

void CGravSimDlg::OnBnClickedUnfocusbutton()
{
	m_SceneMgr.SetCameraFocus(-1);
}
