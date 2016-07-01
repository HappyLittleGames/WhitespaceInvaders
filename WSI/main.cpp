#define CRTDBG_MAP_ALLOC

#include <SFML/Graphics.hpp>
#include "ObjectHandler.h"
#include "Commands.h"
#include <windows.h>
#include "GameOverScreen.h"
#include "MainScreen.h"
#include "ScreenHandler.h"
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif 

int main()
{
	char *a = new char[10];
	char *b = (char*)malloc(20);
	_CrtDumpMemoryLeaks();

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	ObjectHandler* objectHandler = ObjectHandler::GetInstance();

	sf::VideoMode windowMode = sf::VideoMode(310, 512);

	sf::RenderWindow window(windowMode, "whitespace", sf::Style::None);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

#ifndef _DEBUG
	window.setPosition(sf::Vector2i(0, 0));
	FreeConsole();
#endif

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
							screenHandler->SetScreen(1);
							int lives = 3; // ????
							objectHandler->GetPlayer()->SetLives(lives);
							objectHandler->GetHeader()->SetTitle("Lives: 3");
						}
						Commands::EnterCommand(window, objectHandler->GetPlayer()->GetCommand().getString(), event);
					}

					else if (event.key.code == sf::Keyboard::F1)
					{
						objectHandler->NewGame(window);
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
						objectHandler->GetPlayer()->SetLives(3);
						screenHandler->NextScreen();
						for each (Invader* invader in objectHandler->GetInvaders())
						{
							invader->SetExplodingState(true);
						}
					}

					else if (event.key.code == sf::Keyboard::BackSpace)
					{
						objectHandler->GetPlayer()->EnterText(event);
					}
					break;
				}
			}
		}


		// update and draw


		window.clear();

		time = clock.getElapsedTime();
		// std::cout << "Delta Time: " << time.asSeconds() << "." << std::endl;
		deltaTime = time.asSeconds();
		clock.restart();

		screenHandler->UpdateScreen(window, deltaTime);

		objectHandler->UpdateEverything(window, deltaTime);
		objectHandler->ExplodeExploders(window);
		objectHandler->DrawEverything(window);

		window.display();
	}
	return 0;
}
