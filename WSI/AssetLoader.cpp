#include "AssetLoader.h"
#include <iostream>



AssetLoader::AssetLoader()
{
}


AssetLoader::~AssetLoader()
{
}


sf::Font& AssetLoader::GetFont()
{
	if (!m_font.loadFromFile("lucon.ttf"))
	{
		std::cout << "Failed to load font 'lucon.tff'" << std::endl;
	}
	sf::Font& fontRef = m_font;
	return fontRef;
}
