#include "YahtzeeGame.h"
#include "../Logging/Logger.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Yathzee Game", sf::Style::Titlebar | sf::Style::Close);
    // load sound and music into ram
    sf::Music msnd_intro;
    if (!msnd_intro.openFromFile("audio.ogg"))
        std::cout << "Error OFF : Failed to load audio.ogg" << std::endl;
    msnd_intro.play();
    Menu menu(window);
	return 0;
}


