#include <iostream>
using namespace std;
#include "FHC_Start.h"

void FHC_Start::outStart()
{
	do
	{
		n = 0;
		cout << "请输入正整数n:" << endl;
		cin >> n;
		cout << "输入的n是：" << n << endl;
		//下面清空缓存区
		if (cin.eof() || cin.bad())
		{ // 如果用户输入文件结束标志（或文件已被读完），
		  // 或者发生读写错误，则退出循环

		  // do something
			break;
		}
		// 读到非法字符后，输入流将处于出错状态，
		// 为了继续获取输入，首先要调用 clear 函数
		// 来清除输入流的错误标记，然后才能调用
		// ignore 函数来清除输入流中的数据。
		cin.clear();
		// numeric_limits<streamsize>::max() 返回输入缓冲的大小。
		// ignore 函数在此将把输入流中的数据清空。
		// 这两个函数的具体用法请读者自行查询。
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (n <= 0);
	unsigned long t;
	for (t = 0, ans1 = 0; t <= n; t += 2)
		ans1 += t;
	cout << "第一种方法计算结果：" << ans1 << endl;
	ans2 = (unsigned long long)(n / 2 + 1) * (n / 2);
	//必须先进行强制类型转换
	cout << "第二种方法计算结果：" << ans2 << endl;
}