#pragma once
#include"SFML\Graphics.hpp"

class DrawableObject
{
public:
	DrawableObject();
	~DrawableObject();

	virtual void Update(sf::RenderWindow& window, float deltaTime) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	sf::Vector2f GetSpeed() const;
	void SetSpeed(sf::Vector2f speed);
	void Bounce();

	bool GetFollowState() const;
	void SetFollowState(bool state);

protected:
	sf::Vector2f m_speed;

	virtual void FollowWindow(sf::RenderWindow& window) = 0;

	bool m_followingWindow;

};

