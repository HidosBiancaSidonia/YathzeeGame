#include "GameGraphics.h"
#include "TheWinner.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

void GameGraphics::SetWindow(sf::RenderWindow& window)
{
	std::ofstream logFile("Log.log", std::ios::app);
	if (!background.loadFromFile("images\\Play.jpg"))
	{
		std::cout << "Error: Could not display Yahtzee Game image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Game image!", Logger::Level::Error);
	}
	backgroundImage.setTexture(background);
}

void GameGraphics::SetDices()
{
	if (!diceOne.loadFromFile("images\\zar1.png"))
		std::cout << "Can't find the image" << std::endl;
	diceOneImage.setPosition(100.0f, 270.0f);
	float diceOneWidth = diceOneImage.getLocalBounds().width;
	float diceOneHeight = diceOneImage.getLocalBounds().height;
	diceOneImage.setTexture(diceOne);

	if (!diceTwo.loadFromFile("images\\zar2.png"))
		std::cout << "Can't find the image" << std::endl;
	diceTwoImage.setPosition(205.0f, 270.0f);
	float diceTwoWidth = diceTwoImage.getLocalBounds().width;
	float diceTwoHeight = diceTwoImage.getLocalBounds().height;
	diceTwoImage.setTexture(diceTwo);

	if (!diceThree.loadFromFile("images\\zar3.png"))
		std::cout << "Can't find the image" << std::endl;
	diceThreeImage.setPosition(310.0f, 270.0f);
	float diceThreeWidth = diceThreeImage.getLocalBounds().width;
	float diceThreeHeight = diceThreeImage.getLocalBounds().height;
	diceThreeImage.setTexture(diceThree);

	if (!diceFour.loadFromFile("images\\zar4.png"))
		std::cout << "Can't find the image" << std::endl;
	diceFourImage.setPosition(415.0f, 270.0f);
	float diceFourWidth = diceFourImage.getLocalBounds().width;
	float diceFourHeight = diceFourImage.getLocalBounds().height;
	diceFourImage.setTexture(diceFour);

	if (!diceFive.loadFromFile("images\\zar5.png"))
		std::cout << "Can't find the image" << std::endl;
	diceFiveImage.setPosition(520.0f, 270.0f);
	float diceFiveWidth = diceFiveImage.getLocalBounds().width;
	float diceFiveHeight = diceFiveImage.getLocalBounds().height;
	diceFiveImage.setTexture(diceFive);
}

void GameGraphics::DrawDices(sf::RenderWindow& window)
{
	window.draw(diceOneImage);
	window.draw(diceTwoImage);
	window.draw(diceThreeImage);
	window.draw(diceFourImage);
	window.draw(diceFiveImage);
}

void GameGraphics::SetRollButton(sf::RenderWindow& window)
{
	std::ofstream logFile("Log.log", std::ios::app);
	if (!rollButton.loadFromFile("images\\RollButton3.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display roll button!", Logger::Level::Error);
	}
	rollButtonImage.setPosition(250.0f, 400.0f);

	float rollButtonWidth = rollButtonImage.getLocalBounds().width;
	float rollButtonHeight = rollButtonImage.getLocalBounds().height;

	rollButtonImage.setTexture(rollButton);
}

void GameGraphics::ErrorWindow()
{
	sf::RenderWindow errorWindow(sf::VideoMode(800, 400), "Error", sf::Style::Default);

	sf::Texture backgroundError;
	sf::Sprite backgroundImageError;

	std::ofstream logFile("Log.log", std::ios::app);

	if (!backgroundError.loadFromFile("images\\Error.jpg"))
	{
		std::cout << "Error: Could not load the error image" << '\n';
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display error window background!", Logger::Level::Error);
	}

	backgroundImageError.setTexture(backgroundError);

	sf::Texture okButton;
	sf::Sprite okButtonImage;


	if (!okButton.loadFromFile("images\\Ok2.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display ok button!", Logger::Level::Error);
	}
	okButtonImage.setPosition(350.0f, 250.0f);
	float okWidth = okButtonImage.getLocalBounds().width;
	float okHeight = okButtonImage.getLocalBounds().height;
	okButtonImage.setTexture(okButton);

	while (errorWindow.isOpen())
	{
		sf::Event Event;
		while (errorWindow.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
			{
				errorWindow.close();
			}
			break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Escape)
					errorWindow.close();
				break;
			case sf::Event::MouseButtonPressed:
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(errorWindow);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (okButtonImage.getGlobalBounds().contains(mousePosF))
				{
					errorWindow.close();
				}
			}
			}
		}

		errorWindow.clear();
		errorWindow.draw(backgroundImageError);
		errorWindow.draw(okButtonImage);
		errorWindow.display();
	}
}


void GameGraphics::SetPlayer()
{
	std::ofstream logFile("Log.log", std::ios::app);

	if (!playerButtonOne.loadFromFile("images\\player1.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not find man's image!", Logger::Level::Error);
	}
	playerButtonImageOne.setPosition(200.0f, 50.0f);

	float playerOneButtonWidth = playerButtonImageOne.getLocalBounds().width;
	float playerOneButtonHeight = playerButtonImageOne.getLocalBounds().height;

	playerButtonImageOne.setTexture(playerButtonOne);

	if (!playerButtonTwo.loadFromFile("images\\player2.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not find girl's image!", Logger::Level::Error);
	}
	playerButtonImageTwo.setPosition(400.0f, 50.0f);

	float playerTwoButtonWidth = playerButtonImageTwo.getLocalBounds().width;
	float playerTwoButtonHeight = playerButtonImageTwo.getLocalBounds().height;

	playerButtonImageTwo.setTexture(playerButtonTwo);
}

void GameGraphics::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(playerButtonImageOne);
	window.draw(playerButtonImageTwo);
}

void GameGraphics::DrawText(sf::RenderWindow& window, string nameOfTheFrirstPlayer, string nameOfTheSecondPlayer)
{
	sf::Font font;

	std::ofstream logFile("Log.log", std::ios::app);
	
	if (!font.loadFromFile("Elephant.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not upload the font!", Logger::Level::Error);
	}

	sf::Text firstPlayer;
	firstPlayer.setCharacterSize(30);
	firstPlayer.setFont(font);
	firstPlayer.setString(nameOfTheFrirstPlayer);
	firstPlayer.setPosition(230, 200);
	firstPlayer.setFillColor(sf::Color::Black);

	sf::Text secondPlayer;
	secondPlayer.setCharacterSize(30);
	secondPlayer.setFont(font);
	secondPlayer.setString(nameOfTheSecondPlayer);
	secondPlayer.setPosition(430, 200);
	secondPlayer.setFillColor(sf::Color::Black);

	sf::Text firstPlayerInColumn;
	firstPlayerInColumn.setCharacterSize(18);
	firstPlayerInColumn.setFont(font);
	firstPlayerInColumn.setString(nameOfTheFrirstPlayer);
	firstPlayerInColumn.setPosition(910, 45);
	firstPlayerInColumn.setFillColor(sf::Color::Black);

	sf::Text secondPlayerInColumn;
	secondPlayerInColumn.setCharacterSize(18);
	secondPlayerInColumn.setFont(font);
	secondPlayerInColumn.setString(nameOfTheSecondPlayer);
	secondPlayerInColumn.setPosition(1010, 45);
	secondPlayerInColumn.setFillColor(sf::Color::Black);

	window.draw(firstPlayerInColumn);
	window.draw(secondPlayerInColumn);

	window.draw(firstPlayer);
	window.draw(secondPlayer);
}

