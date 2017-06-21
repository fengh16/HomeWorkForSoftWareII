/**
* FH_Binary.h
*
* ������Binary�����а������� void SetBi(double NewDouble) �� void Print()
*
* ���ļ������������Լ������Ķ���
*
* ���
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
