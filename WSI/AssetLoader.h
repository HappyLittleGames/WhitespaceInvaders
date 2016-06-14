#pragma once
#include "SFML\Graphics.hpp"
class AssetLoader
{
public:
	AssetLoader();
	~AssetLoader();

	sf::Font& GetFont();
private:
	sf::Font m_font;
};

