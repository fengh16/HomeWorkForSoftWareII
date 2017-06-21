
// FHCalculateDlg.h : 头文件
//

#pragma once


// CFHCalculateDlg 对话框
class CFHCalculateDlg : public CDialogEx
{
// 构造
public:
	CFHCalculateDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FHCALCULATE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 第一个加数的字符串
	CString Num1_Str;
	// 第二个数字字符串
	CString Num2_Str;
	// 运算字符串
	CString Operater_Str;
	// 结果字符串
	CString Sum_Str;
	// 运算
	int Operate;
	afx_msg void OnEnChangeNum1();
	afx_msg void OnEnChangeNum2();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMulti();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedEqual();
	// 提示语
	CString NOTE;
};
