#include "TopFive.h"
TopFive::TopFive(int validation)
{
	sf::RenderWindow windowForTopFive(sf::VideoMode(700, 400), "Yathzee Game", sf::Style::Titlebar | sf::Style::Close);
	

	if (!background.loadFromFile("images\\winner.jpg"))
	{
		std::cout << "Error: Could not display Yahtzee Game image" << std::endl;
	}

	backgroundImage.setTexture(background);

	if (!font.loadFromFile("Elephant.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}

	title.setCharacterSize(50);
	title.setFont(font);
	title.setFillColor(sf::Color(255, 80, 80));
	title.setPosition(50, 5);
	title.setString("Top 5 scores:");

	typedef std::pair<std::string, int> pair;
	std::ifstream in;
	in.open("top5.txt");
	
	std::vector<pair>vectorOfWinners;
	vectorOfWinners.clear();

	while (in >> name >> score)
	{
		std::stringstream geek(score);

		int scoreInt = 0;
		geek >> scoreInt;
		vectorOfWinners.push_back(make_pair(name, scoreInt));
	}

	std::sort(vectorOfWinners.begin(), vectorOfWinners.end(), [](const pair& x, const pair& y) {
		if (x.second != y.second)
			return x.second > y.second;
		return x.first > y.first; });

	if (!font1.loadFromFile("Elephant.ttf"))
	{
		std::cout << "Error: Could not display font!" << std::endl;
	}

	topFive.setCharacterSize(50);
	topFive.setFont(font1);
	topFive.setFillColor(sf::Color(255, 204, 204));
	topFive.setPosition(50, 60);

	if (vectorOfWinners.size() == 1)
	{
		topFive.setString("1." + vectorOfWinners[0].first + " -Score: " + std::to_string(vectorOfWinners[0].second) );
	}
	else if (vectorOfWinners.size() == 2)
	{
		topFive.setString("1." + vectorOfWinners[0].first + " -Score: " + std::to_string(vectorOfWinners[0].second) + "\n2." +
			vectorOfWinners[1].first + " -Score: " + std::to_string(vectorOfWinners[1].second));
			
	}
	else if (vectorOfWinners.size() == 3)
	{
		topFive.setString("1." + vectorOfWinners[0].first + " -Score: " + std::to_string(vectorOfWinners[0].second) + "\n2." +
			vectorOfWinners[1].first + " -Score: " + std::to_string(vectorOfWinners[1].second) + "\n3." +
			vectorOfWinners[2].first + " -Score: " + std::to_string(vectorOfWinners[2].second));
	}
	else if (vectorOfWinners.size() == 4)
	{
		topFive.setString("1." + vectorOfWinners[0].first + " -Score: " + std::to_string(vectorOfWinners[0].second) + "\n2." +
			vectorOfWinners[1].first + " -Score: " + std::to_string(vectorOfWinners[1].second) + "\n3." +
			vectorOfWinners[2].first + " -Score: " + std::to_string(vectorOfWinners[2].second) + "\n4." +
			vectorOfWinners[3].first + " -Score: " + std::to_string(vectorOfWinners[3].second));
	}
	else if (vectorOfWinners.size() >= 5)
	{
		topFive.setString("1." + vectorOfWinners[0].first + " -Score: " + std::to_string(vectorOfWinners[0].second) + "\n2." +
			vectorOfWinners[1].first + " -Score: " + std::to_string(vectorOfWinners[1].second) + "\n3." + vectorOfWinners[2].first + " - Score: " + std::to_string(vectorOfWinners[2].second) + "\n4." +
			vectorOfWinners[3].first + " -Score: " + std::to_string(vectorOfWinners[3].second) + "\n5." +
			vectorOfWinners[4].first + " -Score: " + std::to_string(vectorOfWinners[4].second));
	}

	while (windowForTopFive.isOpen())
	{
		sf::Event event;
		while (windowForTopFive.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				windowForTopFive.close();
			}
			break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					windowForTopFive.close();
				break;
			}

		}
		windowForTopFive.clear();
		windowForTopFive.draw(backgroundImage);
		windowForTopFive.draw(title);
		windowForTopFive.draw(topFive);
		windowForTopFive.display();
	}
}


