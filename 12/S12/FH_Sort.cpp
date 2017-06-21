#include "FH_Sort.h"


FH_Sort_Class::FH_Sort_Class()
{
}

FH_Sort_Class::~FH_Sort_Class()
{
}

void FH_Sort_Class::Start()
{
	try
	{
		Read();
		Print();
	}
	catch (ErrorType &ET)
	{
		if (ET == NoSuchFile)
		{
			cout << "Didn't Find File \"data.txt\". Please Check That The File Is Put In The Same Directory As the EXE File!" << endl;
			TCHAR szPath[MAX_PATH];
			GetModuleFileName(NULL, szPath, MAX_PATH);
			*(strrchr(szPath, '\\')) = '\0';
#ifdef _DEBUG
			//不要少了_！！！！！！！！！！！！！！！
			*(strrchr(szPath, '\\')) = '\0';
			cout << "The File \"data.txt\" Need To Be Put In : ";
			for (int n = 0; szPath[n]; n++)
			{
				cout << szPath[n];
			}
			cout << "\\S12\\" << endl;
#else
			cout << "The File \"data.txt\" Need To Be Put In : ";
			for (int n = 0; szPath[n]; n++)
			{
				cout << szPath[n];
			}
			cout << "\\" << endl;
#endif // _DEBUG
		}
		else if (ET == NoThing)
			cout << "The File Contains NOTHING!" << endl;
		else if (ET == ErrorReading)
			cout << "There Is Something WRONG While Reading Data! Maybe The Data Is Out Of Range Of LONG LONG!" << endl;
	}
}

void FH_Sort_Class::Read() throw(ErrorType)
{
	ifstream In("data.txt", ios::in);
	if (!In)
	{
		throw(NoSuchFile);
	}
	m_Vec.clear();
	m_Set.clear();
	long long temp;
	while (!In.eof())
	{
		In >> temp;
		if (In.bad())
			throw(ErrorReading);
		m_Vec.push_back(temp);
		m_Set.insert(temp);
	}
}

void FH_Sort_Class::Print() throw(ErrorType)
{
	if (m_Vec.empty())
		throw(NoThing);
	sort(m_Vec.begin(), m_Vec.end());
	cout << "VectorSort:\n";
	for (int i = 0; i < m_Vec.size(); i++)
	{
		cout << "[" << i << "]: " << m_Vec[i];
		if (i < m_Vec.size() - 1)
			cout << ", ";
	}
	cout << endl;
	cout << "SetSort:\n";
	set<long long>::iterator S_It = m_Set.begin();
	for (int i = 0; i < m_Set.size(); i++, S_It++)
	{
		cout << "[" << i << "]: " << *S_It;
		if (i < m_Set.size() - 1)
			cout << ", ";
	}
	cout << endl;
}

