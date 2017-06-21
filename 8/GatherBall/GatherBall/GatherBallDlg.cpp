
// GatherBallDlg.cpp : ʵ���ļ�
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

// CGatherBallDlg �Ի���
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


// CGatherBallDlg ��Ϣ�������

BOOL CGatherBallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	TotalView = GetDlgItem(ID_Nums_Of_POINTS);
	PointsView = GetDlgItem(ID_POINTS);
	ShowView = GetDlgItem(IDC_SHOW);
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGatherBallDlg::OnPaint()
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
		//һ��Ҫ�ǵ���lf����������������
		//һ��Ҫ�ǵ���&������������������
		//�о�swscanfͦ���õ�
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
		//û�취������ȡ����д��һ�����Էֿ���
		//ǰ���ȡ��ʱ��Ҳ�õ���mid
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