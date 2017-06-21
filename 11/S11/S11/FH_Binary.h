/**
* FH_Binary.h
*
* 包含类Binary，其中包含函数 void SetBi(double NewDouble) 和 void Print()
*
* 该文件进行上述类以及函数的定义
*
* 冯昊
*
* V1.0  2017/05/13
*
* CopyRight 2017
*/

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Binary
{
public:
	Binary();
	~Binary();
	void SetBi(double NewDouble);
	void Print();

private:
	union
	{
		double m_double;
		int64_t m_in;
	};
};
