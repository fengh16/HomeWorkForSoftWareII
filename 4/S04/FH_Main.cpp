#include "FH_Auto_Test.h"
#include "FH_Test.h"

int main()
{
	char ch;
	do
	{
		cout << "------------------------------------------------------------" << endl;
		cout << "����  1  �����ֶ����ԣ�����  2  �����Զ����ԣ�" << endl;
		cout << "------------------------------------------------------------" << endl;
		ch = getchar();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (ch != '1' && ch != '2');
	if (ch == '1')
	{
		Human_Test();
	}
	else if (ch == '2')
	{
		Auto_Test();
		system("pause");
	}
	return 0;
}