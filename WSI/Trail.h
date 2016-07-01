#pragma once
#include "Line.h"
class Trail : public Line
{
public:
	Trail(const sf::Text* text);
	~Trail() override;

	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, float deltaTime) override;
};

