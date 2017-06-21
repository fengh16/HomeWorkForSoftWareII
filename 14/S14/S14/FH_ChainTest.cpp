#include "FH_ChainTest.h"

void Man_Test()
{
	FH_Chain m_Chain;
	CreateNodeFromFile(m_Chain, "三国人物.txt");
	cout << "-----------------------------------\n";
	cout << "按照综合值大小排序：\n";
	cout << "顺序为\t名称\t体力\t智力\t武力\t魅力\t运气\n";
	m_Chain.SortAll(AllSort);
	m_Chain.AllPutOut();
	cout << "-----------------------------------\n";
	cout << "按照武力值大小排序：\n";
	cout << "顺序为\t名称\t体力\t智力\t武力\t魅力\t运气\n";
	m_Chain.SortAll(PowerSort);
	m_Chain.AllPutOut();
}