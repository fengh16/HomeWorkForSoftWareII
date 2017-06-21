#include "FH_Start.h"
Genetic::Genetic(int a, int b)
{
	x = a;
	y = b;
};

Genetic::~Genetic()
{
};

int Genetic::Calculate()
{
	unsigned int base = 1;
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		switch (i % 5)
		{
		case 0:
			ans += base & (~(x & base));
			break;
		case 1:
			ans += base & (~(y & base));
			break;
		case 2:
			ans += base & (x | y);
			break;
		case 3:
			ans += base & (x & y);
			break;
		case 4:
			ans += base & (x ^ y);
			break;
		default:
			break;
		}
		base *= 2;
	}
	return ans;
};