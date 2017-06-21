/**
* FH_Binary.cpp
*
* 包含类Binary，其中包含函数 void SetBi(double NewDouble) 和 void Print()
*
* 该文件进行上述类以及函数的具体实现
*
* 冯昊
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
* SetBi()函数，需要Binary类对象，可以设置该类对象的m_double变量
* 参数为要设置的double类变量，无返回值
* 冯昊 2017/05/13
*/
void Binary::SetBi(double NewDouble)
{
	m_double = NewDouble;
}

/**
* Print()函数，需要Binary类对象，需要先设置m_double变量（默认为0.0）， 可以输出该变量二进制表示形式
* 无参数，无返回值
* 冯昊 2017/05/13
*/
void Binary::Print()
{
	const int n = sizeof(double) * 8;
	int i;
	cout << "\t二进制表示为： \t(";
	for (i = 0; i < n; i++, m_in <<= 1)
	{
		cout << (m_in < 0 ? 1 : 0);
		if (i % 8 == 7)
			cout << " ";
	}
	cout << ")。" << endl;
}
