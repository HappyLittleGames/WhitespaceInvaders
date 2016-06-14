#pragma once
#include "DrawableObject.h"

class Line : DrawableObject
{
public:

	Line();
	~Line();

	sf::Text GetText() const;
	void SetText(sf::Text text);

	void FollowWindow(sf::RenderWindow& window) override;

protected:
	sf::Text m_text;
	sf::Vector2f m_oldWindowPos;
};

