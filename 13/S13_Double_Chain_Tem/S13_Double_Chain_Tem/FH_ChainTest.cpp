#include "FH_ChainTest.h"

void Man_Test()
{
	FH_Chain_Tem<HumanData> m_Chain;
	m_Chain.CreateNodeFromFile(m_Chain, "��������.txt");
	cout << "-----------------------------------\n";
	cout << "�����ۺ�ֵ��С����\n";
	cout << "˳��Ϊ\t����\t����\t����\t����\t����\t����\n";
	m_Chain.SortAll();
	m_Chain.AllPutOut();
}