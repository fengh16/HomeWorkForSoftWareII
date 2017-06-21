#include "FH_Date_Test.h"
#include <string>

Calendar My_Calendar;
/*void Print_Date(My_Date & This_Date)
{
	int* get = This_Date.Get_Date();
	cout << "Now date is " << Months_Name[get[1] - 1] << " " << get[2];
	Print_Days(get[2]);
	cout << ", " << get[0] << "." << endl;
	delete(get);
}*/

void Put_In_Date()
{
	long long Year = 0;
	int Month = -1, Day = -1;
	do
	{
		cout << "������һ�����ڣ����� �� �� �� ��˳���м��� �ո� ������" << endl;
		cin >> Year >> Month >> Day;
		if (cin.good() && Year != 0 && Month < 13 && Month > 0 && Day > 0 && Day <= Calendar::Days_In_The_Month(Year, Month))
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����������������룡" << endl;
		Year = 0;
		Month = -1;
		Day = -1;
	} while (1);
	My_Calendar.SetDate(Year, Month, Day);
	Print_Date();
}

void Man_Testing()
{
	char ch;
	Print_Date();
	while(1)
	{
		cout << "���� 1 ����n��֮������ڣ����� 2 �����������ڣ����������ַ��˳���" << endl;
		ch = getchar();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (ch == '1')
			Calculate_After();
		else if (ch == '2')
			Put_In_Date();
		else
			break;
	}
}

/*void Print_Days(int day)
{
	switch (day)
	{
	case 1:
	case 21:
	case 31:
		cout << "st";
		return;
	case 2:
	case 22:
		cout << "nd";
		return;
	case 3:
	case 23:
		cout << "rd";
		return;
	default:
		cout << "th";
		return;
	}
}*/

void Calculate_After()
{
	int n;
	while (1)
	{
		cout << "����n��" << endl;
		cin >> n;
		if (cin.good())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "����������������룡" << endl;
	}
	My_Calendar.GetDesiredDate(n);
}

void Print_Date()
{
	My_Calendar.PrintDate();
}