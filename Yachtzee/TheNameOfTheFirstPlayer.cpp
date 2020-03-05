#include "TheNameOfTheFirstPlayer.h"
#include "TheNameOfTheSecondPlayer.h"
#include "../Logging/Logger.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

TheNameOfTheFirstPlayer::TheNameOfTheFirstPlayer(sf::RenderWindow& window)
{
    sf::Texture background;
    sf::Sprite backgroundImage;

	std::ofstream logFile("Log.log", std::ios::app);

    if (!background.loadFromFile("images\\RulesP.jpg"))
	{
		std::cout << "Error: Could not display Yahtzee Game image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display Yahtzee Game image!", Logger::Level::Error);
	}

    backgroundImage.setTexture(background);

    sf::Texture nextButton;
    sf::Sprite nextButtonImage;

    if (!nextButton.loadFromFile("images\\next.png"))
	{
		std::cout << "Can't find the image" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display next button!", Logger::Level::Error);
	}

    nextButtonImage.setPosition(890.0f, 550.0f);

    float nextButtonWidth = nextButtonImage.getLocalBounds().width;
    float nextButtonHeight = nextButtonImage.getLocalBounds().height;

    nextButtonImage.setTexture(nextButton);

    sf::Font font;
    if (!font.loadFromFile("Elephant.ttf"))
    {
        std::cout << "Error: Could not display font!" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not upload font!", Logger::Level::Error);
    }

    sf::Text text("Enter the name of the first player!", font, 50);
    text.setPosition(80, 90);
    text.setFillColor(sf::Color::Black);

    sf::Text userText("Player        1:", font, 30);
    userText.setPosition(90, 300);
    userText.setFillColor(sf::Color::Black);

    sf::RectangleShape rectangle(sf::Vector2f(400.f, 40.f));
    rectangle.setFillColor(sf::Color(180, 180, 180, 255));
    rectangle.setOutlineThickness(3.0f);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setPosition(300, 300);

    sf::Texture texture;
    if (!texture.loadFromFile("images\\man.png"))
    {
        std::cout << "Error: Could not display texture!" << std::endl;
		Logger logger(logFile, Logger::Level::Error);
		logger.Log("Could not display man's image!", Logger::Level::Error);
	}

    sf::Sprite player1(texture);
    player1.setPosition(160, 250);

    sf::Text textBoxText;
    textBoxText.setFont(font);
    textBoxText.setCharacterSize(24);
    textBoxText.setPosition(rectangle.getPosition());
    textBoxText.setFillColor(sf::Color::Black);

    sf::Event Event;

    while (window.isOpen())
    {

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
                if(nameOfTheFirstPlayer.length() > 0 && Event.key.code == sf::Keyboard::Enter)
                    TheNameOfTheSecondPlayer nameOfTheSecondPlayer(window, nameOfTheFirstPlayer);
                break;
            case sf::Event::TextEntered:
            {
                if (Event.text.unicode >= 33 && Event.text.unicode <= 126)
                    nameOfTheFirstPlayer += (char)Event.text.unicode;
                else
                    if (Event.text.unicode == 8)
                         nameOfTheFirstPlayer = nameOfTheFirstPlayer.substr(0, nameOfTheFirstPlayer.length() - 1);
                textBoxText.setString(nameOfTheFirstPlayer);
            }
            break;

            case sf::Event::MouseMoved:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

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
                if (nextButtonImage.getGlobalBounds().contains(mousePosF))
                {
					if (!nameOfTheFirstPlayer.length() > 0)
					{
						Logger logger(logFile, Logger::Level::Error);
						logger.Log("The player didn't write his name", Logger::Level::Error);
					}
					else if (nameOfTheFirstPlayer.length() > 0)
					{
						Logger logger(logFile, Logger::Level::Info);
						logger.Log("Next step. Going to enter second's player name.", Logger::Level::Info);
						TheNameOfTheSecondPlayer nameOfTheSecondPlayer(window, nameOfTheFirstPlayer);
					}
                }
            }
            break;
            }
        }

        window.clear();

        window.draw(backgroundImage);
        window.draw(nextButtonImage);
        window.draw(text);
        window.draw(userText);
        window.draw(rectangle);
        window.draw(player1);
        window.draw(textBoxText);
        window.display();
    }
}
