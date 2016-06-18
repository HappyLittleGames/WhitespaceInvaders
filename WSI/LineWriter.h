#pragma once
#include "Player.h"
#include "Invader.h"
#include "Lazer.h"
#include "Splosion.h"
#include <iostream>

class LineWriter
{
public:
	LineWriter();
	~LineWriter();

	static Player* NewPlayer(const sf::RenderWindow& window, sf::Font& font);

	static Lazer* NewLazer(const sf::RenderWindow& window, const sf::Text& copyText);

	static Splosion* NewSplosion(const sf::RenderWindow& window, const sf::Text& copyText);
};

