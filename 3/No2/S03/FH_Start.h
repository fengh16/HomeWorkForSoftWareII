#ifndef FH_START_H
#define FH_START_H
#include <iostream>
#include <vector>
using namespace std;

class Prime
{
public:
	Prime(int a, int b);
	~Prime();
	vector<int> Calculate();
	int getx();
	int gety();
private:
	int x, y;
};

#endif // !FH_START_H
