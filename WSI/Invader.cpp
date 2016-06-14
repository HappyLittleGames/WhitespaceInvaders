#include "Invader.h"


Invader::Invader()
{
}


Invader::~Invader()
{
}


void Invader::Update(sf::RenderWindow & window, float deltaTime)
{
	FollowWindow(window);
}
