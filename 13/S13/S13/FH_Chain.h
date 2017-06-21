#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <direct.h>
using namespace std;

enum SortType { PowerSort, AllSort, SortTypeNum };

class FH_Chain
{
private:
	string m_name;
	int m_strength;
	int m_intelligence;
	int m_power;
	int m_charisma;
	int m_luck;
	FH_Chain * m_previous; //ø’¡¥±Ìm_previous==NULL
	FH_Chain * m_next;

public:
	FH_Chain();
	~FH_Chain();

	FH_Chain & operator [ ] (int i);

	void CreateNode();
	void DeleteNode(FH_Chain * p);
	int  GetNodeNumber();
	void AllPutOut();
	void SwapWith(FH_Chain & destination, FH_Chain & source);
	void SortAll(SortType s);

	friend void CopySingleNode(FH_Chain & destination, FH_Chain & source);
	friend void CreateNodeFromFile(FH_Chain & r, string fileName);
	friend ostream & operator << (ostream & stream, FH_Chain & myChain);
};

extern void CopySingleNode(FH_Chain & destination, FH_Chain & source);
extern void CreateNodeFromFile(FH_Chain & r, string fileName);