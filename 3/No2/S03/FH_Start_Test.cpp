#include "FH_Start_Test.h"

void outStartTest()
{
	int m, n;
	do
	{
		m = n = 0;
		cout << "��������������:" << endl;
		cin >> n >> m;
		if (cin.good() && n > 0 && m > 0)
			break;
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (1);
	Prime app(n, m);
	cout << "��������";
	vector<int>::iterator it;
	vector<int> ans = app.Calculate();
	for (it = ans.begin(); it != ans.end(); it++)
		cout << *it << " ";
	cout << endl;
}