#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	m_spawnRate = 1.9;
	m_spawnTime = m_spawnRate - 0.1;

	m_textTemplate->setColor(sf::Color(255, 0, 0, 255));
	m_textTemplate->setString("Game Over");
}


GameOverScreen::~GameOverScreen()
{
	delete m_textTemplate;
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
			ObjectHandler::GetInstance()->GetInvaders().back()->SetFollowState(false);
			ObjectHandler::GetInstance()->GetInvaders().back()->SetTrailState(true);
		}
	}
	else
	{
		m_spawnTime += deltaTime;
	}
	if (ObjectHandler::GetInstance()->GetInvaders().size() > 0)
	{
		for (int i = ObjectHandler::GetInstance()->GetInvaders().size() - 1; i >= 0; i--)
		{
			if (ObjectHandler::GetInstance()->GetInvaders()[i]->GetText()->getPosition().y < 0 - window.getPosition().y)
			{
				// std::cout << "   -    " << ObjectHandler::GetInstance()->GetInvaders()[i]->GetText()->getPosition().y << std::endl;
				ObjectHandler::GetInstance()->GetInvaders()[i]->SetExplodingState(true);
				
				//ObjectHandler::GetInstance()->GetInvaders()[i]->~Invader();
				//ObjectHandler::GetInstance()->GetInvaders().erase(ObjectHandler::GetInstance()->GetInvaders().begin() + i);
			}
		}
	}
	return false;
}