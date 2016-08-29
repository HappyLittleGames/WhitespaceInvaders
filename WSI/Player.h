#pragma once
#include "Line.h"
#include <iostream>
#include "CommandLog.h"

class Player : public Line
{
public:
	Player();
	~Player();

	void FollowWindow(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, float deltaTime) override;

	void Draw(sf::RenderWindow& window) override;

	void SetCommand(sf::Text text);
	sf::Text GetCommand() const;
	void SetCommandString(std::string string);

	void EnterText(sf::Event& event);

	void SetLives(int lives);
	int GetLives();

private:
	sf::Text m_command;
	int m_lives;
};

