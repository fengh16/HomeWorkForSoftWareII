#include "FH_Find.h"
#include <time.h>

string Changed;

int GetEndLine(string FilePath, string OutPath)
{
	ifstream FH_File_In(FilePath, ios::in);
	if (!FH_File_In)
		return -1;
	string TargetFile = "_Changed_" + Get_File_Name(FilePath);
	ofstream FH_File_Out;
	int LoopTimes = 0;
	do
	{
		ifstream *In_Temp = NULL;
		In_Temp = new ifstream(OutPath + TargetFile, ios::in);
		if (!*In_Temp)
		{
			In_Temp->close();
			delete In_Temp;
			break;
		}
		In_Temp->close();
		delete In_Temp;
		LoopTimes++;
		TargetFile = "_FH" + TargetFile;
	} while (LoopTimes < 10);
	if (LoopTimes >= 10)
	{
		TargetFile = "_Changed_" + Get_File_Name(FilePath);
	}
	Changed = (TargetFile = OutPath + TargetFile);
	FH_File_Out.open(TargetFile, ios::out);
	int No = 0;
	char ch = '0';
	while (ch != EOF)
	{
		ch = FH_File_In.get();
		FH_File_Out << ch;
		if (ch == ';')
		{
FH_Mark:	ch = FH_File_In.get();
			if (ch != '\n' && ch != ';')
			{
				No++;
				FH_File_Out << '\n' << ch;
			}
			else if (ch == ';')
			{
				No++;
				FH_File_Out << '\n' << ch;
				goto FH_Mark;
			}
			else
			{
				FH_File_Out << ch;
			}
		}
	}
	FH_File_In.close();
	FH_File_Out.close();
	ofstream Log("log.txt", ios::out | ios::app);
	time_t Get_Now_Time;
	time(&Get_Now_Time);
	Get_Now_Time += 8 * 3600;
	struct tm *Temp_To_YMD = new tm;
	gmtime_s(Temp_To_YMD, &Get_Now_Time);
	Log << "于" << Temp_To_YMD->tm_year + 1900 << "年" << Temp_To_YMD->tm_mon + 1 << "月" << Temp_To_YMD->tm_mday << "日" << Get_Now_Time % (24 * 3600) / 3600 << "时" << Get_Now_Time % (24 * 3600) / 60 % 60 << "分" << Get_Now_Time % (24 * 3600) % 60 << "秒运行程序，检查文件 " << FilePath << " ，最终输出为 " << TargetFile << " ，其中找到错误共 " << No << "条！" << endl;
	delete Temp_To_YMD;
	return No;
}

string Get_File_Name(string FilePath)
{
	int i;
	string Ans = "";
	for (i = FilePath.length() - 1; i >= 0; --i)
		if (FilePath[i] == '\\')
			break;
	i++;
	for (; i < FilePath.length(); ++i)
		Ans += FilePath[i];
	return Ans;
}