#include "Splosion.h"


Splosion::Splosion()
{
	m_speed = sf::Vector2f(60, 60);
	float x = (rand() % 3) - 1;
	float y = (rand() % 2);
	m_speed = sf::Vector2f(m_speed.x * x + 30, m_speed.y * y + 30);
	m_lifeTime = (((x + y) > 0.4) ? x + y : 0.4) * 10;
	m_elapsedTime = 0;
	m_intervalTime = 0;
}


Splosion::~Splosion()
{

	delete m_text;
	for each (Trail* trail in m_trails)
	{
		delete trail;
	}
	m_trails.clear();
}


void Splosion::Update(sf::RenderWindow& window, float deltaTime)
{
	m_text->setPosition(m_text->getPosition() + m_speed * deltaTime);
	FollowWindow(window);
	m_elapsedTime += deltaTime;
	m_speed += sf::Vector2f(0, (fabsf(m_speed.x) * 2 ) * deltaTime);

	MakeTrail(window, deltaTime);

	for each (Trail* trail in m_trails)
	{
		trail->Update(window, deltaTime);
	}

	Bounce(window);
}


void Splosion::Draw(sf::RenderWindow& window)
{
	window.draw(*m_text);


	for each (Trail* trail in m_trails)
	{
		window.draw(*trail->GetText());
	}
}


void Splosion::MakeTrail(sf::RenderWindow& window, float deltaTime)
{
	if (m_intervalTime > .2 * m_text->getString().getSize())
	{
		m_intervalTime = 0;
		m_trails.push_back(new Trail(m_text));
		// m_trails.back() = m_text; // gotta make a trails class from Line
	}
	else
	{
		m_intervalTime += deltaTime;
	}

	if (m_trails.size() > 0)
	{
		if (m_trails[0]->GetText()->getColor().a < 10)
		{
			m_trails[0]->~Trail();
			m_trails.erase(m_trails.begin());
		}
	}
}