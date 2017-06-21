
// FH_ShapesView.cpp : CFH_ShapesView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "FH_Shapes.h"
#endif

#include "FH_ShapesDoc.h"
#include "FH_ShapesView.h"
#include "FH_Eclipse.h"
#include "FH_NorRec.h"
#include "FH_RotRec.h"
#include "FH_Triangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFH_ShapesView

IMPLEMENT_DYNCREATE(CFH_ShapesView, CView)

BEGIN_MESSAGE_MAP(CFH_ShapesView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFH_ShapesView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFH_ShapesView 构造/析构

CFH_ShapesView::CFH_ShapesView()
{
	// TODO: 在此处添加构造代码

}

CFH_ShapesView::~CFH_ShapesView()
{
}

BOOL CFH_ShapesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFH_ShapesView 绘制

void CFH_ShapesView::OnDraw(CDC* pDC)
{
	CFH_ShapesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	FH_Triangle Tri1(253, 17, 60, 352, 446, 352, RGB(108, 103, 10), RGB(255, 248, 15), 1, 0), Tri2(253, 30, 71, 346, 435, 346, RGB(0, 0, 0), RGB(246, 5, 0), 1, 1), Tri3(253, 85, 119, 317, 387, 317, RGB(0, 0, 0), RGB(245, 245, 5), 1, 1);
	FH_Eclipse Ecl1(220, 126, 286, 192, RGB(0, 2, 0), RGB(0, 2, 0), 1, 0), Ecl2(220, 246, 286, 312, RGB(0, 2, 0), RGB(0, 2, 0), 1, 0), Ecl3(226, 132, 280, 186, RGB(254, 0, 0), RGB(254, 0, 0), 1, 0), Ecl4(226, 192, 280, 246, RGB(255, 255, 0), RGB(255, 255, 0), 1, 0), Ecl5(226, 252, 280, 306, RGB(0, 128, 1), RGB(0, 128, 1), 1, 0);
	FH_NorRec NorR(220, 159, 286, 279, RGB(0, 2, 0), RGB(0, 2, 0), 1, 0);
	Tri1.Draw(pDC);
	Tri2.Draw(pDC);
	Tri3.Draw(pDC);
	Ecl1.Draw(pDC);
	Ecl2.Draw(pDC);
	NorR.Draw(pDC);
	Ecl3.Draw(pDC);
	Ecl4.Draw(pDC);
	Ecl5.Draw(pDC);
}


// CFH_ShapesView 打印


void CFH_ShapesView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFH_ShapesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFH_ShapesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFH_ShapesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CFH_ShapesView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFH_ShapesView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFH_ShapesView 诊断

#ifdef _DEBUG
void CFH_ShapesView::AssertValid() const
{
	CView::AssertValid();
}

void CFH_ShapesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFH_ShapesDoc* CFH_ShapesView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFH_ShapesDoc)));
	return (CFH_ShapesDoc*)m_pDocument;
}
#endif //_DEBUG


// CFH_ShapesView 消息处理程序
