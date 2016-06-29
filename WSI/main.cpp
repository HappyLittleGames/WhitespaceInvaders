#include <SFML/Graphics.hpp>
#include "ObjectHandler.h"
#include "Commands.h"
#include <windows.h>
#include "GameOverScreen.h"
#include "MainScreen.h"
#include "ScreenHandler.h"

int main()
{
#ifndef _DEBUG
	FreeConsole();
#endif

	ObjectHandler* objectHandler = ObjectHandler::GetInstance();

	sf::VideoMode windowMode = sf::VideoMode(310, 512);

	sf::RenderWindow window(windowMode, "whitespace", sf::Style::None);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	sf::Clock clock;
	sf::Time time;
	float deltaTime = 0;

	sf::Vector2i mousePos;

	objectHandler->NewGame(window);

	ScreenHandler* screenHandler = new ScreenHandler();

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
						if (objectHandler->GetPlayer()->GetCommand().getString() == "newgame")
						{
							screenHandler->NextScreen();
							int lives = 3; // ????
							objectHandler->GetPlayer()->SetLives(lives);
							objectHandler->GetHeader()->SetTitle("Lives: 3");
						}
						Commands::EnterCommand(window, objectHandler->GetPlayer()->GetCommand().getString(), event);
					}

					else if (event.key.code == sf::Keyboard::F1)
					{
						// Man you gotta make a commands class
						// objectHandler->AddInvader(LineWriter::NewInvader(window, objectHandler->GetLoader()->GetFont(), sf::Vector2f(window.getSize().x / 2, 40)));
						objectHandler->AddInvader(LineWriter::NewInvader(window, objectHandler->GetPlayer()->GetCommand(), objectHandler->GetGameAngle(), sf::Vector2f((rand() % 30) - 10, 50), sf::Vector2f(window.getSize().x/2, 60)));
						std::cout << "amount of invaders: " << objectHandler->GetInvaders().size() << "." << std::endl;
					}

					else if (event.key.code == sf::Keyboard::F2)
					{
						// Man you gotta make a commands class
						
						for each (Line* lazer in objectHandler->GetLazers())
						{
							lazer->SetExplodingState(true);
							lazer->GetText()->setColor(sf::Color(255, 0, 0, 255));
						}
						for each (Line* invader in objectHandler->GetInvaders())
						{
							invader->SetExplodingState(true);
							invader->GetText()->setColor(sf::Color(255, 0, 0, 255));
						}
					}
					else if (event.key.code == sf::Keyboard::F3)
					{
						std::cout << "making lazers splode " << std::endl;
						for each (Lazer* lazer in objectHandler->GetLazers())
						{
							//objectHandler->AddSplosion(LineWriter::NewSplosion(window, *lazer->GetText()));
							lazer->SetExplodingState(true);
						}	
						for each (Invader* invader in objectHandler->GetInvaders())
						{
							//objectHandler->AddSplosion(LineWriter::NewSplosion(window, *lazer->GetText()));
							invader->SetExplodingState(true);
						}
					}
					else if (event.key.code == sf::Keyboard::F4)
					{
						screenHandler->NextScreen();
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

		time = clock.getElapsedTime();
		// std::cout << "Delta Time: " << time.asSeconds() << "." << std::endl;
		deltaTime = time.asSeconds();
		clock.restart();

		screenHandler->UpdateScreen(window, deltaTime);

		/*if (gameScreen != nullptr)
		{
			if (gameScreen->UpdateScreen(window, deltaTime))
			{
				gameScreen->~Screen();
				gameScreen = new GameOverScreen();
			}
		}*/

		objectHandler->UpdateEverything(window, deltaTime);
		objectHandler->ExplodeExploders(window);
		objectHandler->DrawEverything(window);

		window.display();
	}

	return 0;
}
