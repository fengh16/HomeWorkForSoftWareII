#include <iostream>
using namespace std;
#include "CP_GetInteger.h"

int main(int argc, char* args[])
{
	int i = gb_getInteger();
	cout << "输入的整数是: " << i << endl;
	return 0;
} // main函数结束