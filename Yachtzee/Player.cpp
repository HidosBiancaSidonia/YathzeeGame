#include "Player.h"

Player::Player(const std::string& name) : m_name(name)
{
	Dice d;
	Points p;
	m_keptDiceforPoints = d.GetKeptDices();
	m_rollDices = d.GetRolledDices();
	m_possiblePlacesForPoints = p.GetPossiblePlaces();
	m_lowerPoints = p.GetVectorLowerPoints();
	m_upperPoints = p.GetVectorUpperPoints();
	m_numberOfDices = d.GetSizeOfArray();
}

//Rule of three
Player::Player(const Player& player)
{
	*this = player;
}

Player Player::operator=(const Player& player)
{
	m_name = player.m_name;
	m_keptDiceforPoints = player.m_keptDiceforPoints;
	m_rollDices = player.m_rollDices;
	m_possiblePlacesForPoints = player.m_possiblePlacesForPoints;
	m_upperPoints = player.m_upperPoints;
	m_lowerPoints = player.m_lowerPoints;
	m_numberOfDices = player.m_numberOfDices;
	indexOfOption = player.indexOfOption;
	std::cout << "Copying object.";
	return *this;
}

Player::~Player()
{
	m_name.clear();
	std::fill(std::begin(m_keptDiceforPoints), std::end(m_keptDiceforPoints), 0);
	m_rollDices.clear();
	std::fill(std::begin(m_possiblePlacesForPoints), std::end(m_possiblePlacesForPoints), 0);
	m_upperPoints.clear();
	m_lowerPoints.clear();
	m_numberOfDices = 0;
	indexOfOption = 0;
}


void Player::DisplayOptions()
{
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::One)] == false)
		std::cout << "1. Ones" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Two)] == false)
		std::cout << "2. Twos" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Three)] == false)
		std::cout << "3. Threes" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Four)] == false)
		std::cout << "4. Fours" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Five)] == false)
		std::cout << "5. Fives" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Six)] == false)
		std::cout << "6. Sixes" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::ThreeOfKind)] == false)
		std::cout << "9. Three of a kind" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::FourOfKind)] == false)
		std::cout << "10. Four of a kind" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Full)] == false)
		std::cout << "11. Full house" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Small)] == false)
		std::cout << "12. Small Straight" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Large)] == false)
		std::cout << "13. Large Straight" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Chance)] == false)
		std::cout << "14. Chance" << '\n';
	if (m_possiblePlacesForPoints[int(Points::TypesOfScore::Yahtzee)] == false)
		std::cout << "15. Yahtzee" << '\n';
}

void Player::DisplayKeptDices()
{
	for (int i = 0; i < 6; i++)
		if (m_keptDiceforPoints[i] != 0)
			for (int j = 0; j < m_keptDiceforPoints[i]; j++)
				std::cout << "Index of kept dice is " << i << " and the dice is " << i + 1 << '\n';
}

void Player::PlacePoints(int indexOfOption)
{
	Points p;
	bool chooseCorrect = false;
	do {
		if (indexOfOption == 1 && m_possiblePlacesForPoints[int(Points::TypesOfScore::One)] == false)
		{
			p.Ones(m_upperPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 2 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Two)] == false)
		{
			p.Twos(m_upperPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 3 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Three)] == false)
		{
			p.Threes(m_upperPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 4 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Four)] == false)
		{
			p.Fours(m_upperPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 5 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Five)] == false)
		{
			p.Fives(m_upperPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 6 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Six)] == false)
		{
			p.Sixes(m_upperPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 9 && m_possiblePlacesForPoints[int(Points::TypesOfScore::ThreeOfKind)] == false)
		{
			p.ThreeOfAKind(m_lowerPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 10 && m_possiblePlacesForPoints[int(Points::TypesOfScore::FourOfKind)] == false)
		{
			p.FourOfAKind(m_lowerPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 11 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Full)] == false)
		{
			p.FullHouse(m_lowerPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 12 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Small)] == false)
		{
			p.SmallStraight(m_lowerPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 13 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Large)] == false)
		{
			p.LargeStraight(m_lowerPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 14 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Chance)] == false)
		{
			p.Chance(m_lowerPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		else if (indexOfOption == 15 && m_possiblePlacesForPoints[int(Points::TypesOfScore::Yahtzee)] == false)
		{
			p.Yachtzee(m_lowerPoints, m_keptDiceforPoints, m_possiblePlacesForPoints);
			chooseCorrect = true;
		}
		if (chooseCorrect == false)
		{
			std::cout << "*INVALID OPTION!**" << '\n';
			std::cin >> indexOfOption;
		}
	} while (chooseCorrect == false);
}

