
// GatherBall.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGatherBallApp: 
// �йش����ʵ�֣������ GatherBall.cpp
//

class CGatherBallApp : public CWinApp
{
public:
	CGatherBallApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGatherBallApp theApp;
