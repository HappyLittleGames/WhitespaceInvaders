#pragma once
#include "Line.h"
#include "Trail.h"

class Invader : public Line
{
public:
	Invader();
	~Invader();

	void Update(sf::RenderWindow& window, float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

	void SetTrailState(bool state);

private:
	bool m_trailing;

	void MakeTrail(sf::RenderWindow& window, float deltaTime);

	float m_intervalTime;
	std::vector<Trail*> m_trails;
};

