#include "TheWinner.h"
#include "TheNameOfTheFirstPlayer.h"
#include "Menu.h"
#include "TopFive.h"

#include <fstream>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

TheWinner::TheWinner(sf::RenderWindow& winnerWindow, string nameOfTheFrirstPlayer, string nameOfTheSecondPlayer, int ok, int winnerPoints, int pointsFirstPlayer, int pointsSecondPlayer)
{
	ofstream outputFile;
	outputFile.open("top5.txt", ofstream::app);

	// load sound and music into ram
	sf::Music msnd_intro;
	if (!msnd_intro.openFromFile("applause.ogg"))
		std::cout << "Error OFF : Failed to load applause.ogg" << std::endl;
	msnd_intro.play();


	if (!backgroundWinner.loadFromFile("images\\winner.jpg"))
		std::cout << "Error: Could not load the winner image" << '\n';

	backgroundWinnerImage.setTexture(backgroundWinner);

	if (!font.loadFromFile("ashcanbb_bold.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}
	sf::Text winnerText;

	winnerText.setCharacterSize(50);
	winnerText.setFont(font);
	winnerText.setFillColor(sf::Color::Black);
	winnerText.setPosition(90, 250);

	auto points = std::to_string(winnerPoints);
	int validation = 0;

	if (ok == 1)
	{
		winnerText.setString("The winner is \n          " + nameOfTheFrirstPlayer + " with " + points + " points!");
		validation = 1;
		outputFile << nameOfTheFrirstPlayer <<" "<< winnerPoints<< endl;
	}
	else if (ok == 2)
	{
		winnerText.setString("The winner is \n          " + nameOfTheSecondPlayer + " with " + points + " points!");
		validation = 2;
		outputFile << nameOfTheSecondPlayer << " " << winnerPoints << endl;
	}
	else
	{
		winnerText.setString("It is equality with " + points + " points!");
		validation = 3;
		outputFile << nameOfTheFrirstPlayer << " " << winnerPoints << endl;
		outputFile << nameOfTheSecondPlayer << " " << winnerPoints << endl;
	}

	Buttons(winnerWindow);

	while (winnerWindow.isOpen())
	{
		sf::Event Event;
		while (winnerWindow.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
			{
				winnerWindow.close();
			}
			break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Escape)
					winnerWindow.close();
				break;
			case sf::Event::MouseMoved:
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(winnerWindow);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

				if (resetButtonImage.getGlobalBounds().contains(mousePosF))
				{
					resetButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					resetButtonImage.setColor(sf::Color(255, 255, 255));
				}
				if (menuButtonImage.getGlobalBounds().contains(mousePosF))
				{
					menuButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					menuButtonImage.setColor(sf::Color(255, 255, 255));
				}
				if (exitButtonImage.getGlobalBounds().contains(mousePosF))
				{
					exitButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					exitButtonImage.setColor(sf::Color(255, 255, 255));
				}
				if (topButtonImage.getGlobalBounds().contains(mousePosF))
				{
					topButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					topButtonImage.setColor(sf::Color(255, 255, 255));
				}
			}
			break;
			case sf::Event::MouseButtonPressed:
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(winnerWindow);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (resetButtonImage.getGlobalBounds().contains(mousePosF))
				{
					TheNameOfTheFirstPlayer nameOfTheFirstPlayer(winnerWindow);
				}
				if (menuButtonImage.getGlobalBounds().contains(mousePosF))
				{
					Menu Menu(winnerWindow);
				}
				if (exitButtonImage.getGlobalBounds().contains(mousePosF))
				{
					winnerWindow.close();
				}
				if (topButtonImage.getGlobalBounds().contains(mousePosF))
				{
					TopFive top(1);
				}
			}
			break;
			}
		}

		winnerWindow.clear();
		winnerWindow.draw(backgroundWinnerImage);
		if (validation == 1)
			WinnerPlayer1(winnerWindow);
		else
			if (validation == 2)
				WinnerPlayer2(winnerWindow);
			else
				if (validation == 3)
					BothWinners(winnerWindow);

		winnerWindow.draw(winnerText);

		TotalPoints(winnerWindow, pointsFirstPlayer, pointsSecondPlayer);

		winnerWindow.draw(resetButtonImage);
		winnerWindow.draw(menuButtonImage);
		winnerWindow.draw(exitButtonImage);
		winnerWindow.draw(topButtonImage);
		winnerWindow.display();
	}
	outputFile.close();

}
void TheWinner::WinnerPlayer1(sf::RenderWindow& windowWinner)
{
	sf::Texture texture;
	if (!texture.loadFromFile("images\\winnerPlayer1.png"))
	{
		std::cout << "Error: Could not display texture!" << std::endl;
	}

	sf::Sprite winnerPlayer1(texture);
	winnerPlayer1.setPosition(170, 360);

	windowWinner.draw(winnerPlayer1);
}

