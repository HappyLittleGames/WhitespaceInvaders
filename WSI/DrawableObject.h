#pragma once
#include"SFML\Graphics.hpp"

class DrawableObject
{
public:
	DrawableObject();
	~DrawableObject();

	virtual void Update(sf::RenderWindow& window, float deltaTime);
	virtual void Draw(sf::RenderWindow& window);
};

