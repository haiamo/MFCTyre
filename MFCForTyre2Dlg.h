
// MFCForTyre2Dlg.h : 头文件
//

#pragma once

#undef min
#undef max 

#define PI 3.1415926535
#define ACCURACY 10e-3

#include <string.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/features/integral_image_normal.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/normal_3d_omp.h>
#include <sstream>
#include <fstream>


using namespace pcl;
using namespace std;
using namespace Eigen;

struct NormalEstStruct
{
	double Radius;
	size_t Threads;
	size_t Folder;
	double EstTime;
	size_t NormalIndices;
	double SearchTime;
	Vector3d ProjectNormal;
};

class NormalEstObj
{
private:
	vector<NormalEstStruct> neObj;

public:
	//Constructors and destructors;
	NormalEstObj();
	NormalEstObj(double r, size_t thds, size_t fld);
	~NormalEstObj();

	//Set values and output into files
	void AddNEObject(double r, size_t thds, size_t fld, double et, size_t ni, double st, Vector3d v3);
	void AddNEObject(NormalEstStruct &nes);

	int WriteInFile(string fpath);

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
	CButton m_btn_loaddata;
	CButton m_btn_normalest;
	CButton m_btn_saveneresult;

	//Static
	CStatic m_stc_openfile;
	CStatic m_stc_loaddata;
	CStatic m_stc_ne_radius;
	CStatic m_stc_normalest;
	CStatic m_stc_ne_threadnum;
	CStatic m_stc_ne_indexfolder;

	//Edit
	CEdit m_edt_ne_radius;
	CEdit m_edt_ne_threadnum;
	CEdit m_edt_ne_indexfolder;

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
	PointCloud<PointXYZ>::Ptr m_cloud;
	float m_mindist;

public:
	PointCloud<PointXYZ>::Ptr GetCloudPtr();
	void SetCloudPtr(PointCloud<PointXYZ>::Ptr in_cloud);
	float GetCloudMinDist();
	BOOL EnableWindows(BOOL bEnable=TRUE);
	afx_msg void OnBnClickedOpenfile();
	afx_msg void OnBnClickedLoaddata();
	afx_msg void OnBnClickedNormalest();

	CString GetTimeSpreadCString(string procstr, LARGE_INTEGER nfreq, LARGE_INTEGER nst, LARGE_INTEGER nend,double& tspread);
	double GetValueFromCString(CEdit* inEdit);
//	afx_msg void OnEnChangeNeRadius();
	afx_msg void OnBnClickedSaveneresult();
};

