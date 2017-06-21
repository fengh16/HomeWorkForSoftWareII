#include "FH_Auto_Test.h"
#include "FH_ChainTest.h"

void Auto_Main()
{
	cout << "�Զ����Կ�ʼ��" << endl;
	ofstream Auto_Out("Auto_Out.txt", ios::out | ios::trunc);
	// ����cout��������ָ��  
	streambuf* coutBuf = cout.rdbuf();
	// ��ȡ�ļ�out.txt��������ָ��  
	streambuf* fileBuf = Auto_Out.rdbuf();
	// ����cout��������ָ��Ϊout.txt����������ָ��  
	cout.rdbuf(fileBuf);

	Man_Test();

	Auto_Out.flush();
	Auto_Out.close();
	// �ָ�coutԭ������������ָ��  
	cout.rdbuf(coutBuf);
	cout << "�Զ����Խ�����" << endl;
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
			cout << "�Զ����Խ����ȷ��" << endl;
		}
		else
		{
			cout << "�Զ����Խ���쳣��" << endl;
		}
		cout << "����Ѿ������� Auto_Out.txt �ļ��У�" << endl;
	}
	catch (...)
	{
		cout << "��ȡ�ļ�����!" << endl;
		char buffer[_MAX_PATH];
		buffer[0] = 0;
		if (_getcwd(buffer, _MAX_PATH) == NULL)
			cout << "�޷���ȡ��ǰ·��!" << endl;
		else
		{
			cout << "��ǰ·����: " << buffer << endl;
		}
		return;
	}
}