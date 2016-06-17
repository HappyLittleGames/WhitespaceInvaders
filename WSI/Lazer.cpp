#include "Lazer.h"



Lazer::Lazer()
{
}


Lazer::~Lazer()
{
}


void Lazer::Update(sf::RenderWindow& window, float deltaTime)
{
	m_text->setPosition(m_text->getPosition() + m_speed);
	FollowWindow(window);
}


void Lazer::Draw(sf::RenderWindow& window)
{
	window.draw(*m_text);
}
