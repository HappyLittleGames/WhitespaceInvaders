#include "Line.h"


Line::Line()
{
	m_exploding = false;
}


Line::~Line()
{
	//delete m_text;
}


sf::Text* Line::GetText() const
{
	return m_text;
}


void Line::SetText(sf::Text* text)
{
	m_text = text;
}

void Line::SetString(sf::String string)
{
	m_text->setString(string);
}

bool Line::IsExploding() const
{
	return m_exploding;
}

void Line::SetExplodingState(bool state)
{
	m_exploding = state;
}


void Line::SetWindowPos(sf::Vector2f windowPos)
{
	m_oldWindowPos.x = windowPos.x;
	m_oldWindowPos.y = windowPos.y;

}


void Line::FollowWindow(sf::RenderWindow & window)
{
	sf::Vector2f windowPos = sf::Vector2f(window.getPosition().x, window.getPosition().y);
	if (!m_followingWindow)
	{
		sf::Vector2f posDif = m_oldWindowPos - windowPos;

		m_text->setPosition(m_text->getPosition() + posDif);

		m_oldWindowPos = windowPos;
	}
	else
	{
		m_followingWindow = false;
		m_oldWindowPos = windowPos;
	}
}



void Line::Bounce(sf::RenderWindow& window)
{
	if ( ( m_text->getPosition().x < m_text->getCharacterSize() ) /* || ( window.getPosition().x + m_text->getPosition().x < m_text->getCharacterSize()) - window.getPosition().x */ )
	{
		float absX = fabs(m_speed.x);
		m_speed = sf::Vector2f(absX, m_speed.y);
	}
	else if (m_text->getPosition().x > window.getSize().x - m_text->getCharacterSize())
	{
		float absX = fabs(m_speed.x);
		m_speed = sf::Vector2f(-absX, m_speed.y);
	}
}