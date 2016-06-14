#include "Line.h"



Line::Line()
{
}


Line::~Line()
{
}

sf::Text Line::GetText() const
{
	return m_text;
}

void Line::SetText(sf::Text text)
{
	m_text = text;
}

