#pragma once

#include "FH_GenShape.h"

class FH_Eclipse : FH_Shape
{
public:
	FH_Eclipse(const double X1 = 20, const double Y1 = 20, const double X2 = 10, const double Y2 = 10, const COLORREF LineColor = 0, const COLORREF FillColor = 0, const int LineWide = 1, const int DrawFlag = 0, const int AreaFlag = 0);
	~FH_Eclipse();
	void Draw(CDC* pDC, COLORREF MyFill, COLORREF MyLine, int MyDrawFlag = 0);
	void Draw(CDC* pDC, int MyDrawFlag);
	void Draw(CDC* pDC);
	double Area();

private:
	// 左上右下顶点坐标
	FH_Pos PointPos[2];
};
