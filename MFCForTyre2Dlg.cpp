
// MFCForTyre2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCForTyre2.h"
#include "MFCForTyre2Dlg.h"
#include "afxdialogex.h"
#include <windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCForTyre2Dlg 对话框



CMFCForTyre2Dlg::CMFCForTyre2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCFORTYRE2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCForTyre2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, BTN_OpenFile, m_btn_openfile);
	DDX_Control(pDX, BTN_LoadData, m_btn_loaddata);
	DDX_Control(pDX, BTN_NormalEst, m_btn_normalest);
	DDX_Control(pDX, BTN_SaveNEResult, m_btn_saveneresult);

	DDX_Control(pDX, STC_OpenFile, m_stc_openfile);
	DDX_Control(pDX, STC_LoadData, m_stc_loaddata);
	DDX_Control(pDX, STC_NormalEst, m_stc_normalest);
	DDX_Control(pDX, STC_NE_Radius, m_stc_ne_radius);
	DDX_Control(pDX, STC_NE_ThreadNum, m_stc_ne_threadnum);
	DDX_Control(pDX, STC_NE_IndexFolder, m_stc_ne_indexfolder);

	DDX_Control(pDX, EDT_NE_Radius, m_edt_ne_radius);
	DDX_Control(pDX, EDT_NE_ThreadNum, m_edt_ne_threadnum);
	DDX_Control(pDX, EDT_NE_IndexFolder, m_edt_ne_indexfolder);
}

BEGIN_MESSAGE_MAP(CMFCForTyre2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCForTyre2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(BTN_OpenFile, &CMFCForTyre2Dlg::OnBnClickedOpenfile)
	ON_BN_CLICKED(BTN_LoadData, &CMFCForTyre2Dlg::OnBnClickedLoaddata)
	ON_BN_CLICKED(BTN_NormalEst, &CMFCForTyre2Dlg::OnBnClickedNormalest)
//	ON_EN_CHANGE(EDT_NE_Radius, &CMFCForTyre2Dlg::OnEnChangeNeRadius)
ON_BN_CLICKED(BTN_SaveNEResult, &CMFCForTyre2Dlg::OnBnClickedSaveneresult)
END_MESSAGE_MAP()


// CMFCForTyre2Dlg 消息处理程序

BOOL CMFCForTyre2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_mindist = -1;
	m_edt_ne_radius.SetWindowTextA("0.1");
	m_edt_ne_threadnum.SetWindowTextA("2");
	m_edt_ne_indexfolder.SetWindowTextA("10");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCForTyre2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCForTyre2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCForTyre2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnOK();
}

PointCloud<PointXYZ>::Ptr CMFCForTyre2Dlg::GetCloudPtr()
{
	return m_cloud;
}

void CMFCForTyre2Dlg::SetCloudPtr(PointCloud<PointXYZ>::Ptr in_cloud)
{
	m_cloud = in_cloud;

	//Compute the minmum distance between points in cloud.
	double curdist = 0.0;
	Vector3d v3row, v3col;
	for (size_t ii = 1; ii < in_cloud->points.size(); ++ii)
	{
		v3row = Vector3d(in_cloud->points[ii-1].x, in_cloud->points[ii-1].y, in_cloud->points[ii-1].z);
		v3col = Vector3d(in_cloud->points[ii].x, in_cloud->points[ii].y, in_cloud->points[ii].z);
		curdist = (v3row - v3col).norm();
		if (m_mindist < ACCURACY)
		{
			if (curdist > ACCURACY)
			{
				m_mindist = curdist;
			}
			else
			{
				m_mindist = ACCURACY;
			}
		}
		else if (curdist > ACCURACY && curdist < m_mindist)
		{
			m_mindist = curdist;
		}
	}
}

float CMFCForTyre2Dlg::GetCloudMinDist()
{
	return m_mindist;
}

BOOL CMFCForTyre2Dlg::EnableWindows(BOOL bEnable)
{
	m_btn_loaddata.EnableWindow(bEnable);
	m_btn_normalest.EnableWindow(bEnable);
	m_btn_openfile.EnableWindow(bEnable);
	m_btn_saveneresult.EnableWindow(bEnable);
	return bEnable;
}

void CMFCForTyre2Dlg::OnBnClickedOpenfile()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fileopendlg(TRUE);
	CString filepath;
	if (fileopendlg.DoModal() == IDOK)
	{
		filepath = fileopendlg.GetPathName();
		m_stc_openfile.SetWindowTextA(filepath);
	}
}


