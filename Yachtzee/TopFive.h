#pragma once
#include<vector>
#include<string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>


class TopFive
{
public:
	TopFive(int validation);

private:
	sf::Texture background;
	sf::Sprite backgroundImage;

	sf::Text title;
	sf::Font font;

	sf::Text topFive;
	sf::Font font1;

	std::string name;
	std::string score;
};

