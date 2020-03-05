#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initFonts();
	this->InitKeybinds();
	this->initButtons();



	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Green);
}

MainMenuState::~MainMenuState()
{

	/*auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}*/
}

void MainMenuState::EndState()
{
	std::cout << "Ending MainMenuState." << '\n';
}

void MainMenuState::UpdateInput(const float& deltaTime)
{
	this->CheckForQuit();

	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))


}


void MainMenuState::UpdateButtons()
{

	/*for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}

	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameStates(this->window, this->supportedKeys, this->states));
	}*/
}

void MainMenuState::Update(const float& deltaTime)
{
	this->updateMousePositions();
	this->UpdateInput(deltaTime);

	this->UpdateButtons();


	//system("cls");
	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
}

void MainMenuState::RenderButtons(sf::RenderTarget* target)
{
	/*for (auto& it : this->buttons)
	{
		it.second->render(target);
	}*/
}

void MainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->RenderButtons(target);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("x64/Debug/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::InitKeybinds()
{
	std::ifstream ifs("x64/Debug/mainmenustate_keybinds.ini");

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

void MainMenuState::initButtons()
{
	/*this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
		&this->font, "Start Game!",
		sf::Color(70, 70, 70, 200), sf::Color(70, 70, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50,
		&this->font, "Quit",
		sf::Color(100, 100, 100, 200), sf::Color(70, 70, 150, 255), sf::Color(20, 20, 20, 200));*/
}


