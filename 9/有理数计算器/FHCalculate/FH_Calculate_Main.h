#pragma once
#include "stdafx.h"
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

struct RationalNum
{
	bool Positive;
	unsigned long long int numerator, denominator;

	RationalNum(bool P1, unsigned long long int n1, unsigned long long int n2) : Positive(P1), numerator(n1), denominator(n2)
	{
	};

	RationalNum()
	{};
};

enum Operations { O_plus, O_minus, O_multi, O_divide };

class FH_Cal
{
public:
	FH_Cal();
	~FH_Cal();
	CString Get_Nums(CString CS1, CString CS2);
	void SetOp(Operations);

private:
	RationalNum Num1, Num2, TempAnsNum;
	Operations Op;
	CString TempAns;
	bool Cstring_To_Nums(CString CS, RationalNum& Num_CS);
	bool Check_Cstrings(CString CS);
	int Calcu();
	unsigned long long Get_Max_Co(unsigned long long a, unsigned long long b);
};

