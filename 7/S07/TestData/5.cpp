#include "FH_Man_Test.h"
#include <Windows.h>

string File_Path;void Man_Test()
{
	cout << "------------------------------------------------------------" << endl;GetName();int t = GetEndLine(File_Path);if(t >= 0)
		cout << "操作成功！输出到文件" << Changed << " ，其中找到错误" << t << "个！";else
	{
		cout << "操作失败！请重新输入！" << endl;GetName();}
	cout << endl << "------------------------------------------------------------" << endl;}

string Change_File_Path(string Name)
{
	string NewName = "";char ch;int i = 0;bool Is_Rev = false;while (i < Name.length())
	{
		ch = Name[i++];if (ch == '\\')
		{
			if (!Is_Rev)
			{
				NewName += "\\\\";Is_Rev = true;}
			continue;}
		Is_Rev = false;NewName += ch;}
	return NewName;}

void GetName()
{
	cout << "请输入一个文件名（与exe文件在一起），或者输入文件的完整路径！" << endl;getline(cin, File_Path);File_Path = Change_File_Path(File_Path);cout << "文件目录：";if (File_Path[1] == ':')
		cout << File_Path;else
	{
		TCHAR szPath[MAX_PATH];GetModuleFileName(NULL, szPath, MAX_PATH);*(strrchr(szPath, '\\')) = '\0';string strPath;for (int n = 0; szPath[n]; n++)
		{
			if (szPath[n] != '\\')
			{
				strPath += szPath[n];}
			else
			{
				strPath += "\\\\";}
		}
		cout << strPath << "\\\\" << File_Path;}
	cout << endl;}
