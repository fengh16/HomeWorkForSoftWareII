#include "FH_Auto_Test.h"

double Test_Use[6][3] = { {25, 15.2, 0}, {0.6, -958625, 99.3}, {952, -35, 584.6}, {0, 3.8, -2.6}, {3.5, -0.0006, 925.6358}, {0, 3.02, 9.65} };

void Auto_Test()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "��һ�ֲ��Կ�ʼ��" << endl;
	cout << "------------------------------------------------------------" << endl;
	Complex Test_Complex[27] = {
		Complex(1, 3), Complex(0.999, 10), 
		Complex(-96.2, 35.6), Complex(96.2, 3), 
		Complex(12.3, -63.2), Complex(15.965, 63.3), 
		
		Complex(1, 31.3), Complex(1, 31.3),
		Complex(5, 26), Complex(1, 96.525),
		Complex(96.2, 2.6), Complex(19586, 9.25),

		Complex(1, 3), Complex(-3, 1),
		Complex(-5.625, 2.66), Complex(0, 0),
		Complex(-96.2, 2.6), Complex(-19586, -9.25),

		Complex(1, 31.3), Complex(0, 0),
		Complex(-5, 2.6), Complex(1.69, -9.6),
		Complex(36.2, 2.6), Complex(3.62, 0.26),

		Complex(3.26, 15),
		Complex(1.36, -96),
		Complex(2, 0)
	};
	for (int i = 0; i < 3; i++)
	{
		cout << "(" << Test_Complex[2 * i] << ")+(" << Test_Complex[2 * i + 1] << ")=" << Test_Complex[2 * i] + Test_Complex[2 * i + 1] << endl;
	}
	cout << endl;
	for (int i = 3; i < 6; i++)
	{
		cout << "(" << Test_Complex[2 * i] << ")-(" << Test_Complex[2 * i + 1] << ")=" << Test_Complex[2 * i] - Test_Complex[2 * i + 1] << endl;
	}
	cout << endl;
	for (int i = 6; i < 9; i++)
	{
		cout << "(" << Test_Complex[2 * i] << ")*(" << Test_Complex[2 * i + 1] << ")=" << Test_Complex[2 * i] * Test_Complex[2 * i + 1] << endl;
	}
	cout << endl;
	for (int i = 9; i < 12; i++)
	{
		cout << "(" << Test_Complex[2 * i] << ")/(" << Test_Complex[2 * i + 1] << ")=" << Test_Complex[2 * i] / Test_Complex[2 * i + 1] << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "ԭʼ����Ϊ " << Test_Complex[24 + i] << " ��֮����� " << Test_Complex[24 + i] << " ++ = ";
		cout << Test_Complex[24 + i]++;
		cout << " �����ڼ��������Ϊ " << Test_Complex[24 + i] << endl;

		cout << "ԭʼ����Ϊ " << Test_Complex[24 + i] << " ��֮����� ++ " << Test_Complex[24 + i] << " = ";
		cout << ++Test_Complex[24 + i];
		cout << " �����ڼ��������Ϊ " << Test_Complex[24 + i] << endl;

		cout << "ԭʼ����Ϊ " << Test_Complex[24 + i] << " ��֮����� " << Test_Complex[24 + i] << " -- = ";
		cout << Test_Complex[24 + i]--;
		cout << " �����ڼ��������Ϊ " << Test_Complex[24 + i] << endl;

		cout << "ԭʼ����Ϊ " << Test_Complex[24 + i] << " ��֮����� -- " << Test_Complex[24 + i] << " = ";
		cout << --Test_Complex[24 + i];
		cout << " �����ڼ��������Ϊ " << Test_Complex[24 + i] << endl;

		cout << endl;
	}
	cout << "���濪ʼ���㸴����ָ���������㣡" << endl;
	Complex Power_Use[5] = { Complex(3.6, 9.562), Complex(9, -35), Complex(-1, -2), Complex(0, 2), Complex(3, 0) };
	for (int i = 0; i < 5; i++)
	{
		cout << "ԭ������Ϊ�� " << Power_Use[i] << endl;
		for (int j = 1; j < 6; j++)
			cout << "\t����" << j << "�η�Ϊ: " << Power(Power_Use[i], j) << endl;
		for (int j = 0; j > -6; j--)
			cout << "\t����" << j << "�η�Ϊ: " << Power(Power_Use[i], j) << endl;
		cout << "\t����" << 0.5 << "�η�Ϊ: " << Power(Power_Use[i], 0.5) << endl;
		cout << "\t����" << 0.1 << "�η�Ϊ: " << Power(Power_Use[i], 0.1) << endl;
		cout << "\t����" << 9.6 << "�η�Ϊ: " << Power(Power_Use[i], 9.6) << endl;
		cout << "\t����" << -0.5 << "�η�Ϊ: " << Power(Power_Use[i], -0.5) << endl;

		cout << endl;
	}
	cout << "------------------------------------------------------------" << endl;
	cout << "���漴�����еڶ��ֲ��ԣ�" << endl;
	system("pause");
	cout << "�ڶ��ֲ��Կ�ʼ��" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Test(j, i);
			cout << endl;
		}
	}
}

