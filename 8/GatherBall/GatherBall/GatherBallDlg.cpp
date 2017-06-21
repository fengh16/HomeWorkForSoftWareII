
// GatherBallDlg.cpp : 实现文件
//

///FH
///17.4.22

#include "stdafx.h"
#include "GatherBall.h"
#include "GatherBallDlg.h"
#include "afxdialogex.h"
#include <cstring>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

double nx, ny, nz;
int Total = 0;
CString TotalNum;
CString PointsText;
CWnd* TotalView;
CWnd* PointsView;
CWnd* ShowView;
double RSquared;

// CGatherBallDlg 对话框
void Cal();


CGatherBallDlg::CGatherBallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GATHERBALL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGatherBallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGatherBallDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Cal, &CGatherBallDlg::OnBnClickedCal)
END_MESSAGE_MAP()


// CGatherBallDlg 消息处理程序

BOOL CGatherBallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	TotalView = GetDlgItem(ID_Nums_Of_POINTS);
	PointsView = GetDlgItem(ID_POINTS);
	ShowView = GetDlgItem(IDC_SHOW);
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGatherBallDlg::OnPaint()
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
HCURSOR CGatherBallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGatherBallDlg::OnBnClickedCal()
{
	// TODO: Add your control notification handler code here
	Cal();
}

void Cal()
{
	double Temp;
	nx = ny = nz = 0;
	RSquared = 0;
	TotalView->GetWindowTextW(TotalNum);
	Total = _tstoi(TotalNum);
	if (Total <= 0)
	{
		MessageBox(NULL, _T("Total Num Can't Be Smaller Than 1!"), _T("Warnings!"), MB_OK);
		return;
	}
	PointsView->GetWindowTextW(PointsText);
	double* PointsCo = new double[Total * 3];
	int No = 0;
	CString TempString;
	for (int i = 0; i < Total * 3; i++)
	{
		PointsCo[i] = 0;
		TempString = PointsText.Mid(No);
		if (swscanf_s(TempString, _T("%lf"), &PointsCo[i]) != 1)
		{
			MessageBox(NULL, _T("There Is Something Wrong With Points!"), _T("Warnings!"), MB_OK);
			delete PointsCo;
			return;
		}
		//一定要记得用lf！！！！！！！！
		//一定要记得用&！！！！！！！！！
		//感觉swscanf挺好用的
		if (i == Total * 3 - 1)
			break;
		while (No < PointsText.GetLength())
		{
			if (PointsText[No] == _T(' ') || PointsText[No] == _T('\n') || PointsText[No] == _T('\t') || PointsText[No] == _T('\r'))
				break;
			else
				No++;
		}
		while (No < PointsText.GetLength())
		{
			if (PointsText[No] == _T(' ') || PointsText[No] == _T('\n') || PointsText[No] == _T('\t') || PointsText[No] == _T('\r'))
				No++;
			else
				break;
		}
		//没办法连续读取，就写了一个可以分开的
		//前面读取的时候也用到了mid
		if (No == PointsText.GetLength())
		{
			MessageBox(NULL, _T("There Is Something Wrong With Points!"), _T("Warnings!"), MB_OK);
			delete PointsCo;
			return;
		}
	}
	for (int i = 0; i < Total; i++)
	{
		nx += PointsCo[3 * i];
		ny += PointsCo[3 * i + 1];
		nz += PointsCo[3 * i + 2];
	}
	nx /= Total;
	ny /= Total;
	nz /= Total;
	for (int i = 0; i < Total; i++)
	{
		Temp = (nx - PointsCo[3 * i]) * (nx - PointsCo[3 * i]) + (ny - PointsCo[3 * i + 1]) * (ny - PointsCo[3 * i + 1]) + (nz - PointsCo[3 * i + 2]) * (nz - PointsCo[3 * i + 2]);
		if (Temp > RSquared)
			RSquared = Temp;
	}
	CString AnsString;
	AnsString.Format(_T("Ans\n\n  Num_Of_Points:  %d\n\n  Center of ball:  (%.2f ,%.2f ,%.2f)\n\n  R:  %f"), Total, nx, ny, nz, sqrt(RSquared));
	ShowView->SetWindowTextW(AnsString);
	delete PointsCo;

}