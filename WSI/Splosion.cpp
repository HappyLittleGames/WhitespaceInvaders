#include "Splosion.h"


Splosion::Splosion()
{
	m_speed = sf::Vector2f(2, 2);
}


Splosion::~Splosion()
{
}


void Splosion::Update(sf::RenderWindow& window, float deltaTime)
{
	m_text->setPosition(m_text->getPosition() + m_speed * deltaTime);
	FollowWindow(window);
}


void Splosion::Draw(sf::RenderWindow& window)
{
	window.draw(*m_text);
}