void Test(int No, int Operation)
{
	Complex c1(Test_Use[0][No], Test_Use[1][No]), c2(Test_Use[2][No], Test_Use[3][No]), ans1, ans2, ans3;
	double d1 = Test_Use[4][No], d2 = Test_Use[5][No];
	switch (Operation)
	{
	case 0:
		ans1 = c1 + c2;
		cout << "(" << c1 << ")" << " + " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans1 << endl;
		ans2 = c1 + d1;
		cout << "(" << c1 << ")" << " + " << "(" << d1 << ")" << " �Ľ������Ϊ " << ans2 << endl;
		ans3 = d2 + c2;
		cout << "(" << d2 << ")" << " + " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans3 << endl;
		break;
	case 1:
		ans1 = c1 - c2;
		cout << "(" << c1 << ")" << " - " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans1 << endl;
		ans2 = c1 - d1;
		cout << "(" << c1 << ")" << " - " << "(" << d1 << ")" << " �Ľ������Ϊ " << ans2 << endl;
		ans3 = d2 - c2;
		cout << "(" << d2 << ")" << " - " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans3 << endl;
		break;
	case 2:
		ans1 = c1 * c2;
		cout << "(" << c1 << ")" << " * " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans1 << endl;
		ans2 = c1 * d1;
		cout << "(" << c1 << ")" << " * " << "(" << d1 << ")" << " �Ľ������Ϊ " << ans2 << endl;
		ans3 = d2 * c2;
		cout << "(" << d2 << ")" << " * " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans3 << endl;
		break;
	case 3:
		ans1 = c1 / c2;
		cout << "(" << c1 << ")" << " / " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans1 << endl;
		ans2 = c1 / d1;
		cout << "(" << c1 << ")" << " / " << "(" << d1 << ")" << " �Ľ������Ϊ " << ans2 << endl;
		ans3 = d2 / c2;
		cout << "(" << d2 << ")" << " / " << "(" << c2 << ")" << " �Ľ������Ϊ " << ans3 << endl;
		break;
	case 4:
		cout << "((" << c1 << ")" << " ++) * (-- " << "(" << c2 << "))" << " �Ľ������Ϊ ";
		ans1 = (c1++) * (--c2);
		cout << ans1 << endl;
		cout << "((" << c1 << ")" << " ++) * (-- " << "(" << d1 << "))" << " �Ľ������Ϊ ";
		ans2 = (c1++) * (--d1);
		cout << ans2 << endl;
		cout << "((" << d2 << ")" << " ++) * (-- " << "(" << c2 << "))" << " �Ľ������Ϊ ";
		ans3 = (d2++) * (--c2);
		cout << ans3 << endl;
		break;
	case 5:
		cout << "(-- " << "(" << c1 << "))" << " * " << "((" << c2 << ")" << " ++)" << "�Ľ������Ϊ ";
		ans1 = (--c1) * (c2++);
		cout << ans1 << endl;
		cout << "(-- " << "(" << c1 << "))" << " * " << "((" << d1 << ")" << " ++)" << "�Ľ������Ϊ ";
		ans2 = (--c1) * (d1++);
		cout << ans2 << endl;
		cout << "(-- " << "(" << d2 << "))" << " * " << "((" << c2 << ")" << " ++)" << "�Ľ������Ϊ ";
		ans3 = (--d2) * (c2++);
		cout << ans3 << endl;
		break;
	default:
		break;
	}
}