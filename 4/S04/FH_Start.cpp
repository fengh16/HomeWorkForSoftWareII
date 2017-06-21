#include "FH_Start.h"
Two_Num::Two_Num(long long m = 0, long long n = 0)
{
	if (m <= 0)
		m = 0;
	if (n <= 0)
		n = 0;
	a = m;
	b = n;
}
Two_Num::~Two_Num() { }
long long Two_Num::GetGreatestCommonFact()
{
	if (a <= 0 || b <= 0)
		return 0;
	long long n = a;
	long long m = b;
	long long ans;
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
long long Two_Num::GetLeastCommonMulti()
{
	if (a <= 0 || b <= 0)
		return 0;
	return a / GetGreatestCommonFact() * b;
}
