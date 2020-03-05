#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

namespace sf
{
	class RenderWindow;
}

class TheWinner
{
public:
	TheWinner(sf::RenderWindow& winnerWindow, string nameOfTheFrirstPlayer, string nameOfTheSecondPlayer, int ok, int winnerPoints, int pointsFirstPlayer, int pointsSecondPlayer);

private:
	void WinnerPlayer1(sf::RenderWindow& windowWinner);
	void WinnerPlayer2(sf::RenderWindow& windowWinner);
	void BothWinners(sf::RenderWindow& windowWinner);
	void TotalPoints(sf::RenderWindow& windowWinner, int pointsFirstPlayer, int pointsSecondPlayer);
	void Buttons(sf::RenderWindow& windowWinner);

private:
	sf::Texture backgroundWinner;
	sf::Sprite backgroundWinnerImage;

	sf::Font font;

	sf::Texture resetButton;
	sf::Sprite resetButtonImage;

	sf::Texture menuButton;
	sf::Sprite menuButtonImage;

	sf::Texture exitButton;
	sf::Sprite exitButtonImage;

	sf::Texture topButton;
	sf::Sprite topButtonImage;
	
};

