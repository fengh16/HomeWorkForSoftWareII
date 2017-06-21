
// FHCalculateDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FHCalculate.h"
#include "FHCalculateDlg.h"
#include "afxdialogex.h"
#include "FH_Calculate_Main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFHCalculateDlg 对话框
FH_Cal FHc;


CFHCalculateDlg::CFHCalculateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FHCALCULATE_DIALOG, pParent)
	, Num1_Str(_T(""))
	, Num2_Str(_T(""))
	, Operater_Str(_T(""))
	, Sum_Str(_T(""))
	, Operate(0)
	, NOTE(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFHCalculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM1, Num1_Str);
	DDX_Text(pDX, IDC_NUM2, Num2_Str);
	DDX_Text(pDX, IDC_Option, Operater_Str);
	DDX_Text(pDX, IDC_Sum, Sum_Str);
	DDX_Text(pDX, IDC_NOTE, NOTE);
}

BEGIN_MESSAGE_MAP(CFHCalculateDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_NUM1, &CFHCalculateDlg::OnEnChangeNum1)
	ON_EN_CHANGE(IDC_NUM2, &CFHCalculateDlg::OnEnChangeNum2)
	ON_BN_CLICKED(IDC_Plus, &CFHCalculateDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_Minus, &CFHCalculateDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_Multi, &CFHCalculateDlg::OnBnClickedMulti)
	ON_BN_CLICKED(IDC_Divide, &CFHCalculateDlg::OnBnClickedDivide)
	ON_BN_CLICKED(ID_EQUAL, &CFHCalculateDlg::OnBnClickedEqual)
END_MESSAGE_MAP()


// CFHCalculateDlg 消息处理程序

BOOL CFHCalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	NOTE = _T("    请输入两个有理数，如果不是整数请用分数形式书写，用/隔开分子和分母，负号请写到分数最前面。请勿输入多余的空格等符号！");
	Operater_Str = _T("+");
	Sum_Str = _T("请输入两个有理数！");
	UpdateData(FALSE);
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFHCalculateDlg::OnPaint()
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
HCURSOR CFHCalculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFHCalculateDlg::OnEnChangeNum1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	Sum_Str = FHc.Get_Nums(Num1_Str, Num2_Str);
	UpdateData(FALSE);
	// TODO:  Add your control notification handler code here
}


void CFHCalculateDlg::OnEnChangeNum2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	Sum_Str = FHc.Get_Nums(Num1_Str, Num2_Str);
	UpdateData(FALSE);
	// TODO:  Add your control notification handler code here
}


void CFHCalculateDlg::OnBnClickedPlus()
{
	UpdateData();
	FHc.SetOp(O_plus);
	Operater_Str = _T("+");
	Sum_Str = FHc.Get_Nums(Num1_Str, Num2_Str);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CFHCalculateDlg::OnBnClickedMinus()
{
	UpdateData();
	FHc.SetOp(O_minus);
	Operater_Str = _T("-");
	Sum_Str = FHc.Get_Nums(Num1_Str, Num2_Str);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CFHCalculateDlg::OnBnClickedMulti()
{
	UpdateData();
	FHc.SetOp(O_multi);
	Operater_Str = _T("*");
	Sum_Str = FHc.Get_Nums(Num1_Str, Num2_Str);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CFHCalculateDlg::OnBnClickedDivide()
{
	UpdateData();
	FHc.SetOp(O_divide);
	Operater_Str = _T("/");
	Sum_Str = FHc.Get_Nums(Num1_Str, Num2_Str);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CFHCalculateDlg::OnBnClickedEqual()
{
	UpdateData();
	Sum_Str = FHc.Get_Nums(Num1_Str, Num2_Str);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
