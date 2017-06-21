#include "stdafx.h"
#include "FH_Calculate_Main.h"

FH_Cal::FH_Cal() : Num1(RationalNum(true, 1, 1)), Num2(RationalNum(true, 1, 1)), Op(O_plus)
{
}

FH_Cal::~FH_Cal()
{
}

CString FH_Cal::Get_Nums(CString CS1, CString CS2)
{
	CString Ans;
	if (Check_Cstrings(CS1) && Check_Cstrings(CS2))
	{
		if (Cstring_To_Nums(CS1, Num1) && Cstring_To_Nums(CS2, Num2))
		{
			if (Calcu() == 0)
				Ans = TempAns;
			else if (Calcu() == 1)
				Ans = _T("计算结果越界！");
			else
				Ans = _T("请勿除以0！");
		}
		else if(Cstring_To_Nums(CS1, Num1))
		{
			Ans = _T("第二个数分母为0或者越界！");
		}
		else if (Cstring_To_Nums(CS2, Num2))
		{
			Ans = _T("第一个数分母为0或者越界！");
		}
		else
		{
			Ans = _T("两个数分母为0或者越界！");
		}
	}
	else if (Check_Cstrings(CS1))
	{
		Ans = _T("第二个数输入错误！");
	}
	else if (Check_Cstrings(CS2))
	{
		Ans = _T("第一个数输入错误！");
	}
	else
	{
		Ans = _T("两个数都输入错误！");
	}
	return Ans;
}

void FH_Cal::SetOp(Operations NewOp)
{
	Op = NewOp;
}

bool FH_Cal::Cstring_To_Nums(CString CS, RationalNum& Num_CS)
{
	Num_CS.denominator = 1;
	Num_CS.numerator = 0;
	Num_CS.Positive = true;
	bool Fra = false;
	for (int i = 0; i < CS.GetLength(); i++)
	{
		if (CS.GetAt(i) == _T('-'))
		{
			if (i == 0)
			{
				Num_CS.Positive = false;
				continue;
			}
			else
				break;
		}
		if (CS.GetAt(i) == _T('/'))
		{
			Fra = true;
			Num_CS.denominator = 0;
			continue;
		}
		if (Fra)
		{
			if (Num_CS.denominator > (unsigned long long)184467440737095516 || (Num_CS.denominator == (unsigned long long)184467440737095516 && CS.GetAt(i) - _T('0') > 1))
				return false;
			Num_CS.denominator = Num_CS.denominator * 10 + (CS.GetAt(i) - _T('0'));
		}
		else
		{
			if (Num_CS.numerator > (unsigned long long)184467440737095516 || (Num_CS.numerator == (unsigned long long)184467440737095516 && CS.GetAt(i) - _T('0') > 1))
				return false;
			Num_CS.numerator = Num_CS.numerator * 10 + (CS.GetAt(i) - _T('0'));
		}
	}
	if (Num_CS.denominator == 0)
		return false;
	if (Num_CS.numerator == 0)
	{
		Num_CS.Positive = true;
		Num_CS.denominator = 1;
	}
	else
	{
		unsigned long long temp = Get_Max_Co(Num_CS.denominator, Num_CS.numerator);
		Num_CS.denominator /= temp;
		Num_CS.numerator /= temp;
	}
		return true;
}

bool FH_Cal::Check_Cstrings(CString CS)
{
	bool HaveFrac = false;
	for (int i = 0; i < CS.GetLength(); i++)
	{
		if (CS.GetAt(i) == _T('-'))
		{
			if (i != 0)
				break;
			if (CS.GetLength() < 2 || CS.GetAt(1) == _T('/'))
				break;
		}
		//else if (CS.GetAt(i) == _T('/'))
		//{
		//	if (HaveFrac)
		//		break;
		//	HaveFrac = true;
		//	if (i == CS.GetLength() - 1)
		//		break;
		//}
		else if (CS.GetAt(i) > _T('9') || CS.GetAt(i) < _T('0'))
			break;
		if (i == CS.GetLength() - 1)
			return true;
	}
	return false;
}

