#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	m_spawnRate = 1.4;
	m_spawnTime = 0;

	m_textTemplate->setColor(sf::Color(255, 0, 0, 255));
	m_textTemplate->setString("Game Over");
}


GameOverScreen::~GameOverScreen()
{
}

bool GameOverScreen::UpdateScreen(sf::RenderWindow & window, float deltaTime)
{
	if (m_spawnTime > m_spawnRate)
	{
		sf::Vector2i systemPos = sf::Vector2i(0, 0) - window.getPosition();
		float xPos = (std::rand() % (sf::VideoMode::getDesktopMode().width - 32) + 32);

		m_spawnTime = 0;

		int textAmount = window.getSize().x / ObjectHandler::GetInstance()->GetPlayer()->GetText()->getCharacterSize() + 2;

		for (int i = 0; i < textAmount; i++)
		{
			ObjectHandler::GetInstance()->AddInvader(LineWriter::NewInvader(window, *m_textTemplate,
														ObjectHandler::GetInstance()->GetGameAngle(),
														sf::Vector2f(0, -90),
														sf::Vector2f(textAmount * i, window.getSize().y + 60)));
		}
	}
	else
	{
		m_spawnTime += deltaTime;
	}
	return false;
}