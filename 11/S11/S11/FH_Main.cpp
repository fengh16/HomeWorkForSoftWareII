/**
* FH_Main.cpp
*
* 包含函数main()
*
* 该文件进行上述函数的具体实现
*
* 冯昊
*
* V1.0  2017/05/13
*
* CopyRight 2017
*/

#include "FH_Binary.h"

/**
* main()函数，需要Binary类
* 无参数，返回值为整数
* 冯昊 2017/05/13
*/
int main()
{
	//变量声明区
	Binary my_bi;
	double A[8] = { 0.0,	1.0,		-1.0,		+0.0,	-0.0,	0.1,	2.3,	-4.5 };
	double B[8] = { 0.0,	0.0,		0.0,		1.0,	1.0,	1.0,	1.0,	1.0 };
	string NumsStr[8] = { "非数",	"正无穷",	"负无穷",	"+0.0",	"-0.0",	"0.1",	"2.3",	"-4.5" };

	double d;
	for (int i = 0; i < 8; i++)
	{
		my_bi.SetBi(A[i] / B[i]);
		cout << NumsStr[i];
		my_bi.Print();
	}
	system("pause");
	cout << "请输入一个实数： \n";
	cin >> d;
	my_bi.SetBi(d);
	cout << d << " ";
	my_bi.Print();
	system("pause");
	return 0;
}