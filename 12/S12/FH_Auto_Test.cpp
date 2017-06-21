#include "FH_Auto_Test.h"

void Auto_Main()
{
	cout << "Auto Test Started!" << endl;
	ofstream Auto_Out("Auto_Out.txt", ios::out | ios::trunc);
	// 保存cout流缓冲区指针  
	streambuf* coutBuf = cout.rdbuf();
	// 获取文件out.txt流缓冲区指针  
	streambuf* fileBuf = Auto_Out.rdbuf();
	// 设置cout流缓冲区指针为out.txt的流缓冲区指针  
	cout.rdbuf(fileBuf);

	FH_Sort_Class SC;
	SC.Start();

	Auto_Out.flush();
	Auto_Out.close();
	// 恢复cout原来的流缓冲区指针  
	cout.rdbuf(coutBuf);
	cout << "Auto Test Ended!" << endl;
	try
	{
		ifstream Auto_In("Auto_Ans.txt", ios::in);
		if (!Auto_In)
			throw(NoSuchFile);
		ifstream Check_In("Auto_Out.txt", ios::in);
		if (!Check_In)
			throw(NoSuchFile);
		char a, b;
		while (!Auto_In.eof() && !Check_In.eof())
		{
			a = Auto_In.get();
			b = Check_In.get();
			if (a != b)
				break;
		}
		if (Auto_In.eof() && Check_In.eof())
		{
			cout << "The Progress Is Right!!" << endl;
		}
		else
		{
			cout << "There Is Something Wrong While Doing Auto Test!!" << endl;
		}
		cout << "The Ans Of Auto Test Is In Auto_Out.txt!" << endl;
	}
	catch (...)
	{
		cout << "There Is No Auto_Ans File!! Please Check That The File Is Put In The Same Directory As the EXE File!" << endl;
		TCHAR szPath[MAX_PATH];
		GetModuleFileName(NULL, szPath, MAX_PATH);
		*(strrchr(szPath, '\\')) = '\0';
#ifdef _DEBUG
		//不要少了_！！！！！！！！！！！！！！！
		*(strrchr(szPath, '\\')) = '\0';
		cout << "The File \"data.txt\" Need To Be Put In : ";
		for (int n = 0; szPath[n]; n++)
		{
			cout << szPath[n];
		}
		cout << "\\S12\\" << endl;
#else
		cout << "The File \"data.txt\" Need To Be Put In : ";
		for (int n = 0; szPath[n]; n++)
		{
			cout << szPath[n];
		}
		cout << "\\" << endl;
#endif // _DEBUG
	}
}