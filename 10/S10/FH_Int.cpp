#include "FH_Int.h"

int FH_Int_Input::Start_Input() throw (ios_base::failure, invalid_argument, int)
{
	InputState = true;
	cout << "\nPlease input an integer! Use \"*\" to show that the INPUT HAS ENDED!!\n" << endl;
	cin >> Inputed;
	for (int i = 0; i < Inputed.length(); i++)
	{
		if (Inputed[i] == '*')
			throw (0);
	}
	if (cin.bad())
		throw (ios_base::failure("Error: There is an INVALID INPUT!!"));
	if (Inputed.length() < 1)
		throw (invalid_argument("Error: Input NO NUM!!!"));
	if (Inputed.length() > 1 && Inputed[0] == '0')
		throw (invalid_argument("Error: Not GOOD positive NUM FORM!!!"));
	if (Inputed.length() > 1 && Inputed[0] == '-' && Inputed[1] == '0')
		throw (invalid_argument("Error: Not GOOD negtive NUM FORM!!!"));
	for (int i = 0; i < Inputed.length(); i++)
	{
		if ((Inputed[i] > '9' || Inputed[i] < '0') && !(Inputed[i] == '-' && i == 0))
			throw (invalid_argument("Error: INVALID CHAR!!"));
	}
	OutPut = atoi(Inputed.c_str());
	char check[100] = { 0 };
	int i;
	_itoa_s(OutPut, check, 10);
	for (i = 0; i < Inputed.length() && check[i] == Inputed[i]; i++);
	if (i != Inputed.length())
		throw (out_of_range("Error: OUT OF RANGE!!"));
	return OutPut;
}

void FH_Int_Input::Get_Error(exception e)
{
	InputState = false;
	cout << e.what() << endl;
}

bool FH_Int_Input::Get_State()
{
	return InputState;
}

int FH_Int_Input::Get_Int()
{
	return OutPut;
}

int GetIntMain()
{
	FH_Int_Input My_In;
	do
	{
		try
		{
			My_In.Start_Input();
		}
		catch (int m)
		{
			return 0;
		}
		catch (exception &e)
		{
			My_In.Get_Error(e);
		}
	} while (!My_In.Get_State());
	return My_In.Get_Int();
}