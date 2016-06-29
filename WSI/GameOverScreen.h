#pragma once
#include "Screen.h"

class GameOverScreen : public Screen
{
public:
	GameOverScreen();
	~GameOverScreen();

	bool UpdateScreen(sf::RenderWindow& window, float deltaTime) override;

};

