#pragma once
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <array>
#include "Player.h"
#include "Hints.h"
#include <fstream>
#include "..\Logging\Logger.h"

using namespace std;

namespace sf
{
	class RenderWindow;
}

class GameGraphics
{
private:
	void SetWindow(sf::RenderWindow& window);
	void SetDices();
	void DrawDices(sf::RenderWindow& window);
	void SetRollButton(sf::RenderWindow& window);
	void ErrorWindow();
	void SetPlayer();
	void DrawPlayer(sf::RenderWindow& window);
	void DrawText(sf::RenderWindow& window, string nameOfTheFrirstPlayer, string nameOfTheSecondPlayer);
	void RollDices(sf::RenderWindow& window);
	void SetTable();
	void DrawTable(sf::RenderWindow& window);
	void SetPointsButtons();
	void DrawPointsButtons(sf::RenderWindow& window);
	void MouseMoved(sf::RenderWindow& window);
	void ResetDice();
	void SwitchPlayer();
	void SetArrayOfDices(std::reference_wrapper<Player> player);
	void SetText(sf::Text& pointsOnTable);
	void PlacePoints(int positionX, int positionY, int numberOfPoints, sf::Text& points);
	void DrawPoints(sf::RenderWindow& window);
	void SetHints(sf::Text& hints);
	void SetAllHints(sf::Text& hints);
	void DrawHints(sf::RenderWindow& window);
	void ResetHints();
	void DisplayHints(int player, std::array<int8_t, 6> keptDices, std::reference_wrapper<Player> checkPlayer);
	void SetStatisticsTable();
	void DrawStatisticsTable(sf::RenderWindow& window);
	void DrawStatistics(sf::RenderWindow& window);
	void SetStatisticsData();
	void PlaceApps_Rolls(int rollCounter);
	void PlacePercentage(int diceCounter);

public:
	GameGraphics(sf::RenderWindow& window, string nameOfTheFrirstPlayer, string nameOfTheSecondPlayer);

private:
	sf::Texture background;
	sf::Sprite backgroundImage;

	sf::Texture diceOne;
	sf::Sprite diceOneImage;

	sf::Texture diceTwo;
	sf::Sprite diceTwoImage;

	sf::Texture diceThree;
	sf::Sprite diceThreeImage;

	sf::Texture diceFour;
	sf::Sprite diceFourImage;

	sf::Texture diceFive;
	sf::Sprite diceFiveImage;

	sf::Texture rollButton;
	sf::Sprite rollButtonImage;

	sf::Texture playerButtonOne;
	sf::Sprite playerButtonImageOne;

	sf::Texture playerButtonTwo;
	sf::Sprite playerButtonImageTwo;

	sf::Text firstPlayer;

	std::vector<int> m_rollDices = { 1,2,3,4,5 };
	std::array<bool, 5> m_keptDices;
	std::array<int8_t, 6> diceHints;

	sf::RectangleShape scoreRectangle;
	sf::RectangleShape firstColumn;
	sf::RectangleShape secondColumn;
	sf::RectangleShape lineOne;
	sf::RectangleShape lineTwo;
	sf::RectangleShape lineThree;
	sf::RectangleShape lineFour;
	sf::RectangleShape lineFive;
	sf::RectangleShape lineSix;
	sf::RectangleShape lineSeven;
	sf::RectangleShape lineEight;
	sf::RectangleShape lineNine;
	sf::RectangleShape lineTen;
	sf::RectangleShape lineEleven;
	sf::RectangleShape lineTwelve;
	sf::RectangleShape lineThirteen;
	sf::RectangleShape lineFourteen;
	sf::RectangleShape lineFifteen;
	sf::RectangleShape lineSixteen;

	sf::Texture onesButton;
	sf::Sprite onesButtonImage;

	sf::Texture twosButton;
	sf::Sprite twosButtonImage;

	sf::Texture threesButton;
	sf::Sprite threesButtonImage;

	sf::Texture foursButton;
	sf::Sprite foursButtonImage;

	sf::Texture fivesButton;
	sf::Sprite fivesButtonImage;

	sf::Texture sixesButton;
	sf::Sprite sixesButtonImage;

	sf::Texture sumButton;
	sf::Sprite sumButtonImage;

	sf::Texture bonusButton;
	sf::Sprite bonusButtonImage;

	sf::Texture threeOfAKindButton;
	sf::Sprite threeOfAKindButtonImage;

	sf::Texture fourOfAKindButton;
	sf::Sprite fourOfAKindButtonImage;

	sf::Texture fullButton;
	sf::Sprite fullButtonImage;

	sf::Texture smallButton;
	sf::Sprite smallButtonImage;

	sf::Texture largeButton;
	sf::Sprite largeButtonImage;

	sf::Texture chanceButton;
	sf::Sprite chanceButtonImage;

	sf::Texture yahtzeeButton;
	sf::Sprite yahtzeeButtonImage;

