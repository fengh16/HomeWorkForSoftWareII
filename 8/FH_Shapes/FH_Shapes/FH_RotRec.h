#pragma once

#include "FH_GenShape.h"

class FH_RotRec : FH_Shape
{
public:
	FH_RotRec(const double CenterX = 20, const double CenterY = 20, const double NewWide = 10, const double NewHeight = 10, const double NewRotAngle = 0, const COLORREF LineColor = 0, const COLORREF FillColor = 0, const int LineWide = 1, const int DrawFlag = 0, const int AreaFlag = 0);
	~FH_RotRec();
	void Draw(CDC* pDC, COLORREF MyFill, COLORREF MyLine, int MyDrawFlag = 0);
	void Draw(CDC* pDC, int MyDrawFlag);
	void Draw(CDC* pDC);
	double Area();

private:
	// 旋转的角度，如果为正是逆时针，单位：角度
	double RotAngle;
	// 重心（中心）坐标
	FH_Pos CenterPos;
	// 宽度和高度，这里不是一半的距离！
	double Wide, Height;
	POINT RecPoints[5];
	void CalculatePoints();
};
