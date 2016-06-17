#include <SFML/Graphics.hpp>
#include "ObjectHandler.h"

int main()
{
	ObjectHandler* objectHandler = ObjectHandler::GetInstance();

	sf::VideoMode windowMode = sf::VideoMode(256, 512);

	sf::RenderWindow window(windowMode, "whitespace", sf::Style::None);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	sf::Vector2i mousePos;

	objectHandler->NewGame(window);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case(sf::Event::MouseButtonPressed):
				{
					if (sf::Mouse::getPosition(window).y <= 30)
					{
						std::cout << "mouse clicked in header" << std::endl;
						objectHandler->GetHeader()->SetDragState(true);
					}
					break;
				}
				case (sf::Event::MouseButtonReleased) :
				{
					std::cout << "mouse released in anywhere really" << std::endl;
					objectHandler->GetHeader()->SetDragState(false);
					break;
				}
				case(sf::Event::Closed) :
				{
					window.close();
					break;
				}
				case(sf::Event::TextEntered) :
				{
					objectHandler->GetPlayer()->EnterText(event);
				}
				case (sf::Event::KeyPressed) :
				{
					if (event.key.code == sf::Keyboard::Return)
					{
						objectHandler->GetLazers().push_back(LineWriter::NewLazer(window, objectHandler->GetPlayer()->GetCommand()));
						objectHandler->GetPlayer()->EnterText(event);
						std::cout << "size of lazers: " << objectHandler->GetLazers().size() << "." << std::endl;
					}
					else if (event.key.code == sf::Keyboard::BackSpace)
					{
						objectHandler->GetPlayer()->EnterText(event);
					}
					break;
				}
			}
		}

		window.clear();

		objectHandler->UpdateEverything(window);
		objectHandler->DrawEverything(window);

		window.display();
	}

	return 0;
}