	sf::Texture totalButton;
	sf::Sprite totalButtonImage;

	sf::Text pointsOnTable;
	sf::Font font;

	sf::Text pointsOnePlayerOne;
	sf::Text pointsOnePlayerTwo;
	sf::Text pointsTwoPlayerOne;
	sf::Text pointsTwoPlayerTwo;
	sf::Text pointsThreePlayerOne;
	sf::Text pointsThreePlayerTwo;
	sf::Text pointsFourPlayerOne;
	sf::Text pointsFourPlayerTwo;
	sf::Text pointsFivePlayerOne;
	sf::Text pointsFivePlayerTwo;
	sf::Text pointsSixPlayerOne;
	sf::Text pointsSixPlayerTwo;
	sf::Text pointsBonusPlayerOne;
	sf::Text pointsBonusPlayerTwo;
	sf::Text pointsSumPlayerOne;
	sf::Text pointsSumPlayerTwo;
	sf::Text pointsThreeOfAKindPlayerOne;
	sf::Text pointsThreeOfAKindPlayerTwo;
	sf::Text pointsFourOfAKindPlayerOne;
	sf::Text pointsFourOfAKindPlayerTwo;
	sf::Text pointsFullPlayerOne;
	sf::Text pointsFullPlayerTwo;
	sf::Text pointsSmallPlayerOne;
	sf::Text pointsSmallPlayerTwo;
	sf::Text pointsLargePlayerOne;
	sf::Text pointsLargePlayerTwo;
	sf::Text pointsChancePlayerOne;
	sf::Text pointsChancePlayerTwo;
	sf::Text pointsYahtzeePlayerOne;
	sf::Text pointsYahtzeePlayerTwo;
	sf::Text pointsTotalPlayerOne;
	sf::Text pointsTotalPlayerTwo;

	int pointsFirstPlayer;
	int pointsSecondPlayer;
	int winnerPoints;

	sf::Text hintsPoints;

	sf::Text hintsPointsOnePlayerOne;
	sf::Text hintsPointsOnePlayerTwo;
	sf::Text hintsPointsTwoPlayerOne;
	sf::Text hintsPointsTwoPlayerTwo;
	sf::Text hintsPointsThreePlayerOne;
	sf::Text hintsPointsThreePlayerTwo;
	sf::Text hintsPointsFourPlayerOne;
	sf::Text hintsPointsFourPlayerTwo;
	sf::Text hintsPointsFivePlayerOne;
	sf::Text hintsPointsFivePlayerTwo;
	sf::Text hintsPointsSixPlayerOne;
	sf::Text hintsPointsSixPlayerTwo;
	sf::Text hintsPointsThreeOfAKindPlayerOne;
	sf::Text hintsPointsThreeOfAKindPlayerTwo;
	sf::Text hintsPointsFourOfAKindPlayerOne;
	sf::Text hintsPointsFourOfAKindPlayerTwo;
	sf::Text hintsPointsFullPlayerOne;
	sf::Text hintsPointsFullPlayerTwo;
	sf::Text hintsPointsSmallPlayerOne;
	sf::Text hintsPointsSmallPlayerTwo;
	sf::Text hintsPointsLargePlayerOne;
	sf::Text hintsPointsLargePlayerTwo;
	sf::Text hintsPointsChancePlayerOne;
	sf::Text hintsPointsChancePlayerTwo;
	sf::Text hintsPointsYahtzeePlayerOne;
	sf::Text hintsPointsYahtzeePlayerTwo;

	int ok = 0;

	sf::RectangleShape statisticsTable;
	sf::RectangleShape columnOneStatistics;
	sf::RectangleShape columnDiceOne;
	sf::RectangleShape columnDiceTwo;
	sf::RectangleShape columnDiceThree;
	sf::RectangleShape columnDiceFour;
	sf::RectangleShape columnDiceFive;
	sf::RectangleShape columnDiceSix;
	sf::RectangleShape lineOneStatistics;
	sf::RectangleShape lineTwoStatistics;

	sf::Text columnOneLineOneText;
	sf::Text columnOneLineTwoText;
	sf::Text columnOneDiceText;
	sf::Text columnTwoDiceText;
	sf::Text columnThreeDiceText;
	sf::Text columnFourDiceText;
	sf::Text columnFiveDiceText;
	sf::Text columnSixDiceText;

	std::array<float, 6> diceFrequency;
	float rollCounter = 0;
	float diceCounter = 0;

	sf::Text diceOneApps;
	sf::Text diceTwoApps;
	sf::Text diceThreeApps;
	sf::Text diceFourApps;
	sf::Text diceFiveApps;
	sf::Text diceSixApps;

	sf::Text diceOnePercentage;
	sf::Text diceTwoPercentage;
	sf::Text diceThreePercentage;
	sf::Text diceFourPercentage;
	sf::Text diceFivePercentage;
	sf::Text diceSixPercentage;


};

