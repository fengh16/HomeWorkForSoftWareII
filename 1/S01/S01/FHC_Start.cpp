#include <iostream>
using namespace std;
#include "FHC_Start.h"

void FHC_Start::outStart()
{
	do
	{
		n = 0;
		cout << "������������n:" << endl;
		cin >> n;
		cout << "�����n�ǣ�" << n << endl;
		//������ջ�����
		if (cin.eof() || cin.bad())
		{ // ����û������ļ�������־�����ļ��ѱ����꣩��
		  // ���߷�����д�������˳�ѭ��

		  // do something
			break;
		}
		// �����Ƿ��ַ��������������ڳ���״̬��
		// Ϊ�˼�����ȡ���룬����Ҫ���� clear ����
		// ������������Ĵ����ǣ�Ȼ����ܵ���
		// ignore ����������������е����ݡ�
		cin.clear();
		// numeric_limits<streamsize>::max() �������뻺��Ĵ�С��
		// ignore �����ڴ˽����������е�������ա�
		// �����������ľ����÷���������в�ѯ��
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (n <= 0);
	unsigned long t;
	for (t = 0, ans1 = 0; t <= n; t += 2)
		ans1 += t;
	cout << "��һ�ַ�����������" << ans1 << endl;
	ans2 = (unsigned long long)(n / 2 + 1) * (n / 2);
	//�����Ƚ���ǿ������ת��
	cout << "�ڶ��ַ�����������" << ans2 << endl;
}