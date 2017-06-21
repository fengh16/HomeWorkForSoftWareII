#include "FH_Man_Test.h"
#include <Windows.h>

string File_Path;
void Man_Test()
{
	cout << "------------------------------------------------------------" << endl;
GetName();
int t = GetEndLine(File_Path);
if(t >= 0)
		cout << "²Ù×÷³É¹¦£¡Êä³öµ½ÎÄ¼þ" << Changed << " £¬ÆäÖÐÕÒµ½´íÎó" << t << "¸ö£¡";
else
	{
		cout << "²Ù×÷Ê§°Ü£¡ÇëÖØÐÂÊäÈë£¡" << endl;
GetName();
}
	cout << endl << "------------------------------------------------------------" << endl;
}

string Change_File_Path(string Name)
{
	string NewName = "";
char ch;
int i = 0;
bool Is_Rev = false;
while (i < Name.length())
	{
		ch = Name[i++];
if (ch == '\\')
		{
			if (!Is_Rev)
			{
				NewName += "\\\\";
Is_Rev = true;
}
			continue;
}
		Is_Rev = false;
NewName += ch;
}
	return NewName;
}

void GetName()
{
	cout << "ÇëÊäÈëÒ»¸öÎÄ¼þÃû£¨ÓëexeÎÄ¼þÔÚÒ»Æð£©£¬»òÕßÊäÈëÎÄ¼þµÄÍêÕûÂ·¾¶£¡" << endl;
getline(cin, File_Path);
File_Path = Change_File_Path(File_Path);
cout << "ÎÄ¼þÄ¿Â¼£º";
if (File_Path[1] == ':')
		cout << File_Path;
else
	{
		TCHAR szPath[MAX_PATH];
GetModuleFileName(NULL, szPath, MAX_PATH);
*(strrchr(szPath, '\\')) = '\0';
string strPath;
for (int n = 0;
 szPath[n];
 n++)
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
		cout << strPath << "\\\\" << File_Path;
}
	cout << endl;
}
ÿ