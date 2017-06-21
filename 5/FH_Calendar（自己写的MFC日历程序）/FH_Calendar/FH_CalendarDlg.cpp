
// FH_CalendarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FH_Calendar.h"
#include "FH_CalendarDlg.h"
#include "afxdialogex.h"
#include <string>
#include "FH_Date.h"
#include <cstring>
#include <string>
#include <string.h>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFH_CalendarDlg dialog

void ShowDate();
int year, month;
CFont font;
Calendar ThisCal;
LPCWSTR Nums[32] = { _T(""), _T("1"), _T("2"), _T("3"), _T("4"), _T("5"), _T("6"), _T("7"), _T("8"), _T("9"), _T("10"), _T("11"), _T("12"), _T("13"), _T("14"), _T("15"), _T("16"), _T("17"), _T("18"), _T("19"), _T("20"), _T("21"), _T("22"), _T("23"), _T("24"), _T("25"), _T("26"), _T("27"), _T("28"), _T("29"), _T("30"), _T("31") };
CWnd* Loop;
CWnd* LoopDays[6][7];
CWnd* Note;
CWnd* NowDate;
int WeekIn;
int WeekNum;
int WeekDayUse;
time_t Get_Now_Time;
CWnd* TextViewY;
CWnd* TextViewM;



CFH_CalendarDlg::CFH_CalendarDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FH_CALENDAR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFH_CalendarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFH_CalendarDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(ID_MonthText, &CFH_CalendarDlg::OnEnChangeMonthtext)
	ON_EN_CHANGE(ID_YearText, &CFH_CalendarDlg::OnEnChangeYeartext)
	ON_BN_CLICKED(IDC_BUTTON1, &CFH_CalendarDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CFH_CalendarDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CFH_CalendarDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CFH_CalendarDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CFH_CalendarDlg message handlers

BOOL CFH_CalendarDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	CWnd* TextView1 = GetDlgItem(IDC_STATIC);
	CWnd* TextView2 = GetDlgItem(IDC_STATIC2);

	time(&Get_Now_Time);
	Get_Now_Time += 8 * 3600;
	struct tm *Temp_To_YMD = new struct tm;
	gmtime_s(Temp_To_YMD, &Get_Now_Time);
	year = Temp_To_YMD->tm_year + 1900;
	month = Temp_To_YMD->tm_mon + 1;

	LOGFONT   log;
	GetObject(::GetStockObject(DEFAULT_GUI_FONT), sizeof(log), &log);
	log.lfHeight = 21;     //改 
	log.lfWidth = 10;       //改 
	log.lfCharSet = GB2312_CHARSET;
	lstrcpy(log.lfFaceName, _T("黑体"));
	font.CreateFontIndirect(&log);
	TextView1->SetFont(&font);
	TextView2->SetFont(&font);
	log.lfHeight = 21;     //改 
	log.lfWidth = 10;       //改 
	lstrcpy(log.lfFaceName, _T("黑体"));
	Loop = GetDlgItem(IDC_1);
	Loop->SetFont(&font);
	Loop = GetDlgItem(IDC_2);
	Loop->SetFont(&font);
	Loop = GetDlgItem(IDC_3);
	Loop->SetFont(&font);
	Loop = GetDlgItem(IDC_4);
	Loop->SetFont(&font);
	Loop = GetDlgItem(IDC_5);
	Loop->SetFont(&font);
	Loop = GetDlgItem(IDC_6);
	Loop->SetFont(&font);
	LoopDays[0][0] = GetDlgItem(IDC_00);
	LoopDays[0][0]->SetFont(&font);
	LoopDays[0][1] = GetDlgItem(IDC_01);
	LoopDays[0][1]->SetFont(&font);
	LoopDays[0][2] = GetDlgItem(IDC_02);
	LoopDays[0][2]->SetFont(&font);
	LoopDays[0][3] = GetDlgItem(IDC_03);
	LoopDays[0][3]->SetFont(&font);
	LoopDays[0][4] = GetDlgItem(IDC_04);
	LoopDays[0][4]->SetFont(&font);
	LoopDays[0][5] = GetDlgItem(IDC_05);
	LoopDays[0][5]->SetFont(&font);
	LoopDays[0][6] = GetDlgItem(IDC_06);
	LoopDays[0][6]->SetFont(&font);
	LoopDays[1][0] = GetDlgItem(IDC_10);
	LoopDays[1][0]->SetFont(&font);
	LoopDays[1][1] = GetDlgItem(IDC_11);
	LoopDays[1][1]->SetFont(&font);
	LoopDays[1][2] = GetDlgItem(IDC_12);
	LoopDays[1][2]->SetFont(&font);
	LoopDays[1][3] = GetDlgItem(IDC_13);
	LoopDays[1][3]->SetFont(&font);
	LoopDays[1][4] = GetDlgItem(IDC_14);
	LoopDays[1][4]->SetFont(&font);
	LoopDays[1][5] = GetDlgItem(IDC_15);
	LoopDays[1][5]->SetFont(&font);
	LoopDays[1][6] = GetDlgItem(IDC_16);
	LoopDays[1][6]->SetFont(&font);
	LoopDays[2][0] = GetDlgItem(IDC_20);
	LoopDays[2][0]->SetFont(&font);
	LoopDays[2][1] = GetDlgItem(IDC_21);
	LoopDays[2][1]->SetFont(&font);
	LoopDays[2][2] = GetDlgItem(IDC_22);
	LoopDays[2][2]->SetFont(&font);
	LoopDays[2][3] = GetDlgItem(IDC_23);
	LoopDays[2][3]->SetFont(&font);
	LoopDays[2][4] = GetDlgItem(IDC_24);
	LoopDays[2][4]->SetFont(&font);
	LoopDays[2][5] = GetDlgItem(IDC_25);
	LoopDays[2][5]->SetFont(&font);
	LoopDays[2][6] = GetDlgItem(IDC_26);
	LoopDays[2][6]->SetFont(&font);
	LoopDays[3][0] = GetDlgItem(IDC_30);
	LoopDays[3][0]->SetFont(&font);
	LoopDays[3][1] = GetDlgItem(IDC_31);
	LoopDays[3][1]->SetFont(&font);
	LoopDays[3][2] = GetDlgItem(IDC_32);
	LoopDays[3][2]->SetFont(&font);
	LoopDays[3][3] = GetDlgItem(IDC_33);
	LoopDays[3][3]->SetFont(&font);
	LoopDays[3][4] = GetDlgItem(IDC_34);
	LoopDays[3][4]->SetFont(&font);
	LoopDays[3][5] = GetDlgItem(IDC_35);
	LoopDays[3][5]->SetFont(&font);
	LoopDays[3][6] = GetDlgItem(IDC_36);
	LoopDays[3][6]->SetFont(&font);
	LoopDays[4][0] = GetDlgItem(IDC_40);
	LoopDays[4][0]->SetFont(&font);
	LoopDays[4][1] = GetDlgItem(IDC_41);
	LoopDays[4][1]->SetFont(&font);
	LoopDays[4][2] = GetDlgItem(IDC_42);
	LoopDays[4][2]->SetFont(&font);
	LoopDays[4][3] = GetDlgItem(IDC_43);
	LoopDays[4][3]->SetFont(&font);
	LoopDays[4][4] = GetDlgItem(IDC_44);
	LoopDays[4][4]->SetFont(&font);
	LoopDays[4][5] = GetDlgItem(IDC_45);
	LoopDays[4][5]->SetFont(&font);
	LoopDays[4][6] = GetDlgItem(IDC_46);
	LoopDays[4][6]->SetFont(&font);
	LoopDays[5][0] = GetDlgItem(IDC_50);
	LoopDays[5][0]->SetFont(&font);
	LoopDays[5][1] = GetDlgItem(IDC_51);
	LoopDays[5][1]->SetFont(&font);
	LoopDays[5][2] = GetDlgItem(IDC_52);
	LoopDays[5][2]->SetFont(&font);
	LoopDays[5][3] = GetDlgItem(IDC_53);
	LoopDays[5][3]->SetFont(&font);
	LoopDays[5][4] = GetDlgItem(IDC_54);
	LoopDays[5][4]->SetFont(&font);
	LoopDays[5][5] = GetDlgItem(IDC_55);
	LoopDays[5][5]->SetFont(&font);
	LoopDays[5][6] = GetDlgItem(IDC_56);
	LoopDays[5][6]->SetFont(&font);
	TextViewY = GetDlgItem(ID_YearText);
	Note = GetDlgItem(IDC_note);
	Note->SetFont(&font);
	NowDate = GetDlgItem(IDC_NowDate);
	NowDate->SetFont(&font);
	string yearnumnow = to_string(year);
	CString y;
	y = yearnumnow.c_str();
	TextViewY->SetWindowTextW(y);
	TextViewM = GetDlgItem(ID_MonthText);
	yearnumnow = to_string(month);
	y = yearnumnow.c_str();
	TextViewM->SetWindowTextW(y);
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFH_CalendarDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFH_CalendarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ShowDate()
{
	Note->ShowWindow(true);
	if (year == 0)
		return;
	if (month > 12 || month < 1)
		return;
	Note->ShowWindow(false);
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			LoopDays[j][i]->SetWindowTextW(Nums[0]);
		}
	}
	ThisCal.SetDate(year, month, 1);
	WeekIn = ((ThisCal.GetAllDay() + 1) % 7 + 7) % 7- 1;//1日的星期几（0代表星期天）
	WeekNum = 0;
	for (int day = 1; day <= Calendar::Days_In_The_Month(year, month); day++)
	{
		WeekDayUse = WeekIn + day;
		WeekNum = WeekDayUse / 7;
		WeekDayUse %= 7;
		LoopDays[WeekNum][WeekDayUse]->SetWindowTextW(Nums[day]);
	}
	string DateText;
	string t = "现在显示";
	if (year > 0)
	{
		DateText = t + "公元" + to_string(year) + "年" + to_string(month) + "月";
	}
	else
	{
		DateText = t + "公元前" + to_string(-year) + "年" + to_string(month) + "月";
	}
	CString temp;
	temp = DateText.c_str();
	NowDate->SetWindowTextW(temp);
}

