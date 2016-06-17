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


std::vector<Lazer*> ObjectHandler::GetLazers() const
{
	return m_lazers;
}


void ObjectHandler::AddLazer(Lazer* lazer)
{
	m_lazers.push_back(lazer);
}


std::vector<Invader*> ObjectHandler::GetInvaders() const
{
	return m_invaders;
}


void ObjectHandler::AddInvader(sf::RenderWindow& window, sf::Vector2f spawnPos)
{
	m_invaders.push_back(LineWriter::NewInvader(window, m_loader->GetFont(), spawnPos));
}


Header * ObjectHandler::GetHeader()
{
	return m_header;
}


ObjectHandler::ObjectHandler()
{
	m_loader = new AssetLoader();
	m_header = new Header(m_loader->GetFont());
}


void ObjectHandler::UpdateEverything(sf::RenderWindow& window)
{
	float deltaTime = 1; // DON'T MAKE THIS HERE THO LOL
	
	m_header->Update(window, deltaTime);
	m_player->Update(window, deltaTime);
	
	for (int i = 0; i < m_lazers.size(); i++)
	{
		m_lazers[i]->Update(window, deltaTime);
	}
	for (int i = 0; i < m_invaders.size(); i++)
	{
		m_invaders[i]->Update(window, deltaTime);
	}
}


void ObjectHandler::DrawEverything(sf::RenderWindow& window)
{
	m_player->Draw(window);
	m_header->Draw(window);

	for (int i = 0; i < m_lazers.size(); i++)
	{
		m_lazers[i]->Draw(window);
	}
	for (int i = 0; i < m_invaders.size(); i++)
	{
		//m_invaders[i]->Draw(window);
	}
}


void ObjectHandler::NewGame(sf::RenderWindow& window)
{
	m_player = LineWriter::NewPlayer(window, m_loader->GetFont());
}

AssetLoader* ObjectHandler::GetLoader()
{
	return m_loader;
}
