#include "stdafx.h"
#include "FH_Eclipse.h"

FH_Eclipse::FH_Eclipse(const double X1, const double Y1, const double X2, const double Y2, const COLORREF nLineColor, const COLORREF nFillColor, const int nLineWide, const int nDrawFlag, const int nAreaFlag) :PointPos{ (FH_Pos(X1, Y1)), (FH_Pos(X2, Y2)) }
{
	LineColor = nLineColor;
	FillColor = nFillColor;
	DrawFlag = nDrawFlag;
	AreaFlag = nAreaFlag;
	LineWide = nLineWide;
}

FH_Eclipse::~FH_Eclipse()
{
}

void FH_Eclipse::Draw(CDC* pDC, COLORREF MyFill, COLORREF MyLine, int MyDrawFlag)
{
	FillColor = MyFill;
	LineColor = MyLine;
	DrawFlag = MyDrawFlag;
	Draw(pDC);
}

void FH_Eclipse::Draw(CDC* pDC, int MyDrawFlag)
{
	DrawFlag = MyDrawFlag;
	Draw(pDC);
}

void FH_Eclipse::Draw(CDC* pDC)
{
	CBrush* oldBrush;
	CPen* oldPen;
	CBrush NewBrush(FillColor);
	CBrush* MyBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	CPen NewPen(PS_SOLID, LineWide, LineColor);
	CPen* MyPen = (CPen*)pDC->SelectStockObject(NULL_PEN);
	//如果填充内部
	if (!(DrawFlag & (1 << 1)))
	{
		//不能在这里定义CBrush！否则作用范围仅限于括号内，出去就没用了！
		oldBrush = pDC->SelectObject(&NewBrush);
	}
	else
	{
		oldBrush = pDC->SelectObject(MyBrush);
	}
	//如果显示边线
	if (!(DrawFlag & 1))
	{
		oldPen = pDC->SelectObject(&NewPen);
	}
	else
	{
		oldPen = pDC->SelectObject(MyPen);
	}
	pDC->Ellipse(PointPos[0].x, PointPos[0].y, PointPos[1].x, PointPos[1].y);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}

double FH_Eclipse::Area()
{
	return fabs(PointPos[0].x - PointPos[1].x) * fabs(PointPos[0].y - PointPos[1].y) / 4 * Pi;
}
