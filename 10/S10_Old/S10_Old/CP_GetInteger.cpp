#include <iostream>
using namespace std;
#include "CP_GetInteger.h"

int gb_getInteger()
{
	int result = 0;
	do
	{
		cout << "请输入一个整数: " << endl;
		cin >> result;
		if (cin.good())
			break;
		else
		{
			if (cin.eof())
			{
				cout << "输入被终止。输入结束。" << endl;
				break;
			} // if结构结束
			cout << "输入格式有误，请重新输入。";
			cin.clear(); // 来清除错误状态
			cin.sync(); // 清空输入缓冲区
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} // if-else结构结束
	} while (true); // do-while结构结束
	return result;
} // gb_getInteger函数结束