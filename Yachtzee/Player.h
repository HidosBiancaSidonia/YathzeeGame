#include <string>
#include "Points.h"

class Player
{
public:
	enum class TypesOfOptionsForPlayer
	{
		KeepDices,
		RollDices,
		ChoosePointsOption,
		ReleaseDices
	};

public:
	Player(const std::string& name);

	//Rule of three
	Player(const Player& player);
	Player operator=(const Player& player);
	~Player();


	void DisplayOptions();
	void DisplayKeptDices();
	void PlacePoints(int indexOfOption);
	void  ChooseOption(TypesOfOptionsForPlayer option);
	void SwitchOptions();
	int finalPoints();

	friend std::ostream& operator<<(std::ostream& out, const Player& player);

	std::array<int8_t, 6>& GetKeptDiceforPoints();
	std::vector<int8_t>& GetRollDices();
	std::array<bool, 16>& GetPossiblePlacesForPoints();
	std::vector<int>& GetLowerPoints();
	std::vector<int>& GetUpperPoints();
	uint8_t GetNumberOfDices();
	int GetIndexOfOption();

public:
	std::string m_name;
	std::array<int8_t, 6> m_keptDiceforPoints;
	std::vector<int8_t> m_rollDices;
	std::array<bool, 16> m_possiblePlacesForPoints;
	std::vector<int> m_upperPoints;
	std::vector<int> m_lowerPoints;
	uint8_t m_numberOfDices;
	int indexOfOption;
};