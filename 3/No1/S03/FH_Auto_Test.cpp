#include "FH_Auto_Test.h"
#include <iostream>
using namespace std;
int Test[] = {	351,	68415,	-952,	-486,	0,		68,			564,		68,		15,		94, 6666 };
int Test2[] = { 15,		185,	-69,	15345,	99999,	INT_MAX,	INT_MIN,	25,		35,		68,	99 };
int ans[] = { -969831300, -969830706, 415642361, -1385467741, -969896203, -346368331, 1177652823, -969831305, -969831324, -969831369, -969826783 };
void PrintBit(_int32 i)
{
	int bits[32] = { 0 };
	unsigned int k = 1, m;
	for (int j = 0; j < 32; j++)
	{
		m = k & i;
		bits[31 - j] = (m == 0 ? 0 : 1);
		k *= 2;
	}
	for (int j = 0; j < 32; j++)
		printf("%d", bits[j]);
	cout << endl;
}
void AutoTest()
{
	cout << "���Կ�ʼ��" << endl << "******************************" << endl;
	int t = 0;
	for (int i = 0; i < sizeof(Test) / sizeof(int); i++)
	{
		Genetic TestUse(Test[i], Test2[i]);
		cout << "���ڲ��Ե� " << i + 1 << " �����ݣ�  " << Test[i] << "  ��  " << Test2[i] << "  �Ľ������Ϊ  " << TestUse.Calculate() << "  ������";
		if (TestUse.Calculate() == ans[i])
			cout << "��ȷ����ϸ������£�" << endl;
		else
		{
			cout << "������ϸ������£�" << endl;
			t++;
		}
		PrintBit(Test[i]);
		PrintBit(Test2[i]);
		PrintBit(TestUse.Calculate());
	}
	cout << "******************************" << endl;
	cout << "������" << sizeof(Test) / sizeof(int) << "�����ݣ�����" << t << "�����" << endl;
};