void CMFCForTyre2Dlg::OnBnClickedLoaddata()
{
	// TODO: 在此添加控件通知处理程序代码
	// Load point cloud file
	LARGE_INTEGER nfreq, nst, nend;//Timer parameters.
	PointCloud<PointXYZ>::Ptr cloud(::new PointCloud<PointXYZ>);//Create point cloud pointer.
	CString	cs_file = "";
	string pcfile = "";
	m_stc_openfile.GetWindowTextA(cs_file);
	pcfile = cs_file.GetBuffer();
	if (0 == strcmp("", pcfile.data()))
	{
		MessageBox("The file path is empty, please check again.", "Load Info", MB_OK | MB_ICONERROR);
		m_stc_loaddata.SetWindowTextA("Loading failed: empty file path");
	}
	int f_error = -1;
	string filetype = pcfile.substr(pcfile.length() - 4, 4);
	const char* filetype_c = filetype.data();
	if (0 == strcmp(filetype_c, ".ply"))
	{
		m_stc_loaddata.SetWindowTextA("Loading data, please wait...");
		EnableWindows(FALSE);

		QueryPerformanceFrequency(&nfreq);
		QueryPerformanceCounter(&nst);
		f_error = pcl::io::loadPLYFile(pcfile, *cloud);
		QueryPerformanceCounter(&nend);

		EnableWindows(TRUE);
	}
	else
	{
		MessageBox("Please load valid .ply file.", "Load file Info", MB_OK | MB_ICONERROR);
		m_stc_loaddata.SetWindowTextA("Loading failed: not .ply file");
	}

	if (-1 == f_error)
	{
		MessageBox("Failed to load point cloud data, please try again!", "LoadError", MB_OK | MB_ICONERROR);
		m_stc_loaddata.SetWindowTextA("Loading failed: PCL function failed");
	}
	else
	{
		double spread = 0.0;
		CString cs_info = GetTimeSpreadCString("Loading successfully", nfreq, nst, nend, spread);
		cs_info = cs_info + "\r\n " + "Cloud has " + to_string(cloud->points.size()).c_str() + " pionts.";
		QueryPerformanceCounter(&nst);
		SetCloudPtr(cloud);
		QueryPerformanceCounter(&nend);
		cs_info = cs_info +"\r\n"+ GetTimeSpreadCString("Compute minmum distance successfully", nfreq, nst, nend, spread);
		cs_info = cs_info + "\r\n" + "Minmum distance in cloud is " + to_string(GetCloudMinDist()).c_str()+".";
		m_stc_loaddata.SetWindowTextA(cs_info);
	}
}


