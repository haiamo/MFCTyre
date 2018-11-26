
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
	DDX_Control(pDX, BTN_NormalEst, m_btn_normalest);
	DDX_Control(pDX, BTN_SaveNEResult, m_btn_saveneresult);
	DDX_Control(pDX, BTN_ProjectToPlane, m_btn_projecttoplane);
	DDX_Control(pDX, BTN_RunPCA, m_btn_runpca);
	DDX_Control(pDX, RAD_PCAOrigin, m_rad_pcaorigin);
	DDX_Control(pDX, RAD_PCAProjected, m_rad_pcaprojected);
	DDX_Control(pDX, BTN_ConvertImg, m_btn_convertimg);

	DDX_Control(pDX, STC_OpenFile, m_stc_openfile);
	DDX_Control(pDX, STC_LoadData, m_stc_loaddata);
	DDX_Control(pDX, STC_NormalEst, m_stc_normalest);
	DDX_Control(pDX, STC_NE_Radius, m_stc_ne_radius);
	DDX_Control(pDX, STC_NE_ThreadNum, m_stc_ne_threadnum);
	DDX_Control(pDX, STC_NE_IndexFolder, m_stc_ne_indexfolder);
	DDX_Control(pDX, STC_ProjectToPlane, m_stc_projecttoplane);
	DDX_Control(pDX, STC_RunPCA, m_stc_runpca);
	DDX_Control(pDX, STC_ConvertImg, m_stc_convertimg);

	DDX_Control(pDX, EDT_NE_Radius, m_edt_ne_radius);
	DDX_Control(pDX, EDT_NE_ThreadNum, m_edt_ne_threadnum);
	DDX_Control(pDX, EDT_NE_IndexFolder, m_edt_ne_indexfolder);
	DDX_Control(pDX, EDT_NormalIndex, m_edt_normalindex);
}

