#include "FH_ChainTest.h"
#include "FH_Auto_Test.h"

int main()
{
	char ch;
	do
	{
		do
		{
			cout << "------------------------------------------------------------" << endl;
			cout << "����  1  �����ֶ����ԣ�����  2  �����Զ����ԣ�" << endl;
			cout << "------------------------------------------------------------" << endl;
			ch = getchar();
			cin.clear();
			cin.ignore(10000, '\n');
		} while (ch != '1' && ch != '2');
		if (ch == '1')
		{
			Man_Test();
		}
		else if (ch == '2')
		{
			Auto_Main();
			system("pause");
		}
	} while (1);
	return 0;
}