#include <iostream>
using namespace std;
#include "FHC_StartTest.h"

void outStartTest()
{
	FHC_Start app;
	long m, n;
	do
	{
		m = n = 0;
		cout << "����������������:" << endl;
		cin >> n >> m;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (n <= 0 || m <= 0);
	cout << "���Լ����" << app.outStart(n, m) << endl;
}