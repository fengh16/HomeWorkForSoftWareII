#include <iostream>
using namespace std;
#include "FHC_StartTest.h"
#include "windows.h"
void AutoTestByMultiple(long x, long y, int No)
{
	cout << "------------------------------------------------------------" << endl;
	cout << "��" << No << "����Կ�ʼ���˲���ʹ��������" << x << "��" << y << "�ı������ԣ�" << endl;
	FHC_Start app;
	long p = 0, ans;
	long a, b;
	for (ans = 1; ans <= 99999999; ans++)
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
		if (app.outStart(a, b) != ans)
		{
			cout << "��" << ans << "�����ݳ���" << "�˴�����" << a << "��" << b << "�����Լ����Ӧ��Ϊ" << ans << "������Ϊ" << app.outStart(a, b) << "��" << endl;
			p++;
		}
	}
	cout << "��" << No << "����Խ�����������" << ans - 1 << "�����ݡ�����" << p << "�����ݴ���" << endl;
}
void AutoTest()
{
	DWORD k1 = ::GetTickCount(); //��ȡ���뼶��Ŀ
	FHC_Start app;
	long a, b, ans;
	int p = 0;
	int Test[][2] = { {2, 96}, {3, 9}, {89, 5}, {9560, 5}, {7, 84}, {38, 19} };
	int TestAns[] = { 2, 3, 1, 5, 7, 19 };
	int t = sizeof(TestAns) / sizeof(int);
	cout << "------------------------------------------------------------" << endl;
	cout << "��1����Կ�ʼ���˲���ʹ����֪���ݲ��ԣ�" << endl;
	for (int i = 0; i < t; i++)
	{
		if (app.outStart(Test[i][0], Test[i][1]) != TestAns[i])
		{
			cout << "��" << i + 1 << "�����ݳ���" << "�˴�����" << Test[i][0] << "��" << Test[i][1] << "�����Լ����Ӧ��Ϊ" << TestAns[i] << "������Ϊ" << app.outStart(Test[i][0], Test[i][1]) << "��" << endl;
			p++;
		}
	}
	cout << "��1����Խ�����������" << t << "�����ݡ�����" << p << "�����ݴ���" << endl;
	AutoTestByMultiple(293, 97, 2);
	AutoTestByMultiple(29333, 29947, 3);
	AutoTestByMultiple(49993, 49999, 4);
	AutoTestByMultiple(9982499, 9522827, 5);
	cout << "------------------------------------------------------------" << endl;
	cout << "��6����Կ�ʼ���˲���ʹ��Խ�����ݲ��Գ����ݴ��ԣ�����������0����ʱӦ�����0��" << endl;
	p = 0;
	long long LongTest[][2] = { {-1, 8}, {-8, -5}, {LONG_MIN, 9}, {INT_MIN, 85}, {-958965, 25}, {0, 95} };
	for (int i = 0; i < 6; i++)
	{
		if (app.outStart(LongTest[i][0], LongTest[i][1]) != 0)
		{
			cout << "��" << i + 1 << "�����ݳ���" << "�˴�����" << LongTest[i][0] << "��" << LongTest[i][1] << "�����Լ����Ӧ��Ϊ0������Ϊ" << app.outStart(LongTest[i][0], LongTest[i][1]) << "��" << endl;
			p++;
		}
	}
	cout << "��6����Խ�����������6�����ݡ�����" << p << "�����ݴ���" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "��7����Կ�ʼ���˲���ʹ�ñ߽����ݲ�����Ч���ݷ�Χ��" << endl;
	unsigned long long LastTest[][2] = { { ((unsigned long long)INT_MAX / 2) * 2, (unsigned long long)INT_MAX / 2 },{ (unsigned long long)INT_MAX, (unsigned long long)INT_MAX * 2 },{ (unsigned long long)(INT_MAX / 2 + 1) * 2, (unsigned long long)INT_MAX / 2 + 1},{(unsigned long long)(INT_MAX), 1 },{ (unsigned long long)(INT_MAX), (unsigned long long)(INT_MAX) } };
	unsigned long long LastAnses[] = { (unsigned long long)INT_MAX / 2, (unsigned long long)INT_MAX, (unsigned long long)INT_MAX / 2 + 1, 1, (unsigned long long)(INT_MAX) };
	for (int i = 0; i < 5; i++)
	{
		cout << "����õ�" << LastTest[i][0] << "��" << LastTest[i][1] << "�Ľ��Ϊ" << app.outStart(LastTest[i][0], LastTest[i][1]) << ",���Ӧ��Ϊ" << LastAnses[i] << "�������" << ((unsigned long long)app.outStart(LastTest[i][0], LastTest[i][1]) == (unsigned long long)LastAnses[i] ? "��ȷ��" : "����") << endl;
	}
	cout << "��7����Խ�����������5������!" << endl;
	cout << "------------------------------------------------------------" << endl;

	DWORD k2 = ::GetTickCount();
	long long time = k2 - k1;
	cout << "����ʱ" << time << "ms��";
}