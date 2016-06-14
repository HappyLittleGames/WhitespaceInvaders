#pragma once
#include "DrawableObject.h"

class Line : DrawableObject 
{
public:

	Line();
	~Line();

	sf::Text GetText() const;
	void SetText(sf::Text text);

protected:
	sf::Text m_text;
};

