#pragma once
#include "LineWriter.h"
#include "Header.h"
#include "AssetLoader.h"

class ObjectHandler
{
public:
	static ObjectHandler* GetInstance();

	Player* GetPlayer() const;

	std::vector<Lazer*> GetLazers() const;
	void AddLazer(Lazer* lazer);

	std::vector<Lazer*> GetInvaders() const;
	void AddInvader(Lazer* invader);

	std::vector<Splosion*> GetSplosions() const;
	void AddSplosion(Splosion* splosion);

	Header* GetHeader();

	void UpdateEverything(sf::RenderWindow& window);
	void DrawEverything(sf::RenderWindow& window);

	void NewGame(sf::RenderWindow& window);

	AssetLoader* GetLoader();

	void ExplodeExploders(sf::RenderWindow& window);
private:
	ObjectHandler();
	static ObjectHandler* m_instance;

	Header* m_header;
	AssetLoader* m_loader;
	Player* m_player;

	std::vector<Lazer*> m_invaders;
	std::vector<Lazer*> m_lazers;
	std::vector<Splosion*> m_splosions;
};

