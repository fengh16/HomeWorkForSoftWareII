#include <iostream>
using namespace std;
#include "FH_Start_Test.h"

void outStartTest()
{
	int m, n;
	do
	{
		m = n = 0;
		cout << "��������������:" << endl;
		cin >> n >> m;
		if (cin.good())
			break;
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (1);
	Genetic app(n, m);
	cout << "�Ŵ������" << app.Calculate() << endl;
}