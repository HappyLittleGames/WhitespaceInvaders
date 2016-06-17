#pragma once
#include "Line.h"

class Invader : public Line
{
public:
	Invader();
	~Invader();

	void Update(sf::RenderWindow& window, float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;
};

