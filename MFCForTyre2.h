
// MFCForTyre2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCForTyre2App: 
// �йش����ʵ�֣������ MFCForTyre2.cpp
//

class CMFCForTyre2App : public CWinApp
{
public:
	CMFCForTyre2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCForTyre2App theApp;