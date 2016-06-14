#pragma once
#include "SFML\Graphics.hpp"
class Line
{
public:

	Line();
	~Line();

	void Update(sf::RenderWindow&, float deltaTime);

	sf::Text GetText() const;
	void SetText(sf::Text text);

protected:
	sf::Text m_text;

};

