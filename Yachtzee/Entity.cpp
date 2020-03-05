#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::Move(const float& deltaTime, const float dirx, const float diry)
{
	this->shape.move(dirx * this->movementSpeed * deltaTime, diry * this->movementSpeed * deltaTime);
}

void Entity::Update(const float& deltaTime)
{

}

void Entity::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
