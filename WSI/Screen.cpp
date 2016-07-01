#include "Screen.h"



Screen::Screen()
{
	m_textTemplate = new sf::Text();

	m_textTemplate->setCharacterSize(18);
	m_textTemplate->setPosition(sf::Vector2f(80, 80));
	m_textTemplate->setColor(sf::Color::White);
	m_textTemplate->setRotation(ObjectHandler::GetInstance()->GetGameAngle());
	m_textTemplate->setFont(*ObjectHandler::GetInstance()->GetPlayer()->GetText()->getFont());

	m_textTemplate->setString("welcome");

	m_spawnRate = 0.2;
	m_spawnTime = 0;
}


Screen::~Screen()
{
	delete m_textTemplate;
}

bool Screen::UpdateScreen(sf::RenderWindow & window, float deltaTime)
{
	if (m_spawnTime > m_spawnRate)
	{
		sf::Vector2i systemPos = sf::Vector2i(0, 0) - window.getPosition();
		float xPos = (std::rand() % (sf::VideoMode::getDesktopMode().width - 32) + 32);

		m_spawnTime = 0;
		ObjectHandler::GetInstance()->AddInvader(LineWriter::NewInvader(window, *m_textTemplate,
												 ObjectHandler::GetInstance()->GetGameAngle(),
												 sf::Vector2f(0, 90),
												 sf::Vector2f((rand() % window.getSize().x), -100)));
	}
	else
	{
		m_spawnTime += deltaTime;
	}
	return false;
}
