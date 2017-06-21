#include "FH_Start.h"
Prime::Prime(int a, int b)
{
	if (b < a)
	{
		y = a;
		x = b;
	}
	x = a;
	y = b;
	if (x < 2)
		x = 2;
};

Prime::~Prime()
{
};

vector<int> Prime::Calculate()
{
	int k, j, t = 0;
	vector<int> ans;
	for (k = x; k <= y; k++)
	{
		for (j = 2; j < k && k % j; j++);
		if (k == j)
		{
			t++;
			ans.push_back(k);
		}
	}
	return ans;
};

int Prime::getx()
{
	return x;
};
int Prime::gety()
{
	return y;
};
