#ifndef CP_TIME_H
#define CP_TIME_H
#include <ctime>
#include <iostream>
using namespace std;

class Time
{
private:
	clock_t StartTime, EndTime;

public:
	Time();
	~Time() { }

public:
	void StartClock();
	void EndClock();
	double GetMicroSec(long long RepeatNum);
};

#endif