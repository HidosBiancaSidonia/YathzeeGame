#include "State.h"


class GameStates : public State
{
public:
	GameStates(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameStates();
	void EndState();

	void UpdateInput(const float& deltaTime);
	void Update(const float& deltaTime);
	void Render(sf::RenderTarget* target = nullptr);

private:
	void InitKeybinds();

private:
	Entity player;
};

