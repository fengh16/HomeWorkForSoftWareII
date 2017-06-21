#define _CRT_SECURE_NO_WARNINGS
#include "FH_Date_Auto_Test.h"

Calendar My_Calendar2;
time_t Get_Now_Time;
_int64 Ans[4];//自动测试过程中需要用的，通过调用系统库函数和自己的结果进行比对，这样达到测试目的.其中第一个是到目前的时间（也就是用time得到的秒数，如果是设定时间则是转换成的秒数；第二个到第四个数是年月日
int Result_Right = 0, Result_Wrong = 0;

void Auto_Test()
{
	cout << "现在开始自动测试！在测试中会使用系统库函数进行测试！" << endl;
	time(&Get_Now_Time);
	Get_Now_Time += 8 * 3600;
	SetAns(Get_Now_Time);
	for (int i = -9000; i  < 9999; i += 5)
	{
		Test_Set(i);
	}
	cout << "共测试" << Result_Right + Result_Wrong << "组数据，其中" << Result_Wrong << "组错误！" << endl;
	system("pause");
}

void SetAns(time_t Get_Now_Time)
{
	struct tm *Temp_To_YMD;
	Ans[0] = Get_Now_Time;
	Temp_To_YMD = gmtime(&Get_Now_Time);
	Ans[1] = Temp_To_YMD->tm_year + 1900;
	Ans[2] = Temp_To_YMD->tm_mon + 1;
	Ans[3] = Temp_To_YMD->tm_mday;
}

bool check(int * TempDate)
{
	if (Ans[1] == TempDate[0] && Ans[2] == TempDate[1] && Ans[3] == TempDate[2])
		return true;
	return false;
}

void Test_Set(int n)
{
	SetAns(Get_Now_Time + n * 24 * 3600);
	if (check(My_Calendar2.GetDesiredDate(n)))
	{
		cout << "正确！" << endl;
		Result_Right++;
	}
	else
	{
		cout << "错误！" << endl;
		Result_Wrong++;
	}
}