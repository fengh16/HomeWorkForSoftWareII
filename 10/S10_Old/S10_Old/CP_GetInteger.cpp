#include <iostream>
using namespace std;
#include "CP_GetInteger.h"

int gb_getInteger()
{
	int result = 0;
	do
	{
		cout << "������һ������: " << endl;
		cin >> result;
		if (cin.good())
			break;
		else
		{
			if (cin.eof())
			{
				cout << "���뱻��ֹ�����������" << endl;
				break;
			} // if�ṹ����
			cout << "�����ʽ�������������롣";
			cin.clear(); // ���������״̬
			cin.sync(); // ������뻺����
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} // if-else�ṹ����
	} while (true); // do-while�ṹ����
	return result;
} // gb_getInteger��������