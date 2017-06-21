#define _CRT_SECURE_NO_WARNINGS
#include "FH_Date_Auto_Test.h"

Calendar My_Calendar2;
time_t Get_Now_Time;
_int64 Ans[4];//�Զ����Թ�������Ҫ�õģ�ͨ������ϵͳ�⺯�����Լ��Ľ�����бȶԣ������ﵽ����Ŀ��.���е�һ���ǵ�Ŀǰ��ʱ�䣨Ҳ������time�õ���������������趨ʱ������ת���ɵ��������ڶ��������ĸ�����������
int Result_Right = 0, Result_Wrong = 0;

void Auto_Test()
{
	cout << "���ڿ�ʼ�Զ����ԣ��ڲ����л�ʹ��ϵͳ�⺯�����в��ԣ�" << endl;
	time(&Get_Now_Time);
	Get_Now_Time += 8 * 3600;
	SetAns(Get_Now_Time);
	for (int i = -9000; i  < 9999; i += 5)
	{
		Test_Set(i);
	}
	cout << "������" << Result_Right + Result_Wrong << "�����ݣ�����" << Result_Wrong << "�����" << endl;
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
		cout << "��ȷ��" << endl;
		Result_Right++;
	}
	else
	{
		cout << "����" << endl;
		Result_Wrong++;
	}
}