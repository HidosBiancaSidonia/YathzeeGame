#include "Rules1.h"
#include "Rules2.h"
#include "..\Logging\Logger.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

Rules1::Rules1(sf::RenderWindow& window)
{
	sf::Texture background;
	sf::Sprite backgroundImage;

	std::ofstream logFile("Log.log", std::ios::app);

	if (!background.loadFromFile("images\\Rules2.jpg"))
	{
		std::cout << "Error: Could not display image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display second rules image!", Logger::Level::Error);
	}

	backgroundImage.setTexture(background);

	sf::Texture backButton;
	sf::Texture nextButton;
	sf::Texture backToTheMainMenuButton;
	sf::Sprite backButtonImage;
	sf::Sprite nextButtonImage;
	sf::Sprite backToTheMainMenuButtonImage;

	if (!backButton.loadFromFile("images\\back.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display back button!", Logger::Level::Error);
	}
	backButtonImage.setPosition(500.0f, 550.0f);
	if (!nextButton.loadFromFile("images\\next.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display next button!", Logger::Level::Error);
	}
	nextButtonImage.setPosition(890.0f, 550.0f);
	if (!backToTheMainMenuButton.loadFromFile("images\\backtomainmenu.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display 'back to maine menu' button!", Logger::Level::Error);
	}

	backToTheMainMenuButtonImage.setPosition(100.0f, 550.0f);


	float backButtonWidth = backButtonImage.getLocalBounds().width;
	float backButtonHeight = backButtonImage.getLocalBounds().height;
	float nextButtonWidth = nextButtonImage.getLocalBounds().width;
	float nextButtonHeight = nextButtonImage.getLocalBounds().height;
	float backToTheMainMenuButtonWidth = backToTheMainMenuButtonImage.getLocalBounds().width;
	float backToTheMainMenuButtonHeight = backToTheMainMenuButtonImage.getLocalBounds().height;

	backButtonImage.setTexture(backButton);
	nextButtonImage.setTexture(nextButton);
	backToTheMainMenuButtonImage.setTexture(backToTheMainMenuButton);

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
				if (nextButtonImage.getGlobalBounds().contains(mousePosF))
				{
					nextButtonImage.setColor(sf::Color(250, 20, 20));
				}
				else
				{
					nextButtonImage.setColor(sf::Color(255, 255, 255));
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
					Rules rules(window);
				}
				if (nextButtonImage.getGlobalBounds().contains(mousePosF))
				{
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Goig to next rules page.", Logger::Level::Info);
					Rules2 rules2(window);
				}
				break;
			}
			}
		}
		window.clear();

		window.draw(backgroundImage);
		window.draw(backButtonImage);
		window.draw(nextButtonImage);
		window.draw(backToTheMainMenuButtonImage);

		window.display();
	}
}
