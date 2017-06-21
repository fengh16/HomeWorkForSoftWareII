#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

enum Class_State { NotNewed, HaveNewed, HaveDeleted, DeleteWithoutNew, DoubleNewed, ClassStateNum };

extern bool recordData;

class FH_Debug_Log
{
public:
	FH_Debug_Log();
	FH_Debug_Log(string Path);
	~FH_Debug_Log();
	template <typename T>
	FH_Debug_Log& operator <<(const T& data)
	{
		if (recordData)
		{
			outStream.open(filePath, ios::out | ios::app);
			outStream << data;
			outStream.close();
		}
		return(*this);
	}
	map<int, Class_State> classStates;
	void clear();

private:
	string filePath;
	ofstream outStream;
};

