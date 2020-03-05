#include "Dice.h"

Dice::Dice()
{
	m_rolledDices.push_back(1);
	m_rolledDices.push_back(2);
	m_rolledDices.push_back(3);
	m_rolledDices.push_back(4);
	m_rolledDices.push_back(5);
	m_keptDices = { 0,0,0,0,0,0 };
	m_sizeOfArray = 5;
}

//Rule of three
Dice::Dice(const Dice& dice)
{
	*this = dice;
}

Dice::~Dice()
{
	m_rolledDices.clear();
	std::fill(std::begin(m_keptDices), std::end(m_keptDices), 0);
	m_sizeOfArray = 0;
}

Dice& Dice::operator=(const Dice& dice)
{
	m_rolledDices = dice.m_rolledDices;
	m_keptDices = dice.m_keptDices;
	m_sizeOfArray = dice.m_sizeOfArray;
	std::cout << "Copying object.";
	return *this;
}

std::vector<int8_t>& Dice::GetRolledDices()
{
	return m_rolledDices;
}

std::array<int8_t, 6>& Dice::GetKeptDices()
{
	return m_keptDices;
}

int8_t Dice::operator[](int8_t i)
{
	return m_keptDices[i];
}

uint8_t Dice::GetSizeOfArray()
{
	return m_sizeOfArray;
}

void Dice::RollDice(std::vector<int8_t>& m_rolledDices, uint8_t m_sizeOfArray)
{
	srand((uint8_t)time(0));
	m_rolledDices.clear();
	for (uint8_t index = 0; index < m_sizeOfArray; index++)
		m_rolledDices.push_back(rand() % 6 + 1);
}

void Dice::DisplayDices(std::vector<int8_t> m_rolledDices)
{
	for (auto iterator = m_rolledDices.begin(); iterator != m_rolledDices.end(); ++iterator)
		if (*iterator == 1)
		{
			std::cout << " -------" << '\n';
			std::cout << "|       |" << '\n';
			std::cout << "|   o   |" << '\n';
			std::cout << "|       |" << '\n';
			std::cout << " -------" << '\n';
		}
		else if (*iterator == 2)
		{
			std::cout << " -------" << '\n';
			std::cout << "|       |" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << "|       |" << '\n';
			std::cout << " -------" << '\n';
		}
		else if (*iterator == 3)
		{
			std::cout << " -------" << '\n';
			std::cout << "|o      |" << '\n';
			std::cout << "|   o   |" << '\n';
			std::cout << "|      o|" << '\n';
			std::cout << " -------" << '\n';
		}
		else if (*iterator == 4)
		{
			std::cout << " -------" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << "|       |" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << " -------" << '\n';
		}
		else if (*iterator == 5)
		{
			std::cout << " -------" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << "|   o   |" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << " -------" << '\n';
		}
		else if (*iterator == 6)
		{
			std::cout << " -------" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << "| o   o |" << '\n';
			std::cout << " -------" << '\n';
		}
}

void Dice::Keep(std::vector<int8_t> m_rolledDices, std::array<int8_t, 6>& m_keptDices)
{
	int contor = 0;
	for (auto iterator = m_rolledDices.begin(); iterator != m_rolledDices.end(); ++iterator)
	{
		contor = *iterator;
		m_keptDices[contor - 1]++;
	}
}