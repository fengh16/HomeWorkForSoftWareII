#include "FH_Man_Test.h"

Complex Test_A, Test_B;

void Man_Test()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "手动测试开始！" << endl;
	Put_In();
}

Complex Get_Complex_Num()
{
	double R, I;
	do
	{
		cout << "请输入一个复数！按照 实部 虚部 的顺序，中间用 空格 隔开！" << endl;
		cin >> R >> I;
		if (cin.good())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "输入有误，请重新输入！" << endl;
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
		cout << "输入有误，请重新输入！" << endl;
		ch = '/0';
	} while (1);
	return ch;
}

void Put_In()
{
	char ch;
	Complex Ans;
	cout << "计算开始！" << endl;
	Test_A = Get_Complex_Num();
	cout << "请输入运算符（+， -， *， /）！" << endl;
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
