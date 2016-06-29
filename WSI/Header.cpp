#include "Header.h"



Header::Header(sf::Font& font)
{
	m_title = new sf::Text();
	m_title->setString("Command Prompt");
	m_title->setCharacterSize(18);
	m_title->setFont(font);
	m_title->setColor(sf::Color::Black);

	m_buttons = new sf::Text();
	m_buttons->setString("X");
	m_buttons->setCharacterSize(18);
	m_buttons->setFont(font);
	m_buttons->setColor(sf::Color::Black);

	m_isDragging = false;
}


void Header::SetDragState(bool state)
{
	m_isDragging = state;
}

void Header::SetTitle(std::string string)
{
	m_title->setString(string);
}


Header::~Header()
{
}


void Header::Update(sf::RenderWindow& window, float deltaTime)
{
	if (m_isDragging)
	{
		
		m_mouseChange = sf::Mouse::getPosition() - m_mousePos;
		window.setPosition(window.getPosition() + sf::Mouse::getPosition() - m_mouseChange - m_clickedPos);
	}
	else
	{
		m_clickedPos = sf::Mouse::getPosition() - window.getPosition();
	}
	m_mousePos = sf::Mouse::getPosition(window);
}


void Header::Draw(sf::RenderWindow& window)
{
	m_title->setPosition(sf::Vector2f(4, 4));
	m_buttons->setPosition(sf::Vector2f(window.getSize().x - 24, 4));

	m_area.setSize(sf::Vector2f(window.getSize().x, 32));
	m_area.setFillColor(sf::Color::White);
	m_area.setPosition(sf::Vector2f(0, 0));

	window.draw(m_area);
	window.draw(*m_title);
	window.draw(*m_buttons);
}