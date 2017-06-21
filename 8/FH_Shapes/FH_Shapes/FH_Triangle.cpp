#include "stdafx.h"
#include "FH_Triangle.h"

FH_Triangle::FH_Triangle(const double X1, const double Y1, const double X2, const double Y2, const double X3, const double Y3, const COLORREF nLineColor, const COLORREF nFillColor, const int nLineWide, const int nDrawFlag, const int nAreaFlag) :PointPos{ (FH_Pos(X1, Y1)), (FH_Pos(X2, Y2)), (FH_Pos(X3, Y3)) }
{
	LineColor = nLineColor;
	FillColor = nFillColor;
	DrawFlag = nDrawFlag;
	AreaFlag = nAreaFlag;
	LineWide = nLineWide;
}

FH_Triangle::~FH_Triangle()
{
}

void FH_Triangle::Draw(CDC* pDC, COLORREF MyFill, COLORREF MyLine, int MyDrawFlag)
{
	FillColor = MyFill;
	LineColor = MyLine;
	DrawFlag = MyDrawFlag;
	Draw(pDC);
}

void FH_Triangle::Draw(CDC* pDC, int MyDrawFlag)
{
	DrawFlag = MyDrawFlag;
	Draw(pDC);
}

void FH_Triangle::Draw(CDC* pDC)
{
	CalculatePoints();
	CBrush* oldBrush;
	CPen* oldPen;
	CBrush NewBrush(FillColor);
	CBrush* MyBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	CPen NewPen(PS_SOLID, LineWide, LineColor);
	CPen* MyPen = (CPen*)pDC->SelectStockObject(NULL_PEN);
	//如果填充内部
	if (!(DrawFlag & (1 << 1)))
	{
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
	pDC->Polygon(RecPoints, 4);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}

double FH_Triangle::Area()
{
	return fabs(PointPos[0].x * PointPos[1].y + PointPos[1].x * PointPos[2].y + PointPos[2].x * PointPos[0].y - PointPos[0].x * PointPos[2].y - PointPos[1].x * PointPos[0].y - PointPos[2].x * PointPos[1].y) / 2;
}

void FH_Triangle::CalculatePoints()
{
	RecPoints[0].x = RecPoints[3].x = PointPos[0].x;
	RecPoints[0].y = RecPoints[3].y = PointPos[0].y;
	RecPoints[1].x = PointPos[1].x;
	RecPoints[1].y = PointPos[1].y;
	RecPoints[2].x = PointPos[2].x;
	RecPoints[2].y = PointPos[2].y;
}
