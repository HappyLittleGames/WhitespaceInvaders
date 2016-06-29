#pragma once
#include "Line.h"
#include "Trail.h"


class Splosion : public Line
{
public:
	Splosion();
	~Splosion();

	void Update(sf::RenderWindow& windwo, float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;
private:
	float m_lifeTime;
	float m_elapsedTime;

	void MakeTrail(sf::RenderWindow& window, float deltaTime);

	float m_intervalTime;
	std::vector<Trail*> m_trails;
};