void CMFCForTyre2Dlg::OnBnClickedNormalest()
{
	// Normal Estimation Process
	// Parameters preparation
	pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());//Create a null kdtree object.
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(::new pcl::PointCloud<pcl::Normal>);
	LARGE_INTEGER nfreq, nst, nend;//Timer parameters.
	PointCloud<PointXYZ>::Ptr cloud = this->GetCloudPtr();

	//Estimating normal by multiple threads
	double thdnum = GetValueFromCString(&m_edt_ne_threadnum);
	ne.setNumberOfThreads(floor(thdnum));
	ne.setInputCloud(cloud);

	//Transfer kdtree object to normal estimation object.
	ne.setSearchMethod(tree);

	// Set searching neighbor radius.
	double radius = GetValueFromCString(&m_edt_ne_radius);
	ne.setRadiusSearch(radius);

	//Set searching indices of cloud points
	double indfolder = GetValueFromCString(&m_edt_ne_indexfolder);
	vector<int> indices(floor(cloud->points.size() / int(indfolder)));
	for (int ii = 0; ii<indices.size(); ++ii)
	{
		indices[ii] = ii * int(indfolder);
	}
	IndicesPtr indicesptr(new vector<int>(indices));
	ne.setIndices(indicesptr);

	//Searching normals
	CString cs_info;

	QueryPerformanceFrequency(&nfreq);
	m_stc_normalest.SetWindowTextA("Normal estimating, please wait...");
	EnableWindows(FALSE);

	QueryPerformanceCounter(&nst);
	ne.compute(*cloud_normals);
	QueryPerformanceCounter(&nend);
	double nespread = 0.0;
	cs_info = GetTimeSpreadCString("Normal estimating successfully", nfreq, nst, nend,nespread);
	cs_info = cs_info + "\r\n" + "With " + to_string(indices.size()).c_str() + " indices.";
	//cs_info = cs_info + "\r\n" + "Searching project normal, please wait...";
	m_stc_normalest.SetWindowTextA(cs_info + "\r\n" + "Searching project normal, please wait...");

	//Find main normal for the next preojecting process.
	Vector3d curNormal, cur_mainNorm;
	vector<Vector3d> cand_normals;
	vector<int> cand_normal_len;
	bool newNorm = TRUE;
	double angle = 0.0, angle1 = 0.0;
	size_t cand_len;
	QueryPerformanceCounter(&nst);
	for (size_t ii = 0; ii < cloud_normals->points.size(); ++ii)
	{
		cand_len = cand_normals.size();
		newNorm = TRUE;
		curNormal = Vector3d(cloud_normals->points[ii].normal_x, cloud_normals->points[ii].normal_y, cloud_normals->points[ii].normal_z);
		if (curNormal.norm() < ACCURACY || _isnan(curNormal[0]) || _isnan(curNormal[1]) || _isnan(curNormal[2]))
		{
			continue;
		}
		if (cand_len == 0)
		{
			cand_normals.push_back(curNormal);
			cand_normal_len.push_back(1);
		}
		else
		{
			for (size_t jj = 0; jj < cand_len; ++jj)
			{
				cur_mainNorm = cand_normals[jj];
				//angle1 = acos((curNormal[0] * cur_mainNorm[0] + curNormal[1] * cur_mainNorm[1] + curNormal[2] * cur_mainNorm[2]) / (curNormal.norm()*cur_mainNorm.norm()));
				angle = acos(curNormal.dot(cur_mainNorm) / (curNormal.norm()*cur_mainNorm.norm()));
				if ( angle - PI / 180 * 5<ACCURACY || angle - PI/180*175>ACCURACY)
				{
					newNorm = FALSE;
					cand_normal_len[jj]++;
					break;
				}
			}
			if (newNorm)
			{
				cand_normals.push_back(curNormal);
				cand_normal_len.push_back(1);
			}
		}
	}
	QueryPerformanceCounter(&nend);

	if (cand_normals.size() != 0)
	{
		vector<int>::iterator maxIndex = max_element(begin(cand_normal_len), end(cand_normal_len));
		Vector3d prjNormal = cand_normals[maxIndex-cand_normal_len.begin()];
	
		double pnspread = 0.0;
		cs_info = cs_info + "\r\n" + GetTimeSpreadCString("Project normal searching successfully ", nfreq, nst, nend, pnspread);
		cs_info = cs_info + "\r\n" + "Project normal is (" + to_string(prjNormal[0]).c_str()+", "+ to_string(prjNormal[1]).c_str()+", "+ to_string(prjNormal[2]).c_str() + ").";
		cs_info = cs_info + "\r\n" + "With " + to_string(*maxIndex).c_str() + " normals in 5 degree.";
		m_neObjList.AddNEObject(radius, thdnum, indfolder, nespread, indices.size(), pnspread, prjNormal);
	}
	else
	{
		cs_info = cs_info + "\r\n" + "Failed to get the project normal, please check data!";
	}
	m_stc_normalest.SetWindowTextA(cs_info);
	EnableWindows(TRUE);
	
	/*
	CRect rect;
	CSize size(0, 0);
	m_stc_normalest.GetWindowRect(rect);
	ScreenToClient(&rect);
	CDC dc=m_stc_normalest.GetWindowDC();
	CFont *pOldFont = dc.SelectObject(this->GetFont());
	CString str;
	m_stc_normalest.GetWindowText(str);
	if (::GetTextExtentPoint32((HDC)dc, str, str.GetLength(), &size))
	{
		rect.right = rect.left + size.cx;
		rect.bottom = rect.top + size.cy;
	}
	else
	{
		m_stc_normalest.SetWindowText("GetTextExtentPoint32 fail to get the size of text!");
	}
	m_stc_normalest.MoveWindow(rect);
	dc.SelectObject(pOldFont);
	*/
}

