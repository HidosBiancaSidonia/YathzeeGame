#pragma once
#include "GameState.h"
//#include "Button.h"

class MainMenuState :
	public State
{
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();
	void EndState();

	void UpdateInput(const float& deltaTime);
	void UpdateButtons();
	void Update(const float& deltaTime);
	void RenderButtons(sf::RenderTarget* target = nullptr);
	void Render(sf::RenderTarget* target = nullptr);

private:
	void initFonts();
	void InitKeybinds();
	void initButtons();

	sf::RectangleShape background;
	sf::Font font;

	//std::map<std::string, Button*> buttons;
};

