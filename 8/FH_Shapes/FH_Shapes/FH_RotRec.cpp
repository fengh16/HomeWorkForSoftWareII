#include "stdafx.h"
#include "FH_RotRec.h"

FH_RotRec::FH_RotRec(const double CenterX, const double CenterY, const double NewWide, const double NewHeight, const double NewRotAngle, const COLORREF nLineColor, const COLORREF nFillColor, const int nLineWide, const int nDrawFlag, const int nAreaFlag):CenterPos(FH_Pos(CenterX, CenterY)), Wide(NewWide), Height(NewHeight), RotAngle(NewRotAngle)
{
	LineColor = nLineColor;
	FillColor = nFillColor;
	DrawFlag = nDrawFlag;
	AreaFlag = nAreaFlag;
	LineWide = nLineWide;
}

FH_RotRec::~FH_RotRec()
{
}

void FH_RotRec::Draw(CDC* pDC, COLORREF MyFill, COLORREF MyLine, int MyDrawFlag)
{
	FillColor = MyFill;
	LineColor = MyLine;
	DrawFlag = MyDrawFlag;
	Draw(pDC);
}

void FH_RotRec::Draw(CDC* pDC, int MyDrawFlag)
{
	DrawFlag = MyDrawFlag;
	Draw(pDC);
}

void FH_RotRec::Draw(CDC* pDC)
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
	pDC->Polygon(RecPoints, 5);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}

double FH_RotRec::Area()
{
	return Wide * Height;
}

void FH_RotRec::CalculatePoints()
{
	double RecR = sqrt(Wide * Wide + Height * Height) / 2;
	double OriDeg = asin(Height / Wide);
	RecPoints[0].x = RecPoints[4].x = RecR * cos(OriDeg + RotAngle / 180 * Pi) + CenterPos.x;
	RecPoints[0].y = RecPoints[4].y = RecR * sin(OriDeg + RotAngle / 180 * Pi) + CenterPos.y;
	RecPoints[1].x = RecR * cos(-OriDeg + RotAngle / 180 * Pi) + CenterPos.x;
	RecPoints[1].y = RecR * sin(-OriDeg + RotAngle / 180 * Pi) + CenterPos.y;
	RecPoints[2].x = 2 * CenterPos.x - RecPoints[0].x;
	RecPoints[2].y = 2 * CenterPos.y - RecPoints[0].y;
	RecPoints[3].x = 2 * CenterPos.x - RecPoints[1].x;
	RecPoints[3].y = 2 * CenterPos.y - RecPoints[1].y;
}
