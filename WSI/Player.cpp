#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}


void Player::Update(sf::RenderWindow& window, float deltaTime)
{
	FollowWindow(window);
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(m_text);
}
