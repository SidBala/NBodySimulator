// GravSimDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GravSim.h"
#include "GravSimDlg.h"
#include "PlanetDefs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGravSimDlg dialog




CGravSimDlg::CGravSimDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGravSimDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGravSimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGravSimDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CLOSE()
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

	// Get size and position of the template textfield we created before in the dialog editor
	GetDlgItem(IDC_OPENGL)->GetWindowRect(rect);

	// Convert screen coordinates to client coordinates
	ScreenToClient(rect);

	// Create OpenGL Control window
	m_oglWindow.oglCreate(rect, this);

	// Setup the OpenGL Window's timer to render
	//	Setup the render timer
	SetTimer(1,20,0);
	IsProcessing = false;

	//Do Allocation of Planets here
	m_objList.push_back(new CPlanetEarth);
	m_objList.push_back(new CPlanetSun);
	m_objList.push_back(new CPlanetNemesis);
	m_objList.push_back(new CPlanetMoon);
	m_objList.push_back(new CPlanetVenus);
	
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
  
	m_oglWindow.OnSize(nType, cx-20, cy-20);
}

void CGravSimDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(IsProcessing) return;

	IsProcessing = true;

	//Process Everything

	m_objSim.SimUpdate (1, &m_objList);	//	Run the Physics Simulation here

	m_oglWindow.oglDrawScene(&m_objList);			//	This is the Draw Function




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

								//Deallocation - Do it here!

	//Delete planets here
	std::vector<CGravObject*>::iterator	i;
	printf("\nDeleting Objects Now");
	for(i = m_objList.begin(); i != m_objList.end() ; i++)				//	Delete all planet objects
	{
		CGravObject * CurrentObj = *i;
		delete CurrentObj;
		*i = 0;
	}
	m_objList.empty();
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
