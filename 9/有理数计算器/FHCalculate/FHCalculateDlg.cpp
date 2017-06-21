
// FHCalculateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FHCalculate.h"
#include "FHCalculateDlg.h"
#include "afxdialogex.h"
#include "FH_Calculate_Main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFHCalculateDlg �Ի���
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


// CFHCalculateDlg ��Ϣ�������

BOOL CFHCalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	NOTE = _T("    ��������������������������������÷�����ʽ��д����/�������Ӻͷ�ĸ��������д��������ǰ�档�����������Ŀո�ȷ��ţ�");
	Operater_Str = _T("+");
	Sum_Str = _T("������������������");
	UpdateData(FALSE);
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFHCalculateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
