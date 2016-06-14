#include <SFML/Graphics.hpp>
#include "ObjectHandler.h"

int main()
{
	sf::VideoMode windowMode = sf::VideoMode(256, 512);

	sf::RenderWindow window(windowMode, "whitespace", sf::Style::None);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	ObjectHandler* objectHandler = new ObjectHandler();

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		objectHandler->UpdateEverything(window);
		objectHandler->DrawEverything(window);

		window.display();
	}

	return 0;
}
