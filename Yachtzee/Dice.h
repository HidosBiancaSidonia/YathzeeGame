#include <cstdint>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <array>

class Dice
{
public:

	Dice();
	//Rule of three
	Dice(const Dice& dice);
	Dice& operator =(const Dice& dice);
	~Dice(); //destructor

	std::vector<int8_t>& GetRolledDices();
	std::array<int8_t, 6>& GetKeptDices();
	int8_t operator[](int8_t i);
	uint8_t GetSizeOfArray();
	void RollDice(std::vector<int8_t>& m_rolledDices, uint8_t m_sizeOfArray);
	void DisplayDices(std::vector<int8_t> m_rolledDices);
	void Keep(std::vector<int8_t> m_rolledDices, std::array<int8_t, 6>& m_keptDices);

protected:
	std::vector<int8_t> m_rolledDices;
	std::array<int8_t, 6> m_keptDices;
	uint8_t m_sizeOfArray;
};