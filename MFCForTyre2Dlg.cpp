
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
	DDX_Control(pDX, BTN_PinsAnalysis, m_btn_segementpinsfilter);

	DDX_Control(pDX, STC_OpenFile, m_stc_openfile);
	DDX_Control(pDX, STC_LoadData, m_stc_loaddata);
	DDX_Control(pDX, STC_NormalEst, m_stc_normalest);
	DDX_Control(pDX, STC_NE_Radius, m_stc_ne_radius);
	DDX_Control(pDX, STC_NE_ThreadNum, m_stc_ne_threadnum);
	DDX_Control(pDX, STC_NE_IndexFolder, m_stc_ne_indexfolder);
	DDX_Control(pDX, STC_NE_KNeighbors, m_stc_ne_kneighbors);
	DDX_Control(pDX, STC_ProjectToPlane, m_stc_projecttoplane);
	DDX_Control(pDX, STC_RunPCA, m_stc_runpca);
	DDX_Control(pDX, STC_ConvertImg, m_stc_convertimg);

	DDX_Control(pDX, EDT_NE_Radius, m_edt_ne_radius);
	DDX_Control(pDX, EDT_NE_ThreadNum, m_edt_ne_threadnum);
	DDX_Control(pDX, EDT_NE_IndexFolder, m_edt_ne_indexfolder);
	DDX_Control(pDX, EDT_NE_KNeighbors, m_edt_ne_kneighbors);
	DDX_Control(pDX, EDT_CI_NormalIndex, m_edt_ci_normalindex);
	DDX_Control(pDX, EDT_SPF_NormalDistanceWeight, m_edt_spf_normal_distance_weight);
	DDX_Control(pDX, EDT_SPF_ResampleRadius, m_edt_spf_resample_radius);
	DDX_Control(pDX, EDT_SPF_ClusterTolerance, m_edt_spf_cluster_tolerance);
	DDX_Control(pDX, EDT_SPF_DistanceThreshold, m_edt_spf_distance_threshold);
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
	ON_BN_CLICKED(BTN_PinsAnalysis, &CMFCForTyre2Dlg::OnBnClickedPinsanalysis)
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
	m_edt_ne_kneighbors.SetWindowTextA("30");
	
	m_edt_ci_normalindex.SetWindowTextA("0");

	m_edt_spf_normal_distance_weight.SetWindowTextA("0.5");
	m_edt_spf_resample_radius.SetWindowTextA("300.0");
	m_edt_spf_cluster_tolerance.SetWindowTextA("200.0");
	m_edt_spf_distance_threshold.SetWindowTextA("300.0");

	m_rad_pcaorigin.SetCheck(1);
	m_rad_pcaprojected.SetCheck(0);

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
	PointXYZ curpoint;
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
		m_cloud_downsample.reset();
		m_cloud_nonzeros.reset();
		m_cloud_segbase.reset();
		m_cloudrgb.reset();
		m_cloudi.reset();
		m_pins.reset();
		m_cloudinorm.reset();
		m_prjcld.reset();
		m_transcld.reset();
		m_normal.reset();
		m_pins_cluster.reset();
		break;
	case ORIGINNONZEROS:
		m_cloud = in_cloud;
		if (!m_cloud_nonzeros)
		{
			m_cloud_nonzeros.reset(::new PointCloud<PointXYZ>);
		}
		for (size_t ii = 0; ii < in_cloud->points.size(); ++ii)
		{
			if (abs(in_cloud->points[ii].x)>ACCURACY  && abs(in_cloud->points[ii].y)>ACCURACY && abs(in_cloud->points[ii].z)>ACCURACY)
			{
				curpoint = in_cloud->points[ii];
				m_cloud_nonzeros->points.push_back(curpoint);
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

void CMFCForTyre2Dlg::SetCloudRGBPtr(PointCloud<PointXYZRGB>::Ptr in_cloud)
{
	m_cloudrgb = in_cloud;
}

void CMFCForTyre2Dlg::SetCloudIPtr(PointCloud<PointXYZI>::Ptr in_cloud)
{
	m_cloudi = in_cloud;
}

void CMFCForTyre2Dlg::SetCloudINormalPtr(PointCloud<PointXYZINormal>::Ptr in_cloud)
{
	m_cloudinorm = in_cloud;
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
	m_btn_segementpinsfilter.EnableWindow(bEnable);

	m_edt_ne_radius.EnableWindow(bEnable);
	m_edt_ne_threadnum.EnableWindow(bEnable);
	m_edt_ne_indexfolder.EnableWindow(bEnable);
	m_edt_ne_kneighbors.EnableWindow(bEnable);
	m_edt_ci_normalindex.EnableWindow(bEnable);
	m_edt_spf_normal_distance_weight.EnableWindow(bEnable);
	m_edt_spf_resample_radius.EnableWindow(bEnable);
	m_edt_spf_cluster_tolerance.EnableWindow(bEnable);
	m_edt_spf_distance_threshold.EnableWindow(bEnable);

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
	else
	{
		m_stc_openfile.SetWindowTextA("");
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
	else
	{
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
			m_stc_loaddata.SetWindowTextA(cs_info + "\r\n" + "Computing minmum distance, please wait...");
			QueryPerformanceCounter(&nst);
			SetCloudPtr(cloud, CLOUDTYPE::ORIGIN);
			QueryPerformanceCounter(&nend);
			cs_info = cs_info + "\r\n" + GetTimeSpreadCString("Compute minmum distance successfully", nfreq, nst, nend, spread);
			cs_info = cs_info + "\r\n" + "Minmum distance in cloud is " + to_string(GetCloudMinDist()).c_str() + ".";
			m_stc_loaddata.SetWindowTextA(cs_info);

			SetCloudPtr(cloud, CLOUDTYPE::ORIGINNONZEROS);
			//SaveCloudInPLY(cs_file, CLOUDTYPE::ORIGINNONZEROS);
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
	//tree->setInputCloud(cloud);
	ne.setSearchMethod(tree);

	// Set searching neighbor radius or k-neighbors.
	double radius = GetValueFromCString(&m_edt_ne_radius);
	double indfolder = GetValueFromCString(&m_edt_ne_indexfolder);
	double knghbors = GetValueFromCString(&m_edt_ne_kneighbors);
	if (radius > 0)
	{
		ne.setRadiusSearch(radius);
		m_edt_ne_kneighbors.EnableWindow(FALSE);
	}
	else if (knghbors > 0)
	{
		m_edt_ne_kneighbors.EnableWindow(TRUE);
		ne.setKSearch(int(floor(knghbors)));
	}
	else
	{
		m_edt_ne_radius.SetWindowTextA("0.1");
		ne.setRadiusSearch(0.1);
		m_edt_ne_kneighbors.EnableWindow(FALSE);
	}
	

	//Set searching indices of cloud points
	if (indfolder > 2.0)
	{
		vector<int> indices(floor(cloud->points.size() / int(indfolder)));
		for (int ii = 0; ii<indices.size(); ++ii)
		{
			indices[ii] = ii * int(indfolder);
		}
		IndicesPtr indicesptr(new vector<int>(indices));
		ne.setIndices(indicesptr);
	}

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
	//cs_info = cs_info + "\r\n" + "With " + to_string(indices.size()).c_str() + " indices.";
	//cs_info = cs_info + "\r\n" + "Searching project normal, please wait...";
	m_stc_normalest.SetWindowTextA(cs_info);// +"\r\n" + "Searching project normal, please wait...");
	SetNormalPtr(cloud_normals);


	//Compute principal curvatures.
	/*
	pcl::PrincipalCurvaturesEstimation<pcl::PointXYZ, pcl::Normal, pcl::PrincipalCurvatures> prncrv;
	PointCloud<PrincipalCurvatures>::Ptr cloud_curvatures(::new PointCloud<PrincipalCurvatures>);
	prncrv.setInputCloud(cloud);
	prncrv.setInputNormals(cloud_normals);
	prncrv.setSearchMethod(tree);
	//prncrv.setRadiusSearch(radius);
	prncrv.setKSearch(int(floor(knghbors)));
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
		// Curvature searching
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
	*/
	EnableWindows(TRUE);
	
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

vector<int> CMFCForTyre2Dlg::GetNeighborsAlongPin(PointXYZ in_pt, pcl::octree::OctreePointCloudSearch<pcl::PointXYZ> octree)
{
	PointCloud<PointXYZ>::Ptr cloud;
	if (1 == m_rad_pcaorigin.GetCheck())
	{
		cloud = this->GetCloudPtr(CLOUDTYPE::ORIGIN);
	}
	else if (1 == m_rad_pcaprojected.GetCheck())
	{
		cloud = this->GetCloudPtr(CLOUDTYPE::PROJECTED);
	}

	//pcl::octree::OctreePointCloudSearch<pcl::PointXYZ> octree(1.0f);
	//octree.setInputCloud(cloud);
	//octree.addPointsFromInputCloud();
	//pt: Point, nbr:neighbors, IRS: Index of Radius Search, IKS: Index of K-neighbors Search, ISM: Index Search Method
	vector<int> ptIRS, ptIKS, ptNbrID, nbrIKS, nbrIRS, nbrISM;
	//RSD: Radius Squared Distance, KSD: K-neighbors Squared Distance.
	vector<float> ptRSD, ptKSD, nbrRSD, nbrKSD;
	
	double radius = GetValueFromCString(&m_edt_ne_radius);
	int kneighbors = int(GetValueFromCString(&m_edt_ne_kneighbors));
	PointXYZ cur_pt = in_pt;

	PointXYZI cur_pt_in;
	vector<int> recusionINT;
	//recusionPtr->points.push_back(in_pt);

	vector<int> tmpPtr;
	int curID;
	double angle;

	int normId = int(GetValueFromCString(&m_edt_ci_normalindex));
	Vector3d curV, mineigenVector(m_eigenVectors(normId, 0), m_eigenVectors(normId, 1), m_eigenVectors(normId, 2));

	//octree.nearestKSearch(cur_pt, kneighbors, ptIKS, ptKSD);
	octree.radiusSearch(in_pt, radius, ptIRS, ptRSD);
	if (ptIRS.size() > 1)
	{
		for (vector<int>::iterator ii = ptIRS.begin(); ii < ptIRS.end(); ++ii)
		{
			curID = *ii;
			cur_pt = m_cloud->points[curID];
			curV = Vector3d(cur_pt.x, cur_pt.y, cur_pt.z) - Vector3d(in_pt.x, in_pt.y, in_pt.z);
			if (curV.norm() < ACCURACY)
			{
				recusionINT.push_back(curID);
				continue;
			}

			angle = acos((curV.dot(mineigenVector)) / (curV.norm()*mineigenVector.norm())) / M_PI * 180;
			if (angle < 90.0) 
			{
				tmpPtr = GetNeighborsAlongPin(cur_pt,octree);
				for (vector<int>::iterator tmpIt=tmpPtr.begin(); tmpIt < tmpPtr.end(); ++tmpIt)
				{
					recusionINT.push_back(*tmpIt);
				}
				//break;
			}
		}
	}

	return recusionINT;
}

void CMFCForTyre2Dlg::ShowCurrentCloud(CLOUDTYPE show_type)
{
	visualization::CloudViewer cld_vw("Current Cloud");
	switch (show_type)
	{
	case ORIGIN:
		cld_vw.showCloud(m_cloud);
		break;
	case PROJECTED:
		cld_vw.showCloud(m_prjcld);
		break;
	case TRANSFORMED:
		cld_vw.showCloud(m_transcld);
		break;
	case NORMALS:
		//cld_vw.showCloud(m_normal);
		break;
	default:
		break;
	}
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
	*normVec = &(neObj.back().ProjectNormal);
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
	m_pcaCentroid = pcaCentroid;
	m_covariance = covariance;

	SelfAdjointEigenSolver<Matrix3f> eigen_solver(covariance, ComputeEigenvectors);
	Matrix3f eigenVecotorsPCA = eigen_solver.eigenvectors();
	Vector3f eigenValuesPCA = eigen_solver.eigenvalues();
	m_eigenValues = eigenValuesPCA;
	m_eigenVectors = eigenVecotorsPCA;

	//Searching pins' positions and length, using XYZI structure.
	PointCloud<Normal>::Ptr cur_normals = GetNormalPtr();
	PointCloud<PointXYZRGB>::Ptr cld_rgb(::new PointCloud<PointXYZRGB>);
	PointCloud<PointXYZI>::Ptr cld_xyzi(::new PointCloud<PointXYZI>);
	PointCloud<PointXYZINormal>::Ptr cld_xyzin(::new PointCloud<PointXYZINormal>);
	PointXYZRGB tmprgb;
	PointXYZI tmpi;
	PointXYZINormal tmpin;
	m_edt_ci_normalindex.SetWindowTextA("0");
	int normId = int(GetValueFromCString(&m_edt_ci_normalindex));
	Vector3d mineigenVector(eigenVecotorsPCA(normId,0), eigenVecotorsPCA(normId, 1), eigenVecotorsPCA(normId, 2));
	Vector3d normalPtr, pcaCent3d(pcaCentroid(0), pcaCentroid(1), pcaCentroid(2)), curpoint, curvector;
	vector<double> angles(cur_normals->points.size());
	vector<size_t> ppoinID;
	double cur_angle = 0.0, cur_len = 0.0;
	int angle_range = 10;
	for (size_t ii = 0; ii < cur_normals->points.size(); ++ii)
	{
		normalPtr = Vector3d(cur_normals->points[ii].normal_x, cur_normals->points[ii].normal_y, cur_normals->points[ii].normal_z);
		curpoint = Vector3d(cloud->points[ii].x, cloud->points[ii].y, cloud->points[ii].z);
		curvector = curpoint - pcaCent3d;
		tmprgb.x = cloud->points[ii].x;
		tmprgb.y = cloud->points[ii].y;
		tmprgb.z = cloud->points[ii].z;

		if (normalPtr.norm() < ACCURACY || _isnan(normalPtr[0]) || _isnan(normalPtr[1]) || _isnan(normalPtr[2]))
		{
			continue;
		}
		cur_angle = acos((normalPtr.dot(mineigenVector)) / (normalPtr.norm()*mineigenVector.norm())) / M_PI * 180;
		angles[ii]=cur_angle;
		cur_len = curvector.dot(mineigenVector);
		tmpi.x = cloud->points[ii].x;
		tmpi.y = cloud->points[ii].y;
		tmpi.z = cloud->points[ii].z;
		tmpi.intensity = cur_len;
		cld_xyzi->push_back(tmpi);
		if (cur_angle > 90.0-angle_range && cur_angle < 90+angle_range)
		{
			ppoinID.push_back(ii);
			tmprgb.r = 255;
			tmprgb.g = 0;
			tmprgb.b = 0;
			if (cur_len > 0)
			{
				tmpin.x = tmpi.x;
				tmpin.y = tmpi.y;
				tmpin.z = tmpi.z;
				tmpin.intensity = tmpi.intensity;
				tmpin.normal_x = cur_normals->points[ii].normal_x;
				tmpin.normal_y = cur_normals->points[ii].normal_y;
				tmpin.normal_z = cur_normals->points[ii].normal_z;
				tmpin.curvature = cur_normals->points[ii].curvature;
				cld_xyzin->push_back(tmpin);
			}
		}
		else
		{
			tmprgb.r = 0;
			tmprgb.g = 0;
			tmprgb.b = 255;
		}
		cld_rgb->points.push_back(tmprgb);
	}
	SetCloudRGBPtr(cld_rgb);
	CString cs_file;
	m_stc_openfile.GetWindowTextA(cs_file);
	SaveCloudInPLY(cs_file, ORIGINRGB);

	SetCloudIPtr(cld_xyzi);
	SaveCloudInPLY(cs_file, ORIGINI);

	//SetCloudINormalPtr(cld_xyzin);
	//SaveCloudInPLY(cs_file, ORIGININORMAL);

	//Re-searching candidate pins' positions and length
	/*
	PointXYZ cur_pt;
	PointXYZI cur_pti;
	PointCloud<PointXYZI>::Ptr mod_xyzi(::new PointCloud<PointXYZI>);
	PointCloud<PointXYZI>::Ptr tmp_xyzi(::new PointCloud<PointXYZI>);
	vector<int> xyziID,tmpID;
	pcl::octree::OctreePointCloudSearch<pcl::PointXYZ> octree(1.0f);
	//m_octree.setResolution(1.0f);
	//m_octree = octree;
	octree.setInputCloud(cloud);
	octree.addPointsFromInputCloud();

	for (size_t ii = 0; ii < cld_xyzi->points.size(); ++ii)
	{
		cur_pt.x = cld_xyzi->points[ii].x;
		cur_pt.y = cld_xyzi->points[ii].y;
		cur_pt.z = cld_xyzi->points[ii].z;
		tmpID = GetNeighborsAlongPin(cur_pt, octree);
		vector<int>::iterator ExitPos;
		for (vector<int>::iterator jj=tmpID.begin(); jj <tmpID.end(); ++jj)
		{
			ExitPos = find(tmpID.begin(), tmpID.end(), *jj);
			if (ExitPos != tmpID.end())
			{
				continue;
			}
			else
			{
				cur_pti.x = cloud->points[*jj].x;
				cur_pti.y = cloud->points[*jj].y;
				cur_pti.z = cloud->points[*jj].z;
				curpoint = Vector3d(cloud->points[*jj].x, cloud->points[*jj].y, cloud->points[*jj].z);
				curvector = curpoint - pcaCent3d;
				cur_pti.intensity = curvector.dot(mineigenVector);
				mod_xyzi->points.push_back(cur_pti);
				xyziID.push_back(*jj);
			}

		}
	}
	SetCloudIPtr(mod_xyzi);
	SaveCloudInPLY(cs_file, ORIGINI);
	*/
	//Filting pins' postions and length.
	vector<PointXYZI> pins;
	PointXYZI tmpPt;
	Vector3d cur_vec, cur_proj, base_vec, base_proj;
	double angle;
	bool is_newVector=false;
	for (size_t ii = 0; ii < cld_xyzi->points.size(); ++ii)
	{
		tmpPt = cld_xyzi->points[ii];
		if (ii == 0)
		{
			pins.push_back(tmpPt);
		}
		else
		{
			cur_vec = Vector3d(tmpPt.x, tmpPt.y, tmpPt.z);
			cur_proj = cur_vec - tmpPt.intensity*mineigenVector;
			is_newVector = true;
			for (vector<PointXYZI>::iterator jj = pins.begin(); jj < pins.end(); ++jj)
			{
				base_vec = Vector3d(jj->x, jj->y, jj->z);
				base_proj = base_vec - jj->intensity*mineigenVector;
				angle = acos((cur_proj.dot(base_proj)) / (cur_proj.norm()*base_proj.norm())) / M_PI * 180;
				if (angle < 1.0)
				{
					if (abs(tmpPt.intensity) > abs(jj->intensity))
					{
						*jj = tmpPt;
					}
					is_newVector = false;
				}
			}

			if (is_newVector)
			{
				pins.push_back(tmpPt);
			}
		}
	}

	for (vector<PointXYZI>::iterator ii = pins.begin(); ii < pins.end(); ++ii)
	{
		if (!m_pins)
		{
			m_pins.reset(::new PointCloud<PointXYZI>);
		}
		m_pins->points.push_back(*ii);
	}
	
	SaveCloudInPLY(cs_file, PINS);
	//Show colored point cloud.
	/*
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(::new pcl::visualization::PCLVisualizer("3D Viewer"));
	viewer->setBackgroundColor(0, 0, 0);
	//pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
	//viewer->addPointCloud<pcl::PointXYZRGB>(cloud, cld_rgb, "sample cloud");
	viewer->addPointCloud(cld_rgb, "sample cloud");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
	//viewer->addCoordinateSystem(1.0);
	viewer->initCameraParameters();

	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}
	*/
	/* Transformation and save file processes.
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
	}
	*/


	//Print eigen values and vectors into static text control.
	CString vectorStr, tmpstr;
	for (Eigen::Index ii = 0; ii < pcaCentroid.size()-1; ++ii)
	{
		if (ii < 2)
		{
			tmpstr.Format("%lf, ", pcaCentroid(ii));
			vectorStr += tmpstr;
		}
		else
		{
			tmpstr.Format("%lf", pcaCentroid(ii));
			vectorStr = vectorStr + tmpstr + "\r\n";
		}
	}
	if (cs_info.IsEmpty())
	{
		cs_info = "PCA Centroid:\r\n" + vectorStr;
	}
	else
	{
		cs_info = cs_info + "\r\n" + "PCA Centroid:\r\n" + vectorStr;
	}
	
	vectorStr = "";
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
	EnableWindows(TRUE);
}

int CMFCForTyre2Dlg::SaveCloudInPLY(CString in_path, CLOUDTYPE in_type)
{
	return SaveCloudInPLY(in_path, in_type, ORIGIN, -1, nullptr);
}

int CMFCForTyre2Dlg::SaveCloudInPLY(CString in_path, CLOUDTYPE in_type, CLOUDTYPE ori_type, int seg_id, PointCloud<PointXYZ>::Ptr seg_pt)
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
	case ORIGINDOWNSAMPLE:
		fe = pcl::io::savePLYFile(savepath + "_ods." + ftype, *m_cloud_downsample);
		break;
	case ORIGINSEGEMENT:
		if (seg_id<0)
		{
			fe = pcl::io::savePLYFile(savepath + "_seg." + ftype, *m_cloud_segbase);
		}
		else
		{
			if (!seg_pt)
			{
				return -1;
			}
			fe = pcl::io::savePLYFile(savepath + "_" + to_string(seg_id) + "_seg." + ftype, *seg_pt);
		}
		break;
	case ORIGINNONZEROS:
		fe = pcl::io::savePLYFile(savepath + "_nonzeros." + ftype, *m_cloud_nonzeros);
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
		break;
	case ORIGINRGB:
		fe = pcl::io::savePLYFile(savepath + "_rgb." + ftype, *m_cloudrgb);
		break;
	case ORIGINI:
		fe = pcl::io::savePLYFile(savepath + "_i." + ftype, *m_cloudi);
		break;
	case ORIGININORMAL:
		fe = pcl::io::savePLYFile(savepath + "_in." + ftype, *m_cloudinorm);
		break;
	case PINS:
		fe = pcl::io::savePLYFile(savepath + "_pins." + ftype, *m_pins);
		break;
	case PINSCLUSTER:
		fe = pcl::io::savePLYFile(savepath + "_pins_cluster." + ftype, *m_pins_cluster);
	}
	return fe;
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
	int normalId = GetValueFromCString(&m_edt_ci_normalindex);
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
			res_mat(rowi, coli) = int(floor(255 * curValue / maxV));
			p[coli] = res_mat(rowi, coli);
		}
	}
	
	cv::imshow("test", cvMat);

	//Second step
}


void CMFCForTyre2Dlg::OnBnClickedPinsanalysis()
{
	/*Pins Analysis has two steps:
	First step: Searching pins positions by using 3d-tree.
	Second step: Analyize the pins' propeties: 
		1)hight from the tyre surface, 
		2)the postion of pins(the position on pins' heads projecting points).
	

	//First step: Getting the range-image from point cloud by PCL.
	PointCloud<PointXYZ>::Ptr cloud = GetCloudPtr(ORIGIN);
	PointCloud<PointXYZ>& point_cloud = *cloud;
	
	float angularResolution = (float)deg2rad(GetValueFromCString(&m_edt_pa_angres));
	float maxAngleWidth = (float)deg2rad(GetValueFromCString(&m_edt_pa_maxangwi));
	float maxAngleHeight = (float)deg2rad(GetValueFromCString(&m_edt_pa_maxanghi));

	Eigen::Affine3f sensorPose = (Eigen::Affine3f)Eigen::Translation3f((float)deg2rad(GetValueFromCString(&m_edt_pa_senpos_x)), (float)deg2rad(GetValueFromCString(&m_edt_pa_senpos_y)), (float)deg2rad(GetValueFromCString(&m_edt_pa_senpos_z)));
	pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;
	float noiseLevel = 0.00;
	float minRange = 0.0f;
	int borderSize = 1;
	boost::shared_ptr<pcl::RangeImage> rangeImagePtr(::new pcl::RangeImage);
	pcl::RangeImage& rangeImage=*rangeImagePtr;
	rangeImage.createFromPointCloud(point_cloud, angularResolution, maxAngleWidth, maxAngleHeight, sensorPose, coordinate_frame, noiseLevel, minRange, borderSize);

	//创建3D视图并且添加点云进行显示
	pcl::visualization::PCLVisualizer viewer("3D Viewer");
	viewer.setBackgroundColor(1, 1, 1);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointWithRange> range_image_color_handler(rangeImagePtr, 0, 0, 0);
	viewer.addPointCloud(rangeImagePtr, range_image_color_handler, "range image");
	viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "range image");
	//viewer.addCoordinateSystem (1.0f);
	//PointCloudColorHandlerCustom<PointType> point_cloud_color_handler (point_cloud_ptr, 150, 150, 150);
	//viewer.addPointCloud (point_cloud_ptr, point_cloud_color_handler, "original point cloud");
	viewer.initCameraParameters();
	//setViewerPose(viewer, rangeImage.getTransformationToWorldSystem());

	pcl::visualization::RangeImageVisualizer range_image_widget("Range image");
	range_image_widget.showRangeImage(rangeImage);

	while (!range_image_widget.wasStopped())
	{
		range_image_widget.spinOnce();
	}

	while (!viewer.wasStopped())
	{
		range_image_widget.spinOnce();
		viewer.spinOnce();
		pcl_sleep(0.01);
	}*/
	m_cloud_segbase.reset(::new PointCloud<PointXYZ>);
	m_pins_cluster.reset(::new PointCloud<PointXYZI>);

	EnableWindows(FALSE);

	PointCloud<PointXYZ>::Ptr cloud=m_cloud;
	Vector4f pcaCentroid;
	compute3DCentroid(*cloud, pcaCentroid);
	Matrix3f covariance;
	computeCovarianceMatrixNormalized(*cloud, pcaCentroid, covariance);
	m_pcaCentroid = pcaCentroid;
	m_covariance = covariance;

	SelfAdjointEigenSolver<Matrix3f> eigen_solver(covariance, ComputeEigenvectors);
	Matrix3f eigenVecotorsPCA = eigen_solver.eigenvectors();
	Vector3f eigenValuesPCA = eigen_solver.eigenvalues();
	Vector3d mineigenVector(eigenVecotorsPCA(0, 0), eigenVecotorsPCA(0, 1), eigenVecotorsPCA(0, 2));
	m_eigenValues = eigenValuesPCA;
	m_eigenVectors = eigenVecotorsPCA;
	//Using Euclidean Cluster Extraction
	//m_cloud has been loaded.

	CString cs_file;
	m_stc_openfile.GetWindowTextA(cs_file);

	//Downsample the dataset, Needed?
	float downsample_r = float(GetValueFromCString(&m_edt_spf_resample_radius));
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(::new pcl::PointCloud<pcl::PointXYZ>);
	if (downsample_r > 0)
	{
		pcl::VoxelGrid<pcl::PointXYZ> vg;
		vg.setInputCloud(m_cloud);
		vg.setLeafSize(downsample_r, downsample_r, downsample_r);
		vg.filter(*cloud_filtered);
	}
	else
	{
		cloud_filtered = m_cloud;
	}

	m_cloud_downsample = cloud_filtered;
	SaveCloudInPLY(cs_file, ORIGINDOWNSAMPLE);

	// Estimate point normals
	pcl::NormalEstimationOMP<PointXYZ, pcl::Normal> ne;
	PointCloud<Normal>::Ptr cur_normal(::new PointCloud<Normal>);
	pcl::search::KdTree<PointXYZ>::Ptr tree(::new pcl::search::KdTree<PointXYZ>());
	ne.setNumberOfThreads(2);
	ne.setSearchMethod(tree);
	ne.setInputCloud(cloud_filtered);
	ne.setKSearch(50);
	if (!m_normal)
	{
		m_normal.reset(::new PointCloud<Normal>);
	}
	ne.compute(*cur_normal);
	m_normal = cur_normal;


	// Create the segmentation object for the planar model and set all the parameters
	//pcl::SACSegmentation<pcl::PointXYZ> seg;
	pcl::SACSegmentationFromNormals<PointXYZ, Normal>seg;
	pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
	pcl::IndicesConstPtr outliers;
	pcl::IndicesConstPtr outliers2;
	pcl::ModelCoefficients::Ptr coefficients(::new pcl::ModelCoefficients);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane(::new pcl::PointCloud<pcl::PointXYZ>());
	double distThreshold = GetValueFromCString(&m_edt_spf_distance_threshold);
	double normDistWght = GetValueFromCString(&m_edt_spf_normal_distance_weight);
	seg.setOptimizeCoefficients(true);
	seg.setModelType(pcl::SacModel::SACMODEL_PLANE);
	seg.setMethodType(pcl::SAC_RANSAC);
	seg.setMaxIterations(10000);
	seg.setDistanceThreshold(distThreshold);
	seg.setRadiusLimits(0, 100000);
	seg.setInputNormals(cur_normal);
	seg.setNormalDistanceWeight(normDistWght);
	
	

	PointCloud<PointXYZ>::Ptr cloud_f(::new PointCloud<PointXYZ>);
	int i = 0, nr_points = (int)cloud_filtered->points.size();
	PointXYZ tmpPt;
	if (!m_cloud_segbase)
	{
		m_cloud_segbase.reset(::new PointCloud<PointXYZ>);
	}
	BOOL bNormalRenewed = TRUE;
	int jj = 0;
	do//while (cloud_filtered->points.size() > 0.1 * nr_points && jj<15)
	{
		// Segment the largest planar component from the remaining cloud
		seg.setInputCloud(cloud_filtered);
		if (!bNormalRenewed)
		{
			ne.setSearchMethod(tree);
			ne.setInputCloud(cloud_filtered);
			ne.compute(*cur_normal);
		}
		seg.setInputNormals(cur_normal);
		seg.segment(*inliers, *coefficients);
		if (inliers->indices.size() <0.5*nr_points)
		{
			//MessageBox("Could not estimate a cylinder model for the given dataset.", "Alert");
			//EnableWindows(TRUE);
			if (seg.getModelType() == SACMODEL_PLANE)
			{
				seg.setModelType(SACMODEL_CYLINDER);
				//continue;
			}
			else if (seg.getModelType() == SACMODEL_CYLINDER)
			{
				seg.setModelType(SACMODEL_CYLINDER);
				//continue;
			}
		}

		// Extract the planar inliers from the input cloud
		pcl::ExtractIndices<pcl::PointXYZ> extract;
		extract.setInputCloud(cloud_filtered);
		extract.setIndices(inliers);
		extract.setNegative(false);
		outliers = extract.getIndices();
		outliers2 = extract.getRemovedIndices();

		// Write the planar inliers to disk
		extract.filter(*cloud_plane);
		for (size_t ii = 0; ii < cloud_plane->points.size(); ++ii)
		{
			tmpPt = cloud_plane->points[ii];
			m_cloud_segbase->points.push_back(tmpPt);
		}
		SaveCloudInPLY(cs_file, ORIGINSEGEMENT, ORIGIN, jj, cloud_plane);
		jj++;
		

		// Remove the planar inliers, extract the rest
		extract.setNegative(true);
		extract.filter(*cloud_f);
		cloud_filtered = cloud_f;
		outliers = extract.getIndices();
		outliers2 = extract.getRemovedIndices();
		bNormalRenewed = FALSE;
		cur_normal.reset(::new PointCloud<Normal>);
		tree.reset(::new pcl::search::KdTree<PointXYZ>);
		cloud_plane.reset(::new PointCloud<PointXYZ>);
	} while (cloud_filtered->points.size() > 0.05 * nr_points && cloud_plane->points.size() < 0.1*nr_points&& jj < 15);
	//m_cloud_segbase = cloud_plane;
	SaveCloudInPLY(cs_file, ORIGINSEGEMENT);
	// Creating the KdTree object for the search method of the extraction
	//pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(::new pcl::search::KdTree<pcl::PointXYZ>);
	tree->setInputCloud(cloud_filtered);

	std::vector<pcl::PointIndices> cluster_indices;
	pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
	float clusterTol = float(GetValueFromCString(&m_edt_spf_cluster_tolerance));
	ec.setClusterTolerance(clusterTol); 
	ec.setMinClusterSize(10);
	ec.setMaxClusterSize(25000);
	ec.setSearchMethod(tree);
	ec.setInputCloud(cloud_filtered);
	ec.extract(cluster_indices);

	if (!cluster_indices.empty())
	{
		PointXYZI tmpPti;
		Vector3d curpoint, curvector, pcaCent3d(pcaCentroid(0), pcaCentroid(1), pcaCentroid(2));
		if (!m_pins_cluster)
		{
			m_pins_cluster.reset(::new PointCloud<PointXYZI>);
		}
		for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin(); it != cluster_indices.end(); ++it)
		{
			pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster(::new pcl::PointCloud<pcl::PointXYZ>);
			for (std::vector<int>::const_iterator pit = it->indices.begin(); pit != it->indices.end(); pit++)
			{
				tmpPt = cloud_filtered->points[*pit];
				tmpPti.x = tmpPt.x;
				tmpPti.y = tmpPt.y;
				tmpPti.z = tmpPt.z;
				curpoint = Vector3d(tmpPt.x, tmpPt.y, tmpPt.z);
				curvector = curpoint - pcaCent3d;
				tmpPti.intensity = curvector.dot(mineigenVector);
				m_pins_cluster->points.push_back(tmpPti);
			} 
		}

		//SetCloudPtr(cloud_cluster, PINSCLUSTER);
		SaveCloudInPLY(cs_file, PINSCLUSTER);
	}
	
	EnableWindows(TRUE);
}
