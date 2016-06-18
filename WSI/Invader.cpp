#include "Invader.h"


Invader::Invader()
{	
}


Invader::~Invader()
{
}


void Invader::Update(sf::RenderWindow & window, float deltaTime)
{
	m_text->setPosition(m_text->getPosition() + m_speed * deltaTime);
	FollowWindow(window);
}


void Invader::Draw(sf::RenderWindow & window)
{
	window.draw(*m_text);
}
