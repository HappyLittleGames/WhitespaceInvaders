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


void ObjectHandler::AddInvader(Invader* invader)
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
	m_gameAngle = 90;
	m_score = 0;
	m_time = m_score;
}


void ObjectHandler::UpdateEverything(sf::RenderWindow& window, float deltaTime)
{	

	m_header->Update(window, deltaTime);
	m_player->Update(window, deltaTime);
	
	RunCollisions(m_invaders, m_lazers);

	for (int i = 0; i < m_lazers.size(); i++)
	{
		m_lazers[i]->Update(window, deltaTime);
	}
	for (int i = m_invaders.size() - 1; i >= 0; i--)
	{
		m_invaders[i]->Update(window, deltaTime);

		if (m_player->GetLives() > 0)
		{

			if (m_invaders[i]->GetText()->getPosition().y + window.getPosition().y > sf::VideoMode::getDesktopMode().height + 90)
			{
				m_invaders[i]->~Invader();
				m_invaders.erase(m_invaders.begin() + i);

				m_player->SetLives(m_player->GetLives() - 1);

				for each (Line* lazer in m_lazers)
				{
					lazer->SetExplodingState(true);
					lazer->GetText()->setColor(sf::Color(255, 0, 0, 255));
				}
				for each (Line* invader in m_invaders)
				{
					invader->SetExplodingState(true);
					invader->GetText()->setColor(sf::Color(255, 0, 0, 255));
				}
			}
		}
	}

	if (m_player->GetLives() > 0)
	{
		m_time += deltaTime;
		m_score = m_time;
	}
	if ((m_player->GetLives() >= 0) && (m_player->GetLives() < 4))
	{
		std::ostringstream stats;
		stats << "Lives: " << m_player->GetLives() << " - Score: " << m_score;
		m_header->SetTitle(stats.str());
	}

	for (int i = 0; i < m_splosions.size(); i++)
	{
		m_splosions[i]->Update(window, deltaTime);
	}
}


void ObjectHandler::DrawEverything(sf::RenderWindow& window)
{

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

	m_player->Draw(window);
	m_header->Draw(window);
}


void ObjectHandler::NewGame(sf::RenderWindow& window)
{
	m_player = LineWriter::NewPlayer(window, m_loader->GetFont(), -m_gameAngle);
	
	for each (Splosion* splosion in m_splosions)
	{
		delete splosion;
	}
	for each (Lazer* lazer in m_lazers)
	{
		lazer->SetExplodingState(true);
	}
	for each (Invader* invader in m_invaders)
	{
		invader->SetExplodingState(true);
	}

	// m_time = 0;
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
			std::cout << "Making splosion with string of " << m_lazers[i]->GetText()->getString().getSize() << "." << std::endl;
			for (int j = 0; j < m_lazers[i]->GetText()->getString().getSize(); j++)
			{
				sf::String singleChar = "";
				for (int k = 0; k < j; k++)
				{
					singleChar += " ";
				}
				singleChar += m_lazers[i]->GetText()->getString()[j];
				AddSplosion(LineWriter::NewSplosion(window, *m_lazers[i]->GetText(), - m_gameAngle));
				m_splosions.back()->SetString(singleChar);
			}
			delete m_lazers[i];
			m_lazers.erase(m_lazers.begin() + i);
		}
	}
	for (int i = m_invaders.size() - 1; i >= 0; i--)
	{
		if (m_invaders[i]->IsExploding())
		{
			std::cout << "Making splosion with string of " << m_invaders[i]->GetText()->getString().getSize() << "."  << " m_splosions contains " << m_splosions.size() << " entities." << std::endl;
			for (int j = 0; j < m_invaders[i]->GetText()->getString().getSize(); j++)
			{
				sf::String singleChar = "";
				for (int k = 0; k < j; k++)
				{
					singleChar += " ";
				}
				singleChar += m_invaders[i]->GetText()->getString()[j];
				AddSplosion(LineWriter::NewSplosion(window, *m_invaders[i]->GetText(), - m_gameAngle));
				m_splosions.back()->SetString(singleChar);
			}
			delete m_invaders[i];
			m_invaders.erase(m_invaders.begin() + i);
		}
		for (int i = m_splosions.size() - 1; i >= 0; i--)
		{
			if (m_splosions[i]->GetText()->getPosition().y + window.getPosition().y > sf::VideoMode::getDesktopMode().height + 900)
			{
				delete m_splosions[i];
				m_splosions.erase(m_splosions.begin() + i);

			}
		}
	}
}

float ObjectHandler::GetGameAngle() const
{
	return m_gameAngle;
}

void ObjectHandler::SetGameAngle(float angle)
{
	m_gameAngle = angle;
}


bool ObjectHandler::CheckCollision(Line*& target, Line*& munition)
{
	if ((target->GetText()->getGlobalBounds().left > munition->GetText()->getGlobalBounds().left + munition->GetText()->getGlobalBounds().width) || (munition->GetText()->getGlobalBounds().left > target->GetText()->getGlobalBounds().left + target->GetText()->getGlobalBounds().width))
	{
		//std::cout << "no horizontal collision";
		return false;
	}
	if ((target->GetText()->getGlobalBounds().top > munition->GetText()->getGlobalBounds().top + munition->GetText()->getGlobalBounds().height) || (munition->GetText()->getGlobalBounds().top > target->GetText()->getGlobalBounds().top + target->GetText()->getGlobalBounds().height))
	{
		//std::cout << "no vertical collision";
		return false;
	}
	std::cout << "Collision!" << std::endl;
	return true;
}



void ObjectHandler::RunCollisions(std::vector<Invader*>& targets, std::vector<Lazer*>& munitions)
{
	for each (Line* target in targets)
	{
		bool collision = false;

		for each (Line* munition in munitions)
		{
			if (CheckCollision(munition, target))
			{
				// std::cout << "Collision Detected" << std::endl;
				collision = true;
				munition->SetExplodingState(true);
			}
		}

		if (collision)
		{
			target->SetExplodingState(true);
		}
	}
}

std::string ObjectHandler::GetScore()
{
	std::ostringstream score;
	score << m_score;

	return score.str();
}

void ObjectHandler::ToggleBoringState()
{
	m_boringMode = !m_boringMode;
}

bool ObjectHandler::GetBoringState()
{
	return m_boringMode;
}