void TheWinner::WinnerPlayer2(sf::RenderWindow& windowWinner)
{
	sf::Texture texture;
	if (!texture.loadFromFile("images\\winnerPlayer2.png"))
	{
		std::cout << "Error: Could not display texture!" << std::endl;
	}

	sf::Sprite winnerPlayer2(texture);
	winnerPlayer2.setPosition(170, 360);

	windowWinner.draw(winnerPlayer2);
}

void TheWinner::BothWinners(sf::RenderWindow& windowWinner)
{
	sf::Texture texture1;
	if (!texture1.loadFromFile("images\\winnerPlayer1.png"))
	{
		std::cout << "Error: Could not display texture!" << std::endl;
	}

	sf::Sprite winnerPlayer1(texture1);
	winnerPlayer1.setPosition(170, 360);

	sf::Texture texture2;
	if (!texture2.loadFromFile("images\\winnerPlayer2.png"))
	{
		std::cout << "Error: Could not display texture!" << std::endl;
	}

	sf::Sprite winnerPlayer2(texture2);
	winnerPlayer2.setPosition(200, 360);

	windowWinner.draw(winnerPlayer2);

	windowWinner.draw(winnerPlayer1);
	windowWinner.draw(winnerPlayer2);
}

void TheWinner::TotalPoints(sf::RenderWindow& windowWinner, int pointsFirstPlayer, int pointsSecondPlayer)
{
	sf::Texture texture1;
	if (!texture1.loadFromFile("images\\player1.png"))
	{
		std::cout << "Error: Could not display texture!" << std::endl;
	}

	sf::Sprite player1(texture1);
	player1.setPosition(300.0f, 45.0f);

	sf::Texture texture2;
	if (!texture2.loadFromFile("images\\player2.png"))
	{
		std::cout << "Error: Could not display texture!" << std::endl;
	}

	sf::Sprite player2(texture2);
	player2.setPosition(600.0f, 45.0f);


	if (!font.loadFromFile("ashcanbb_bold.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}
	sf::Text totalPointsFirstPalyer;
	auto pointsPlayer1 = std::to_string(pointsFirstPlayer);

	totalPointsFirstPalyer.setCharacterSize(50);
	totalPointsFirstPalyer.setFont(font);
	totalPointsFirstPalyer.setFillColor(sf::Color::Red);
	totalPointsFirstPalyer.setPosition(300.0f, 55.0f);
	totalPointsFirstPalyer.setString(pointsPlayer1);

	sf::Text totalPointsSecondPalyer;
	auto pointsPlayer2 = std::to_string(pointsSecondPlayer);

	totalPointsSecondPalyer.setCharacterSize(50);
	totalPointsSecondPalyer.setFont(font);
	totalPointsSecondPalyer.setFillColor(sf::Color::Red);
	totalPointsSecondPalyer.setPosition(600.0f, 55.0f);
	totalPointsSecondPalyer.setString(pointsPlayer2);

	windowWinner.draw(player1);
	windowWinner.draw(totalPointsFirstPalyer);
	windowWinner.draw(player2);
	windowWinner.draw(totalPointsSecondPalyer);

}

void TheWinner::Buttons(sf::RenderWindow& windowWinner)
{
	if (!resetButton.loadFromFile("images\\reset.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		
	}
	resetButtonImage.setPosition(470.0f, 470.0f);

	float resetButtonWidth = resetButtonImage.getLocalBounds().width;
	float resetButtonHeight = resetButtonImage.getLocalBounds().height;

	resetButtonImage.setTexture(resetButton);

	if (!menuButton.loadFromFile("images\\menu.png"))
	{
		std::cout << "Can't find the image" << std::endl;

	}
	menuButtonImage.setPosition(670.0f, 470.0f);

	float menuButtonWidth = menuButtonImage.getLocalBounds().width;
	float menuButtonHeight = menuButtonImage.getLocalBounds().height;

	menuButtonImage.setTexture(menuButton);

	if (!exitButton.loadFromFile("images\\exitW.png"))
	{
		std::cout << "Can't find the image" << std::endl;

	}
	exitButtonImage.setPosition(870.0f, 470.0f);

	float exitButtonWidth = exitButtonImage.getLocalBounds().width;
	float exitButtonHeight = exitButtonImage.getLocalBounds().height;

	exitButtonImage.setTexture(exitButton);

	if (!topButton.loadFromFile("images\\top5.png"))
	{
		std::cout << "Can't find the image" << std::endl;

	}
	topButtonImage.setPosition(1070.0f, 470.0f);

	float topButtonWidth = topButtonImage.getLocalBounds().width;
	float topButtonHeight = topButtonImage.getLocalBounds().height;

	topButtonImage.setTexture(topButton);
}

