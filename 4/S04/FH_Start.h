#ifndef FH_START_H
#define FH_START_H
class Two_Num
{
public:
	Two_Num(long long m, long long n);
	~Two_Num();
	long long GetGreatestCommonFact();
	long long GetLeastCommonMulti();
private:
	long long a, b;
};

#endif