void CFH_CalendarDlg::OnEnChangeMonthtext()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CWnd *pMonth;
	pMonth = GetDlgItem(ID_MonthText);
	CString MonthText;
	pMonth->GetWindowTextW(MonthText);
	month = _tstoi(MonthText);
	ShowDate();
	// TODO:  Add your control notification handler code here
}


void CFH_CalendarDlg::OnEnChangeYeartext()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CWnd *pYear;
	pYear = GetDlgItem(ID_YearText);
	CString YearText;
	pYear->GetWindowTextW(YearText);
	year = _tstoi(YearText);
	ShowDate();
	// TODO:  Add your control notification handler code here
}


void CFH_CalendarDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	year = 0;
	CWnd *pYear;
	pYear = GetDlgItem(ID_YearText);
	CString YearText;
	pYear->GetWindowTextW(YearText);
	year = _tstoi(YearText);
	year++;
	if (year == 0)
		year = 1;
	string yearnumnow = to_string(year);
	CString y;
	y = yearnumnow.c_str();
	TextViewY->SetWindowTextW(y);
}


void CFH_CalendarDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	year = 0;
	CWnd *pYear;
	pYear = GetDlgItem(ID_YearText);
	CString YearText;
	pYear->GetWindowTextW(YearText);
	year = _tstoi(YearText);
	year--;
	if (year == 0)
		year = -1;
	string yearnumnow = to_string(year);
	CString y;
	y = yearnumnow.c_str();
	TextViewY->SetWindowTextW(y);
}


