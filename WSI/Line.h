#pragma once
#include "DrawableObject.h"

class Line : public DrawableObject
{
public:
	Line();
	~Line();

	sf::Text GetText() const;
	void SetText(sf::Text text);

protected:
	void FollowWindow(sf::RenderWindow& window) override;

	sf::Text m_text;
	sf::Vector2f m_oldWindowPos;
};

