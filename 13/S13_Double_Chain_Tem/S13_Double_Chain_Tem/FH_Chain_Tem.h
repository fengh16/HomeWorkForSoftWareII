#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <direct.h>
using namespace std;

template <class Data>
class FH_Chain_Tem;

class HumanData;
ostream & operator << (ostream & stream, HumanData & myChain);
istream & operator >> (istream & stream, HumanData & myChain);

template<class Data>
ostream & operator << (ostream & stream, FH_Chain_Tem<Data> & myChain);
//����������ʵ�֣���������������������������������������������������������������������������������

template <class Data>
class FH_Chain_Tem
{
private:
	Data m_data;
	string m_name;
	FH_Chain_Tem<Data> * m_previous; //������m_previous==NULL
	FH_Chain_Tem<Data> * m_next;

public:
	static void CopySingleNode(FH_Chain_Tem<Data> & destination, FH_Chain_Tem<Data> & source)
	{
		destination.m_data = source.m_data;
	}

	static void CreateNodeFromFile(FH_Chain_Tem<Data> & r, string fileName)
	{
		if (fileName == "")
			return;
		ifstream inFile(fileName, ios::in);
		if (!inFile.good())
		{
			cout << "��ȡ�ļ�����!" << endl;
			char buffer[_MAX_PATH];
			buffer[0] = 0;
			if (_getcwd(buffer, _MAX_PATH) == NULL)
				cout << "�޷���ȡ��ǰ·��!" << endl;
			else
			{
				cout << "��ǰ·����: " << buffer << endl;
			}
			return;
		}
		FH_Chain_Tem<Data> *p = NULL;
		string name;
		while (!inFile.eof())
		{
			inFile >> name;
			if (name[0] == '#')
				break;
			r.CreateNode();
			p = r.m_previous;
			p->m_name = name;
			inFile >> p->m_data;
		}
		inFile.close();
	}


	FH_Chain_Tem<Data>() : m_previous(NULL), m_next(NULL)
	{
	}

	~FH_Chain_Tem<Data>()
	{
		if (m_previous == NULL)
			return;
		m_previous->m_next = NULL;
		delete m_next;
	}


	FH_Chain_Tem<Data> & operator [ ] (int i)
	{
		if (i == 0)
			return (*this);
		if (m_previous == NULL)
			return (*this);
		int k;
		FH_Chain_Tem<Data>* p;
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

	void CreateNode()
	{
		//���û������
		if (m_previous == NULL)
		{
			m_previous = this;
			m_next = this;
			return;
		}
		FH_Chain_Tem* p = m_previous;
		m_previous = new FH_Chain_Tem;
		m_previous->m_next = this;
		p->m_next = m_previous;
		m_previous->m_previous = p;
	}

	void DeleteNode(FH_Chain_Tem<Data> * p)
	{
		if (m_previous == NULL)
			return;
		FH_Chain_Tem<Data>* q;
		//ɾ����һ����¼
		if (p == this)
		{
			if (p->m_previous == this)
			{
				p->m_previous = NULL;
				return;
			}
			//����ɾ���ڶ�����¼���Ȱѵڶ�����¼��������һ����֮��ɾ���ڶ�������ֹ֮����øú�����Ԫ�ر�ɾ����
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
		p->m_next = NULL; //��ʵû��Ҫ����Ϊ�����������л��p->previous->next����Ϊnull
		delete p;
	}

	int GetNodeNumber()
	{
		if (m_previous == NULL)
			return 0;
		FH_Chain_Tem<Data> * p = this;
		int n = 0;
		do
		{
			n++;
			p = p->m_next;
		} while (p != this);
		return n;
	}

	friend ostream & operator << (ostream & stream, FH_Chain_Tem<Data> & myChain)
	{
		if (myChain.m_previous == NULL)
		{
			stream << "������" << endl;
			return stream;
		}
		stream << "\t" << myChain.m_name << "\t" << myChain.m_data;
		return stream;
	}

	void AllPutOut()
	{
		if (m_previous == NULL)
		{
			cout << "����һ��������" << endl;
			return;
		}
		FH_Chain_Tem<Data> * p = this;
		do
		{
			cout << *p << endl;
			p = p->m_next;
		} while (p != this);
	}

	void SwapWith(FH_Chain_Tem<Data> & destination, FH_Chain_Tem<Data> & source)
	{
		FH_Chain_Tem<Data> temp;
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

	void SortAll()
	{
		int AllNum = GetNodeNumber();
		for (int i = 0; i < AllNum; i++)
		{
			for (int j = AllNum - 1; j > i; j--)
			{
				if ((*this)[j].m_data > (*this)[j - 1].m_data)
					SwapWith((*this)[j], (*this)[j - 1]);
			}
		}
	}

};
