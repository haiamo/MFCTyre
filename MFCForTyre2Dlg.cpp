
// MFCForTyre2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCForTyre2.h"
#include "MFCForTyre2Dlg.h"
#include "afxdialogex.h"
#include <windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCForTyre2Dlg �Ի���



CMFCForTyre2Dlg::CMFCForTyre2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCFORTYRE2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCForTyre2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCForTyre2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCForTyre2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(OpenFileButton, &CMFCForTyre2Dlg::OnBnClickedOpenfilebutton)
	ON_STN_CLICKED(StaticFilePath, &CMFCForTyre2Dlg::OnStnClickedStaticfilepath)
	ON_BN_CLICKED(LoadDataBtn, &CMFCForTyre2Dlg::OnBnClickedLoaddatabtn)
END_MESSAGE_MAP()


// CMFCForTyre2Dlg ��Ϣ�������

BOOL CMFCForTyre2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCForTyre2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCForTyre2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCForTyre2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCForTyre2Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFCForTyre2Dlg::OnBnClickedOpenfilebutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fileopendlg(TRUE);
	CString filepath;
	if (fileopendlg.DoModal() == IDOK)
	{
		filepath = fileopendlg.GetPathName();
		GetDlgItem(StaticFilePath)->SetWindowTextA(filepath);
	}
}


void CMFCForTyre2Dlg::OnStnClickedStaticfilepath()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCForTyre2Dlg::OnBnClickedLoaddatabtn()
{
	// Load point cloud file
	LARGE_INTEGER nfreq, nst, nend;//Timer parameters.
	PointCloud<PointXYZ>::Ptr cloud(::new PointCloud<PointXYZ>);//Create point cloud pointer.
	CString	cs_file = "";
	string pcfile = "";
	GetDlgItem(StaticFilePath)->GetWindowTextA(cs_file);
	pcfile = cs_file.GetBuffer();
	if (0==strcmp("",pcfile.data()))
	{
		MessageBox("The file path is empty, please check again.", "Load Info", MB_OK | MB_ICONERROR);
	}
	int f_error = -1;
	string filetype = pcfile.substr(pcfile.length() - 4, 4);
	const char* filetype_c = filetype.data();
	if (0 == strcmp(filetype_c, ".ply"))
	{
		QueryPerformanceFrequency(&nfreq);
		QueryPerformanceCounter(&nst);
		f_error = pcl::io::loadPLYFile(pcfile, *cloud);
		QueryPerformanceCounter(&nend);
	}
	else
	{
		MessageBox("Please load valid .ply file.","Load file Info",MB_OK);
	}

	if (-1 == f_error)
	{
		MessageBox("Failed to load point cloud data, please try again!", "LoadError", MB_OK | MB_ICONERROR);
	}
	else
	{
		float timesp = (nend.QuadPart - nst.QuadPart)*1.0 / nfreq.QuadPart;
		stringstream stream;
		stream << timesp;
		string s_timesp;
		stream >> s_timesp;
		string sucInfo = "Loading cloud points cost " + s_timesp + " seconds!";
		MessageBoxA(sucInfo.c_str(), "Load Info", MB_OK | MB_ICONINFORMATION);
	}
}
