#include "Splosion.h"


Splosion::Splosion()
{
	m_speed = sf::Vector2f(90, 90);
	float x = (rand() % 3) - 1;
	float y = (rand() % 3) - 1;
	m_speed = sf::Vector2f(m_speed.x * x, m_speed.y * y);
	m_lifeTime = ((x + y) > 0.4) ? x + y : 0.4;
	m_elapsedTime = 0;
}


Splosion::~Splosion()
{
}


void Splosion::Update(sf::RenderWindow& window, float deltaTime)
{
	m_text->setPosition(m_text->getPosition() + m_speed * deltaTime);
	FollowWindow(window);
	m_elapsedTime += deltaTime;
	m_speed += sf::Vector2f(0, fabsf(m_speed.x) * deltaTime);
}


void Splosion::Draw(sf::RenderWindow& window)
{
	if (m_elapsedTime < m_lifeTime)
	{
		// remove instead ofc idiot
		window.draw(*m_text);
	}
}