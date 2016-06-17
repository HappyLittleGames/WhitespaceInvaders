#include "Invader.h"


Invader::Invader()
{
	m_followingWindow = false;
}


Invader::~Invader()
{
}


void Invader::Update(sf::RenderWindow & window, float deltaTime)
{
	m_text->setPosition(m_text->getPosition() + m_speed);
	FollowWindow(window);
}

void Invader::Draw(sf::RenderWindow & window)
{
	window.draw(*m_text);
}
