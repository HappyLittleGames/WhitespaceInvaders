#pragma once
#include "GameOverScreen.h"
#include "MainScreen.h"

class ScreenHandler
{
public:
	ScreenHandler();
	~ScreenHandler();
	void NextScreen();

	void UpdateScreen(sf::RenderWindow& window, float deltaTime);
private:
	int m_screenIndex;
	std::vector<Screen*> m_screens;
};

