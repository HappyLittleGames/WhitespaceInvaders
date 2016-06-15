#pragma once
#include "DrawableObject.h"

class Header
{
public:
	Header(sf::Font& font);
	~Header();

	void Draw(sf::RenderWindow& window);
private:
	sf::RectangleShape m_area;
	sf::Text* m_title;
	sf::Text* m_buttons;
};

