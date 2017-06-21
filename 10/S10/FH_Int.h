#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class FH_Int_Input
{

private:
	string Inputed;
	int OutPut;
	bool InputState;

public:
	int Start_Input();
	void Get_Error(exception e);
	bool Get_State();
	int Get_Int();
};

extern int GetIntMain();