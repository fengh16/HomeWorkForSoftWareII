/**
* FH_Main.cpp
*
* ��������main()
*
* ���ļ��������������ľ���ʵ��
*
* ���
*
* V1.0  2017/05/13
*
* CopyRight 2017
*/

#include "FH_Binary.h"

/**
* main()��������ҪBinary��
* �޲���������ֵΪ����
* ��� 2017/05/13
*/
int main()
{
	//����������
	Binary my_bi;
	double A[8] = { 0.0,	1.0,		-1.0,		+0.0,	-0.0,	0.1,	2.3,	-4.5 };
	double B[8] = { 0.0,	0.0,		0.0,		1.0,	1.0,	1.0,	1.0,	1.0 };
	string NumsStr[8] = { "����",	"������",	"������",	"+0.0",	"-0.0",	"0.1",	"2.3",	"-4.5" };

	double d;
	for (int i = 0; i < 8; i++)
	{
		my_bi.SetBi(A[i] / B[i]);
		cout << NumsStr[i];
		my_bi.Print();
	}
	system("pause");
	cout << "������һ��ʵ���� \n";
	cin >> d;
	my_bi.SetBi(d);
	cout << d << " ";
	my_bi.Print();
	system("pause");
	return 0;
}