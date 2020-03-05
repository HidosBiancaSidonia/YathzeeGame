#include "GameState.h"

GameStates::GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->InitKeybinds();

}

GameStates::~GameStates()
{

}

void GameStates::EndState()
{
	std::cout << "Ending game states." << '\n';
}

void GameStates::UpdateInput(const float& deltaTime)
{
	this->CheckForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move Left"))))
		this->player.Move(deltaTime, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move Right"))))
		this->player.Move(deltaTime, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move Up"))))
		this->player.Move(deltaTime, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move Down"))))
		this->player.Move(deltaTime, 0.f, 1.f);
}

void GameStates::Update(const float& deltaTime)
{
	this->updateMousePositions();
	this->UpdateInput(deltaTime);

	this->player.Update(deltaTime);
}

void GameStates::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	this->player.Render(target);
}

void GameStates::InitKeybinds()
{
	std::ifstream ifs("x64/Debug/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();


}
