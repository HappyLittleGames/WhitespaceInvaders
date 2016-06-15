#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}


void Player::FollowWindow(sf::RenderWindow & window)
{
	sf::Vector2f windowPos = sf::Vector2f(window.getPosition().x, window.getPosition().y);
	if (!m_followingWindow)
	{
		sf::Vector2f posDif = m_oldWindowPos - windowPos;

		m_text.setPosition(m_text.getPosition() + posDif);

		m_oldWindowPos = windowPos;
	}
	else
	{
		m_oldWindowPos = windowPos;
		// m_followingWindow = false; ??
	}
}


void Player::Update(sf::RenderWindow& window, float deltaTime)
{
	FollowWindow(window);
}


void Player::Draw(sf::RenderWindow & window)
{
	window.draw(m_text);
	window.draw(m_command);
}


void Player::SetCommand(sf::Text text)
{
	m_command = text;
}


sf::Text Player::GetCommand() const
{
	return m_command;
}

void Player::EnterText(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Return)
	{
		// run
	}
	else if (event.key.code == sf::Keyboard::F1)
	{
		// debug yeah
	}
	else if (event.key.code == sf::Keyboard::BackSpace)
	{
		sf::String tempString = m_command.getString();
		if (tempString.getSize() > 0)
		{
			tempString.erase(tempString.getSize() - 1);
			m_command.setString(tempString);
		}
	}
	else if ((event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::Down))
	{
		// memento
	}
	else if (((event.text.unicode >= 65) && (event.text.unicode <= 240)) || event.text.unicode == 59 || event.text.unicode == 40 || event.text.unicode == 41)
	{
		char myChar = event.key.code;
		m_command.setString(m_command.getString() + myChar);
	}
}