#pragma once

#include "stdafx.h"
#include <math.h>

#define Pi acos(-1)

struct FH_Pos
{
	double x, y;

	FH_Pos(double nx, double ny) :x(nx), y(ny) {};
};

class FH_Shape
{
public:
	FH_Shape();
	~FH_Shape();
	virtual void Draw(CDC* pDC) = 0;
	virtual double Area() = 0;

protected:
	COLORREF LineColor, FillColor;
	//��ͼ��������һλ������ʾ���ߣ��Ͷ�λ��������ڲ�
	int DrawFlag;
	int AreaFlag;
	int LineWide;
};