void GameGraphics::RollDices(sf::RenderWindow& window)
{
	srand((uint8_t)time(0));
	int nr;
	if (m_keptDices[0] == 0)
	{
		nr = rand() % 6 + 1;
		m_rollDices[0] = nr;
		if (nr == 1)
		{
			diceOne.loadFromFile("images\\zar1.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 2)
		{
			diceOne.loadFromFile("images\\zar2.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 3)
		{
			diceOne.loadFromFile("images\\zar3.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 4)
		{
			diceOne.loadFromFile("images\\zar4.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 5)
		{
			diceOne.loadFromFile("images\\zar5.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 6)
		{
			diceOne.loadFromFile("images\\zar6.png");
			diceFrequency[nr - 1]++;
		}
	}
	if (m_keptDices[1] == 0)
	{
		nr = rand() % 6 + 1;
		m_rollDices[1] = nr;
		if (nr == 1)
		{
			diceTwo.loadFromFile("images\\zar1.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 2)
		{
			diceTwo.loadFromFile("images\\zar2.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 3)
		{
			diceTwo.loadFromFile("images\\zar3.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 4)
		{
			diceTwo.loadFromFile("images\\zar4.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 5)
		{
			diceTwo.loadFromFile("images\\zar5.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 6)
		{
			diceTwo.loadFromFile("images\\zar6.png");
			diceFrequency[nr - 1]++;
		}
	}
	if (m_keptDices[2] == 0)
	{
		nr = rand() % 6 + 1;
		m_rollDices[2] = nr;

		if (nr == 1)
		{
			diceThree.loadFromFile("images\\zar1.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 2)
		{
			diceThree.loadFromFile("images\\zar2.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 3)
		{
			diceThree.loadFromFile("images\\zar3.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 4)
		{
			diceThree.loadFromFile("images\\zar4.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 5)
		{
			diceThree.loadFromFile("images\\zar5.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 6)
		{
			diceThree.loadFromFile("images\\zar6.png");
			diceFrequency[nr - 1]++;
		}
	}
	if (m_keptDices[3] == 0)
	{
		nr = rand() % 6 + 1;
		m_rollDices[3] = nr;
		if (nr == 1)
		{
			diceFour.loadFromFile("images\\zar1.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 2)
		{
			diceFour.loadFromFile("images\\zar2.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 3)
		{
			diceFour.loadFromFile("images\\zar3.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 4)
		{
			diceFour.loadFromFile("images\\zar4.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 5)
		{
			diceFour.loadFromFile("images\\zar5.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 6)
		{
			diceFour.loadFromFile("images\\zar6.png");
			diceFrequency[nr - 1]++;
		}
	}
	if (m_keptDices[4] == 0)
	{
		nr = rand() % 6 + 1;
		m_rollDices[4] = nr;
		if (nr == 1)
		{
			diceFive.loadFromFile("images\\zar1.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 2)
		{
			diceFive.loadFromFile("images\\zar2.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 3)
		{
			diceFive.loadFromFile("images\\zar3.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 4)
		{
			diceFive.loadFromFile("images\\zar4.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 5)
		{
			diceFive.loadFromFile("images\\zar5.png");
			diceFrequency[nr - 1]++;
		}
		else if (nr == 6)
		{
			diceFive.loadFromFile("images\\zar6.png");
			diceFrequency[nr - 1]++;
		}
	}
	std::cout << "Rolled dice:";
	for (auto iterator = m_rollDices.begin(); iterator != m_rollDices.end(); ++iterator)
		std::cout << *iterator << " ";
	std::cout << '\n';
}

void GameGraphics::SetTable()
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Setting the points table.", Logger::Level::Info);

	scoreRectangle.setSize(sf::Vector2f(350, 612));
	scoreRectangle.setOutlineThickness(3);
	scoreRectangle.setOutlineColor(sf::Color::Black);
	scoreRectangle.setFillColor(sf::Color::White);
	scoreRectangle.setPosition(750, 40);

	firstColumn.setSize(sf::Vector2f(150, 612));
	firstColumn.setOutlineThickness(3);
	firstColumn.setOutlineColor(sf::Color::Black);
	firstColumn.setFillColor(sf::Color::Transparent);
	firstColumn.setPosition(750, 40);

	secondColumn.setSize(sf::Vector2f(250, 612));
	secondColumn.setOutlineThickness(3);
	secondColumn.setOutlineColor(sf::Color::Black);
	secondColumn.setFillColor(sf::Color::Transparent);
	secondColumn.setPosition(750, 40);

	lineOne.setSize(sf::Vector2f(350, 36));
	lineOne.setOutlineThickness(3);
	lineOne.setOutlineColor(sf::Color::Black);
	lineOne.setFillColor(sf::Color::Transparent);
	lineOne.setPosition(750, 40);

	lineTwo.setSize(sf::Vector2f(350, 72));
	lineTwo.setOutlineThickness(3);
	lineTwo.setOutlineColor(sf::Color::Black);
	lineTwo.setFillColor(sf::Color::Transparent);
	lineTwo.setPosition(750, 40);

	lineThree.setSize(sf::Vector2f(350, 108));
	lineThree.setOutlineThickness(3);
	lineThree.setOutlineColor(sf::Color::Black);
	lineThree.setFillColor(sf::Color::Transparent);
	lineThree.setPosition(750, 40);

	lineFour.setSize(sf::Vector2f(350, 144));
	lineFour.setOutlineThickness(3);
	lineFour.setOutlineColor(sf::Color::Black);
	lineFour.setFillColor(sf::Color::Transparent);
	lineFour.setPosition(750, 40);

	lineFive.setSize(sf::Vector2f(350, 180));
	lineFive.setOutlineThickness(3);
	lineFive.setOutlineColor(sf::Color::Black);
	lineFive.setFillColor(sf::Color::Transparent);
	lineFive.setPosition(750, 40);

	lineSix.setSize(sf::Vector2f(350, 216));
	lineSix.setOutlineThickness(3);
	lineSix.setOutlineColor(sf::Color::Black);
	lineSix.setFillColor(sf::Color::Transparent);
	lineSix.setPosition(750, 40);

	lineSeven.setSize(sf::Vector2f(350, 252));
	lineSeven.setOutlineThickness(3);
	lineSeven.setOutlineColor(sf::Color::Black);
	lineSeven.setFillColor(sf::Color::Transparent);
	lineSeven.setPosition(750, 40);

	lineEight.setSize(sf::Vector2f(350, 288));
	lineEight.setOutlineThickness(3);
	lineEight.setOutlineColor(sf::Color::Black);
	lineEight.setFillColor(sf::Color::Transparent);
	lineEight.setPosition(750, 40);

	lineNine.setSize(sf::Vector2f(350, 324));
	lineNine.setOutlineThickness(3);
	lineNine.setOutlineColor(sf::Color::Black);
	lineNine.setFillColor(sf::Color::Transparent);
	lineNine.setPosition(750, 40);

	lineTen.setSize(sf::Vector2f(350, 360));
	lineTen.setOutlineThickness(3);
	lineTen.setOutlineColor(sf::Color::Black);
	lineTen.setFillColor(sf::Color::Transparent);
	lineTen.setPosition(750, 40);

	lineEleven.setSize(sf::Vector2f(350, 396));
	lineEleven.setOutlineThickness(3);
	lineEleven.setOutlineColor(sf::Color::Black);
	lineEleven.setFillColor(sf::Color::Transparent);
	lineEleven.setPosition(750, 40);

	lineTwelve.setSize(sf::Vector2f(350, 432));
	lineTwelve.setOutlineThickness(3);
	lineTwelve.setOutlineColor(sf::Color::Black);
	lineTwelve.setFillColor(sf::Color::Transparent);
	lineTwelve.setPosition(750, 40);

	lineThirteen.setSize(sf::Vector2f(350, 468));
	lineThirteen.setOutlineThickness(3);
	lineThirteen.setOutlineColor(sf::Color::Black);
	lineThirteen.setFillColor(sf::Color::Transparent);
	lineThirteen.setPosition(750, 40);

	lineFourteen.setSize(sf::Vector2f(350, 504));
	lineFourteen.setOutlineThickness(3);
	lineFourteen.setOutlineColor(sf::Color::Black);
	lineFourteen.setFillColor(sf::Color::Transparent);
	lineFourteen.setPosition(750, 40);

	lineFifteen.setSize(sf::Vector2f(350, 540));
	lineFifteen.setOutlineThickness(3);
	lineFifteen.setOutlineColor(sf::Color::Black);
	lineFifteen.setFillColor(sf::Color::Transparent);
	lineFifteen.setPosition(750, 40);

	lineSixteen.setSize(sf::Vector2f(350, 576));
	lineSixteen.setOutlineThickness(3);
	lineSixteen.setOutlineColor(sf::Color::Black);
	lineSixteen.setFillColor(sf::Color::Transparent);
	lineSixteen.setPosition(750, 40);
}

void GameGraphics::DrawTable(sf::RenderWindow& window)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Drawing the table.", Logger::Level::Info);

	window.draw(scoreRectangle);
	window.draw(firstColumn);
	window.draw(secondColumn);
	window.draw(lineOne);
	window.draw(lineTwo);
	window.draw(lineThree);
	window.draw(lineFour);
	window.draw(lineFive);
	window.draw(lineSix);
	window.draw(lineSeven);
	window.draw(lineEight);
	window.draw(lineNine);
	window.draw(lineTen);
	window.draw(lineEleven);
	window.draw(lineTwelve);
	window.draw(lineThirteen);
	window.draw(lineFourteen);
	window.draw(lineFifteen);
	window.draw(lineSixteen);
}

void GameGraphics::SetPointsButtons()
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Setting the points buttons.", Logger::Level::Info);

	if (!onesButton.loadFromFile("images\\buttonOne.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Ones button!", Logger::Level::Error);
	}
	onesButtonImage.setPosition(748.0f, 78.0f);
	float onesButtonWidth = onesButtonImage.getLocalBounds().width;
	float onesButtonHeight = onesButtonImage.getLocalBounds().height;
	onesButtonImage.setTexture(onesButton);

	if (!twosButton.loadFromFile("images\\buttonTwo.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Twos button!", Logger::Level::Error);
	}
	twosButtonImage.setPosition(748.0f, 114.0f);
	float twosButtonWidth = twosButtonImage.getLocalBounds().width;
	float twosButtonHeight = twosButtonImage.getLocalBounds().height;
	twosButtonImage.setTexture(twosButton);

	if (!threesButton.loadFromFile("images\\buttonThree.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Threes button!", Logger::Level::Error);
	}
	threesButtonImage.setPosition(748.0f, 150.0f);
	float threesButtonWidth = threesButtonImage.getLocalBounds().width;
	float threesButtonHeight = threesButtonImage.getLocalBounds().height;
	threesButtonImage.setTexture(threesButton);

	if (!foursButton.loadFromFile("images\\buttonFour.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Fours button!", Logger::Level::Error);
	}
	foursButtonImage.setPosition(748.0f, 186.0f);
	float foursButtonWidth = foursButtonImage.getLocalBounds().width;
	float foursButtonHeight = foursButtonImage.getLocalBounds().height;
	foursButtonImage.setTexture(foursButton);

	if (!fivesButton.loadFromFile("images\\buttonFive.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Fives button!", Logger::Level::Error);
	}
	fivesButtonImage.setPosition(748.0f, 222.0f);
	float fivesButtonWidth = fivesButtonImage.getLocalBounds().width;
	float fivesButtonHeight = fivesButtonImage.getLocalBounds().height;
	fivesButtonImage.setTexture(fivesButton);

	if (!sixesButton.loadFromFile("images\\buttonSix.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Sixex button!", Logger::Level::Error);
	}

	sixesButtonImage.setPosition(748.0f, 258.0f);
	float sixesButtonWidth = sixesButtonImage.getLocalBounds().width;
	float sixesButtonHeight = sixesButtonImage.getLocalBounds().height;
	sixesButtonImage.setTexture(sixesButton);

	if (!sumButton.loadFromFile("images\\buttonSum.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Sixes button!", Logger::Level::Error);
	}
	sumButtonImage.setPosition(748.0f, 294.0f);
	float sumButtonWidth = sumButtonImage.getLocalBounds().width;
	float sumButtonHeight = sumButtonImage.getLocalBounds().height;
	sumButtonImage.setTexture(sumButton);

	if (!bonusButton.loadFromFile("images\\buttonBonus.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Bonus button!", Logger::Level::Error);
	}
	bonusButtonImage.setPosition(748.0f, 330.0f);
	float bonusButtonWidth = bonusButtonImage.getLocalBounds().width;
	float bonusButtonHeight = bonusButtonImage.getLocalBounds().height;
	bonusButtonImage.setTexture(bonusButton);

	if (!threeOfAKindButton.loadFromFile("images\\buttonThreeKind.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Three of a kind button!", Logger::Level::Error);
	}
	threeOfAKindButtonImage.setPosition(748.0f, 366.0f);
	float threeOfAKindButtonWidth = threeOfAKindButtonImage.getLocalBounds().width;
	float threeOfAKindButtonHeight = threeOfAKindButtonImage.getLocalBounds().height;
	threeOfAKindButtonImage.setTexture(threeOfAKindButton);

	if (!fourOfAKindButton.loadFromFile("images\\buttonFourKind.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Four of a kind button!", Logger::Level::Error);
	}
	fourOfAKindButtonImage.setPosition(748.0f, 402.0f);
	float fourOfAKindButtonWidth = fourOfAKindButtonImage.getLocalBounds().width;
	float fourOfAKindButtonHeight = fourOfAKindButtonImage.getLocalBounds().height;
	fourOfAKindButtonImage.setTexture(fourOfAKindButton);

	if (!fullButton.loadFromFile("images\\buttonFull.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Full House button!", Logger::Level::Error);
	}
	fullButtonImage.setPosition(748.0f, 438.0f);
	float fullButtonWidth = fullButtonImage.getLocalBounds().width;
	float fullButtonHeight = fullButtonImage.getLocalBounds().height;
	fullButtonImage.setTexture(fullButton);

	if (!smallButton.loadFromFile("images\\buttonSmall.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Small straight button!", Logger::Level::Error);
	}	
	smallButtonImage.setPosition(748.0f, 474.0f);
	float smallButtonWidth = smallButtonImage.getLocalBounds().width;
	float smallButtonHeight = smallButtonImage.getLocalBounds().height;
	smallButtonImage.setTexture(smallButton);

	if (!largeButton.loadFromFile("images\\buttonLarge.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Large Straight button!", Logger::Level::Error);
	}
	largeButtonImage.setPosition(748.0f, 510.0f);
	float largeButtonWidth = largeButtonImage.getLocalBounds().width;
	float largeButtonHeight = largeButtonImage.getLocalBounds().height;
	largeButtonImage.setTexture(largeButton);

	if (!chanceButton.loadFromFile("images\\buttonChance.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Chance button!", Logger::Level::Error);
	}
	chanceButtonImage.setPosition(748.0f, 546.0f);
	float chanceButtonWidth = chanceButtonImage.getLocalBounds().width;
	float chanceButtonHeight = chanceButtonImage.getLocalBounds().height;
	chanceButtonImage.setTexture(chanceButton);

	if (!yahtzeeButton.loadFromFile("images\\buttonYahtzee.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Yahtzee button!", Logger::Level::Error);
	}
	yahtzeeButtonImage.setPosition(748.0f, 582.0f);
	float yahtzeeButtonWidth = yahtzeeButtonImage.getLocalBounds().width;
	float yahtzeeButtonHeight = yahtzeeButtonImage.getLocalBounds().height;
	yahtzeeButtonImage.setTexture(yahtzeeButton);

	if (!totalButton.loadFromFile("images\\buttonTotal.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Total button!", Logger::Level::Error);
	}
	totalButtonImage.setPosition(748.0f, 618.0f);
	float totalButtonWidth = totalButtonImage.getLocalBounds().width;
	float totalButtonHeight = totalButtonImage.getLocalBounds().height;
	totalButtonImage.setTexture(totalButton);
}

void GameGraphics::DrawPointsButtons(sf::RenderWindow& window)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Drawing the points buttons.", Logger::Level::Info);
	window.draw(onesButtonImage);
	window.draw(twosButtonImage);
	window.draw(threesButtonImage);
	window.draw(foursButtonImage);
	window.draw(fivesButtonImage);
	window.draw(sixesButtonImage);
	window.draw(sumButtonImage);
	window.draw(bonusButtonImage);
	window.draw(threeOfAKindButtonImage);
	window.draw(fourOfAKindButtonImage);
	window.draw(fullButtonImage);
	window.draw(smallButtonImage);
	window.draw(largeButtonImage);
	window.draw(chanceButtonImage);
	window.draw(yahtzeeButtonImage);
	window.draw(totalButtonImage);
}

void GameGraphics::MouseMoved(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	if (onesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		onesButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!onesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		onesButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (twosButtonImage.getGlobalBounds().contains(mousePosF))
	{
		twosButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!twosButtonImage.getGlobalBounds().contains(mousePosF))
	{
		twosButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (threesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		threesButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!threesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		threesButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (foursButtonImage.getGlobalBounds().contains(mousePosF))
	{
		foursButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!foursButtonImage.getGlobalBounds().contains(mousePosF))
	{
		foursButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (fivesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		fivesButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!fivesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		fivesButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (sixesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		sixesButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!sixesButtonImage.getGlobalBounds().contains(mousePosF))
	{
		sixesButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (threeOfAKindButtonImage.getGlobalBounds().contains(mousePosF))
	{
		threeOfAKindButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!threeOfAKindButtonImage.getGlobalBounds().contains(mousePosF))
	{
		threeOfAKindButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (fourOfAKindButtonImage.getGlobalBounds().contains(mousePosF))
	{
		fourOfAKindButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!fourOfAKindButtonImage.getGlobalBounds().contains(mousePosF))
	{
		fourOfAKindButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (fullButtonImage.getGlobalBounds().contains(mousePosF))
	{
		fullButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!fullButtonImage.getGlobalBounds().contains(mousePosF))
	{
		fullButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (smallButtonImage.getGlobalBounds().contains(mousePosF))
	{
		smallButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!smallButtonImage.getGlobalBounds().contains(mousePosF))
	{
		smallButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (largeButtonImage.getGlobalBounds().contains(mousePosF))
	{
		largeButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!largeButtonImage.getGlobalBounds().contains(mousePosF))
	{
		largeButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (chanceButtonImage.getGlobalBounds().contains(mousePosF))
	{
		chanceButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!chanceButtonImage.getGlobalBounds().contains(mousePosF))
	{
		chanceButtonImage.setColor(sf::Color(255, 255, 255));
	}
	if (yahtzeeButtonImage.getGlobalBounds().contains(mousePosF))
	{
		yahtzeeButtonImage.setColor(sf::Color(128, 128, 128));
	}
	else if (!yahtzeeButtonImage.getGlobalBounds().contains(mousePosF))
	{
		yahtzeeButtonImage.setColor(sf::Color(255, 255, 255));
	}
}

void GameGraphics::ResetDice()
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Reseting the dice.", Logger::Level::Info);
	diceOneImage.setColor(sf::Color(255, 255, 255));
	diceTwoImage.setColor(sf::Color(255, 255, 255));
	diceThreeImage.setColor(sf::Color(255, 255, 255));
	diceFourImage.setColor(sf::Color(255, 255, 255));
	diceFiveImage.setColor(sf::Color(255, 255, 255));
}

void GameGraphics::SwitchPlayer()
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Switching the player.", Logger::Level::Info);
	if (playerButtonImageOne.getColor() == sf::Color(255, 255, 255))
	{
		playerButtonImageTwo.setColor(sf::Color(255, 255, 255));
		playerButtonImageOne.setColor(sf::Color(256, 256, 256));
	}
	else if (playerButtonImageTwo.getColor() == sf::Color(255, 255, 255))
	{
		playerButtonImageTwo.setColor(sf::Color(256, 256, 256));
		playerButtonImageOne.setColor(sf::Color(255, 255, 255));
	}
}

void GameGraphics::SetArrayOfDices(std::reference_wrapper<Player> player)
{
	for (auto it = m_rollDices.begin(); it != m_rollDices.end(); ++it)
	{
		if (*it >= 1)
			player.get().m_keptDiceforPoints[*it - 1]++;
	}
	for (auto it = player.get().m_keptDiceforPoints.begin(); it != player.get().m_keptDiceforPoints.end(); ++it)
		std::cout << static_cast<int> (*it) << " ";
	std::fill(std::begin(m_keptDices), std::end(m_keptDices), 0);
	std::cout << '\n';
}

void GameGraphics::SetText(sf::Text& pointsOnTable)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Setting the text for points.", Logger::Level::Info);

	if (!font.loadFromFile("Elephant.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}
	pointsOnTable.setCharacterSize(20);
	pointsOnTable.setFont(font);
	pointsOnTable.setFillColor(sf::Color::Black);
}

void GameGraphics::PlacePoints(int positionX, int positionY, int numberOfPoints, sf::Text& points)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Placing the points.", Logger::Level::Info);

	std::string str1 = std::to_string(numberOfPoints);
	points.setPosition(positionX, positionY);
	points.setString(str1);
}

void GameGraphics::DrawPoints(sf::RenderWindow& window)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Drawing the points on table.", Logger::Level::Info);

	window.draw(pointsOnePlayerOne);
	window.draw(pointsOnePlayerTwo);
	window.draw(pointsTwoPlayerOne);
	window.draw(pointsTwoPlayerTwo);
	window.draw(pointsThreePlayerOne);
	window.draw(pointsThreePlayerTwo);
	window.draw(pointsFourPlayerOne);
	window.draw(pointsFourPlayerTwo);
	window.draw(pointsFivePlayerOne);
	window.draw(pointsFivePlayerTwo);
	window.draw(pointsSixPlayerOne);
	window.draw(pointsSixPlayerTwo);
	window.draw(pointsBonusPlayerOne);
	window.draw(pointsBonusPlayerTwo);
	window.draw(pointsSumPlayerOne);
	window.draw(pointsSumPlayerTwo);
	window.draw(pointsThreeOfAKindPlayerOne);
	window.draw(pointsThreeOfAKindPlayerTwo);
	window.draw(pointsFourOfAKindPlayerOne);
	window.draw(pointsFourOfAKindPlayerTwo);
	window.draw(pointsFullPlayerOne);
	window.draw(pointsFullPlayerTwo);
	window.draw(pointsSmallPlayerOne);
	window.draw(pointsSmallPlayerTwo);
	window.draw(pointsLargePlayerOne);
	window.draw(pointsLargePlayerTwo);
	window.draw(pointsChancePlayerOne);
	window.draw(pointsChancePlayerTwo);
	window.draw(pointsYahtzeePlayerOne);
	window.draw(pointsYahtzeePlayerOne);
	window.draw(pointsYahtzeePlayerTwo);
	window.draw(pointsTotalPlayerOne);
	window.draw(pointsTotalPlayerTwo);
}

void GameGraphics::SetHints(sf::Text& hints)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Setting the text for the hints.", Logger::Level::Info);

	if (!font.loadFromFile("Elephant.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}
	hints.setCharacterSize(20);
	hints.setFont(font);
	hints.setFillColor(sf::Color::Red);
}

void GameGraphics::SetAllHints(sf::Text& hints)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Setting all the text hints.", Logger::Level::Info);
	SetHints(hintsPointsOnePlayerOne);
	SetHints(hintsPointsOnePlayerTwo);
	SetHints(hintsPointsTwoPlayerOne);
	SetHints(hintsPointsTwoPlayerTwo);
	SetHints(hintsPointsThreePlayerOne);
	SetHints(hintsPointsThreePlayerTwo);
	SetHints(hintsPointsFourPlayerOne);
	SetHints(hintsPointsFourPlayerTwo);
	SetHints(hintsPointsFivePlayerOne);
	SetHints(hintsPointsFivePlayerTwo);
	SetHints(hintsPointsSixPlayerOne);
	SetHints(hintsPointsSixPlayerTwo);
	SetHints(hintsPointsThreeOfAKindPlayerOne);
	SetHints(hintsPointsThreeOfAKindPlayerTwo);
	SetHints(hintsPointsFourOfAKindPlayerOne);
	SetHints(hintsPointsFourOfAKindPlayerTwo);
	SetHints(hintsPointsFullPlayerOne);
	SetHints(hintsPointsFullPlayerTwo);
	SetHints(hintsPointsSmallPlayerOne);
	SetHints(hintsPointsSmallPlayerTwo);
	SetHints(hintsPointsLargePlayerOne);
	SetHints(hintsPointsLargePlayerTwo);
	SetHints(hintsPointsChancePlayerOne);
	SetHints(hintsPointsChancePlayerTwo);
	SetHints(hintsPointsYahtzeePlayerOne);
	SetHints(hintsPointsYahtzeePlayerTwo);
}

void GameGraphics::DrawHints(sf::RenderWindow& window)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Drawing the hints.", Logger::Level::Info);
	window.draw(hintsPointsOnePlayerOne);
	window.draw(hintsPointsOnePlayerTwo);
	window.draw(hintsPointsTwoPlayerOne);
	window.draw(hintsPointsTwoPlayerTwo);
	window.draw(hintsPointsThreePlayerOne);
	window.draw(hintsPointsThreePlayerTwo);
	window.draw(hintsPointsFourPlayerOne);
	window.draw(hintsPointsFourPlayerTwo);
	window.draw(hintsPointsFivePlayerOne);
	window.draw(hintsPointsFivePlayerTwo);
	window.draw(hintsPointsSixPlayerOne);
	window.draw(hintsPointsSixPlayerTwo);
	window.draw(hintsPointsThreeOfAKindPlayerOne);
	window.draw(hintsPointsThreeOfAKindPlayerTwo);
	window.draw(hintsPointsFourOfAKindPlayerOne);
	window.draw(hintsPointsFourOfAKindPlayerTwo);
	window.draw(hintsPointsFullPlayerOne);
	window.draw(hintsPointsFullPlayerTwo);
	window.draw(hintsPointsSmallPlayerOne);
	window.draw(hintsPointsSmallPlayerTwo);
	window.draw(hintsPointsLargePlayerOne);
	window.draw(hintsPointsLargePlayerTwo);
	window.draw(hintsPointsChancePlayerOne);
	window.draw(hintsPointsChancePlayerTwo);
	window.draw(hintsPointsYahtzeePlayerOne);
	window.draw(hintsPointsYahtzeePlayerTwo);
}

void GameGraphics::ResetHints()
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Reseting the hints.", Logger::Level::Info);
	hintsPointsOnePlayerOne.setString("");
	hintsPointsOnePlayerTwo.setString("");
	hintsPointsTwoPlayerOne.setString("");
	hintsPointsTwoPlayerTwo.setString("");
	hintsPointsThreePlayerOne.setString("");
	hintsPointsThreePlayerTwo.setString("");
	hintsPointsFourPlayerOne.setString("");
	hintsPointsFourPlayerTwo.setString("");
	hintsPointsFivePlayerOne.setString("");
	hintsPointsFivePlayerTwo.setString("");
	hintsPointsSixPlayerOne.setString("");
	hintsPointsSixPlayerTwo.setString("");
	hintsPointsThreeOfAKindPlayerOne.setString("");
	hintsPointsThreeOfAKindPlayerTwo.setString("");
	hintsPointsFourOfAKindPlayerOne.setString("");
	hintsPointsFourOfAKindPlayerTwo.setString("");
	hintsPointsFullPlayerOne.setString("");
	hintsPointsFullPlayerTwo.setString("");
	hintsPointsSmallPlayerOne.setString("");
	hintsPointsSmallPlayerTwo.setString("");
	hintsPointsLargePlayerOne.setString("");
	hintsPointsLargePlayerTwo.setString("");
	hintsPointsChancePlayerOne.setString("");
	hintsPointsChancePlayerTwo.setString("");
	hintsPointsYahtzeePlayerOne.setString("");
	hintsPointsYahtzeePlayerTwo.setString("");
}

void GameGraphics::DisplayHints(int player, std::array<int8_t, 6> keptDices, std::reference_wrapper<Player> checkPlayer)
{
	std::ofstream logFile("Log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Displaying the hints.", Logger::Level::Info);
	Hints h;
	int point;
	if (player == 1)
	{
		if (h.Ones(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::One)] == false)
		{
			point = h.Ones(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsOnePlayerOne.setPosition(910, 81);
			hintsPointsOnePlayerOne.setString(str1);
		}
		if (h.Twos(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Two)] == false)
		{
			point = h.Twos(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsTwoPlayerOne.setPosition(910, 117);
			hintsPointsTwoPlayerOne.setString(str1);
		}
		if (h.Threes(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Three)] == false)
		{
			point = h.Threes(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsThreePlayerOne.setPosition(910, 153);
			hintsPointsThreePlayerOne.setString(str1);
		}
		if (h.Fours(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Four)] == false)
		{
			point = h.Fours(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFourPlayerOne.setPosition(910, 189);
			hintsPointsFourPlayerOne.setString(str1);
		}
		if (h.Fives(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Five)] == false)
		{
			point = h.Fives(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFivePlayerOne.setPosition(910, 225);
			hintsPointsFivePlayerOne.setString(str1);
		}
		if (h.Sixes(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Six)] == false)
		{
			point = h.Sixes(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsSixPlayerOne.setPosition(910, 261);
			hintsPointsSixPlayerOne.setString(str1);
		}
		if (h.ThreeOfAKind(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::ThreeOfKind)] == false)
		{
			point = h.ThreeOfAKind(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsThreeOfAKindPlayerOne.setPosition(910, 369);
			hintsPointsThreeOfAKindPlayerOne.setString(str1);
		}
		if (h.FourOfAKind(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::FourOfKind)] == false)
		{
			point = h.FourOfAKind(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFourOfAKindPlayerOne.setPosition(910, 405);
			hintsPointsFourOfAKindPlayerOne.setString(str1);
		}
		if (h.FullHouse(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Full)] == false)
		{
			point = h.FullHouse(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFullPlayerOne.setPosition(910, 441);
			hintsPointsFullPlayerOne.setString(str1);
		}
		if (h.SmallStraight(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Small)] == false)
		{
			point = h.SmallStraight(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsSmallPlayerOne.setPosition(910, 477);
			hintsPointsSmallPlayerOne.setString(str1);
		}
		if (h.LargeStraight(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Large)] == false)
		{
			point = h.LargeStraight(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsLargePlayerOne.setPosition(910, 513);
			hintsPointsLargePlayerOne.setString(str1);
		}
		if (h.Chance(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Chance)] == false)
		{
			point = h.Chance(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsChancePlayerOne.setPosition(910, 549);
			hintsPointsChancePlayerOne.setString(str1);
		}
		if (h.Yahtzee(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Yahtzee)] == false)
		{
			point = h.Yahtzee(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsYahtzeePlayerOne.setPosition(910, 585);
			hintsPointsYahtzeePlayerOne.setString(str1);
		}
	}
	else if (player == 2)
	{
		if (h.Ones(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::One)] == false)
		{
			point = h.Ones(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsOnePlayerTwo.setPosition(1010, 81);
			hintsPointsOnePlayerTwo.setString(str1);
		}
		if (h.Twos(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Two)] == false)
		{
			point = h.Twos(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsTwoPlayerTwo.setPosition(1010, 117);
			hintsPointsTwoPlayerTwo.setString(str1);
		}
		if (h.Threes(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Three)] == false)
		{
			point = h.Threes(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsThreePlayerTwo.setPosition(1010, 153);
			hintsPointsThreePlayerTwo.setString(str1);
		}
		if (h.Fours(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Four)] == false)
		{
			point = h.Fours(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFourPlayerTwo.setPosition(1010, 189);
			hintsPointsFourPlayerTwo.setString(str1);
		}
		if (h.Fives(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Five)] == false)
		{
			point = h.Fives(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFivePlayerTwo.setPosition(1010, 225);
			hintsPointsFivePlayerTwo.setString(str1);
		}
		if (h.Sixes(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Six)] == false)
		{
			point = h.Sixes(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsSixPlayerTwo.setPosition(1010, 261);
			hintsPointsSixPlayerTwo.setString(str1);
		}
		if (h.ThreeOfAKind(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::ThreeOfKind)] == false)
		{
			point = h.ThreeOfAKind(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsThreeOfAKindPlayerTwo.setPosition(1010, 369);
			hintsPointsThreeOfAKindPlayerTwo.setString(str1);
		}
		if (h.FourOfAKind(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::FourOfKind)] == false)
		{
			point = h.FourOfAKind(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFourOfAKindPlayerTwo.setPosition(1010, 405);
			hintsPointsFourOfAKindPlayerTwo.setString(str1);
		}
		if (h.FullHouse(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Full)] == false)
		{
			point = h.FullHouse(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsFullPlayerTwo.setPosition(1010, 441);
			hintsPointsFullPlayerTwo.setString(str1);
		}
		if (h.SmallStraight(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Small)] == false)
		{
			point = h.SmallStraight(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsSmallPlayerTwo.setPosition(1010, 477);
			hintsPointsSmallPlayerTwo.setString(str1);
		}
		if (h.LargeStraight(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Large)] == false)
		{
			point = h.LargeStraight(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsLargePlayerTwo.setPosition(1010, 513);
			hintsPointsLargePlayerTwo.setString(str1);
		}
		if (h.Chance(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Chance)] == false)
		{
			point = h.Chance(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsChancePlayerTwo.setPosition(1010, 549);
			hintsPointsChancePlayerTwo.setString(str1);
		}
		if (h.Yahtzee(keptDices) != 0 && checkPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Yahtzee)] == false)
		{
			point = h.Yahtzee(keptDices);
			std::string str1 = std::to_string(point);
			hintsPointsYahtzeePlayerTwo.setPosition(1010, 585);
			hintsPointsYahtzeePlayerTwo.setString(str1);
		}
	}
}

void GameGraphics::SetStatisticsTable()
{
	statisticsTable.setSize(sf::Vector2f(700, 150));
	statisticsTable.setOutlineThickness(3);
	statisticsTable.setOutlineColor(sf::Color::Black);
	statisticsTable.setFillColor(sf::Color::White);
	statisticsTable.setPosition(20, 500);

	lineOneStatistics.setSize(sf::Vector2f(700, 50));
	lineOneStatistics.setOutlineThickness(3);
	lineOneStatistics.setOutlineColor(sf::Color::Black);
	lineOneStatistics.setFillColor(sf::Color::Transparent);
	lineOneStatistics.setPosition(20, 500);

	lineTwoStatistics.setSize(sf::Vector2f(700, 100));
	lineTwoStatistics.setOutlineThickness(3);
	lineTwoStatistics.setOutlineColor(sf::Color::Black);
	lineTwoStatistics.setFillColor(sf::Color::Transparent);
	lineTwoStatistics.setPosition(20, 500);

	columnOneStatistics.setSize(sf::Vector2f(130, 150));
	columnOneStatistics.setOutlineThickness(3);
	columnOneStatistics.setOutlineColor(sf::Color::Black);
	columnOneStatistics.setFillColor(sf::Color::Transparent);
	columnOneStatistics.setPosition(20, 500);

	columnDiceOne.setSize(sf::Vector2f(225, 150));
	columnDiceOne.setOutlineThickness(3);
	columnDiceOne.setOutlineColor(sf::Color::Black);
	columnDiceOne.setFillColor(sf::Color::Transparent);
	columnDiceOne.setPosition(20, 500);

	columnDiceTwo.setSize(sf::Vector2f(320, 150));
	columnDiceTwo.setOutlineThickness(3);
	columnDiceTwo.setOutlineColor(sf::Color::Black);
	columnDiceTwo.setFillColor(sf::Color::Transparent);
	columnDiceTwo.setPosition(20, 500);

	columnDiceThree.setSize(sf::Vector2f(415, 150));
	columnDiceThree.setOutlineThickness(3);
	columnDiceThree.setOutlineColor(sf::Color::Black);
	columnDiceThree.setFillColor(sf::Color::Transparent);
	columnDiceThree.setPosition(20, 500);

	columnDiceFour.setSize(sf::Vector2f(510, 150));
	columnDiceFour.setOutlineThickness(3);
	columnDiceFour.setOutlineColor(sf::Color::Black);
	columnDiceFour.setFillColor(sf::Color::Transparent);
	columnDiceFour.setPosition(20, 500);

	columnDiceFive.setSize(sf::Vector2f(605, 150));
	columnDiceFive.setOutlineThickness(3);
	columnDiceFive.setOutlineColor(sf::Color::Black);
	columnDiceFive.setFillColor(sf::Color::Transparent);
	columnDiceFive.setPosition(20, 500);

	if (!font.loadFromFile("Elephant.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}

	columnOneLineOneText.setCharacterSize(20);
	columnOneLineOneText.setFont(font);
	columnOneLineOneText.setFillColor(sf::Color::Black);
	columnOneLineOneText.setPosition(35, 560);
	columnOneLineOneText.setString("Apps/rolls");

	columnOneLineTwoText.setCharacterSize(20);
	columnOneLineTwoText.setFont(font);
	columnOneLineTwoText.setFillColor(sf::Color::Black);
	columnOneLineTwoText.setPosition(35, 610);
	columnOneLineTwoText.setString("Apps %");

	columnOneDiceText.setCharacterSize(20);
	columnOneDiceText.setFont(font);
	columnOneDiceText.setFillColor(sf::Color::Black);
	columnOneDiceText.setPosition(180, 510);
	columnOneDiceText.setString("One");

	columnTwoDiceText.setCharacterSize(20);
	columnTwoDiceText.setFont(font);
	columnTwoDiceText.setFillColor(sf::Color::Black);
	columnTwoDiceText.setPosition(270, 510);
	columnTwoDiceText.setString("Two");

	columnThreeDiceText.setCharacterSize(20);
	columnThreeDiceText.setFont(font);
	columnThreeDiceText.setFillColor(sf::Color::Black);
	columnThreeDiceText.setPosition(355, 510);
	columnThreeDiceText.setString("Three");

	columnFourDiceText.setCharacterSize(20);
	columnFourDiceText.setFont(font);
	columnFourDiceText.setFillColor(sf::Color::Black);
	columnFourDiceText.setPosition(455, 510);
	columnFourDiceText.setString("Four");

	columnFiveDiceText.setCharacterSize(20);
	columnFiveDiceText.setFont(font);
	columnFiveDiceText.setFillColor(sf::Color::Black);
	columnFiveDiceText.setPosition(555, 510);
	columnFiveDiceText.setString("Five");

	columnSixDiceText.setCharacterSize(20);
	columnSixDiceText.setFont(font);
	columnSixDiceText.setFillColor(sf::Color::Black);
	columnSixDiceText.setPosition(660, 510);
	columnSixDiceText.setString("Six");
}

void GameGraphics::DrawStatisticsTable(sf::RenderWindow& window)
{
	window.draw(statisticsTable);
	window.draw(lineOneStatistics);
	window.draw(lineTwoStatistics);
	window.draw(columnOneStatistics);
	window.draw(columnDiceOne);
	window.draw(columnDiceTwo);
	window.draw(columnDiceThree);
	window.draw(columnDiceFour);
	window.draw(columnDiceFive);
	window.draw(columnOneLineOneText);
	window.draw(columnOneLineTwoText);
	window.draw(columnOneDiceText);
	window.draw(columnTwoDiceText);
	window.draw(columnThreeDiceText);
	window.draw(columnFourDiceText);
	window.draw(columnFiveDiceText);
	window.draw(columnSixDiceText);
}

void GameGraphics::DrawStatistics(sf::RenderWindow& window)
{
	window.draw(diceOneApps);
	window.draw(diceTwoApps);
	window.draw(diceThreeApps);
	window.draw(diceFourApps);
	window.draw(diceFiveApps);
	window.draw(diceSixApps);
	window.draw(diceOnePercentage);
	window.draw(diceTwoPercentage);
	window.draw(diceThreePercentage);
	window.draw(diceFourPercentage);
	window.draw(diceFivePercentage);
	window.draw(diceSixPercentage);
}

void GameGraphics::SetStatisticsData()
{
	if (!font.loadFromFile("Elephant.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}

	diceOneApps.setCharacterSize(18);
	diceOneApps.setFont(font);
	diceOneApps.setFillColor(sf::Color::Black);

	diceTwoApps.setCharacterSize(18);
	diceTwoApps.setFont(font);
	diceTwoApps.setFillColor(sf::Color::Black);

	diceThreeApps.setCharacterSize(18);
	diceThreeApps.setFont(font);
	diceThreeApps.setFillColor(sf::Color::Black);

	diceFourApps.setCharacterSize(18);
	diceFourApps.setFont(font);
	diceFourApps.setFillColor(sf::Color::Black);

	diceFiveApps.setCharacterSize(18);
	diceFiveApps.setFont(font);
	diceFiveApps.setFillColor(sf::Color::Black);

	diceSixApps.setCharacterSize(18);
	diceSixApps.setFont(font);
	diceSixApps.setFillColor(sf::Color::Black);

	diceOnePercentage.setCharacterSize(18);
	diceOnePercentage.setFont(font);
	diceOnePercentage.setFillColor(sf::Color::Black);

	diceTwoPercentage.setCharacterSize(18);
	diceTwoPercentage.setFont(font);
	diceTwoPercentage.setFillColor(sf::Color::Black);

	diceThreePercentage.setCharacterSize(18);
	diceThreePercentage.setFont(font);
	diceThreePercentage.setFillColor(sf::Color::Black);

	diceFourPercentage.setCharacterSize(18);
	diceFourPercentage.setFont(font);
	diceFourPercentage.setFillColor(sf::Color::Black);

	diceFivePercentage.setCharacterSize(18);
	diceFivePercentage.setFont(font);
	diceFivePercentage.setFillColor(sf::Color::Black);

	diceSixPercentage.setCharacterSize(18);
	diceSixPercentage.setFont(font);
	diceSixPercentage.setFillColor(sf::Color::Black);
}

void GameGraphics::PlaceApps_Rolls(int rollCounter)
{
	std::stringstream streamDiceOne;
	streamDiceOne << diceFrequency[0] << "/" << rollCounter;
	std::string sDiceOne = streamDiceOne.str();
	diceOneApps.setPosition(176, 562);
	diceOneApps.setString(sDiceOne);

	std::stringstream streamDiceTwo;
	streamDiceTwo << diceFrequency[1] << "/" << rollCounter;
	std::string sDiceTwo = streamDiceTwo.str();
	diceTwoApps.setPosition(275, 562);
	diceTwoApps.setString(sDiceTwo);

	std::stringstream streamDiceThree;
	streamDiceThree << diceFrequency[2] << "/" << rollCounter;
	std::string sDiceThree = streamDiceThree.str();
	diceThreeApps.setPosition(370, 562);
	diceThreeApps.setString(sDiceThree);

	std::stringstream streamDiceFour;
	streamDiceFour << diceFrequency[3] << "/" << rollCounter;
	std::string sDiceFour = streamDiceFour.str();
	diceFourApps.setPosition(465, 562);
	diceFourApps.setString(sDiceFour);

	std::stringstream streamDiceFive;
	streamDiceFive << diceFrequency[4] << "/" << rollCounter;
	std::string sDiceFive = streamDiceFive.str();
	diceFiveApps.setPosition(560, 562);
	diceFiveApps.setString(sDiceFive);

	std::stringstream streamDiceSix;
	streamDiceSix << diceFrequency[5] << "/" << rollCounter;
	std::string sDiceSix = streamDiceSix.str();
	diceSixApps.setPosition(653, 562);
	diceSixApps.setString(sDiceSix);
}

void GameGraphics::PlacePercentage(int diceCounter)
{
	std::stringstream streamPercentajeOne;
	if (diceFrequency[0] != 0)
		streamPercentajeOne << std::fixed << std::setprecision(2) << (diceFrequency[0] * 100) / diceCounter << "%";
	else streamPercentajeOne << "0.00%";
	std::string sPercentageOne = streamPercentajeOne.str();
	diceOnePercentage.setPosition(162, 612);
	diceOnePercentage.setString(sPercentageOne);

	std::stringstream streamPercentajeTwo;
	if (diceFrequency[1] != 0)
		streamPercentajeTwo << std::fixed << std::setprecision(2) << (diceFrequency[1] * 100) / diceCounter << "%";
	else streamPercentajeTwo << "0.00%";
	std::string sPercentageTwo = streamPercentajeTwo.str();
	diceTwoPercentage.setPosition(257, 612);
	diceTwoPercentage.setString(sPercentageTwo);

	std::stringstream streamPercentajeThree;
	if (diceFrequency[2] != 0)
		streamPercentajeThree << std::fixed << std::setprecision(2) << (diceFrequency[2] * 100) / diceCounter << "%";
	else streamPercentajeThree << "0.00%";
	std::string sPercentageThree = streamPercentajeThree.str();
	diceThreePercentage.setPosition(352, 612);
	diceThreePercentage.setString(sPercentageThree);

	std::stringstream streamPercentajeFour;
	if (diceFrequency[3] != 0)
		streamPercentajeFour << std::fixed << std::setprecision(2) << (diceFrequency[3] * 100) / diceCounter << "%";
	else streamPercentajeFour << "0.00%";
	std::string sPercentageFour = streamPercentajeFour.str();
	diceFourPercentage.setPosition(447, 612);
	diceFourPercentage.setString(sPercentageFour);

	std::stringstream streamPercentajeFive;
	if (diceFrequency[4] != 0)
		streamPercentajeFive << std::fixed << std::setprecision(2) << (diceFrequency[4] * 100) / diceCounter << "%";
	else streamPercentajeFive << "0.00%";
	std::string sPercentageFive = streamPercentajeFive.str();
	diceFivePercentage.setPosition(542, 612);
	diceFivePercentage.setString(sPercentageFive);

	std::stringstream streamPercentajeSix;
	if (diceFrequency[5] != 0)
		streamPercentajeSix << std::fixed << std::setprecision(2) << (diceFrequency[5] * 100) / diceCounter << "%";
	else streamPercentajeSix << "0.00%";
	std::string sPercentageSix = streamPercentajeSix.str();
	diceSixPercentage.setPosition(637, 612);
	diceSixPercentage.setString(sPercentageSix);
}

GameGraphics::GameGraphics(sf::RenderWindow& window, string nameOfTheFrirstPlayer, string nameOfTheSecondPlayer)
{
	SetWindow(window);
	SetDices();
	SetPlayer();
	SetRollButton(window);
	SetTable();
	SetPointsButtons();
	SetAllHints(hintsPoints);
	SetStatisticsTable();
	SetStatisticsData();

	int numberOfRolls = 3;
	int numberOfMoves = 1;
	Player player1("player1");
	Player player2("player2");
	std::reference_wrapper<Player> firstPlayer = player1;
	std::reference_wrapper<Player> secondPlayer = player2;
	playerButtonImageTwo.setColor(sf::Color(256, 256, 256));

	std::ofstream logFile("Log.log", std::ios::app);

	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			case sf::Event::MouseMoved:
				MouseMoved(window);
				break;
			case sf::Event::MouseButtonPressed:
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (diceOneImage.getGlobalBounds().contains(mousePosF) && numberOfRolls != 3)
				{
					if (m_keptDices[0] == 0)
					{
						diceOneImage.setColor(sf::Color(250, 20, 20));
						m_keptDices[0] = 1;
					}
					else
					{
						diceOneImage.setColor(sf::Color(255, 255, 255));
						m_keptDices[0] = 0;
					}
				}
				if (diceTwoImage.getGlobalBounds().contains(mousePosF) && numberOfRolls != 3)
				{
					if (m_keptDices[1] == 0)
					{
						diceTwoImage.setColor(sf::Color(250, 20, 20));
						m_keptDices[1] = 1;
					}
					else
					{
						diceTwoImage.setColor(sf::Color(255, 255, 255));
						m_keptDices[1] = 0;
					}
				}
				if (diceThreeImage.getGlobalBounds().contains(mousePosF) && numberOfRolls != 3)
				{
					if (m_keptDices[2] == 0)
					{
						diceThreeImage.setColor(sf::Color(250, 20, 20));
						m_keptDices[2] = 1;
					}
					else
					{
						diceThreeImage.setColor(sf::Color(255, 255, 255));
						m_keptDices[2] = 0;
					}
				}
				if (diceFourImage.getGlobalBounds().contains(mousePosF) && numberOfRolls != 3)
				{
					if (m_keptDices[3] == 0)
					{
						diceFourImage.setColor(sf::Color(250, 20, 20));
						m_keptDices[3] = 1;
					}
					else
					{
						diceFourImage.setColor(sf::Color(255, 255, 255));
						m_keptDices[3] = 0;
					}
				}
				if (diceFiveImage.getGlobalBounds().contains(mousePosF) && numberOfRolls != 3)
				{
					if (m_keptDices[4] == 0)
					{
						diceFiveImage.setColor(sf::Color(250, 20, 20));
						m_keptDices[4] = 1;
					}
					else
					{
						diceFiveImage.setColor(sf::Color(255, 255, 255));
						m_keptDices[4] = 0;
					}
				}
				if (rollButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls > 0)
				{
					rollCounter++;
					RollDices(window);
					numberOfRolls--;
					for (auto iterator = m_keptDices.begin(); iterator != m_keptDices.end(); ++iterator) 
						if (*iterator == 0) 
							diceCounter++;
					PlaceApps_Rolls(rollCounter);
					PlacePercentage(diceCounter);
					
					if (numberOfRolls == 2)
					{
						rollButton.loadFromFile("images\\RollButton2.png");
					}
					else if (numberOfRolls == 1)
					{
						rollButton.loadFromFile("images\\RollButton1.png");
					}
					else if (numberOfRolls == 0)
					{
						rollButton.loadFromFile("images\\RollButton0.png");
					}
					for (auto iterator = m_rollDices.begin(); iterator != m_rollDices.end(); ++iterator)
						diceHints[*iterator - 1]++;

					ResetHints();
					if (numberOfRolls == 2 || numberOfRolls == 1 || numberOfRolls == 0)
						if (numberOfMoves % 2 != 0)
							DisplayHints(1, diceHints, firstPlayer);
						else if (numberOfMoves % 2 == 0)
							DisplayHints(2, diceHints, firstPlayer);

					std::fill(diceHints.begin(), diceHints.end(), 0);
				}
				else if (rollButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls == 0)
				{
					ErrorWindow();
				}
				if (onesButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::One)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on ones.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(1);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsOnePlayerOne);
						PlacePoints(910, 81, firstPlayer.get().m_upperPoints.back(), pointsOnePlayerOne);
					}
					else
					{
						SetText(pointsOnePlayerTwo);
						PlacePoints(1010, 81, firstPlayer.get().m_upperPoints.back(), pointsOnePlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (twosButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Two)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on twos.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(2);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsTwoPlayerOne);
						PlacePoints(910, 117, firstPlayer.get().m_upperPoints.back(), pointsTwoPlayerOne);
					}
					else
					{
						SetText(pointsTwoPlayerTwo);
						PlacePoints(1010, 117, firstPlayer.get().m_upperPoints.back(), pointsTwoPlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (threesButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Three)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on threes.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(3);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsThreePlayerOne);
						PlacePoints(910, 153, firstPlayer.get().m_upperPoints.back(), pointsThreePlayerOne);
					}
					else
					{
						SetText(pointsThreePlayerTwo);
						PlacePoints(1010, 153, firstPlayer.get().m_upperPoints.back(), pointsThreePlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (foursButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Four)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on fours.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(4);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsFourPlayerOne);
						PlacePoints(910, 189, firstPlayer.get().m_upperPoints.back(), pointsFourPlayerOne);
					}
					else
					{
						SetText(pointsFourPlayerTwo);
						PlacePoints(1010, 189, firstPlayer.get().m_upperPoints.back(), pointsFourPlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (fivesButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Five)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on fives.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(5);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsFivePlayerOne);
						PlacePoints(910, 225, firstPlayer.get().m_upperPoints.back(), pointsFivePlayerOne);
					}
					else
					{
						SetText(pointsFivePlayerTwo);
						PlacePoints(1010, 225, firstPlayer.get().m_upperPoints.back(), pointsFivePlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (sixesButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Six)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on sixes.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(6);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsSixPlayerOne);
						PlacePoints(910, 261, firstPlayer.get().m_upperPoints.back(), pointsSixPlayerOne);
					}
					else
					{
						SetText(pointsSixPlayerTwo);
						PlacePoints(1010, 261, firstPlayer.get().m_upperPoints.back(), pointsSixPlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (threeOfAKindButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::ThreeOfKind)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on three of a kind.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(9);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsThreeOfAKindPlayerOne);
						PlacePoints(910, 369, firstPlayer.get().m_lowerPoints.back(), pointsThreeOfAKindPlayerOne);
					}
					else
					{
						SetText(pointsThreeOfAKindPlayerTwo);
						PlacePoints(1010, 369, firstPlayer.get().m_lowerPoints.back(), pointsThreeOfAKindPlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (fourOfAKindButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::FourOfKind)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on four of a kind.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(10);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsFourOfAKindPlayerOne);
						PlacePoints(910, 405, firstPlayer.get().m_lowerPoints.back(), pointsFourOfAKindPlayerOne);
					}
					else
					{
						SetText(pointsFourOfAKindPlayerTwo);
						PlacePoints(1010, 405, firstPlayer.get().m_lowerPoints.back(), pointsFourOfAKindPlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (fullButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Full)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on full house.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(11);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsFullPlayerOne);
						PlacePoints(910, 441, firstPlayer.get().m_lowerPoints.back(), pointsFullPlayerOne);
					}
					else
					{
						SetText(pointsFullPlayerTwo);
						PlacePoints(1010, 441, firstPlayer.get().m_lowerPoints.back(), pointsFullPlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (smallButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Small)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on small straight.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(12);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsSmallPlayerOne);
						PlacePoints(910, 477, firstPlayer.get().m_lowerPoints.back(), pointsSmallPlayerOne);
					}
					else
					{
						SetText(pointsSmallPlayerTwo);
						PlacePoints(1010, 477, firstPlayer.get().m_lowerPoints.back(), pointsSmallPlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (largeButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Large)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on large straight.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(13);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsLargePlayerOne);
						PlacePoints(910, 513, firstPlayer.get().m_lowerPoints.back(), pointsLargePlayerOne);
					}
					else
					{
						SetText(pointsLargePlayerTwo);
						PlacePoints(1010, 513, firstPlayer.get().m_lowerPoints.back(), pointsLargePlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (chanceButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Chance)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on chance.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(14);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsChancePlayerOne);
						PlacePoints(910, 549, firstPlayer.get().m_lowerPoints.back(), pointsChancePlayerOne);
					}
					else
					{
						SetText(pointsChancePlayerTwo);
						PlacePoints(1010, 549, firstPlayer.get().m_lowerPoints.back(), pointsChancePlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (yahtzeeButtonImage.getGlobalBounds().contains(mousePosF) && numberOfRolls < 3 && firstPlayer.get().m_possiblePlacesForPoints[int(Points::TypesOfScore::Yahtzee)] == false)
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("The player places his points on yahtzee.", Logger::Level::Info);
					ResetHints();
					SetDices();
					SetArrayOfDices(firstPlayer);
					firstPlayer.get().PlacePoints(15);
					if (numberOfMoves % 2 != 0)
					{
						SetText(pointsYahtzeePlayerOne);
						PlacePoints(910, 585, firstPlayer.get().m_lowerPoints.back(), pointsYahtzeePlayerOne);
					}
					else
					{
						SetText(pointsYahtzeePlayerTwo);
						PlacePoints(1010, 585, firstPlayer.get().m_lowerPoints.back(), pointsYahtzeePlayerTwo);
					}
					std::fill(std::begin(firstPlayer.get().m_keptDiceforPoints), std::end(firstPlayer.get().m_keptDiceforPoints), 0);
					std::swap(firstPlayer, secondPlayer);
					ResetDice();
					numberOfRolls = 3;
					numberOfMoves++;
					rollButton.loadFromFile("images\\RollButton3.png");
					SwitchPlayer();
				}
				if (numberOfMoves == 26)
				{
					std::swap(firstPlayer, secondPlayer);
					SwitchPlayer();
					Points points;
					SetText(pointsSumPlayerOne);
					PlacePoints(910, 297, points.PartialSum(firstPlayer.get().m_upperPoints), pointsSumPlayerOne);
					SetText(pointsBonusPlayerOne);
					PlacePoints(910, 333, points.VerifyBonus(firstPlayer.get().m_upperPoints), pointsBonusPlayerOne);
					SetText(pointsTotalPlayerOne);
					PlacePoints(910, 621, firstPlayer.get().finalPoints(), pointsTotalPlayerOne);
					pointsFirstPlayer = firstPlayer.get().finalPoints();
					std::swap(firstPlayer, secondPlayer);
					SwitchPlayer();
				}
				if (numberOfMoves == 27)
				{
					std::swap(firstPlayer, secondPlayer);
					SwitchPlayer();
					Points points;
					SetText(pointsSumPlayerTwo);
					PlacePoints(1010, 297, points.PartialSum(firstPlayer.get().m_upperPoints), pointsSumPlayerTwo);
					SetText(pointsBonusPlayerTwo);
					PlacePoints(1010, 333, points.VerifyBonus(firstPlayer.get().m_upperPoints), pointsBonusPlayerTwo);
					SetText(pointsTotalPlayerTwo);
					PlacePoints(1010, 621, firstPlayer.get().finalPoints(), pointsTotalPlayerTwo);
					pointsSecondPlayer = firstPlayer.get().finalPoints();
					std::swap(firstPlayer, secondPlayer);
					SwitchPlayer();

					if (pointsFirstPlayer > pointsSecondPlayer)
					{
						ok = 1;
						winnerPoints = pointsFirstPlayer;
					}
					else if (pointsFirstPlayer < pointsSecondPlayer)
					{
						ok = 2;
						winnerPoints = pointsSecondPlayer;
					}
					else
					{
						ok = 3;
						winnerPoints = pointsFirstPlayer;
					}

					playerButtonImageOne.setColor(sf::Color(255, 255, 255));
					playerButtonImageTwo.setColor(sf::Color(255, 255, 255));

					TheWinner winnerWindow(window, nameOfTheFrirstPlayer, nameOfTheSecondPlayer, ok, winnerPoints, pointsFirstPlayer, pointsSecondPlayer);
				}

			}
			break;
			}

		}
		window.clear();

		window.draw(backgroundImage);
		DrawDices(window);
		window.draw(rollButtonImage);
		DrawPlayer(window);
		DrawTable(window);
		DrawText(window, nameOfTheFrirstPlayer, nameOfTheSecondPlayer);
		DrawPointsButtons(window);
		DrawPoints(window);
		DrawHints(window);
		DrawStatisticsTable(window);
		DrawStatistics(window);
		window.display();
	}
}


