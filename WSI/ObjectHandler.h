#pragma once
#include "LineWriter.h"
#include "Header.h"
#include "AssetLoader.h"

class ObjectHandler
{
public:
	ObjectHandler();
	~ObjectHandler();

	void UpdateEverything(sf::RenderWindow& window);
	void DrawEverything(sf::RenderWindow& window);

private:
	Header* m_header;
	AssetLoader* m_loader;
};

