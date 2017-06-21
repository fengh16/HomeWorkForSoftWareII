#include "FH_Start_Test.h"

void outStartTest()
{
	int m, n;
	do
	{
		m = n = 0;
		cout << "请输入两个整数:" << endl;
		cin >> n >> m;
		if (cin.good() && n > 0 && m > 0)
			break;
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (1);
	Prime app(n, m);
	cout << "计算结果：";
	vector<int>::iterator it;
	vector<int> ans = app.Calculate();
	for (it = ans.begin(); it != ans.end(); it++)
		cout << *it << " ";
	cout << endl;
}