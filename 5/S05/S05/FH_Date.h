#ifndef FH_DATE_H
#define FH_DATE_H

#include <time.h>
#include <iostream>
using namespace std;

const int Days_In_Months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Calendar
{
private:
	long long year;
	int month;
	int day;
	long long All_Days;
	//在这里用0代表1年1月1日，用-1代表公元前1年12月31日
	void Calculate_From_All_Days();
	void Calculate_To_All_Days();

public:
	Calendar();
	~Calendar(){}
	int * SetDate(long long year, int month, int day);
	int * SetDate(long long All_Days);
	//int* Get_Date();
	void PrintDate();
	int * GetDesiredDate(int n);
	//void Add_Days(int Added_Days);

	static bool If_Leap_Year(long long This_Year);
	static int Total_Days_In_Year(long long year);
	static int Get_Feb_Plus_Day(long long year);
	static int Days_In_The_Month(long long year, int month);
};

#endif // !FH_DATE_H
