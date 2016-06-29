#pragma once
#include "Screen.h"
class MainScreen : public Screen
{
public:
	MainScreen();
	~MainScreen();

	bool UpdateScreen(sf::RenderWindow& window, float deltaTime) override;
};

