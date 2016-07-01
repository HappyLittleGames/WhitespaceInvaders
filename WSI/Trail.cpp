#include "Trail.h"


Trail::Trail(const sf::Text* text)
{
	m_text = new sf::Text();

	m_text->setCharacterSize(text->getCharacterSize());
	m_text->setPosition(text->getPosition());
	m_text->setColor(text->getColor() - sf::Color(0,0,0,55));
	m_text->setRotation(text->getRotation());
	m_text->setFont(*text->getFont());

	m_text->setString(text->getString());
}

Trail::~Trail()
{
	delete m_text;
}

void Trail::Draw(sf::RenderWindow& window)
{
	window.draw(*m_text);
}

void Trail::Update(sf::RenderWindow & window, float deltaTime)
{
	FollowWindow(window);
	m_text->setColor(sf::Color(m_text->getColor().r, m_text->getColor().g, m_text->getColor().b, (m_text->getColor().a * (1 - (0.3 * deltaTime)))));
}
