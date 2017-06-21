#include "FH_Debug_Log.h"

string Class_State_Str[] = { "Have Not Been Newed",	"Have Been Newed",	"Have Been Newed And Deleted WithOut Any Error", "Have Been Deleted Without Newed", "Have Been Double Newed" };

FH_Debug_Log::FH_Debug_Log()
{
	FH_Debug_Log("Data.txt");
}

FH_Debug_Log::FH_Debug_Log(string Path) : filePath(Path)
{
}

FH_Debug_Log::~FH_Debug_Log()
{
	clear();
}

void FH_Debug_Log::clear()
{
	if (recordData && classStates.size() > 0)
	{
		int ErrorNum = 0;
		outStream.open(filePath, ios::out | ios::app);
		outStream << "-------------------------------------\n";
		map<int, Class_State>::iterator m_It;
		for (m_It = classStates.begin(); m_It != classStates.end(); m_It++)
		{
			outStream << m_It->first << " " << Class_State_Str[m_It->second] << "!\n";
			if (m_It->second != HaveDeleted)
				ErrorNum++;
		}
		outStream << "-------------------------------------\n";
		cout << "-------------------------------------\n";
		if (ErrorNum)
			cout << "Errors Num Is " << ErrorNum << endl;
		else
			cout << "Didn't Have Error Of New And Delete!" << endl;
		outStream.close();
	}
	classStates.clear();
}

#ifdef _DEBUG
bool recordData = true;
#else
bool recordData = false;
#endif // _DEBUG
