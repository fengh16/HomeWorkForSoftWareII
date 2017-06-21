#include "FH_Human_Test.h"
#include "FH_Auto_Test.h"

int main()
{
	char ch;
	do
	{
		do
		{
			cout << "------------------------------------------------------------" << endl;
			cout << "输入  1  进行手动测试，输入  2  进行自动测试！" << endl;
			cout << "------------------------------------------------------------" << endl;
			ch = getchar();
			cin.clear();
			cin.ignore(10000, '\n');
		} while (ch != '1' && ch != '2');
		if (ch == '1')
		{
			Human_Main();
		}
		else if (ch == '2')
		{
			Auto_Main();
			system("pause");
		}
	} while (1);
	return 0;
}