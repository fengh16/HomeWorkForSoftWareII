#include <iostream>
using namespace std;
#include "FHC_StartTest.h"

int main()
{
	do
	{
		outStartTest();
		cout << "输入Y并回车继续下一次测试，输入其他字符并回车退出。" << endl;
	} while (getchar() == 'Y');
	
	return 0;
}