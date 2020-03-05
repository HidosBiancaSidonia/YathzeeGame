#include "UpperScores.h"
#include "Rules2.h"
#include "..\Logging\Logger.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

UpperScores::UpperScores(sf::RenderWindow& window)
{
    sf::Texture background;
    sf::Sprite backgroundImage;

	std::ofstream logFile("Log.log", std::ios::app);

	if (!background.loadFromFile("images\\upperScores.jpg"))
	{
		std::cout << "Error: Could not display image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Upper Score image!", Logger::Level::Error);
	}

    backgroundImage.setTexture(background);

    sf::Texture backButton;

    sf::Sprite backButtonImage;

	if (!backButton.loadFromFile("images\\back.png"))
	{
		std::cout << "Can't find the image" << std::endl; Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display back button!", Logger::Level::Error);
	}
    backButtonImage.setPosition(890.0f, 550.0f);

    float backButtonWidth = backButtonImage.getLocalBounds().width;
    float backButtonHeight = backButtonImage.getLocalBounds().height;

    backButtonImage.setTexture(backButton);

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
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (backButtonImage.getGlobalBounds().contains(mousePosF))
                {
					Logger logger(logFile, Logger::Level::Info);
					logger.Log("Goig to previous rules page.", Logger::Level::Info);
                    Rules2 rules2(window);
                }
                break;
            }
            }
        }
        window.clear();

        window.draw(backgroundImage);
        window.draw(backButtonImage);

        window.display();
    }
}

