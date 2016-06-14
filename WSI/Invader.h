#pragma once
#include "Line.h"

class Invader : Line
{
public:
	Invader();
	~Invader();

	void Update(sf::RenderWindow& window, float deltaTime) override;
};

