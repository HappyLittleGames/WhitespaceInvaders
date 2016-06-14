#pragma once
#include "Player.h"
#include "Invader.h"

class LineWriter
{
public:
	LineWriter();
	~LineWriter();

	Player* NewPlayer(sf::RenderWindow& window, sf::Font& font, sf::String type);
};

