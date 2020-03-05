#include "Menu.h"

#include "YahtzeeGame.h"
#include "Rules.h"
#include "GameGraphics.h"
#include "TheNameOfTheFirstPlayer.h"
#include "../Logging/Logger.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>


Menu::Menu(sf::RenderWindow& window)
{
    sf::Texture background;
    sf::Sprite backgroundImage;

	std::ofstream logFile("Log.log", std::ios::app);

    if (!background.loadFromFile("images\\YahtzeeGame.jpg"))
	{
		std::cout << "Error: Could not display Yahtzee Game image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Yahtzee Game image!", Logger::Level::Error);
	}

    backgroundImage.setTexture(background);


    sf::Texture playButton;
    sf::Texture rulesButton;
    sf::Texture exitButton;

    sf::Sprite playButtonImage;
    sf::Sprite rulesButtonImage;
    sf::Sprite exitButtonImage;

    if (!exitButton.loadFromFile("images\\exit.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display exit button!", Logger::Level::Error);
	}
    exitButtonImage.setPosition(230.0f, 500.0f);

    if (!playButton.loadFromFile("images\\play.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display play button!", Logger::Level::Error);
	}
    playButtonImage.setPosition(230.0f, 300.0f);

    if (!rulesButton.loadFromFile("images\\rules.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display rules button!", Logger::Level::Error);
	}
    rulesButtonImage.setPosition(230.0f, 400.0f);

    float playButtonWidth = playButtonImage.getLocalBounds().width;
    float playButtonHeight = playButtonImage.getLocalBounds().height;
    float rulesButtonWidth = rulesButtonImage.getLocalBounds().width;
    float rulesButtonHeight = rulesButtonImage.getLocalBounds().height;
    float exitButtonWidth = exitButtonImage.getLocalBounds().width;
    float exitButtonHeight = exitButtonImage.getLocalBounds().height;

    playButtonImage.setTexture(playButton);
    rulesButtonImage.setTexture(rulesButton);
    exitButtonImage.setTexture(exitButton);

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

                if (playButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    playButtonImage.setColor(sf::Color(250, 20, 20));
                }
                else
                {
                    playButtonImage.setColor(sf::Color(255, 255, 255));
                }
                if (rulesButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    rulesButtonImage.setColor(sf::Color(250, 20, 20));
                }
                else
                {
                    rulesButtonImage.setColor(sf::Color(255, 255, 255));
                }
                if (exitButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    exitButtonImage.setColor(sf::Color(250, 20, 20));
                }
                else
                {
                    exitButtonImage.setColor(sf::Color(255, 255, 255));
                }
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (playButtonImage.getGlobalBounds().contains(mousePosF))
                {
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Start game. Going to enter first player name.", Logger::Level::Info);
                    TheNameOfTheFirstPlayer nameOfTheFirstPlayer(window);
                }
                if (rulesButtonImage.getGlobalBounds().contains(mousePosF))
                {
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Rules", Logger::Level::Info);
                    Rules rules(window);
                }
                if (exitButtonImage.getGlobalBounds().contains(mousePosF))
                {
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Exit", Logger::Level::Info);
                    window.close();
                }
            }
            break;
            }
        }

        window.clear();
        window.draw(backgroundImage);
        window.draw(playButtonImage);
        window.draw(rulesButtonImage);
        window.draw(exitButtonImage);

        window.display();
    }
}


