#include "FH_ChainTest.h"

void Man_Test()
{
	FH_Chain m_Chain;
	CreateNodeFromFile(m_Chain, "��������.txt");
	cout << "-----------------------------------\n";
	cout << "�����ۺ�ֵ��С����\n";
	cout << "˳��Ϊ\t����\t����\t����\t����\t����\t����\n";
	m_Chain.SortAll(AllSort);
	m_Chain.AllPutOut();
	cout << "-----------------------------------\n";
	cout << "��������ֵ��С����\n";
	cout << "˳��Ϊ\t����\t����\t����\t����\t����\t����\n";
	m_Chain.SortAll(PowerSort);
	m_Chain.AllPutOut();
}