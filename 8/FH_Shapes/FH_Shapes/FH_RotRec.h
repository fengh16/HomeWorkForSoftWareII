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
	// ��ת�ĽǶȣ����Ϊ������ʱ�룬��λ���Ƕ�
	double RotAngle;
	// ���ģ����ģ�����
	FH_Pos CenterPos;
	// ��Ⱥ͸߶ȣ����ﲻ��һ��ľ��룡
	double Wide, Height;
	POINT RecPoints[5];
	void CalculatePoints();
};
