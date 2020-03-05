#include "Rules2.h"
#include "Menu.h"
#include "Rules1.h"
#include "UpperScores.h"
#include "LowerScores.h"
#include "ScratchOrDumpScores.h"
#include "..\Logging\Logger.h"

#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

Rules2::Rules2(sf::RenderWindow& window)
{
	sf::Texture background;
	sf::Sprite backgroundImage;

	std::ofstream logFile("Log.log", std::ios::app);

	if (!background.loadFromFile("images\\Rules3.jpg"))
	{
		std::cout << "Error: Could not display image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display third rules image!", Logger::Level::Error);
	}

	backgroundImage.setTexture(background);

	sf::Texture backButton;
	sf::Texture backToTheMainMenuButton;
	sf::Texture upperScoresButton;
	sf::Texture lowerScoresButton;
	sf::Texture scratchOrDumpScoresButton;


	sf::Sprite backButtonImage;
	sf::Sprite backToTheMainMenuButtonImage;
	sf::Sprite upperScoresButtonImage;
	sf::Sprite lowerScoresButtonImage;
	sf::Sprite scratchOrDumpScoresButtonImage;

	if (!backButton.loadFromFile("images\\back.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display back button!", Logger::Level::Error);
	}
	backButtonImage.setPosition(500.0f, 550.0f);
	if (!backToTheMainMenuButton.loadFromFile("images\\backtomainmenu.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display 'back to main menu' button!", Logger::Level::Error);
	}
	backToTheMainMenuButtonImage.setPosition(100.0f, 550.0f);
	if (!upperScoresButton.loadFromFile("images\\upperScores.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display 'Upper Scores' button!", Logger::Level::Error);
	}
	upperScoresButtonImage.setPosition(300.0f, 350.0f);
	if (!lowerScoresButton.loadFromFile("images\\lowerScores.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display 'lower scores' button!", Logger::Level::Error);
	}
	lowerScoresButtonImage.setPosition(600.0f, 350.0f);
	if (!scratchOrDumpScoresButton.loadFromFile("images\\Scratch.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display 'Scratch' button!", Logger::Level::Error);
	}
	scratchOrDumpScoresButtonImage.setPosition(900.0f, 350.0f);

	float backButtonWidth = backButtonImage.getLocalBounds().width;
	float backButtonHeight = backButtonImage.getLocalBounds().height;
	float backToTheMainMenuButtonWidth = backToTheMainMenuButtonImage.getLocalBounds().width;
	float backToTheMainMenuButtonHeight = backToTheMainMenuButtonImage.getLocalBounds().height;
	float upperScoresButtonWidth = upperScoresButtonImage.getLocalBounds().width;
	float upperScoresButtonHeight = upperScoresButtonImage.getLocalBounds().height;
	float lowerScoresButtonWidth = lowerScoresButtonImage.getLocalBounds().width;
	float lowerScoresButtonHeight = lowerScoresButtonImage.getLocalBounds().height;
	float scratchOrDumpScoresButtonWidth = scratchOrDumpScoresButtonImage.getLocalBounds().width;
	float scratchOrDumpScoresButtonHeight = scratchOrDumpScoresButtonImage.getLocalBounds().height;

	backButtonImage.setTexture(backButton);
	backToTheMainMenuButtonImage.setTexture(backToTheMainMenuButton);
	upperScoresButtonImage.setTexture(upperScoresButton);
	lowerScoresButtonImage.setTexture(lowerScoresButton);
	scratchOrDumpScoresButtonImage.setTexture(scratchOrDumpScoresButton);

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
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

				if (backButtonImage.getGlobalBounds().contains(mousePosF))
				{
					backButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					backButtonImage.setColor(sf::Color(255, 255, 255));
				}
				if (backToTheMainMenuButtonImage.getGlobalBounds().contains(mousePosF))
				{
					backToTheMainMenuButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					backToTheMainMenuButtonImage.setColor(sf::Color(255, 255, 255));
				}

				if (upperScoresButtonImage.getGlobalBounds().contains(mousePosF))
				{
					upperScoresButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					upperScoresButtonImage.setColor(sf::Color(255, 255, 255));
				}
				if (lowerScoresButtonImage.getGlobalBounds().contains(mousePosF))
				{
					lowerScoresButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					lowerScoresButtonImage.setColor(sf::Color(255, 255, 255));
				}
				if (scratchOrDumpScoresButtonImage.getGlobalBounds().contains(mousePosF))
				{
					scratchOrDumpScoresButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					scratchOrDumpScoresButtonImage.setColor(sf::Color(255, 255, 255));
				}
			}
			break;
			case sf::Event::MouseButtonPressed:
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				if (backToTheMainMenuButtonImage.getGlobalBounds().contains(mousePosF))
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Goig back to menu.", Logger::Level::Info);
					Menu menu(window);
				}
				if (backButtonImage.getGlobalBounds().contains(mousePosF))
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Goig to previous rules page.", Logger::Level::Info);
					Rules1 rules1(window);
				}
				if (upperScoresButtonImage.getGlobalBounds().contains(mousePosF))
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Goig to Upper Score page.", Logger::Level::Info);
					UpperScores upperScores(window);
				}
				if (lowerScoresButtonImage.getGlobalBounds().contains(mousePosF))
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Goig to Lower Score page.", Logger::Level::Info);
					LowerScores lowerScores(window);
				}
				if (scratchOrDumpScoresButtonImage.getGlobalBounds().contains(mousePosF))
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Goig to Scratch Or Dump Score page.", Logger::Level::Info);
					ScratchOrDumpScores scratchOrDumpScores(window);
				}
				break;
			}
			}
		}
		window.clear();

		window.draw(backgroundImage);
		window.draw(backButtonImage);
		window.draw(backToTheMainMenuButtonImage);
		window.draw(upperScoresButtonImage);
		window.draw(lowerScoresButtonImage);
		window.draw(scratchOrDumpScoresButtonImage);

		window.display();
	}
}
