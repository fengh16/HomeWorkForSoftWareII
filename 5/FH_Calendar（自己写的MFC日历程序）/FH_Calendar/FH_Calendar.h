
// FH_Calendar.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFH_CalendarApp:
// See FH_Calendar.cpp for the implementation of this class
//

class CFH_CalendarApp : public CWinApp
{
public:
	CFH_CalendarApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFH_CalendarApp theApp;
