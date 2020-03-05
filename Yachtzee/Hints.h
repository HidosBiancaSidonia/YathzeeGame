#include <iostream>
#include <array>

class Hints
{
public:
	Hints();
	Hints& operator=(const Hints& other);
	int Ones(std::array<int8_t, 6> m_keptDices);
	int Twos(std::array<int8_t, 6> m_keptDices);
	int Threes(std::array<int8_t, 6> m_keptDices);
	int Fours(std::array<int8_t, 6> m_keptDices);
	int Fives(std::array<int8_t, 6> m_keptDices);
	int Sixes(std::array<int8_t, 6> m_keptDices);
	int ThreeOfAKind(std::array<int8_t, 6> m_keptDices);
	int FourOfAKind(std::array<int8_t, 6> m_keptDices);
	int FullHouse(std::array<int8_t, 6> m_keptDices);
	int SmallStraight(std::array<int8_t, 6> m_keptDices);
	int LargeStraight(std::array<int8_t, 6> m_keptDices);
	int Chance(std::array<int8_t, 6> m_keptDices);
	int Yahtzee(std::array<int8_t, 6> m_keptDices);

protected:
	std::array<int8_t, 6> m_keptDices;
};

