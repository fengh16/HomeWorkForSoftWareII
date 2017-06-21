#include "FH_Start.h"
#include "FH_Time.h"

void AutoTestByMultiple(long long x, long long y, long long No)
{
	cout << "------------------------------------------------------------" << endl;
	cout << "��" << No << "����Կ�ʼ���˲���ʹ��������" << x << "��" << y << "�ı������ԣ�" << endl;
	long long p = 0, ans;
	long long a, b;
	for (ans = 1; ans <= 20000; ans++)
	{
		a = ans * x;
		b = ans * y;
		if (a < 0)
		{
			cout << "��ʱʹ�õ�һ������Ϊ" << ans << "*" << x << "�Ľ����������Ϊ" << a << "���������" << endl;
			break;
		}
		if (b < 0)
		{
			cout << "��ʱʹ�õ�һ������Ϊ" << ans << "*" << y << "�Ľ����������Ϊ" << b << "���������" << endl;
			break;
		}
		Two_Num app(a, b);
		if (app.GetGreatestCommonFact() != ans)
		{
			cout << "��" << ans << "�����ݳ���" << "�˴�����" << a << "��" << b << "�����Լ����Ӧ��Ϊ" << ans << "������Ϊ" << app.GetGreatestCommonFact() << "��" << endl;
			p++;
		}
		if (app.GetLeastCommonMulti() / a * ans != b)
		{
			cout << "��" << ans << "�����ݳ���" << "�˴�����" << a << "��" << b << "����С��������Ӧ��Ϊ" << a * b / ans << "������Ϊ" << app.GetLeastCommonMulti() << "��" << endl;
			p++;
		}
	}
	cout << "��" << No << "����Խ�����������" << ans - 1 << "�����ݡ�ÿ�����ݼ��������������Լ������С��������������" << p << "�����Խ������" << endl;
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
	cout << "��1����Կ�ʼ���˲���ʹ����֪���ݲ��ԣ�" << endl;
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
			cout << "��" << i + 1 << "�����ݳ���" << "�˴�����" << Test[i][0] << "��" << Test[i][1] << "�����Լ����Ӧ��Ϊ" << TestAns1[i] << "������Ϊ" << CF << "��" << endl;
			p++;
		}
		if (CM != TestAns2[i])
		{
			cout << "��" << i + 1 << "�����ݳ���" << "�˴�����" << Test[i][0] << "��" << Test[i][1] << "����С��������Ӧ��Ϊ" << TestAns2[i] << "������Ϊ" << CM << "��" << endl;
			p++;
		}
		cout << "����õ�" << Test[i][0] << "��" << Test[i][1] << "�����Լ��Ϊ" << CF << "����ʱ" << Time1 << "΢�룻����õ�" << Test[i][0] << "��" << Test[i][1] << "����С������Ϊ" << CM << "����ʱ" << Time2 << "΢�룡" << endl;
	}
	cout << "��1����Խ�����������" << t << "�����ݡ�ÿ�����ݼ��������������Լ������С��������������" << p << "�����Խ������" << endl;
	AutoTestByMultiple(293, 97, 2);
	AutoTestByMultiple(29333, 29947, 3);
	AutoTestByMultiple(49993, 49999, 4);
	AutoTestByMultiple(9982499, 9522827, 5);
	cout << "------------------------------------------------------------" << endl;
}