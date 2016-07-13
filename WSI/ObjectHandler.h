#pragma once
#include "LineWriter.h"
#include "Header.h"
#include "AssetLoader.h"
#include <stdio.h>
#include <sstream>

class ObjectHandler
{
public:
	static ObjectHandler* GetInstance();

	Player* GetPlayer() const;

	std::vector<Lazer*> GetLazers() const;
	void AddLazer(Lazer* lazer);

	std::vector<Invader*> GetInvaders() const;
	void AddInvader(Invader* invader);

	std::vector<Splosion*> GetSplosions() const;
	void AddSplosion(Splosion* splosion);

	Header* GetHeader();

	void UpdateEverything(sf::RenderWindow& window, float deltaTime);
	void DrawEverything(sf::RenderWindow& window);

	void NewGame(sf::RenderWindow& window);

	AssetLoader* GetLoader();

	void ExplodeExploders(sf::RenderWindow& window);

	float GetGameAngle() const;
	void SetGameAngle(float angle);

	bool CheckCollision(Line*& target, Line*& munition);
	void RunCollisions(std::vector<Invader*>& targets, std::vector<Lazer*>& munitions);

	std::string GetScore();

	void ToggleBoringState();
	bool GetBoringState();

private:
	ObjectHandler();
	static ObjectHandler* m_instance;

	float m_gameAngle;

	Header* m_header;
	AssetLoader* m_loader;
	Player* m_player;

	std::vector<Invader*> m_invaders;
	std::vector<Lazer*> m_lazers;
	std::vector<Splosion*> m_splosions;

	int m_score;
	float m_time;
	bool m_boringMode;
};

