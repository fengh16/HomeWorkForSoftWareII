#include <iostream>
using namespace std;
#include "FHC_StartTest.h"
#include "windows.h"
void AutoTestByMultiple(long x, long y, int No)
{
	cout << "------------------------------------------------------------" << endl;
	cout << "第" << No << "类测试开始！此测试使用两质数" << x << "和" << y << "的倍数测试！" << endl;
	FHC_Start app;
	long p = 0, ans;
	long a, b;
	for (ans = 1; ans <= 99999999; ans++)
	{
		a = ans * x;
		b = ans * y;
		if (a < 0)
		{
			cout << "此时使用的一个数据为" << ans << "*" << x << "的结果，但计算为" << a << "，已溢出！" << endl;
			break;
		}
		if (b < 0)
		{
			cout << "此时使用的一个数据为" << ans << "*" << y << "的结果，但计算为" << b << "，已溢出！" << endl;
			break;
		}
		if (app.outStart(a, b) != ans)
		{
			cout << "第" << ans << "组数据出错！" << "此处计算" << a << "与" << b << "的最大公约数，应该为" << ans << "但计算为" << app.outStart(a, b) << "！" << endl;
			p++;
		}
	}
	cout << "第" << No << "类测试结束，共测试" << ans - 1 << "组数据。其中" << p << "组数据错误！" << endl;
}
void AutoTest()
{
	DWORD k1 = ::GetTickCount(); //获取毫秒级数目
	FHC_Start app;
	long a, b, ans;
	int p = 0;
	int Test[][2] = { {2, 96}, {3, 9}, {89, 5}, {9560, 5}, {7, 84}, {38, 19} };
	int TestAns[] = { 2, 3, 1, 5, 7, 19 };
	int t = sizeof(TestAns) / sizeof(int);
	cout << "------------------------------------------------------------" << endl;
	cout << "第1类测试开始！此测试使用已知数据测试！" << endl;
	for (int i = 0; i < t; i++)
	{
		if (app.outStart(Test[i][0], Test[i][1]) != TestAns[i])
		{
			cout << "第" << i + 1 << "组数据出错！" << "此处计算" << Test[i][0] << "与" << Test[i][1] << "的最大公约数，应该为" << TestAns[i] << "但计算为" << app.outStart(Test[i][0], Test[i][1]) << "！" << endl;
			p++;
		}
	}
	cout << "第1类测试结束，共测试" << t << "组数据。其中" << p << "组数据错误！" << endl;
	AutoTestByMultiple(293, 97, 2);
	AutoTestByMultiple(29333, 29947, 3);
	AutoTestByMultiple(49993, 49999, 4);
	AutoTestByMultiple(9982499, 9522827, 5);
	cout << "------------------------------------------------------------" << endl;
	cout << "第6类测试开始！此测试使用越界数据测试程序容错性！包括负数和0！此时应当输出0！" << endl;
	p = 0;
	long long LongTest[][2] = { {-1, 8}, {-8, -5}, {LONG_MIN, 9}, {INT_MIN, 85}, {-958965, 25}, {0, 95} };
	for (int i = 0; i < 6; i++)
	{
		if (app.outStart(LongTest[i][0], LongTest[i][1]) != 0)
		{
			cout << "第" << i + 1 << "组数据出错！" << "此处计算" << LongTest[i][0] << "与" << LongTest[i][1] << "的最大公约数，应该为0但计算为" << app.outStart(LongTest[i][0], LongTest[i][1]) << "！" << endl;
			p++;
		}
	}
	cout << "第6类测试结束，共测试6组数据。其中" << p << "组数据错误！" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "第7类测试开始！此测试使用边界数据测试有效数据范围！" << endl;
	unsigned long long LastTest[][2] = { { ((unsigned long long)INT_MAX / 2) * 2, (unsigned long long)INT_MAX / 2 },{ (unsigned long long)INT_MAX, (unsigned long long)INT_MAX * 2 },{ (unsigned long long)(INT_MAX / 2 + 1) * 2, (unsigned long long)INT_MAX / 2 + 1},{(unsigned long long)(INT_MAX), 1 },{ (unsigned long long)(INT_MAX), (unsigned long long)(INT_MAX) } };
	unsigned long long LastAnses[] = { (unsigned long long)INT_MAX / 2, (unsigned long long)INT_MAX, (unsigned long long)INT_MAX / 2 + 1, 1, (unsigned long long)(INT_MAX) };
	for (int i = 0; i < 5; i++)
	{
		cout << "计算得到" << LastTest[i][0] << "与" << LastTest[i][1] << "的结果为" << app.outStart(LastTest[i][0], LastTest[i][1]) << ",结果应该为" << LastAnses[i] << "，此输出" << ((unsigned long long)app.outStart(LastTest[i][0], LastTest[i][1]) == (unsigned long long)LastAnses[i] ? "正确！" : "错误！") << endl;
	}
	cout << "第7类测试结束，共测试5组数据!" << endl;
	cout << "------------------------------------------------------------" << endl;

	DWORD k2 = ::GetTickCount();
	long long time = k2 - k1;
	cout << "总用时" << time << "ms！";
}