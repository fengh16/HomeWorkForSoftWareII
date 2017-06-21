#pragma once

#include "FH_Chain_Tem.h"

class HumanData
{
private:
	int m_strength;
	int m_intelligence;
	int m_power;
	int m_charisma;
	int m_luck;

public:
	HumanData()
	{
	}

	~HumanData()
	{
	}

	HumanData(const HumanData& temp)
	{
		m_strength = temp.m_strength;
		m_intelligence = temp.m_intelligence;
		m_power = temp.m_power;
		m_charisma = temp.m_charisma;
		m_luck = temp.m_luck;
	}

	bool operator < (HumanData & Right)
	{
		if (m_strength + m_intelligence + m_power + m_charisma + m_luck < Right.m_strength + Right.m_intelligence + Right.m_power + Right.m_charisma + Right.m_luck)
			return true;
		return false;
	}

	bool operator > (HumanData & Right)
	{
		if (m_strength + m_intelligence + m_power + m_charisma + m_luck > Right.m_strength + Right.m_intelligence + Right.m_power + Right.m_charisma + Right.m_luck)
			return true;
		return false;
	}

	friend ostream & operator << (ostream & stream, HumanData & myChain)
	{
		stream << myChain.m_strength << "\t" << myChain.m_intelligence << "\t" << myChain.m_power << "\t" << myChain.m_charisma << "\t" << myChain.m_luck;
		return stream;
	}

	friend istream & operator >> (istream & stream, HumanData & myChain)
	{
		stream >> myChain.m_strength >> myChain.m_intelligence >> myChain.m_power >> myChain.m_charisma >> myChain.m_luck;
		return stream;
	}
};

