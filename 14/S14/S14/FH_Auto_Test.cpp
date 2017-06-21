#include "FH_Auto_Test.h"
#include "FH_ChainTest.h"

void Auto_Main()
{
	cout << "自动测试开始！" << endl;
	ofstream Auto_Out("Auto_Out.txt", ios::out | ios::trunc);
	// 保存cout流缓冲区指针  
	streambuf* coutBuf = cout.rdbuf();
	// 获取文件out.txt流缓冲区指针  
	streambuf* fileBuf = Auto_Out.rdbuf();
	// 设置cout流缓冲区指针为out.txt的流缓冲区指针  
	cout.rdbuf(fileBuf);

	Man_Test();

	Auto_Out.flush();
	Auto_Out.close();
	// 恢复cout原来的流缓冲区指针  
	cout.rdbuf(coutBuf);
	cout << "自动测试结束！" << endl;
	try
	{
		ifstream Auto_In("Auto_Ans.txt", ios::in);
		if (!Auto_In)
			throw(1);
		ifstream Check_In("Auto_Out.txt", ios::in);
		if (!Check_In)
			throw(1);
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
			cout << "自动测试结果正确！" << endl;
		}
		else
		{
			cout << "自动测试结果异常！" << endl;
		}
		cout << "结果已经保存在 Auto_Out.txt 文件中！" << endl;
	}
	catch (...)
	{
		cout << "读取文件有误!" << endl;
		char buffer[_MAX_PATH];
		buffer[0] = 0;
		if (_getcwd(buffer, _MAX_PATH) == NULL)
			cout << "无法读取当前路径!" << endl;
		else
		{
			cout << "当前路径是: " << buffer << endl;
		}
		return;
	}
}