CString CMFCForTyre2Dlg::GetTimeSpreadCString(string procstr, LARGE_INTEGER nfreq, LARGE_INTEGER nst, LARGE_INTEGER nend, double& tspread)
{
	float timesp = (nend.QuadPart - nst.QuadPart)*1.0 / nfreq.QuadPart;
	stringstream stream;
	stream << timesp;
	string s_timesp;
	stream >> s_timesp;
	string sucInfo = procstr + ", costs " + s_timesp + " seconds!";
	tspread = timesp;
	return sucInfo.c_str();
}

double CMFCForTyre2Dlg::GetValueFromCString(CEdit* inEdit)
{
	CString cstr;
	char* chstr;
	inEdit->GetWindowTextA(cstr);
	chstr = cstr.GetBuffer();
	double val = atof(chstr);
	return val;
}

//void CMFCForTyre2Dlg::OnEnChangeNeRadius()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}


//Normal Estimation Oject Memeber Functions:
NormalEstObj::NormalEstObj()
{
	/*NormalEstStruct nsstr;
	nsstr.Radius = 0.1;
	nsstr.EstTime = 0.0;
	nsstr.NormalIndices = 0;
	nsstr.SearchTime = 0.0;
	nsstr.ProjectNormal = Vector3d(1.0, 0.0, 0.0);
	nsstr.Threads = 2;
	nsstr.Folder = 10;
	neObj.push_back(nsstr);*/
}

NormalEstObj::NormalEstObj(double r, size_t thds, size_t fld)
{
	NormalEstStruct nsstr;
	nsstr.Radius = r;
	nsstr.EstTime = 0.0;
	nsstr.NormalIndices = 0;
	nsstr.SearchTime = 0.0;
	nsstr.ProjectNormal = Vector3d(1.0, 0.0, 0.0);
	nsstr.Threads = thds;
	nsstr.Folder = fld;
	nsstr.IntSectAngle = 0.0;
	neObj.push_back(nsstr);
}

NormalEstObj::~NormalEstObj()
{
	neObj.clear();
}

void NormalEstObj::AddNEObject(double r, size_t thds, size_t fld, double et, size_t ni, double st, Vector3d v3)
{
	NormalEstStruct tmpstr;
	tmpstr.Radius = r;
	tmpstr.Threads = thds;
	tmpstr.Folder = fld;
	tmpstr.EstTime = et;
	tmpstr.NormalIndices = ni;
	tmpstr.SearchTime = st;
	tmpstr.ProjectNormal = v3;
	tmpstr.IntSectAngle = 0.0;
	neObj.push_back(tmpstr);
}

void NormalEstObj::AddNEObject(NormalEstStruct & nes)
{
	neObj.push_back(nes);
}

int NormalEstObj::WriteInFile(string fpath)
{
	fstream fs;
	fs.open(fpath, ios::out);
	if (!fs)
	{
		return -1;//Open file failed.
	}
	ComputeIntSectAngle();
	vector<NormalEstStruct>::iterator neit;
	fs << "Radius" << "\t" << "Thread" << "\t" << "Folder" << "\t" << "EstTime" << "\t";
	fs << "NormalIndices" << "\t" << "SearchTime" << "\t" << "ProjectNormal" << "\t" << "Intersection Angle" << endl;
	for (neit = neObj.begin(); neit != neObj.end(); ++neit)
	{
		fs << neit->Radius << "\t" << neit->Threads << "\t" << neit->Folder << "\t" << neit->EstTime << "\t";
		fs << neit->NormalIndices << "\t" << neit->SearchTime << "\t (" << neit->ProjectNormal.transpose() << ")" << "\t" << neit->IntSectAngle << endl;
	}
	fs.close();
	return 0;
}

void NormalEstObj::ComputeIntSectAngle()
{
	vector<NormalEstStruct>::iterator tmp_it;
	for (auto tmp_it = neObj.begin() + 1; tmp_it != neObj.end(); ++tmp_it)
	{
		if (tmp_it->ProjectNormal.norm() < ACCURACY)
		{
			continue;
		}
		tmp_it->IntSectAngle = acos((tmp_it-1)->ProjectNormal.dot(tmp_it->ProjectNormal.transpose())/((tmp_it - 1)->ProjectNormal.norm()*tmp_it->ProjectNormal.norm()));
	}
}


void CMFCForTyre2Dlg::OnBnClickedSaveneresult()
{
	// TODO: 在此添加控件通知处理程序代码
	if (0 > m_neObjList.WriteInFile("NormalEstimation.txt"))
	{
		MessageBox("Write file failed.", "Write Warning", MB_OK | MB_ICONERROR);
	}
}
