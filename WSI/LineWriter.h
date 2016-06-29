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

	static Player* NewPlayer(const sf::RenderWindow& window, sf::Font& font, float angle);

	static Lazer* NewLazer(const sf::RenderWindow& window, const sf::Text& copyText, float angle, sf::Vector2f speed);

	static Invader* NewInvader(const sf::RenderWindow& window, const sf::Text& copyText, float angle, sf::Vector2f speed, sf::Vector2f position);

	static Splosion* NewSplosion(const sf::RenderWindow& window, const sf::Text& copyText, float angle);
};

