#include "FH_Auto_Test.h"
#include <Windows.h>

string PathBase;

void Auto_Test()
{
	cout << "------------------------------------------------------------" << endl << "自动测试开始！" << endl << "------------------------------------------------------------" << endl;
	PathBase = GetPathOfTest();
	int Ans[] = { 0, 14, 45, 13, 93, 34, 45 }, TestUse;
	for (int i = 1; i < 7; i++)
	{
		if (GetEndLine(PathBase + to_string(i) + ".cpp", PathBase) == Ans[i] && CompareFile(i))
			cout << "第 " << i << " 组运行正确！发现" << Ans[i] << "处错误！" << endl;
		else
			cout << "第 " << i << " 组运行错误！" << endl;
	}
	cout << "------------------------------------------------------------" << endl;
}

string GetPathOfTest()
{
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	*(strrchr(szPath, '\\')) = '\0';
	*(strrchr(szPath, '\\')) = '\0';
	string strPath;
	for (int n = 0; szPath[n]; n++)
	{
		if (szPath[n] != '\\')
		{
			strPath += szPath[n];
		}
		else
		{
			strPath += "\\\\";
		}
	}
	return strPath + "\\\\TestData\\\\";
}

bool CompareFile(int i)
{
	ifstream Ans(PathBase + "Ans_" + to_string(i) + ".cpp", ios::in);
	if (!Ans)
		return false;
	ifstream My_Ans(PathBase + "_Changed_" + to_string(i) + ".cpp", ios::in);
	if (!My_Ans)
		return false;
	char ch1 = '0', ch2 = '0';
	while (ch1 != EOF && ch2 != EOF)
	{
		ch1 = Ans.get();
		ch2 = My_Ans.get();
		if (ch1 != ch2)
			return false;
	}
	return true;
}