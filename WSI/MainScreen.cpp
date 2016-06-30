#include "MainScreen.h"



MainScreen::MainScreen()
{
	m_spawnRate = 2.2;
	m_spawnTime = 0;

	m_textTemplate->setColor(sf::Color(255, 255, 255, 255));
}


MainScreen::~MainScreen()
{
}

bool MainScreen::UpdateScreen(sf::RenderWindow & window, float deltaTime)
{
	if (m_spawnTime > m_spawnRate)
	{
		sf::Vector2i systemPos = sf::Vector2i(0, 0) - window.getPosition();
		float xPos = (std::rand() % (sf::VideoMode::getDesktopMode().width - 32) + 32);

		m_spawnTime = 0;

		int speed = rand() % 159 - 80;
		ObjectHandler::GetInstance()->AddInvader(LineWriter::NewInvader(window, *m_textTemplate,
																		ObjectHandler::GetInstance()->GetGameAngle(),
																		sf::Vector2f(speed, 90),
																		sf::Vector2f((rand() % window.getSize().x), -100)));

		if (m_spawnRate < .05)
		{
			m_spawnRate *= .95;
		}
	}
	else
	{
		m_spawnTime += deltaTime;
	}
	if (ObjectHandler::GetInstance()->GetPlayer()->GetLives() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
