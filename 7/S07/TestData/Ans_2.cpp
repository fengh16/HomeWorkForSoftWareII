#include "FH_Find.h"

string Changed;
int GetEndLine(string FilePath)
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
In_Temp = new ifstream(TargetFile, ios::in);
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
	Changed = TargetFile;
FH_File_Out.open(TargetFile, ios::out);
int No = 0;
char ch = '0';
while (ch != EOF)
	{
		ch = FH_File_In.get();
FH_File_Out << ch;
if (ch == ';
')
		{
FH_Mark:	ch = FH_File_In.get();
if (ch != '\n' && ch != ';
')
			{
				No++;
FH_File_Out << '\n' << ch;
}
			else if (ch == ';
')
			{
				No++;
FH_File_Out << '\n' << ch;
goto FH_Mark;
}
		}
	}
	FH_File_In.close();
FH_File_Out.close();
return No;
}

string Get_File_Name(string FilePath)
{
	int i;
string Ans = "";
for (i = FilePath.length() - 1;
 i >= 0;
 --i)
		if (FilePath[i] == '\\')
			break;
i++;
for (;
 i < FilePath.length();
 ++i)
		Ans += FilePath[i];
return Ans;
}
ÿ