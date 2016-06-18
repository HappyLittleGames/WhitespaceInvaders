#pragma once
#include "Line.h"

class Lazer : public Line
{
public:
	Lazer();
	~Lazer();

	void Update(sf::RenderWindow& windwo, float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

};

