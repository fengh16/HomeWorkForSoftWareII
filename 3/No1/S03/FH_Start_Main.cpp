#include <iostream>
using namespace std;
#include "FH_Start_Test.h"
#include "FH_Auto_Test.h"

int main()
{
	cout << "����1�����ֶ����ԣ�����2�����Զ����ԣ�" << endl;
	char ch = getchar();
	if (ch == '1')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		do
		{
			outStartTest();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����Y���س�������һ���ֶ����ԣ����������ַ����س��˳���" << endl;
		} while (getchar() == 'Y');
	}
	else if (ch == '2')
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		AutoTest();
		system("pause");
	}
	return 0;
}