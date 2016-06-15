#include "ObjectHandler.h"

ObjectHandler* ObjectHandler::m_instance = nullptr;

ObjectHandler* ObjectHandler::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new ObjectHandler();
	}
	return m_instance;
}

Player * ObjectHandler::GetPlayer() const
{
	return m_player;
}


ObjectHandler::ObjectHandler()
{
	m_loader = new AssetLoader();
	m_header = new Header(m_loader->GetFont());
}


void ObjectHandler::UpdateEverything(sf::RenderWindow& window)
{
	float deltaTime = 1; // DON'T MAKE THIS HERE THO LOL
	
	m_player->Update(window, deltaTime);
}


void ObjectHandler::DrawEverything(sf::RenderWindow& window)
{
	m_player->Draw(window);
	m_header->Draw(window);
}


void ObjectHandler::NewGame(sf::RenderWindow& window)
{
	m_player = LineWriter::NewPlayer(window, m_loader->GetFont());
}
