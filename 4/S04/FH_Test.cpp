#include "FH_Test.h"
void Human_Test()
{
	long long m, n, CF, CM;
	long long RepeatTimeNow = 100000;
	cout << "------------------------------------------------------------" << endl << "�ֶ����Կ�ʼ����������������������������ʾ���Լ����ʱ�����(΢��)����С��������ʱ�����(΢��)��" << endl << "\tһ�������������ֱ��������һ�����ݼ��ɣ����صȴ�������ʾ��" << endl << "------------------------------------------------------------" << endl;
	while (1)
	{
		do
		{
			m = n = 0;
			cin >> n >> m;
			if (cin.good() && n > 0 && m > 0)
				break;
			cout << "����������������룡" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (1);
		Time MyTime;
		MyTime.StartClock();
		for(long long i = 0; i < RepeatTimeNow; i++)
		{
			Two_Num MyNums(m, n);
			CF = MyNums.GetGreatestCommonFact();
		}
		MyTime.EndClock();
		cout << CF << " " << MyTime.GetMicroSec(RepeatTimeNow) << endl;
		MyTime.StartClock();
		for (long long i = 0; i < RepeatTimeNow; i++)
		{
			Two_Num MyNums(m, n);
			CM = MyNums.GetLeastCommonMulti();
		}
		MyTime.EndClock();
		cout << CM << " " << MyTime.GetMicroSec(RepeatTimeNow) << endl;
		if (CM / m * CF != n)
			cout << "��Խ�磡��С�������������" << endl;
	}
}