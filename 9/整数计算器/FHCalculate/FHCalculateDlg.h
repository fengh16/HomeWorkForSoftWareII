
// FHCalculateDlg.h : ͷ�ļ�
//

#pragma once


// CFHCalculateDlg �Ի���
class CFHCalculateDlg : public CDialogEx
{
// ����
public:
	CFHCalculateDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FHCALCULATE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// ��һ���������ַ���
	CString Num1_Str;
	// �ڶ��������ַ���
	CString Num2_Str;
	// �����ַ���
	CString Operater_Str;
	// ����ַ���
	CString Sum_Str;
	// ����
	int Operate;
	afx_msg void OnEnChangeNum1();
	afx_msg void OnEnChangeNum2();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMulti();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedEqual();
	// ��ʾ��
	CString NOTE;
};
