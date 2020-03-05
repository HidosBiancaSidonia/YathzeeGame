#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Move(const float& deltaTime, const float dirx, const float diry);
	virtual void Update(const float& deltaTime);
	virtual void Render(sf::RenderTarget* target);

protected:
	sf::RectangleShape shape;
	float movementSpeed;
};

