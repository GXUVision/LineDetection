
// MFCApplication12-4.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication124App: 
// �йش����ʵ�֣������ MFCApplication12-4.cpp
//

class CMFCApplication124App : public CWinApp
{
public:
	CMFCApplication124App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication124App theApp;