#include "FH_Auto_Test.h"
#include "FH_Man_Test.h"

int main()
{
	char ch;
do
	{
		do
		{
			cout << "------------------------------------------------------------" << endl;
cout << "ÊäÈë  1  ½øÐÐÊÖ¶¯²âÊÔ£¬ÊäÈë  2  ½øÐÐ×Ô¶¯²âÊÔ£¡" << endl;
cout << "------------------------------------------------------------" << endl;
ch = getchar();
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
} while (ch != '1' && ch != '2');
if (ch == '1')
		{
			Man_Test();
}
		else if (ch == '2')
		{
			Auto_Test();
system("pause");
}
	} while (1);
return 0;
}
ÿ