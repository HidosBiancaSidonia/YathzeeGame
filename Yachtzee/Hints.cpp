#include "Hints.h"

Hints::Hints()
{
	//empty
}

Hints& Hints::operator=(const Hints& other)
{
	m_keptDices = other.m_keptDices;
	return *this;
}

int Hints::Ones(std::array<int8_t, 6> m_keptDices)
{
	return m_keptDices[0];
}

int Hints::Twos(std::array<int8_t, 6> m_keptDices)
{
	return m_keptDices[1] * 2;
}

int Hints::Threes(std::array<int8_t, 6> m_keptDices)
{
	return m_keptDices[2] * 3;
}

int Hints::Fours(std::array<int8_t, 6> m_keptDices)
{
	return m_keptDices[3] * 4;
}

int Hints::Fives(std::array<int8_t, 6> m_keptDices)
{
	return m_keptDices[4] * 5;
}

int Hints::Sixes(std::array<int8_t, 6> m_keptDices)
{
	return m_keptDices[5] * 6;
}

int Hints::ThreeOfAKind(std::array<int8_t, 6> m_keptDices)
{
	bool verifyThreeOfAKind = false;
	int sumOfDices = 0;
	for (uint8_t index = 0; index < 6; index++)
	{
		sumOfDices += m_keptDices[index] * (index + 1);
		if (m_keptDices[index] >= 3)
			verifyThreeOfAKind = true;
	}
	if (verifyThreeOfAKind == true)
		return sumOfDices;
	return 0;
}

int Hints::FourOfAKind(std::array<int8_t, 6> m_keptDices)
{
	bool verifyFourOfAKind = false;
	int sumOfDices = 0;
	for (uint8_t index = 0; index < 6; index++)
	{
		sumOfDices += m_keptDices[index] * (index + 1);
		if (m_keptDices[index] >= 4)
			verifyFourOfAKind = true;
	}
	if (verifyFourOfAKind == true)
		return sumOfDices;
	return 0;
}

int Hints::FullHouse(std::array<int8_t, 6> m_keptDices)
{
	bool verifyThree = false, verifyTwo = false;
	for (uint8_t index = 0; index < 6; index++)
		if (m_keptDices[index] == 3)
			verifyThree = true;
		else if (m_keptDices[index] == 2)
			verifyTwo = true;

	if (verifyThree == true && verifyTwo == true)
		return 25;
	return 0;
}

int Hints::SmallStraight(std::array<int8_t, 6> m_keptDices)
{
	if ((m_keptDices[0] >= 1 && m_keptDices[1] >= 1 && m_keptDices[2] >= 1 && m_keptDices[3] >= 1) ||
		(m_keptDices[1] >= 1 && m_keptDices[2] >= 1 && m_keptDices[3] >= 1 && m_keptDices[4] >= 1) ||
		(m_keptDices[2] >= 1 && m_keptDices[3] >= 1 && m_keptDices[4] >= 1 && m_keptDices[5] >= 1))
		return 30;
	return 0;
}

int Hints::LargeStraight(std::array<int8_t, 6> m_keptDices)
{
	if ((m_keptDices[0] == 1 && m_keptDices[1] == 1 && m_keptDices[2] == 1 && m_keptDices[3] == 1 && m_keptDices[4] == 1) ||
		(m_keptDices[1] == 1 && m_keptDices[2] == 1 && m_keptDices[3] == 1 && m_keptDices[4] == 1 && m_keptDices[5] == 1))
		return 40;
	return 0;
}

int Hints::Chance(std::array<int8_t, 6> m_keptDices)
{
	int sumOfDices = 0;
	for (int i = 0; i < 6; i++)
		sumOfDices += m_keptDices[i] * (i + 1);
	return sumOfDices;
}

int Hints::Yahtzee(std::array<int8_t, 6> m_keptDices)
{
	bool verifyYahtzee = false;
	for (auto iterator = m_keptDices.begin(); iterator != m_keptDices.end(); ++iterator)
		if (*iterator == 5)
			verifyYahtzee = true;
	if (verifyYahtzee == true)
		return 50;
	return 0;
}
