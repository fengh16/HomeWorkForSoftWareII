#include <iostream>
using namespace std;
#include "FH_Start_Test.h"
#include "FH_Auto_Test.h"

int main()
{
	cout << "输入1进行手动测试，输入2进行自动测试！" << endl;
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
			cout << "输入Y并回车继续下一次手动测试，输入其他字符并回车退出。" << endl;
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