
// RobotValidateMFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRobotValidateMFCApp:
// �йش����ʵ�֣������ RobotValidateMFC.cpp
//

class CRobotValidateMFCApp : public CWinApp
{
public:
	CRobotValidateMFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRobotValidateMFCApp theApp;