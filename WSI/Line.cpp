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


void Line::FollowWindow(sf::RenderWindow & window)
{
	sf::Vector2f windowPos = sf::Vector2f(window.getPosition().x, window.getPosition().y);
	if (!m_followingWindow)
	{
		sf::Vector2f posDif = m_oldWindowPos - windowPos;

		m_text.setPosition(m_text.getPosition() + posDif);

		m_oldWindowPos = windowPos;
	}
	else
	{
		m_oldWindowPos = windowPos;
		m_followingWindow = false;
	}
}

