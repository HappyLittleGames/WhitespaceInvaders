#pragma once
#include "ObjectHandler.h"

class Screen
{
public:
	Screen();
	~Screen();

	virtual bool UpdateScreen(sf::RenderWindow& window, float deltaTime);

protected:
	float m_spawnRate;
	float m_spawnTime;
	sf::Text* m_textTemplate;
};

