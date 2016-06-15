#pragma once
#include "Player.h"
#include "Invader.h"

static class LineWriter
{
public:
	LineWriter();
	~LineWriter();

	static Player* NewPlayer(sf::RenderWindow& window, sf::Font& font);
};

