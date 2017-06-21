#include "FH_Time.h"

Time::Time()
{
	StartTime = clock();
	EndTime = StartTime;
}

void Time::StartClock()
{
	StartTime = clock();
}

void Time::EndClock()
{
	EndTime = clock();
}

double Time::GetMicroSec(long long RepeatNum)
{
	clock_t Used = EndTime - StartTime;
	double TrueTime = (double)(Used) / CLOCKS_PER_SEC / RepeatNum * 1000000;
	return TrueTime;
}
