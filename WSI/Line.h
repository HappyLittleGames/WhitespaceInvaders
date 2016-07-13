#pragma once
#include "DrawableObject.h"

class Line : public DrawableObject
{
public:
	Line();
	virtual ~Line();

	sf::Text* GetText() const;
	void SetText(sf::Text* text);
	void SetString(sf::String string);

	void SetWindowPos(sf::Vector2f windowPos);

	bool IsExploding() const;
	void SetExplodingState(bool state);

	void Bounce(sf::RenderWindow& window);
protected:
	void FollowWindow(sf::RenderWindow& window) override;

	sf::Text* m_text;
	sf::Vector2f m_oldWindowPos;

	bool m_exploding;
	bool m_boringMode
};

