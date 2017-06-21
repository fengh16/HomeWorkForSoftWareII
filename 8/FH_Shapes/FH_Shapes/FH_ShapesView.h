
// FH_ShapesView.h : CFH_ShapesView ��Ľӿ�
//

#pragma once


class CFH_ShapesView : public CView
{
protected: // �������л�����
	CFH_ShapesView();
	DECLARE_DYNCREATE(CFH_ShapesView)

// ����
public:
	CFH_ShapesDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFH_ShapesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FH_ShapesView.cpp �еĵ��԰汾
inline CFH_ShapesDoc* CFH_ShapesView::GetDocument() const
   { return reinterpret_cast<CFH_ShapesDoc*>(m_pDocument); }
#endif

