/**
* FH_Binary.cpp
*
* ������Binary�����а������� void SetBi(double NewDouble) �� void Print()
*
* ���ļ������������Լ������ľ���ʵ��
*
* ���
*
* V1.0  2017/05/13
*
* CopyRight 2017
*/

#include "FH_Binary.h"

Binary::Binary() :m_double(0)
{
}

Binary::~Binary()
{
}

/**
* SetBi()��������ҪBinary����󣬿������ø�������m_double����
* ����ΪҪ���õ�double��������޷���ֵ
* ��� 2017/05/13
*/
void Binary::SetBi(double NewDouble)
{
	m_double = NewDouble;
}

/**
* Print()��������ҪBinary�������Ҫ������m_double������Ĭ��Ϊ0.0���� ��������ñ��������Ʊ�ʾ��ʽ
* �޲������޷���ֵ
* ��� 2017/05/13
*/
void Binary::Print()
{
	const int n = sizeof(double) * 8;
	int i;
	cout << "\t�����Ʊ�ʾΪ�� \t(";
	for (i = 0; i < n; i++, m_in <<= 1)
	{
		cout << (m_in < 0 ? 1 : 0);
		if (i % 8 == 7)
			cout << " ";
	}
	cout << ")��" << endl;
}
