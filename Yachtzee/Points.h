#include <vector>
#include "Dice.h"

class Points
{
public:
	enum class TypesOfScore : uint8_t
	{
		One,
		Two,
		Three,
		Four,
		Five,
		Six,
		Sum,
		Bonus,
		ThreeOfKind,
		FourOfKind,
		Full,
		Small,
		Large,
		Chance,
		Yahtzee,
		Total
	};

public:
	Points();

	//Rule of 3
	Points(const Points& other);
	Points& operator=(const Points& other); //Rule of 3
	~Points();

	std::vector<int>& GetVectorUpperPoints();
	std::vector<int>& GetVectorLowerPoints();
	std::array<int8_t, 6>& GetKeptDices();
	std::array<bool, 16>& GetPossiblePlaces();
	void Ones(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void Twos(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void Threes(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void Fours(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void Fives(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void Sixes(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	int PartialSum(std::vector<int> m_upperPoints);
	int VerifyBonus(std::vector<int> m_upperPoints);
	void ThreeOfAKind(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void FourOfAKind(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void FullHouse(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void SmallStraight(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void LargeStraight(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void Chance(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	void Yachtzee(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints);
	int TotalScore(std::vector<int>& m_lowerPoints, std::vector<int> m_upperPoints);

protected:
	std::vector<int> m_upperPoints;
	std::vector<int>m_lowerPoints;
	std::array<int8_t, 6> m_keptDices;
	std::array<bool, 16> m_possiblePlacesForPoints;
};