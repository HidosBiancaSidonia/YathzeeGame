//#include "GameState.h"
#include "MainMenuState.h"

class YahtzeeGraphics
{
private:
	void InitializeWindow();
	void InitializeStates();

public:
	YahtzeeGraphics();
	virtual ~YahtzeeGraphics();

	void EndApplication();

	void UpdateDeltaTime();
	void UpdateSFMLEvents();
	void Update();

	void Render();

	void Run();

	void InitKeys();

private:
	sf::RenderWindow* window;
	sf::Event SFevent;

	sf::Clock deltaTimeClock;
	float deltaTime;

	std::stack<State*> states;

	std::map<std::string, int> suportedKeys;

};

