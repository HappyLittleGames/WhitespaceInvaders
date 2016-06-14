#include "ObjectHandler.h"



ObjectHandler::ObjectHandler()
{
	m_loader = new AssetLoader();
	m_header = new Header(m_loader->GetFont());
}


ObjectHandler::~ObjectHandler()
{
}


void ObjectHandler::UpdateEverything(sf::RenderWindow& window)
{
}


void ObjectHandler::DrawEverything(sf::RenderWindow& window)
{
	float deltaTime = 1; // DON'T MAKE THIS HERE THO

	m_header->Draw(window, deltaTime);
}
