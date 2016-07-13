#include "Commands.h"


void Commands::EnterCommand(sf::RenderWindow & window, const std::string& command, sf::Event event)
{
	std::cout << "attempting to run commmand '" << command << "' for no reason" << std::endl;

	if ((command == "pew") ||(command == "lazer"))
	{
		if (ObjectHandler::GetInstance()->GetPlayer()->GetCommand().getString().getSize() > 0)
		{
			ObjectHandler::GetInstance()->AddLazer(LineWriter::NewLazer(window, ObjectHandler::GetInstance()->GetPlayer()->GetCommand(), -ObjectHandler::GetInstance()->GetGameAngle(), sf::Vector2f(0, -120)));
			ObjectHandler::GetInstance()->GetLazers().back()->GetText()->setString("lazer();");
			std::cout << "size of lazers: " << ObjectHandler::GetInstance()->GetLazers().size() << "." << std::endl;
			
		}

		ObjectHandler::GetInstance()->GetPlayer()->EnterText(event);
	}
	else if (command == "help")
	{
		sf::Text refText = *ObjectHandler::GetInstance()->GetPlayer()->GetText();

		ObjectHandler::GetInstance()->AddInvader(LineWriter::NewInvader(window, refText, ObjectHandler::GetInstance()->GetGameAngle() - 180, sf::Vector2f(0, 0), ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition()));
		ObjectHandler::GetInstance()->GetInvaders().back()->SetString(ObjectHandler::GetInstance()->GetPlayer()->GetText()->getString() + ObjectHandler::GetInstance()->GetPlayer()->GetCommand().getString());
		ObjectHandler::GetInstance()->GetInvaders().back()->SetFollowState(false);
		ObjectHandler::GetInstance()->GetInvaders().back()->SetTrailState(false);
		ObjectHandler::GetInstance()->GetInvaders().back()->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));

		for (int i = 0; i < GetCommands().size(); i++)
		{
			// sf::Text refText = *ObjectHandler::GetInstance()->GetPlayer()->GetText();

			ObjectHandler::GetInstance()->AddInvader(LineWriter::NewInvader(window, refText, ObjectHandler::GetInstance()->GetGameAngle() - 180, sf::Vector2f(0, 0), ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition()));
			ObjectHandler::GetInstance()->GetInvaders().back()->SetString(GetCommands().at(i));
			ObjectHandler::GetInstance()->GetInvaders().back()->SetFollowState(false);
			ObjectHandler::GetInstance()->GetInvaders().back()->SetTrailState(false);
			ObjectHandler::GetInstance()->GetInvaders().back()->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));
			ObjectHandler::GetInstance()->GetInvaders().back()->GetText()->setPosition(ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition() + sf::Vector2f( (i + 1) * ObjectHandler::GetInstance()->GetInvaders().back()->GetText()->getCharacterSize() + 2, 0));
		}
		ObjectHandler::GetInstance()->GetPlayer()->EnterText(event);
		
		window.setPosition(window.getPosition() + sf::Vector2i(ObjectHandler::GetInstance()->GetPlayer()->GetText()->getCharacterSize() * ( GetCommands().size() + 1.5), 0));

	}
	else if (command == "reset")
	{
		window.setPosition(sf::Vector2i(30, 30));
	}
	else if (command == "newgame")
	{
		for each (Invader* invader in ObjectHandler::GetInstance()->GetInvaders())
		{
			invader->SetExplodingState(true);
		}
		for each (Lazer* lazer in ObjectHandler::GetInstance()->GetLazers())
		{
			lazer->SetExplodingState(true);
		}
	}
	else if (command == "left")
	{
		float xPos = (ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition().x > 45) ? 45 : ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition().x;
		sf::Vector2f moveAmount( -xPos, 0 );

		ObjectHandler::GetInstance()->GetPlayer()->GetText()->setPosition(ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition() + moveAmount);
		
	}
	else if (command == "right")
	{
		float xPos = (ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition().x < window .getSize().x - 45) ? 45 : window.getSize().x - ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition().x - ObjectHandler::GetInstance()->GetPlayer()->GetText()->getCharacterSize();
		sf::Vector2f moveAmount( xPos, 0 );

		ObjectHandler::GetInstance()->GetPlayer()->GetText()->setPosition(ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition() + moveAmount);
		
	}
	else if ((command == "quit") || (command == "exit"))
	{
		window.close();
	}
	else
	{
		if (ObjectHandler::GetInstance()->GetPlayer()->GetCommand().getString().getSize() > 0);
		{
			sf::Text refText = *ObjectHandler::GetInstance()->GetPlayer()->GetText();

			ObjectHandler::GetInstance()->AddInvader(LineWriter::NewInvader(window, refText, ObjectHandler::GetInstance()->GetGameAngle() - 180, sf::Vector2f(0, 0), ObjectHandler::GetInstance()->GetPlayer()->GetText()->getPosition()));
			ObjectHandler::GetInstance()->GetInvaders().back()->SetString(GetError());
			ObjectHandler::GetInstance()->GetInvaders().back()->SetFollowState(false);
			ObjectHandler::GetInstance()->GetInvaders().back()->SetTrailState(false);
			ObjectHandler::GetInstance()->GetInvaders().back()->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));

			window.setPosition(window.getPosition() + sf::Vector2i(ObjectHandler::GetInstance()->GetPlayer()->GetText()->getCharacterSize() * 4.5, 0));
		}
	}
	ObjectHandler::GetInstance()->GetPlayer()->EnterText(event);
}


std::vector<std::string> Commands::GetCommands()
{
	std::vector<std::string> commands;

	//commands.push_back("COMMAND			description");
	commands.push_back("newgame             start a new game");
	commands.push_back("lazer               pew pew pew pew");
	commands.push_back("reset               resets position, might be helpful");
	commands.push_back("options             there are no options");
	commands.push_back("credits             as if");
	commands.push_back("quit                give up and quit");

	return commands;
}

std::string Commands::GetError()
{
	return ObjectHandler::GetInstance()->GetPlayer()->GetText()->getString() + ObjectHandler::GetInstance()->GetPlayer()->GetCommand().getString() + "\n'" + ObjectHandler::GetInstance()->GetPlayer()->GetCommand().getString() + "' is not recognized as an internal nor external command, \noperable program or batch file. \nType 'help' for more information.";
}

void Commands::SetExploding(std::vector<Line*>& lines)
{
	for each (Line* line in lines)
	{
		line->SetExplodingState(true);
	}
}
