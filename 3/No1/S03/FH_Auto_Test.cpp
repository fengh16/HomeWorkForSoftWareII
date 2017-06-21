#include "FH_Auto_Test.h"
#include <iostream>
using namespace std;
int Test[] = {	351,	68415,	-952,	-486,	0,		68,			564,		68,		15,		94, 6666 };
int Test2[] = { 15,		185,	-69,	15345,	99999,	INT_MAX,	INT_MIN,	25,		35,		68,	99 };
int ans[] = { -969831300, -969830706, 415642361, -1385467741, -969896203, -346368331, 1177652823, -969831305, -969831324, -969831369, -969826783 };
void PrintBit(_int32 i)
{
	int bits[32] = { 0 };
	unsigned int k = 1, m;
	for (int j = 0; j < 32; j++)
	{
		m = k & i;
		bits[31 - j] = (m == 0 ? 0 : 1);
		k *= 2;
	}
	for (int j = 0; j < 32; j++)
		printf("%d", bits[j]);
	cout << endl;
}
void AutoTest()
{
	cout << "测试开始！" << endl << "******************************" << endl;
	int t = 0;
	for (int i = 0; i < sizeof(Test) / sizeof(int); i++)
	{
		Genetic TestUse(Test[i], Test2[i]);
		cout << "现在测试第 " << i + 1 << " 组数据，  " << Test[i] << "  和  " << Test2[i] << "  的结果计算为  " << TestUse.Calculate() << "  ，计算";
		if (TestUse.Calculate() == ans[i])
			cout << "正确！详细结果如下：" << endl;
		else
		{
			cout << "错误！详细结果如下：" << endl;
			t++;
		}
		PrintBit(Test[i]);
		PrintBit(Test2[i]);
		PrintBit(TestUse.Calculate());
	}
	cout << "******************************" << endl;
	cout << "共测试" << sizeof(Test) / sizeof(int) << "组数据，其中" << t << "组错误！" << endl;
};