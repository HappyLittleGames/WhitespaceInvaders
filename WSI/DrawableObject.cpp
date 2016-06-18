#include "DrawableObject.h"


DrawableObject::DrawableObject()
{
}


DrawableObject::~DrawableObject()
{
}


sf::Vector2f DrawableObject::GetSpeed() const
{
	return m_speed;
}


void DrawableObject::SetSpeed(sf::Vector2f speed)
{
	m_speed = speed;
}


bool DrawableObject::GetFollowState() const
{
	return m_followingWindow;
}


void DrawableObject::SetFollowState(bool state)
{
	m_followingWindow = state;
}
