#include "Invader.h"


Invader::Invader()
{
	m_intervalTime = 0;
}


Invader::~Invader()
{
	delete m_text;
	for each (Trail* trail in m_trails)
	{
		trail->~Trail();
	}
	m_trails.clear();
}


void Invader::Update(sf::RenderWindow & window, float deltaTime)
{
	m_text->setPosition(m_text->getPosition() + m_speed * deltaTime);
	FollowWindow(window);

	MakeTrail(window, deltaTime);

	for each (Trail* trail in m_trails)
	{
		trail->Update(window, deltaTime);
	}
	if (m_text->getPosition().y + window.getPosition().y > sf::VideoMode::getDesktopMode().height)
	{
		for each (Trail* trail in m_trails)
		{
			trail->GetText()->setColor(sf::Color(255, 0, 0, trail->GetText()->getColor().a));
		}
	}

	Bounce(window);
}


void Invader::Draw(sf::RenderWindow & window)
{
	window.draw(*m_text);

	for each (Trail* text in m_trails)
	{
		window.draw(*text->GetText());
	}
}

void Invader::SetTrailState(bool state)
{
	m_trailing = state;
}


void Invader::MakeTrail(sf::RenderWindow& window, float deltaTime)
{
	if (m_intervalTime > .25 * (m_text->getString().getSize() / 2 ))
	{
		m_intervalTime = 0;
		if (m_trailing)
		{
			m_trails.push_back(new Trail(m_text));
			m_trails.back()->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));
		}
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