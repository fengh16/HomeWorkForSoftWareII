#include "FH_Auto_Test.h"
#include <Windows.h>

void Auto_Test()
{
	cout << "------------------------------------------------------------" << endl << "自动测试开始！" "------------------------------------------------------------" << endl;string PathBase = GetPathOfTest();cout << PathBase;cout << "------------------------------------------------------------" << endl;}

string GetPathOfTest()
{
	TCHAR szPath[MAX_PATH];GetModuleFileName(NULL, szPath, MAX_PATH);*(strrchr(szPath, '\\')) = '\0';*(strrchr(szPath, '\\')) = '\0';string strPath;for (int n = 0; szPath[n]; n++)
	{
		if (szPath[n] != '\\')
		{
			strPath += szPath[n];}
		else
		{
			strPath += "\\\\";}
	}
	return strPath + "\\\\TestData\\\\";}
