#include "Points.h"

Points::Points()
{
	m_upperPoints.reserve(6);
	m_lowerPoints.reserve(7);
	Dice d;
	m_keptDices = d.GetKeptDices();
}

//Rule of 3
Points::Points(const Points& other)
{
	*this = other;
}

Points& Points::operator=(const Points& other)
{
	m_upperPoints = other.m_upperPoints;
	m_lowerPoints = other.m_lowerPoints;
	m_keptDices = other.m_keptDices;
	m_possiblePlacesForPoints = other.m_possiblePlacesForPoints;
	std::cout << "Copying object.";
	return *this;
}

Points::~Points()
{
	m_upperPoints.clear();
	m_lowerPoints.clear();
}

std::vector<int>& Points::GetVectorUpperPoints()
{
	return m_upperPoints;
}

std::vector<int>& Points::GetVectorLowerPoints()
{
	return m_lowerPoints;
}

std::array<int8_t, 6>& Points::GetKeptDices()
{
	return m_keptDices;
}

std::array<bool, 16>& Points::GetPossiblePlaces()
{
	return m_possiblePlacesForPoints;
}

void Points::Ones(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	m_upperPoints.push_back(m_keptDices[static_cast<int>(TypesOfScore::One)]);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::One)] = true;
}

void Points::Twos(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	m_upperPoints.push_back(m_keptDices[static_cast<int>(TypesOfScore::Two)] * 2);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Two)] = true;
}

void Points::Threes(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	m_upperPoints.push_back(m_keptDices[static_cast<int>(TypesOfScore::Three)] * 3);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Three)] = true;
}

void Points::Fours(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	m_upperPoints.push_back(m_keptDices[static_cast<int>(TypesOfScore::Four)] * 4);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Four)] = true;
}

void Points::Fives(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	m_upperPoints.push_back(m_keptDices[static_cast<int>(TypesOfScore::Five)] * 5);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Five)] = true;
}

void Points::Sixes(std::vector<int>& m_upperPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	m_upperPoints.push_back(m_keptDices[static_cast<int>(TypesOfScore::Six)] * 6);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Six)] = true;

}

int Points::PartialSum(std::vector<int> m_upperPoints)
{
	int sumOfUpperPoints = 0;
	for (auto iterator = m_upperPoints.begin(); iterator != m_upperPoints.end(); ++iterator)
		sumOfUpperPoints += *iterator;
	return sumOfUpperPoints;
}

int Points::VerifyBonus(std::vector<int> m_upperPoints)
{
	if (PartialSum(m_upperPoints) >= 63)
		return 35;
	return 0;
}

void Points::ThreeOfAKind(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
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
		m_lowerPoints.push_back(sumOfDices);
	else
		m_lowerPoints.push_back(0);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::ThreeOfKind)] = true;
}

void Points::FourOfAKind(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
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
		m_lowerPoints.push_back(sumOfDices);
	else
		m_lowerPoints.push_back(0);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::FourOfKind)] = true;
}

void Points::FullHouse(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	bool verifyThree = false, verifyTwo = false;
	for (uint8_t index = 0; index < 6; index++)
		if (m_keptDices[index] == 3)
			verifyThree = true;
		else if (m_keptDices[index] == 2)
			verifyTwo = true;

	if (verifyThree == true && verifyTwo == true)
		m_lowerPoints.push_back(25);
	else
		m_lowerPoints.push_back(0);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Full)] = true;
}

void Points::SmallStraight(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	if ((m_keptDices[0] >= 1 && m_keptDices[1] >= 1 && m_keptDices[2] >= 1 && m_keptDices[3] >= 1) ||
		(m_keptDices[1] >= 1 && m_keptDices[2] >= 1 && m_keptDices[3] >= 1 && m_keptDices[4] >= 1) ||
		(m_keptDices[2] >= 1 && m_keptDices[3] >= 1 && m_keptDices[4] >= 1 && m_keptDices[5] >= 1))
		m_lowerPoints.push_back(30);
	else
		m_lowerPoints.push_back(0);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Small)] = true;
}

void Points::LargeStraight(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	if ((m_keptDices[0] == 1 && m_keptDices[1] == 1 && m_keptDices[2] >= 1 && m_keptDices[3] == 1 && m_keptDices[4] == 1) ||
		(m_keptDices[1] == 1 && m_keptDices[2] == 1 && m_keptDices[3] >= 1 && m_keptDices[4] == 1 && m_keptDices[5] == 1))
		m_lowerPoints.push_back(40);
	else
		m_lowerPoints.push_back(0);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Large)] = true;
}

void Points::Chance(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	int sumOfDices = 0;
	for (int i = 0; i < 6; i++)
		sumOfDices += m_keptDices[i] * (i + 1);
	m_lowerPoints.push_back(sumOfDices);
	m_possiblePlacesForPoints[int(TypesOfScore::Chance)] = true;
}

void Points::Yachtzee(std::vector<int>& m_lowerPoints, std::array<int8_t, 6> m_keptDices, std::array<bool, 16>& m_possiblePlacesForPoints)
{
	bool verifyYahtzee = false;
	for (auto iterator = m_keptDices.begin(); iterator != m_keptDices.end(); ++iterator)
		if (*iterator == 5)
			verifyYahtzee = true;
	if (verifyYahtzee == true)
		m_lowerPoints.push_back(50);
	else
		m_lowerPoints.push_back(0);
	m_possiblePlacesForPoints[static_cast<int>(TypesOfScore::Yahtzee)] = true;

}

int Points::TotalScore(std::vector<int>& m_lowerPoints, std::vector<int> m_upperPoints)
{
	int sumOfLowerPoints = 0;
	for (auto iterator = m_lowerPoints.begin(); iterator != m_lowerPoints.end(); ++iterator)
		sumOfLowerPoints += *iterator;
	sumOfLowerPoints = sumOfLowerPoints + PartialSum(m_upperPoints) + VerifyBonus(m_upperPoints);
	return sumOfLowerPoints;
}