#include "Entity.h"

class State
{
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	virtual void InitKeybinds() = 0;

	const bool& GetQuit() const;
	virtual void CheckForQuit();
	virtual void EndState() = 0;

	virtual void UpdateInput(const float& deltaTime) = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;
	virtual void updateMousePositions();

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;
	std::stack<State*>* states;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

private:

};