BEGIN_MESSAGE_MAP(CMFCForTyre2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCForTyre2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(BTN_OpenFile, &CMFCForTyre2Dlg::OnBnClickedOpenfile)
	ON_BN_CLICKED(BTN_NormalEst, &CMFCForTyre2Dlg::OnBnClickedNormalest)
//	ON_EN_CHANGE(EDT_NE_Radius, &CMFCForTyre2Dlg::OnEnChangeNeRadius)
	ON_BN_CLICKED(BTN_SaveNEResult, &CMFCForTyre2Dlg::OnBnClickedSaveneresult)
	ON_BN_CLICKED(BTN_ProjectToPlane, &CMFCForTyre2Dlg::OnBnClickedProjecttoplane)
	ON_BN_CLICKED(BTN_RunPCA, &CMFCForTyre2Dlg::OnBnClickedRunpca)
	ON_BN_CLICKED(BTN_ConvertImg, &CMFCForTyre2Dlg::OnBnClickedConvertimg)
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
	//m_edt_normalindex.SetWindowTextA("0");

	m_rad_pcaorigin.SetCheck(0);
	m_rad_pcaprojected.SetCheck(1);

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

PointCloud<PointXYZ>::Ptr CMFCForTyre2Dlg::GetCloudPtr(CLOUDTYPE out_type)
{
	switch (out_type)
	{
	case ORIGIN:
		return m_cloud;
	case PROJECTED:
		return m_prjcld;
	case TRANSFORMED:
		return m_transcld;
	default:
		PointCloud<PointXYZ>::Ptr tmp(::new PointCloud<PointXYZ>);
		return tmp;
	}
}

PointCloud<Normal>::Ptr CMFCForTyre2Dlg::GetNormalPtr()
{
	return m_normal;
}

void CMFCForTyre2Dlg::SetCloudPtr(PointCloud<PointXYZ>::Ptr in_cloud,CLOUDTYPE in_type)
{
	double curdist = 0.0;
	Vector3d v3row, v3col;	
	switch (in_type)
	{
	case ORIGIN:
		m_cloud = in_cloud;
		//Compute the minmum distance between points in cloud.
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
		break;
	case PROJECTED:
		m_prjcld = in_cloud;
		break;
	case TRANSFORMED:
		m_transcld = in_cloud;
		break;
	}

}

void CMFCForTyre2Dlg::SetNormalPtr(PointCloud<Normal>::Ptr in_cloud)
{
	m_normal = in_cloud;
}

float CMFCForTyre2Dlg::GetCloudMinDist()
{
	return m_mindist;
}

BOOL CMFCForTyre2Dlg::EnableWindows(BOOL bEnable)
{
	m_btn_normalest.EnableWindow(bEnable);
	m_btn_openfile.EnableWindow(bEnable);
	m_btn_saveneresult.EnableWindow(bEnable);
	m_btn_projecttoplane.EnableWindow(bEnable);
	m_btn_runpca.EnableWindow(bEnable);
	m_rad_pcaorigin.EnableWindow(bEnable);
	m_rad_pcaprojected.EnableWindow(bEnable);
	m_btn_convertimg.EnableWindow(bEnable);
	m_stc_convertimg.EnableWindow(bEnable);
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
		m_stc_loaddata.SetWindowTextA(cs_info+"\r\n"+"Computing minmum distance, please wait...");
		QueryPerformanceCounter(&nst);
		SetCloudPtr(cloud,CLOUDTYPE::ORIGIN);
		QueryPerformanceCounter(&nend);
		cs_info = cs_info +"\r\n"+ GetTimeSpreadCString("Compute minmum distance successfully", nfreq, nst, nend, spread);
		cs_info = cs_info + "\r\n" + "Minmum distance in cloud is " + to_string(GetCloudMinDist()).c_str()+".";
		m_stc_loaddata.SetWindowTextA(cs_info);

		/*
		Show original and projected cloud points.
		boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("MyPointCloud"));
		viewer->setBackgroundColor(0, 0, 0);
		viewer->addPointCloud(cloud, "Original one");
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "Original one");
		viewer->addCoordinateSystem(1.0);
		viewer->initCameraParameters();
		
		viewer->setBackgroundColor(150, 150, 150);
		viewer->addPointCloud(prjcld, "Project one");
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
		viewer->addCoordinateSystem(1.0);
		viewer->initCameraParameters();
		


		while (!viewer->wasStopped())
		{
			viewer->spinOnce(100);
			boost::this_thread::sleep(boost::posix_time::microseconds(100000));
		}*/
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
	PointCloud<PointXYZ>::Ptr cloud = this->GetCloudPtr(CLOUDTYPE::ORIGIN);

	//Estimating normal by multiple threads
	double thdnum = GetValueFromCString(&m_edt_ne_threadnum);
	ne.setNumberOfThreads(floor(thdnum));
	ne.setInputCloud(cloud);

	//Transfer kdtree object to normal estimation object.
	tree->setInputCloud(cloud);
	ne.setSearchMethod(tree);

	// Set searching neighbor radius or k-neighbors.
	double radius = GetValueFromCString(&m_edt_ne_radius);
	//ne.setRadiusSearch(radius);
	double indfolder = GetValueFromCString(&m_edt_ne_indexfolder);
	ne.setKSearch(int(floor(indfolder)));

	//Set searching indices of cloud points
	
	vector<int> indices(cloud->points.size());
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
	SetNormalPtr(cloud_normals);

	//Compute principal curvatures.
	
	pcl::PrincipalCurvaturesEstimation<pcl::PointXYZ, pcl::Normal, pcl::PrincipalCurvatures> prncrv;
	PointCloud<PrincipalCurvatures>::Ptr cloud_curvatures(::new PointCloud<PrincipalCurvatures>);
	prncrv.setInputCloud(cloud);
	prncrv.setInputNormals(cloud_normals);
	prncrv.setSearchMethod(tree);
	//prncrv.setRadiusSearch(radius);
	prncrv.setKSearch(int(floor(indfolder)));
	prncrv.compute(*cloud_curvatures);
	

	//Find main normal for the next preojecting process.
	Vector3d curNormal, cur_mainNorm;
	vector<Vector3d> cand_normals;
	vector<int> cand_normal_len;
	bool newNorm = TRUE;
	double angle = 0.0, angle1 = 0.0;
	double min_curv = 0.0, max_curv = 0.0, tmp_curv = 0.0;
	size_t cand_len;
	QueryPerformanceCounter(&nst);
	for (size_t ii = 0; ii < cloud_normals->points.size(); ++ii)
	{
		cand_len = cand_normals.size();
		newNorm = TRUE;
		curNormal = Vector3d(cloud_normals->points[ii].normal_x, cloud_normals->points[ii].normal_y, cloud_normals->points[ii].normal_z);
		tmp_curv = cloud_normals->points[ii].curvature;
		if (tmp_curv > max_curv)
		{
			max_curv = tmp_curv;
		}

		if (tmp_curv < min_curv)
		{
			min_curv = tmp_curv;
		}

		tmp_curv = cloud_curvatures->points[ii].pc1;
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
		cs_info = cs_info + "\r\n" + "Max curvature: " + to_string(max_curv).c_str();
		cs_info = cs_info + "\r\n" + "Min curvature: " + to_string(min_curv).c_str();
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

NormalEstObj::NormalEstObj(NormalEstStruct & nes)
{
	neObj.push_back(nes);
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

BOOL NormalEstObj::GetProjectNormal(Vector3d** normVec)
{
	*normVec = &neObj.back().ProjectNormal;
	if (NULL !=normVec)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
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


void CMFCForTyre2Dlg::OnBnClickedProjecttoplane()
{
	/*
	Projection Algrithm:
		The normal of project plane is N(nx,ny,nz);
		The origin point on the plane is O(x0,y0,z0);
		The point of cloud is P(curx,cury,curz);
		Our goal is to compute the projection point Q of P along the normal N onto the plane.
	*/
	Vector3d* prjNormal=::new Vector3d(0.0,0.0,0.0);
	if (m_neObjList.GetProjectNormal(&prjNormal))
	{
		//Windows control
		EnableWindows(FALSE);
		LARGE_INTEGER nfreq, nst, nend;//Timer parameters.
		QueryPerformanceFrequency(&nfreq);
		m_stc_projecttoplane.SetWindowTextA("Projection calculating, please wait...");


		//Computing data preparation
		Vector3d pt_O(0.0,0.0,0.0);//Point on plane.
		Vector3d pt_cur(0.0, 0.0, 0.0);
		double t = 0.0;
		double norm2 = prjNormal->norm();
		PointCloud<PointXYZ>::Ptr cloud = this->GetCloudPtr(CLOUDTYPE::ORIGIN);
		PointCloud<PointXYZ>::Ptr prjcld(::new PointCloud<PointXYZ>);
		PointXYZ tmpPT(0.0,0.0,0.0);
		QueryPerformanceCounter(&nst);
		for (size_t ii = 0; ii < cloud->points.size(); ++ii)
		{
			//The point in the cloud.
			pt_cur = Vector3d(cloud->points[ii].x, cloud->points[ii].y, cloud->points[ii].z);

			//Temporary parameter of t.
			t = (prjNormal->dot(pt_O) - prjNormal->dot(pt_cur)) / norm2;

			//The projection points on the plane.
			tmpPT.x = pt_cur(0) + (*prjNormal)(0)*t;
			tmpPT.y = pt_cur(1) + (*prjNormal)(1)*t;
			tmpPT.z = pt_cur(2) + (*prjNormal)(2)*t;
			prjcld->points.push_back(tmpPT);
		}
		QueryPerformanceCounter(&nend);
		CString cs_info;
		double prjspread;
		cs_info = GetTimeSpreadCString("Projection successfully", nfreq, nst, nend, prjspread);
		m_stc_projecttoplane.SetWindowTextA(cs_info);

		CString cs_file;
		m_stc_openfile.GetWindowTextA(cs_file);
		SetCloudPtr(prjcld, PROJECTED);
		if (-1 == SaveCloudInPLY(cs_file, PROJECTED))
		{
			cs_info = cs_info + "\r\n" + "Save point cloud file failed. Please Check!";
			m_stc_projecttoplane.SetWindowTextA(cs_info);
		}
		EnableWindows(TRUE);
		/*Show original and projected cloud points.
		boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("MyPointCloud"));
		viewer->setBackgroundColor(0, 0, 0);
		viewer->addPointCloud(cloud, "Original one");
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "Original one");
		viewer->addCoordinateSystem(1.0);
		viewer->initCameraParameters();
		
		viewer->setBackgroundColor(0, 0, 0);
		viewer->addPointCloud(prjcld, "Project one");
		viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "Project one");
		viewer->addCoordinateSystem(1.0);
		viewer->initCameraParameters();
		

		
		while (!viewer->wasStopped())
		{
			viewer->spinOnce(100);
			boost::this_thread::sleep(boost::posix_time::microseconds(1000));
		}*/

	}
	else
	{
		m_stc_projecttoplane.SetWindowTextA("Failed to get the project normal!");
	}

}


void CMFCForTyre2Dlg::OnBnClickedRunpca()
{
	LARGE_INTEGER nfreq, nst, nend;//Timer parameters.
	CString cs_info;
	QueryPerformanceFrequency(&nfreq);
	PointCloud<PointXYZ>::Ptr cloud;
	EnableWindows(FALSE);
	CLOUDTYPE cdtype;
	if (1 == m_rad_pcaorigin.GetCheck())
	{
		cloud = this->GetCloudPtr(CLOUDTYPE::ORIGIN);
		cdtype = ORIGIN;
	}
	else if (1 == m_rad_pcaprojected.GetCheck())
	{
		cloud = this->GetCloudPtr(CLOUDTYPE::PROJECTED);
		cdtype = PROJECTED;
	}

	//Calculate the eigen vectors by PCA.
	QueryPerformanceCounter(&nst);
	Vector4f pcaCentroid;
	compute3DCentroid(*cloud, pcaCentroid);
	Matrix3f covariance;
	computeCovarianceMatrixNormalized(*cloud, pcaCentroid, covariance);

	SelfAdjointEigenSolver<Matrix3f> eigen_solver(covariance, ComputeEigenvectors);
	Matrix3f eigenVecotorsPCA = eigen_solver.eigenvectors();
	Vector3f eigenValuesPCA = eigen_solver.eigenvalues();

	Matrix4f transform(Eigen::Matrix4f::Identity());
	transform.block<3, 3>(0, 0) = eigenVecotorsPCA.transpose();
	transform.block<3,1>(0,3)= -1.0f * (transform.block<3, 3>(0, 0)) * (pcaCentroid.head<3>());
	PointCloud<PointXYZ>::Ptr transformedCloud (::new PointCloud<PointXYZ>);
	transformPointCloud(*cloud, *transformedCloud, transform);
	QueryPerformanceCounter(&nend);

	//Save transformed point cloud in file.
	CString cs_file;
	m_stc_openfile.GetWindowTextA(cs_file);
	SetCloudPtr(transformedCloud, TRANSFORMED);
	double prjspread;
	cs_info = GetTimeSpreadCString("Transformated successfully", nfreq, nst, nend, prjspread);
	m_stc_runpca.SetWindowTextA(cs_info);
	if (-1 == SaveCloudInPLY(cs_file, TRANSFORMED, cdtype))
	{
		cs_info = cs_info + "\r\n" + "Save into .ply file failed, please check!";
		m_stc_runpca.SetWindowTextA(cs_info);
	}
	else
	{
		cs_info = cs_info + "\r\n" + "Save transformed point cloud file successfully.";
		CString vectorStr, tmpstr;
		for (Eigen::Index ii = 0; ii < eigenVecotorsPCA.size(); ++ii)
		{
			if (ii % 3 == 2)
			{
				tmpstr.Format("%lf", eigenVecotorsPCA(ii));
				vectorStr = vectorStr + tmpstr + "\r\n";
			}
			else
			{
				tmpstr.Format("%lf, ", eigenVecotorsPCA(ii));
				vectorStr += tmpstr;
			}
		}
		cs_info = cs_info + "\r\n" + "Eigen Vectors: " + "\r\n" + vectorStr;

		vectorStr = "";
		tmpstr = "";
		for (Eigen::Index ii = 0; ii < eigenValuesPCA.size(); ++ii)
		{
			tmpstr.Format("%lf, ", eigenValuesPCA(ii));
			vectorStr += tmpstr;
		}
		cs_info = cs_info + "\r\n" + "Eigen Values: " + "\r\n" + vectorStr;
		m_stc_runpca.SetWindowTextA(cs_info);
	}
	EnableWindows(TRUE);
}

int CMFCForTyre2Dlg::SaveCloudInPLY(CString in_path, CLOUDTYPE in_type)
{
	return SaveCloudInPLY(in_path, in_type, ORIGIN);
}

int CMFCForTyre2Dlg::SaveCloudInPLY(CString in_path, CLOUDTYPE in_type, CLOUDTYPE ori_type)
{
	string path, fullname, fname, ftype, savepath;
	size_t pathid = 0, ftypeid = 0;

	path = in_path.GetBuffer();
	pathid = path.find_last_of("\\");
	fullname = path.substr(pathid + 1);
	ftypeid = fullname.find_last_of(".");
	fname = fullname.substr(0, ftypeid);
	ftype = fullname.substr(ftypeid + 1);
	savepath = path.substr(0, pathid + 1) + fname;// +"_prj." + ftype;

	int fe;
	switch (in_type)
	{
	case ORIGIN:
		fe = pcl::io::savePLYFile(savepath + "_org." + ftype, *m_cloud);
		break;
	case PROJECTED:
		fe = pcl::io::savePLYFile(savepath + "_prj." + ftype, *m_prjcld);
		break;
	case TRANSFORMED:
		switch (ori_type)
		{
		case ORIGIN:
			fe = pcl::io::savePLYFile(savepath + "_o_tra." + ftype, *m_transcld);
			break;
		case PROJECTED:
			fe = pcl::io::savePLYFile(savepath + "_p_tra." + ftype, *m_transcld);
			break;
		}
	}
	return 0;
}


void CMFCForTyre2Dlg::OnBnClickedConvertimg()
{
	//Convert transformed cloud to gray image.
	/*
	There are two parts for convertation.
	First:
	For each pixle in gray image, it just counts the number of points in the square which
	is defined by four corners: (pixle.x-delta/2,pixle.y+delta/2),(pixle.x+delta/2,pixle.y+delta/2)
	(pixle.x-delta/2,pixle.y-delta/2),(pixle.x+delta/2,pixle.y-delta/2).
	Those points are defined by transformedCloud.(x,y);

	Second:
	Converting the deepth of points, which is defined by transformedCloud.z, along the normal
	vector into gray scale.

	Combining these two parts of gray scale will be set as the value in pixels of (x,y), which are
	different from the points in the cloud.
	xmin,ymax-------------------------xmax,ymax
	|                                 |
	|                                 |
	|                                 |
	|                                 |
	xmin,ymin-------------------------xmax,ymin
	*/
	//First step:
	//Get Normal index and assign the binormal and tangent vector indices at the same time.
	int normalId = GetValueFromCString(&m_edt_normalindex);
	//int normalId = 0;
	int xId = 0, yId = 1;
	switch (normalId)
	{
	case 0:
		xId = 1;
		yId = 2;
		break;
	case 1:
		xId = 0;
		yId = 2;
		break;
	case 2:
		xId = 0;
		yId = 1;
		break;
	}

	double xmin = 0, xmax = 0, ymin = 0, ymax = 0;
	PointXYZ tmppt(0.0, 0.0, 0.0);
	PointCloud<PointXYZ>::Ptr transformedCloud;
	transformedCloud = GetCloudPtr(TRANSFORMED);
	for (size_t ii = 0; ii < transformedCloud->points.size(); ++ii)
	{
		tmppt = transformedCloud->points[ii];
		if (tmppt.data[xId] < xmin)
		{
			xmin = tmppt.data[xId];
		}

		if (tmppt.data[xId] > xmax)
		{
			xmax = tmppt.data[xId];
		}

		if (tmppt.data[yId] < ymin)
		{
			ymin = tmppt.data[yId];
		}

		if (tmppt.data[yId] > ymax)
		{
			ymax = tmppt.data[yId];
		}
	}

	double delta = GetValueFromCString(&m_edt_ne_radius);
	short rows = short(ceil((xmax - xmin) / delta)), cols = short(ceil((ymax - ymin) / delta));//Rows and columns of gray scale image.
	Eigen::MatrixXi img_mat = MatrixXi::Zero(rows, cols);
	size_t rowi = 0, coli = 0;
	int maxV = 0;
	for (size_t ii = 0; ii < transformedCloud->points.size(); ++ii)
	{
		tmppt = transformedCloud->points[ii];
		rowi = size_t(floor((tmppt.data[xId] - xmin) / delta));
		coli = size_t(floor((tmppt.data[yId] - ymin) / delta));
		if (rowi >= rows)
		{
			rowi = rows;
		}
		if (coli >= cols)
		{
			coli = cols;
		}
		img_mat(rowi, coli) += 1;
		if (img_mat(rowi, coli) > maxV)
		{
			maxV = img_mat(rowi, coli);
		}
	}
	int curValue = 0;
	Eigen::MatrixXi res_mat = MatrixXi::Zero(rows, cols);
	cv::Mat cvMat(rows, cols, CV_8UC1);	
	uchar* p;
	for (size_t rowi = 0; rowi < rows; ++rowi)
	{
		p = cvMat.ptr<uchar>(rowi);
		for (size_t coli = 0; coli < cols; ++coli)
		{
			curValue = img_mat(rowi, coli);
			res_mat(rowi, coli) = size_t(floor(255 * curValue / maxV));
			p[coli] = res_mat(rowi, coli);
		}
	}
	
	cv::imshow("test", cvMat);

	//Second step
}