int FH_Cal::Calcu()
{
	unsigned long long temp, temp1, temp2;
	switch (Op)
	{
	case O_multi:
		if (Num1.Positive == Num2.Positive)
			TempAnsNum.Positive = true;
		else
			TempAnsNum.Positive = false;
		if (Num1.numerator == 0 || Num2.numerator == 0)
		{
			TempAnsNum.denominator = 1;
			TempAnsNum.Positive = true;
			TempAnsNum.numerator = 0;
			break;
		}
		temp = Get_Max_Co(Num1.denominator, Num2.numerator);
		Num1.denominator /= temp;
		Num2.numerator /= temp;
		temp = Get_Max_Co(Num2.denominator, Num1.numerator);
		Num2.denominator /= temp;
		Num1.numerator /= temp;
		TempAnsNum.denominator = Num1.denominator * Num2.denominator;
		if (TempAnsNum.denominator / Num1.denominator != Num2.denominator)
			return 1;
		TempAnsNum.numerator = Num1.numerator * Num2.numerator;
		if (TempAnsNum.numerator / Num1.numerator != Num2.numerator)
			return 1;
		break;
	case O_divide:
		if (Num1.Positive == Num2.Positive)
			TempAnsNum.Positive = true;
		else
			TempAnsNum.Positive = false;
		/*if (Num2.numerator == 0)
			return 2;
		if (Num1.numerator == 0)
		{
			TempAnsNum.denominator = 1;
			TempAnsNum.Positive = true;
			TempAnsNum.numerator = 0;
			break;
		}
		temp = Get_Max_Co(Num1.denominator, Num2.denominator);
		Num1.denominator /= temp;
		Num2.denominator /= temp;
		temp = Get_Max_Co(Num2.numerator, Num1.numerator);
		Num2.numerator /= temp;
		Num1.numerator /= temp;
		TempAnsNum.denominator = Num1.denominator * Num2.numerator;
		if (TempAnsNum.denominator / Num1.denominator != Num2.numerator)
			return 1;
		TempAnsNum.numerator = Num1.numerator * Num2.denominator;
		if (TempAnsNum.numerator / Num1.numerator != Num2.denominator)
			return 1;*/
		TempAnsNum.denominator = 1;
		TempAnsNum.numerator = Num1.numerator / Num2.numerator;
		if (TempAnsNum.numerator == 0)
			TempAnsNum.Positive = true;
		break;
	case O_plus:
		temp = Get_Max_Co(Num1.denominator, Num2.denominator);
		temp1 = Num1.numerator;
		Num1.numerator *= Num2.denominator / temp;
		if (Num1.numerator / temp1 != Num2.denominator / temp)
			return 1;
		temp1 = Num2.numerator;
		Num2.numerator *= Num1.denominator / temp;
		if (Num2.numerator / temp1 != Num1.denominator / temp)
			return 1;
		temp1 = Num1.denominator;
		Num1.denominator *= Num2.denominator / temp;
		if (Num1.denominator / temp1 != Num2.denominator / temp)
			return 1;
		Num2.denominator = Num1.denominator;
		TempAnsNum.denominator = Num1.denominator;
		if (Num1.Positive == true && Num2.Positive == true)
		{
			TempAnsNum.Positive = true;
			TempAnsNum.numerator = Num1.numerator + Num2.numerator;
			if (TempAnsNum.numerator < Num1.numerator)
				return 1;
		}
		else if (Num2.Positive == false && Num1.Positive == true)
		{
			if (Num1.numerator >= Num2.numerator)
			{
				TempAnsNum.Positive = true;
				TempAnsNum.numerator = Num1.numerator - Num2.numerator;
			}
			else
			{
				TempAnsNum.Positive = false;
				TempAnsNum.numerator = Num2.numerator - Num1.numerator;
			}
		}
		else if (Num1.Positive == false && Num2.Positive == true)
		{
			if (Num1.numerator <= Num2.numerator)
			{
				TempAnsNum.Positive = true;
				TempAnsNum.numerator = Num2.numerator - Num1.numerator;
			}
			else
			{
				TempAnsNum.Positive = false;
				TempAnsNum.numerator = Num1.numerator - Num2.numerator;
			}
		}
		else
		{
			TempAnsNum.Positive = false;
			TempAnsNum.numerator = Num1.numerator + Num2.numerator;
			if (TempAnsNum.numerator < Num1.numerator)
				return 1;
		}
		if (TempAnsNum.numerator == 0)
		{
			TempAnsNum.denominator = 1;
			TempAnsNum.Positive = true;
			break;
		}
		temp = Get_Max_Co(TempAnsNum.denominator, TempAnsNum.numerator);
		TempAnsNum.denominator /= temp;
		TempAnsNum.numerator /= temp;
		break;
	case O_minus:
		temp = Get_Max_Co(Num1.denominator, Num2.denominator);
		temp1 = Num1.numerator;
		Num1.numerator *= Num2.denominator / temp;
		if (Num1.numerator / temp1 != Num2.denominator / temp)
			return 1;
		temp1 = Num2.numerator;
		Num2.numerator *= Num1.denominator / temp;
		if (Num2.numerator / temp1 != Num1.denominator / temp)
			return 1;
		temp1 = Num1.denominator;
		Num1.denominator *= Num2.denominator / temp;
		if (Num1.denominator / temp1 != Num2.denominator / temp)
			return 1;
		Num2.denominator = Num1.denominator;
		TempAnsNum.denominator = Num1.denominator;
		if (Num1.Positive == true && Num2.Positive == false)
		{
			TempAnsNum.Positive = true;
			TempAnsNum.numerator = Num1.numerator + Num2.numerator;
			if (TempAnsNum.numerator < Num1.numerator)
				return 1;
		}
		else if (Num2.Positive == true && Num1.Positive == true)
		{
			if (Num1.numerator >= Num2.numerator)
			{
				TempAnsNum.Positive = true;
				TempAnsNum.numerator = Num1.numerator - Num2.numerator;
			}
			else
			{
				TempAnsNum.Positive = false;
				TempAnsNum.numerator = Num2.numerator - Num1.numerator;
			}
		}
		else if (Num1.Positive == false && Num2.Positive == false)
		{
			if (Num1.numerator <= Num2.numerator)
			{
				TempAnsNum.Positive = true;
				TempAnsNum.numerator = Num2.numerator - Num1.numerator;
			}
			else
			{
				TempAnsNum.Positive = false;
				TempAnsNum.numerator = Num1.numerator - Num2.numerator;
			}
		}
		else
		{
			TempAnsNum.Positive = false;
			TempAnsNum.numerator = Num1.numerator + Num2.numerator;
			if (TempAnsNum.numerator < Num1.numerator)
				return 1;
		}
		if (TempAnsNum.numerator == 0)
		{
			TempAnsNum.denominator = 1;
			TempAnsNum.Positive = true;
			break;
		}
		temp = Get_Max_Co(TempAnsNum.denominator, TempAnsNum.numerator);
		TempAnsNum.denominator /= temp;
		TempAnsNum.numerator /= temp;
		break;
	default:
		break;
	}
		if (TempAnsNum.Positive == false)
			TempAns = _T("-");
		else
			TempAns = _T("");
		TempAns.Format(_T("%s%llu"), TempAns, TempAnsNum.numerator);
		if (TempAnsNum.denominator != 1)
		{
			TempAns.Format(_T("%s/%llu"), TempAns, TempAnsNum.denominator);
		}
		return 0;//正确
}

unsigned long long FH_Cal::Get_Max_Co(unsigned long long a, unsigned long long b)
{
	unsigned long long n, m, ans;
	if (a <= 0 || b <= 0)
		return 0;
	n = a;
	m = b;
	while (n != 0 && m != 0)
	{
		n %= m;
		if (n == 0)
			break;
		m %= n;
	}
	if (n == 0)
		ans = m;
	else
		ans = n;
	return ans;
}