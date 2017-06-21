#include <iostream>
using namespace std;
#include "FHC_Start.h"

long FHC_Start::outStart(long a, long b)
{
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