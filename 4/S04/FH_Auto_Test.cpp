#include "FH_Start.h"
#include "FH_Time.h"

void AutoTestByMultiple(long long x, long long y, long long No)
{
	cout << "------------------------------------------------------------" << endl;
	cout << "第" << No << "类测试开始！此测试使用两质数" << x << "和" << y << "的倍数测试！" << endl;
	long long p = 0, ans;
	long long a, b;
	for (ans = 1; ans <= 20000; ans++)
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
		Two_Num app(a, b);
		if (app.GetGreatestCommonFact() != ans)
		{
			cout << "第" << ans << "组数据出错！" << "此处计算" << a << "与" << b << "的最大公约数，应该为" << ans << "但计算为" << app.GetGreatestCommonFact() << "！" << endl;
			p++;
		}
		if (app.GetLeastCommonMulti() / a * ans != b)
		{
			cout << "第" << ans << "组数据出错！" << "此处计算" << a << "与" << b << "的最小公倍数，应该为" << a * b / ans << "但计算为" << app.GetLeastCommonMulti() << "！" << endl;
			p++;
		}
	}
	cout << "第" << No << "类测试结束，共测试" << ans - 1 << "组数据。每组数据计算两个数（最大公约数和最小公倍数），其中" << p << "个测试结果错误！" << endl;
}

void Auto_Test()
{
	Time MyTime;
	MyTime.StartClock();
	long long p = 0;
	long long Test[][2] = { { 2, 96 },{ 3, 9 },{ 89, 5 },{ 9560, 5 },{ 7, 84 },{ 38, 19 } };
	long long TestAns1[] = { 2, 3, 1, 5, 7, 19 };
	long long TestAns2[] = { 96, 9, 445, 9560, 84, 38 };
	long long t = sizeof(TestAns1) / sizeof(long long);
	long long CF, CM;
	long long RepeatTimeNow = 100000;
	double Time1, Time2;
	cout << "------------------------------------------------------------" << endl;
	cout << "第1类测试开始！此测试使用已知数据测试！" << endl;
	for (long long i = 0; i < t; i++)
	{
		Time MyTime;
		MyTime.StartClock();
		for (long long k = 0; k < RepeatTimeNow; k++)
		{
			Two_Num MyNums(Test[i][0], Test[i][1]);
			CF = MyNums.GetGreatestCommonFact();
		}
		MyTime.EndClock();
		Time1 = MyTime.GetMicroSec(RepeatTimeNow);
		MyTime.StartClock();
		for (long long k = 0; k < RepeatTimeNow; k++)
		{
			Two_Num MyNums(Test[i][0], Test[i][1]);
			CM = MyNums.GetLeastCommonMulti();
		}
		MyTime.EndClock();
		Time2 = MyTime.GetMicroSec(RepeatTimeNow);
		if (CF != TestAns1[i])
		{
			cout << "第" << i + 1 << "组数据出错！" << "此处计算" << Test[i][0] << "与" << Test[i][1] << "的最大公约数，应该为" << TestAns1[i] << "但计算为" << CF << "！" << endl;
			p++;
		}
		if (CM != TestAns2[i])
		{
			cout << "第" << i + 1 << "组数据出错！" << "此处计算" << Test[i][0] << "与" << Test[i][1] << "的最小公倍数，应该为" << TestAns2[i] << "但计算为" << CM << "！" << endl;
			p++;
		}
		cout << "计算得到" << Test[i][0] << "与" << Test[i][1] << "的最大公约数为" << CF << "，用时" << Time1 << "微秒；计算得到" << Test[i][0] << "与" << Test[i][1] << "的最小公倍数为" << CM << "，用时" << Time2 << "微秒！" << endl;
	}
	cout << "第1类测试结束，共测试" << t << "组数据。每组数据计算两个数（最大公约数和最小公倍数），其中" << p << "个测试结果错误！" << endl;
	AutoTestByMultiple(293, 97, 2);
	AutoTestByMultiple(29333, 29947, 3);
	AutoTestByMultiple(49993, 49999, 4);
	AutoTestByMultiple(9982499, 9522827, 5);
	cout << "------------------------------------------------------------" << endl;
}