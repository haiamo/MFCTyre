
// MFCForTyre2Dlg.h : 头文件
//

#pragma once

#undef min
#undef max 

#define PI 3.1415926535
#define ACCURACY 10e-6

//c++
#include <string.h>
#include <sstream>
#include <fstream>

//pcl
#include <pcl\io\io.h>
#include <pcl\io\pcd_io.h>
#include <pcl\io\ply_io.h>
#include <pcl\features\integral_image_normal.h>
#include <pcl\visualization\cloud_viewer.h>
#include <pcl\visualization\pcl_visualizer.h>
#include <pcl\point_types.h>
#include <pcl\features\normal_3d.h>
#include <pcl\features\normal_3d_omp.h>
#include <pcl\features\principal_curvatures.h>
#include <pcl\common\transforms.h>

//opencv 
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv.hpp>


using namespace pcl;
using namespace std;
using namespace Eigen;
using namespace cv;

enum CLOUDTYPE
{
	ORIGIN,
	PROJECTED,
	TRANSFORMED
};

struct NormalEstStruct
{
	double Radius;
	size_t Threads;
	size_t Folder;
	double EstTime;
	size_t NormalIndices;
	double SearchTime;
	Vector3d ProjectNormal;
	double IntSectAngle;//Intersection Angle
};

class NormalEstObj
{
private:
	vector<NormalEstStruct> neObj;

public:
	//Constructors and destructors;
	NormalEstObj();
	NormalEstObj(double r, size_t thds, size_t fld);
	NormalEstObj(NormalEstStruct &nes);
	~NormalEstObj();

	//Set values and output into files
	void AddNEObject(double r, size_t thds, size_t fld, double et, size_t ni, double st, Vector3d v3);
	void AddNEObject(NormalEstStruct &nes);
	int WriteInFile(string fpath);

	void ComputeIntSectAngle();
	BOOL GetProjectNormal(Vector3d** normVec);

};

// CMFCForTyre2Dlg 对话框
class CMFCForTyre2Dlg : public CDialogEx
{
// 构造
public:
	CMFCForTyre2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCFORTYRE2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	//Normal Estimation Struct
	NormalEstObj m_neObjList;

	// members for DDX_control
	//Button
	CButton m_btn_openfile;
	CButton m_btn_normalest;
	CButton m_btn_saveneresult;
	CButton m_btn_projecttoplane;
	CButton m_btn_runpca;
	CButton m_rad_pcaorigin;
	CButton m_rad_pcaprojected;
	CButton m_btn_convertimg;

	//Static Text
	CStatic m_stc_openfile;
	CStatic m_stc_loaddata;
	CStatic m_stc_ne_radius;
	CStatic m_stc_normalest;
	CStatic m_stc_ne_threadnum;
	CStatic m_stc_ne_indexfolder;
	CStatic m_stc_projecttoplane;
	CStatic m_stc_runpca;
	CStatic m_stc_convertimg;

	//Edit
	CEdit m_edt_ne_radius;
	CEdit m_edt_ne_threadnum;
	CEdit m_edt_ne_indexfolder;
	CEdit m_edt_normalindex;


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

// PCL parameters and methods.
private:
	PointCloud<PointXYZ>::Ptr m_cloud;//Original Point Cloud
	PointCloud<PointXYZ>::Ptr m_prjcld;//Point Cloud which is projected onto a plane.
	PointCloud<PointXYZ>::Ptr m_transcld;//Transformed Point Cloud
	PointCloud<Normal>::Ptr m_normal;//Normal Point Cloud
	float m_mindist;

public:
	PointCloud<PointXYZ>::Ptr GetCloudPtr(CLOUDTYPE out_type);
	PointCloud<Normal>::Ptr GetNormalPtr();
	void SetCloudPtr(PointCloud<PointXYZ>::Ptr in_cloud, CLOUDTYPE in_type);
	void SetNormalPtr(PointCloud<Normal>::Ptr in_cloud);
	float GetCloudMinDist();
	BOOL EnableWindows(BOOL bEnable=TRUE);
	afx_msg void OnBnClickedOpenfile();
	afx_msg void OnBnClickedLoaddata();
	afx_msg void OnBnClickedNormalest();

	CString GetTimeSpreadCString(string procstr, LARGE_INTEGER nfreq, LARGE_INTEGER nst, LARGE_INTEGER nend,double& tspread);
	double GetValueFromCString(CEdit* inEdit);
//	afx_msg void OnEnChangeNeRadius();
	afx_msg void OnBnClickedSaveneresult();
	afx_msg void OnBnClickedProjecttoplane();
	afx_msg void OnBnClickedRunpca();

	int SaveCloudInPLY(CString in_path, CLOUDTYPE in_type);
	int SaveCloudInPLY(CString in_path, CLOUDTYPE in_type, CLOUDTYPE ori_type);
	afx_msg void OnBnClickedConvertimg();
};

