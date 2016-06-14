#pragma once
#include "Line.h"
class Player : Line
{
public:
	Player();
	~Player();

	void Update(sf::RenderWindow& window, float deltaTime) override;

	void Draw(sf::RenderWindow& window) override;
};

