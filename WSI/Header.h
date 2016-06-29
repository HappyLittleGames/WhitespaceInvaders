#pragma once
#include "DrawableObject.h"

class Header
{
public:
	Header(sf::Font& font);
	~Header();

	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, float deltaTime);

	void SetDragState(bool state);

	void SetTitle(std::string string);

private:
	sf::RectangleShape m_area;
	sf::Text* m_title;
	sf::Text* m_buttons;

	sf::Vector2i m_mousePos;
	sf::Vector2i m_mouseChange;
	sf::Vector2i m_clickedPos;
	bool m_isDragging;
};

