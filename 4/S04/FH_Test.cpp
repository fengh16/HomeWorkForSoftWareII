#include "FH_Test.h"
void Human_Test()
{
	long long m, n, CF, CM;
	long long RepeatTimeNow = 100000;
	cout << "------------------------------------------------------------" << endl << "手动测试开始！请输入两个正整数！将依次显示最大公约数及时间代价(微秒)、最小公倍数及时间代价(微秒)！" << endl << "\t一组数据输入完后直接输入下一组数据即可，不必等待文字提示！" << endl << "------------------------------------------------------------" << endl;
	while (1)
	{
		do
		{
			m = n = 0;
			cin >> n >> m;
			if (cin.good() && n > 0 && m > 0)
				break;
			cout << "输入错误，请重新输入！" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (1);
		Time MyTime;
		MyTime.StartClock();
		for(long long i = 0; i < RepeatTimeNow; i++)
		{
			Two_Num MyNums(m, n);
			CF = MyNums.GetGreatestCommonFact();
		}
		MyTime.EndClock();
		cout << CF << " " << MyTime.GetMicroSec(RepeatTimeNow) << endl;
		MyTime.StartClock();
		for (long long i = 0; i < RepeatTimeNow; i++)
		{
			Two_Num MyNums(m, n);
			CM = MyNums.GetLeastCommonMulti();
		}
		MyTime.EndClock();
		cout << CM << " " << MyTime.GetMicroSec(RepeatTimeNow) << endl;
		if (CM / m * CF != n)
			cout << "已越界！最小公倍数计算错误！" << endl;
	}
}