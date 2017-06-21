#include "FH_Man_Test.h"

Complex Test_A, Test_B;

void Man_Test()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "�ֶ����Կ�ʼ��" << endl;
	Put_In();
}

Complex Get_Complex_Num()
{
	double R, I;
	do
	{
		cout << "������һ������������ ʵ�� �鲿 ��˳���м��� �ո� ������" << endl;
		cin >> R >> I;
		if (cin.good())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�����������������룡" << endl;
	} while (1);
	Complex ans(R, I);
	return ans;
}

int Get_One_Operation()
{
	char ch = '\0';
	do
	{
		while (ch == '\0' || ch == '\n')
		{
			cin >> ch;
		}
		if (cin.good())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "�����������������룡" << endl;
		ch = '/0';
	} while (1);
	return ch;
}

void Put_In()
{
	char ch;
	Complex Ans;
	cout << "���㿪ʼ��" << endl;
	Test_A = Get_Complex_Num();
	cout << "�������������+�� -�� *�� /����" << endl;
	ch = Get_One_Operation();
	Test_B = Get_Complex_Num();
	switch (ch)
	{
	case '+':
		Ans = Test_A + Test_B;
		break;
	case '-':
		Ans = Test_A - Test_B;
		break;
	case '*':
		Ans = Test_A * Test_B;
		break;
	case '/':
		Ans = Test_A / Test_B;
		break;
	default:
		break;
	};
	Ans.Print();
	cout << endl;
}
