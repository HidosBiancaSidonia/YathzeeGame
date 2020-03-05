#pragma once
#include <cstdint>
#include <iostream>
#include <array>

class Diece
{
public:
	Diece(); //constructor
	~Diece(); //destructor
	std::array<uint8_t, 5> GetRolledDieces() const;
	std::array<uint8_t, 6> GetKeptDieces() const;
	uint8_t GetsizeOfArray() const;
	void RollDiece(std::array<uint8_t, 5>& m_rolledDieces, uint8_t m_sizeOfArray);
	void DisplayDices(std::array<uint8_t, 5> m_rolledDieces, uint8_t m_sizeOfArray);


private:
	std::array<uint8_t, 5> m_rolledDieces;
	std::array<uint8_t, 6> m_keptDieces;
	uint8_t m_sizeOfArray;

};

