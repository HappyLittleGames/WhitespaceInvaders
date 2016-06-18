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


std::vector<Lazer*> ObjectHandler::GetInvaders() const
{
	return m_invaders;
}


void ObjectHandler::AddInvader(Lazer* invader)
{
	m_invaders.push_back(invader);
}

std::vector<Splosion*> ObjectHandler::GetSplosions() const
{
	return m_splosions;
}

void ObjectHandler::AddSplosion(Splosion * splosion)
{
	m_splosions.push_back(splosion);
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
	for (int i = 0; i < m_splosions.size(); i++)
	{
		m_splosions[i]->Update(window, deltaTime);
	}
}


void ObjectHandler::DrawEverything(sf::RenderWindow& window)
{
	m_player->Draw(window);

	for (int i = 0; i < m_lazers.size(); i++)
	{
		m_lazers[i]->Draw(window);
	}
	for (int i = 0; i < m_invaders.size(); i++)
	{
		m_invaders[i]->Draw(window);
	}
	for (int i = 0; i < m_splosions.size(); i++)
	{
		m_splosions[i]->Draw(window);
	}

	m_header->Draw(window);
}


void ObjectHandler::NewGame(sf::RenderWindow& window)
{
	// delete them pointers too
	m_player = LineWriter::NewPlayer(window, m_loader->GetFont());
	m_lazers = std::vector<Lazer*>{};
	m_invaders = std::vector<Lazer*>{};
	m_splosions = std::vector<Splosion*>{};
}

AssetLoader* ObjectHandler::GetLoader()
{
	return m_loader;
}

void ObjectHandler::ExplodeExploders(sf::RenderWindow& window)
{
	for (int i = m_lazers.size() - 1; i >= 0; i--)
	{
		if (m_lazers[i]->IsExploding())
		{
			Line* exploder = m_lazers[i];
			AddSplosion(LineWriter::NewSplosion(window, *m_lazers[i]->GetText()));
			m_lazers.erase(m_lazers.begin() + i);
			delete exploder;
		}
	}
	for (int i = m_invaders.size() - 1; i >= 0; i--)
	{
		if (m_invaders[i]->IsExploding())
		{
			Line* exploder = m_invaders[i];
			AddSplosion(LineWriter::NewSplosion(window, *m_invaders[i]->GetText()));
			m_invaders.erase(m_invaders.begin() + i);
			delete exploder;
		}
	}
}



