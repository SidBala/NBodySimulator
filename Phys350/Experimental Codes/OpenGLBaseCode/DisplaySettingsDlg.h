
// DisplaySettingsDlg.h : header file
//


class CDisplaySettingsDlg : public CDialog
{

public:
	BOOL ModeExists( DEVMODE *dm );
	CString WordToString( UINT uValue );
	void LoadSettings( );
	void SaveSettings( );

	void FillCombo();
	void EnumDisplays();
	CDisplaySettingsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDisplaySettingsDlg();

	CPtrArray	m_DisplayModes;
	CString		m_strIniFile;

	enum { IDD = IDD_DISPLAY_SETTINGS };
	CComboBox	m_cboResolutions;
	BOOL	m_bDontAskAgain;
	BOOL	m_bFullscreen;




	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

protected:


	virtual void OnOK();
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};

