#include "FH_Chain.h"

FH_Chain::FH_Chain() : m_name(""), m_strength(0), m_intelligence(0), m_power(0), m_charisma(0), m_luck(0), m_previous(NULL), m_next(NULL)
{
}

FH_Chain::~FH_Chain()
{
	if (m_previous == NULL)
		return;
	m_previous->m_next = NULL;
	delete m_next;
}

FH_Chain & FH_Chain::operator[](int i)
{
	if (i == 0)
		return (*this);
	if (m_previous == NULL)
		return (*this);
	int k;
	FH_Chain* p;
	if (i >= 0)
	{
		for (k = 0, p = this; k < i; k++)
		{
			p = p->m_next;
		}
	}
	else
	{
		for (k = 0, p = this; k > i; k--)
		{
			p = p->m_previous;
		}
	}
	return(*p);
}

void FH_Chain::CreateNode()
{
	//如果没有数据
	if (m_previous == NULL)
	{
		m_previous = this;
		m_next = this;
		return;
	}
	FH_Chain* p = m_previous;
	m_previous = new FH_Chain;
	m_previous->m_next = this;
	p->m_next = m_previous;
	m_previous->m_previous = p;
}

void FH_Chain::DeleteNode(FH_Chain * p)
{
	if (m_previous == NULL)
		return;
	FH_Chain* q;
	//删除第一个记录
	if (p == this)
	{
		if (p->m_previous == this)
		{
			p->m_previous = NULL;
			return;
		}
		//否则删除第二个记录（先把第二个记录拷贝到第一个，之后删除第二个，防止之后调用该函数的元素被删除）
		CopySingleNode(*this, *(p->m_next));
		p = p->m_next;
	}
	for (q = m_next; ((q != p) && (q != this)); q = q->m_next);
	if (q == this || q != p)
		return;
	q = p->m_previous;
	q->m_next = p->m_next;
	q = p->m_next;
	q->m_previous = p->m_previous;
	p->m_previous = p;
	p->m_next = NULL; //其实没必要，因为在析构函数中会把p->previous->next设置为null
	delete p;
}

int FH_Chain::GetNodeNumber()
{
	if (m_previous == NULL)
		return 0;
	FH_Chain * p = this;
	int n = 0;
	do
	{
		n++;
		p = p->m_next;
	} while (p != this);
	return n;
}

void FH_Chain::AllPutOut()
{
	if (m_previous == NULL)
	{
		cout << "这是一个空链表！" << endl;
		return;
	}
	FH_Chain * p = this;
	do
	{
		cout << *p << endl;
		p = p->m_next;
	} while (p != this);
}

void FH_Chain::SwapWith(FH_Chain & destination, FH_Chain & source)
{
	FH_Chain temp;
	CopySingleNode(temp, source);
	CopySingleNode(source, destination);
	CopySingleNode(destination, temp);
	source.m_previous->m_next = &source;
	source.m_next->m_previous = &source;
	destination.m_previous->m_next = &destination;
	destination.m_next->m_previous = &destination;
	temp.m_next = NULL;
	temp.m_previous = NULL;
}

void FH_Chain::SortAll(SortType s)
{
	int AllNum = GetNodeNumber();
	for (int i = 0; i < AllNum; i++)
	{
		for (int j = AllNum - 1; j > i; j--)
		{
			if (s == PowerSort)
			{
				if ((*this)[j].m_power > (*this)[j - 1].m_power)
					SwapWith((*this)[j], (*this)[j - 1]);
			}
			else if (s == AllSort)
			{
				if((*this)[j].m_power + (*this)[j].m_charisma + (*this)[j].m_intelligence + (*this)[j].m_luck + (*this)[j].m_strength > (*this)[j - 1].m_power + (*this)[j - 1].m_charisma + (*this)[j - 1].m_intelligence + (*this)[j - 1].m_luck + (*this)[j - 1].m_strength)
					SwapWith((*this)[j], (*this)[j - 1]);
			}
		}
	}
}

void CopySingleNode(FH_Chain & destination, FH_Chain & source)
{
	destination.m_name = source.m_name;
	destination.m_strength = source.m_strength;
	destination.m_intelligence = source.m_intelligence;
	destination.m_power = source.m_power;
	destination.m_charisma = source.m_charisma;
	destination.m_luck = source.m_luck;
}

ostream & operator<<(ostream & stream, FH_Chain & myChain)
{
	if (myChain.m_previous == NULL)
	{
		stream << "空链表！" << endl;
		return stream;
	}
	stream << "\t" << myChain.m_name << "\t" << myChain.m_strength << "\t" << myChain.m_intelligence << "\t" << myChain.m_power << "\t" << myChain.m_charisma << "\t" << myChain.m_luck;
	return stream;
}

void CreateNodeFromFile(FH_Chain & r, string fileName)
{
	if (fileName == "")
		return;
	ifstream inFile(fileName, ios::in);
	if (!inFile.good())
	{
		cout << "读取文件有误!" << endl;
		char buffer[_MAX_PATH];
		buffer[0] = 0;
		if (_getcwd(buffer, _MAX_PATH) == NULL)
			cout << "无法读取当前路径!" << endl;
		else
		{
			cout << "当前路径是: " << buffer << endl;
		}
		return;
	}
	FH_Chain *p = NULL;
	string name;
	while (!inFile.eof())
	{
		inFile >> name;
		if (name[0] == '#')
			break;
		r.CreateNode();
		p = r.m_previous;
		p->m_name = name;
		inFile >> p->m_strength;
		inFile >> p->m_intelligence;
		inFile >> p->m_power;
		inFile >> p->m_charisma;
		inFile >> p->m_luck;
	}
	inFile.close();
}