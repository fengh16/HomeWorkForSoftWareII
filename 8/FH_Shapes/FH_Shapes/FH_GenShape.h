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
	//画图参数，低一位：不显示边线；低二位：不填充内部
	int DrawFlag;
	int AreaFlag;
	int LineWide;
};
