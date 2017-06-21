#include <iostream>
using namespace std;
#include "FH_Start_Test.h"

void outStartTest()
{
	int m, n;
	do
	{
		m = n = 0;
		cout << "请输入两个整数:" << endl;
		cin >> n >> m;
		if (cin.good())
			break;
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (1);
	Genetic app(n, m);
	cout << "遗传结果：" << app.Calculate() << endl;
}