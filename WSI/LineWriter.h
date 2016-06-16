#pragma once
#include "Player.h"
#include "Invader.h"
#include "Lazer.h"
#include <iostream>

class LineWriter
{
public:
	LineWriter();
	~LineWriter();

	static Player* NewPlayer(sf::RenderWindow& window, sf::Font& font);

	static Lazer* NewLazer(sf::RenderWindow& window, const sf::Text& copyText);
};

