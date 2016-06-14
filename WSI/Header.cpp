#include "Header.h"



Header::Header(sf::Font& font)
{
	m_title = new sf::Text();
	m_title->setString("CMD");
	m_title->setCharacterSize(18);
	m_title->setFont(font);
	m_title->setColor(sf::Color::Black);

	m_buttons = new sf::Text();
	m_buttons->setString("X");
	m_buttons->setCharacterSize(18);
	m_buttons->setFont(font);
	m_buttons->setColor(sf::Color::Black);
}


Header::~Header()
{
}


void Header::Draw(sf::RenderWindow& window, float deltaTime)
{
	m_title->setPosition(sf::Vector2f(0, 0));
	m_buttons->setPosition(sf::Vector2f(window.getSize().x - 32, 0));

	m_area.setSize(sf::Vector2f(window.getSize().x, 32));
	m_area.setFillColor(sf::Color::White);
	m_area.setPosition(sf::Vector2f(0, 0));
	

	window.draw(m_area);
	window.draw(*m_title);
	window.draw(*m_buttons);
}