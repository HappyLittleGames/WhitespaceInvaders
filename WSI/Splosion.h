#pragma once
#include "Line.h"

class Splosion : public Line
{
public:
	Splosion();
	~Splosion();

	void Update(sf::RenderWindow& windwo, float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

};

