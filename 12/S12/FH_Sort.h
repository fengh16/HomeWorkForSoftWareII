#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Windows.h>

using namespace std;

enum ErrorType { NoSuchFile, NoThing, ErrorReading };

class FH_Sort_Class
{
private:
	vector<long long> m_Vec;
	set<long long> m_Set;
	void Read();
	void Print();

public:
	FH_Sort_Class();
	~FH_Sort_Class();
	void Start();
};
