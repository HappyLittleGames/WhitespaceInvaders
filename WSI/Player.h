#pragma once
#include "Line.h"
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

	void EnterText(sf::Event event);

private:
	sf::Text m_command;
};