void CFH_CalendarDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	month = 0;
	CWnd *pMonth;
	pMonth = GetDlgItem(ID_MonthText);
	CString MonthText;
	pMonth->GetWindowTextW(MonthText);
	month = _tstoi(MonthText);
	if (month < 1 || month > 12)
		month = 1;
	else
		month++;
	if (month == 13)
	{
		year++;
		if (year == 0)
			year = 1;
		month = 1;
	}
	string yearnumnow = to_string(year);
	CString y;
	y = yearnumnow.c_str();
	TextViewY->SetWindowTextW(y);
	yearnumnow = to_string(month);
	y = yearnumnow.c_str();
	TextViewM->SetWindowTextW(y);
}


void CFH_CalendarDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	month = 0;
	CWnd *pMonth;
	pMonth = GetDlgItem(ID_MonthText);
	CString MonthText;
	pMonth->GetWindowTextW(MonthText);
	month = _tstoi(MonthText);
	if (month < 1 || month > 12)
		month = 12;
	else
		month--;
	if (month == 0)
	{
		year--;
		if (year == 0)
			year = -1;
		month = 12;
	}
	string yearnumnow = to_string(year);
	CString y;
	y = yearnumnow.c_str();
	TextViewY->SetWindowTextW(y);
	yearnumnow = to_string(month);
	y = yearnumnow.c_str();
	TextViewM->SetWindowTextW(y);
}