void Player::ChooseOption(TypesOfOptionsForPlayer option)
{
	switch (option)
	{
	case TypesOfOptionsForPlayer::KeepDices:
	{
		int numberOfDices;
		int indexOfDice;
		std::cout << "How many dices do you want to keep?" << "   ";
		std::cin >> numberOfDices;

		if (numberOfDices > m_numberOfDices)
		{
			do
			{
				std::cout << "**YOU ARE TRYING TO KEEP MORE DICES THAN YOU HAVE!**" << '\n';
				std::cin >> numberOfDices;
			} while (numberOfDices > m_numberOfDices);
		}

		std::cout << "Please write the index of the dices you want to keep." << '\n';
		std::cout << '\n';
		for (int index = 0; index < numberOfDices; index++)
		{
			std::cout << "Dice " << index + 1 << " ";
			std::cin >> indexOfDice;

			if (indexOfDice > m_numberOfDices)
			{
				do
				{
					std::cout << "**NO SUCH INDEX! PLEASE SELECT INDEXES BETWEEN 1 AND " << static_cast<int>(m_numberOfDices) << " !**" << '\n';
					std::cin >> indexOfDice;
				} while (indexOfDice > 5);
			}

			int8_t x = m_rollDices.at(indexOfDice - 1);
			m_rollDices[indexOfDice - 1] = 0;
			m_keptDiceforPoints[x - 1]++;
		}
		m_numberOfDices = m_numberOfDices - numberOfDices;

	}
	break;
	case TypesOfOptionsForPlayer::RollDices:
	{
		Dice d;
		d.RollDice(m_rollDices, m_numberOfDices);
		d.DisplayDices(m_rollDices);
	}
	break;
	case TypesOfOptionsForPlayer::ChoosePointsOption:
	{
		for (auto iterator = m_rollDices.begin(); iterator != m_rollDices.end(); ++iterator)
			if (*iterator != 0)
				m_keptDiceforPoints[*iterator - 1]++;

		std::cout << "Your possible places for displaying the points are:" << '\n';
		DisplayOptions();
		std::cout << '\n' << "Please type the index where you want to place your points: ";
		std::cin >> indexOfOption;
		PlacePoints(indexOfOption);
		m_numberOfDices = 5;
		std::fill(std::begin(m_keptDiceforPoints), std::end(m_keptDiceforPoints), 0);
	}
	break;
	case TypesOfOptionsForPlayer::ReleaseDices:
		int numberOfDices;
		int indexOfDice;
		DisplayKeptDices();
		std::cout << "How many dices do you want to release?" << "   ";
		std::cin >> numberOfDices;
		if (numberOfDices > 5 - m_numberOfDices)
			do
			{
				std::cout << "**YOU DON'T HAVE " << numberOfDices << " DICES TO RELEASE!**" << '\n';
				std::cout << "Please write how many dices do you want to release: ";
				std::cin >> numberOfDices;
			} while (numberOfDices > 5 - m_numberOfDices);
			m_numberOfDices = m_numberOfDices + numberOfDices;
			m_rollDices.resize(m_rollDices.size() + numberOfDices);
			std::cout << "Insert the index of the dices you want to release: ";
			std::cout << '\n';
			for (int index = 0; index < numberOfDices; index++)
			{
				std::cout << "Dice " << index + 1 << " ";
				std::cin >> indexOfDice;
				if (m_keptDiceforPoints[indexOfDice] == 0)
				{
					do
					{
						std::cout << "**INVALID INDEX!**" << '\n';
						std::cout << "Please insert a correct index: ";
						std::cin >> indexOfDice;
					} while (m_keptDiceforPoints[indexOfDice] == 0);
				}
				m_keptDiceforPoints[indexOfDice]--;
			}

			break;
	}
}

void Player::SwitchOptions()
{
	std::cout << "The options are:" << '\n';
	std::cout << "1. Keep some dices from the ones you rolled." << '\n';
	std::cout << "2. Roll dices." << '\n';
	std::cout << "3. Choose where do you want to use the points." << '\n';
	std::cout << "4. Release some of the kept dices." << '\n';
	std::cout << "Please write the index of the option you want to proceed." << '\n';
}

int Player::finalPoints()
{
	Points p;
	return p.TotalScore(m_lowerPoints, m_upperPoints);
}

std::array<int8_t, 6>& Player::GetKeptDiceforPoints()
{
	return m_keptDiceforPoints;
}

std::vector<int8_t>& Player::GetRollDices()
{
	return m_rollDices;
}

std::array<bool, 16>& Player::GetPossiblePlacesForPoints()
{
	return m_possiblePlacesForPoints;
}

std::vector<int>& Player::GetLowerPoints()
{
	return m_lowerPoints;
}

std::vector<int>& Player::GetUpperPoints()
{
	return m_upperPoints;
}

uint8_t Player::GetNumberOfDices()
{
	return m_numberOfDices;
}

int Player::GetIndexOfOption()
{
	return indexOfOption;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << player.m_name;
	return out;
}