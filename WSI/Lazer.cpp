#include "Lazer.h"


Lazer::Lazer()
{
}


Lazer::~Lazer()
{
}


void Lazer::Update(sf::RenderWindow& window, float deltaTime)
{
	m_text->setColor(m_text->getColor() - sf::Color(-45 * deltaTime, 0, -45 * deltaTime, 0));
	m_text->setPosition(m_text->getPosition() + m_speed * deltaTime);
	FollowWindow(window);
}


void Lazer::Draw(sf::RenderWindow& window)
{
#ifdef _DEBUG
	sf::RectangleShape debugShape = sf::RectangleShape(sf::Vector2f(m_text->getGlobalBounds().width, m_text->getGlobalBounds().height));
	debugShape.setPosition(sf::Vector2f(m_text->getGlobalBounds().left, m_text->getGlobalBounds().top));
	debugShape.setFillColor(sf::Color::Red);
	window.draw(debugShape);
#endif
	window.draw(*m_text);
}
