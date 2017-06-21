#define _CRT_SECURE_NO_WARNINGS
#include "FH_Date.h"

int TempDate[3];//这个是为了自动测试创建的数组

Calendar::Calendar()
{
	time_t Get_Now_Time;
	struct tm *Temp_To_YMD;
	time(&Get_Now_Time);
	Get_Now_Time += 8 * 3600;
	Temp_To_YMD = gmtime(&Get_Now_Time);
	year = Temp_To_YMD->tm_year + 1900;
	month = Temp_To_YMD->tm_mon + 1;
	day = Temp_To_YMD->tm_mday;
	Calculate_To_All_Days();
}

bool Calendar::If_Leap_Year(long long This_Year)
{
	long long Temp_Year = This_Year;
	if (Temp_Year < 0)
		Temp_Year = -Temp_Year - 1;
	if (Temp_Year % 172800 == 0)
		return true;
	if (Temp_Year % 3200 == 0)
		return false;
	if (Temp_Year % 400 == 0)
		return true;
	if (Temp_Year % 100 == 0)
		return false;
	if (Temp_Year % 4 == 0)
		return true;
	return false;
}

int Calendar::Get_Feb_Plus_Day(long long year)
{
	if (If_Leap_Year(year))
		return 1;
	return 0;
}

void Calendar::Calculate_From_All_Days()
{
	bool If_Positive = (All_Days >= 0);
	long long Temp_All_Days = All_Days;
	long long Temp_Year = 1;
	int Temp_Day = 1, Temp_Month = 1;
	if (If_Positive)
	{
		while (Temp_All_Days >= Total_Days_In_Year(Temp_Year))
		{
			Temp_All_Days -= Total_Days_In_Year(Temp_Year);
			Temp_Year++;
		}
	}
	else
	{
		Temp_Year = 0;
		while (Temp_All_Days < 0)
		{
			Temp_All_Days += Total_Days_In_Year(Temp_Year - 1);
			Temp_Year--;
		}
	}
	while (Temp_All_Days >= Days_In_The_Month(Temp_Year, Temp_Month))
	{
		Temp_All_Days -= Days_In_The_Month(Temp_Year, Temp_Month);
		Temp_Month++;
	}
	Temp_Day += Temp_All_Days;
	year = Temp_Year;
	month = Temp_Month;
	day = Temp_Day;
}

int Calendar::Total_Days_In_Year(long long year)
{
	if (If_Leap_Year(year))
		return 366;
	return 365;
}

int Calendar::Days_In_The_Month(long long year, int month)
{
	int ans = Days_In_Months[month - 1] + (month != 2 ? 0 : Get_Feb_Plus_Day(year));
	return ans;
}

void Calendar::Calculate_To_All_Days()
{
	long long Temp_All_Day = 0;
	for (long long LoopTemp = 1; LoopTemp < year; LoopTemp++)
		Temp_All_Day += Total_Days_In_Year(LoopTemp);
	for (long long LoopTemp = 0; LoopTemp > year; LoopTemp--)
		Temp_All_Day -= Total_Days_In_Year(LoopTemp - 1);
	for (long long LoopTemp = 1; LoopTemp < month; LoopTemp++)
		Temp_All_Day += Days_In_The_Month(year, LoopTemp);
	Temp_All_Day += day - 1;
	All_Days = Temp_All_Day;
	TempDate[0] = year;
	TempDate[1] = month;
	TempDate[2] = day;
}

//void Calendar::Add_Days(int Added_Days)
//{
//	int k = All_Days;
//	All_Days += Added_Days;
//	Calculate_From_All_Days();
//	Calculate_To_All_Days();
//	if (All_Days - k != Added_Days)
//		cout << "数据已经溢出，目前结果错误！";
//}

int * Calendar::SetDate(long long New_Year, int New_Month, int New_Day)
{
	if (New_Year != 0 && New_Month < 13 && New_Month > 0 && New_Day > 0 && New_Day <= Days_In_The_Month(New_Year, New_Month))
	{
		year = New_Year;
		month = New_Month;
		day = New_Day;
		Calculate_To_All_Days();
		Calculate_From_All_Days();
		if (year != New_Year)
			cout << "数据已经溢出，目前结果错误！";
		TempDate[0] = year;
		TempDate[1] = month;
		TempDate[2] = day;
		return TempDate;
	}
	else
		cout << "输入错误，请重新输入！" << endl;
	return TempDate;
}

int * Calendar::SetDate(long long New_All_Days)
{
	All_Days = New_All_Days;
	Calculate_From_All_Days();
	Calculate_To_All_Days();
	if (All_Days != New_All_Days)
		cout << "数据已经溢出，目前结果错误！";
	TempDate[0] = year;
	TempDate[1] = month;
	TempDate[2] = day;
	return TempDate;
}

//int* Calendar::Get_Date()
//{
//	int* Returned_Dates = new int[3];
//	Returned_Dates[0] = year;
//	Returned_Dates[1] = month;
//	Returned_Dates[2] = day;
//	return Returned_Dates;
//}

void Calendar::PrintDate()
{
	if (year < 0)
		cout << "公元前 " << -year;
	else
		cout << "公元 " << year;
	cout << "年 " << month << "月 " << day << "日" << endl;
}

int * Calendar::GetDesiredDate(int n)
{
	All_Days += n;
	Calculate_From_All_Days();
	PrintDate();
	TempDate[0] = year;
	TempDate[1] = month;
	TempDate[2] = day;
	All_Days -= n;
	Calculate_From_All_Days();
	return TempDate;
}