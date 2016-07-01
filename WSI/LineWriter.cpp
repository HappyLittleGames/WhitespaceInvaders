#include "LineWriter.h"



LineWriter::LineWriter()
{
}


LineWriter::~LineWriter()
{
}


Player* LineWriter::NewPlayer(const sf::RenderWindow& window, sf::Font& font, float angle)
{
	Player* player = new Player();
	sf::Text* playerText = new sf::Text();

	playerText->setCharacterSize(18);
	playerText->setPosition((window.getSize().x / 2 - (playerText->getCharacterSize()/2)), window.getSize().y - 16);
	playerText->setColor(sf::Color::White);
	playerText->setRotation(angle);
	playerText->setFont(font);

	playerText->setString("C:/player> ");

	player->SetText(playerText);
	// sort the fucker out
	sf::Text playerCommand = sf::Text();

	playerCommand.setCharacterSize(18);
	playerCommand.setPosition((playerText->getPosition() - sf::Vector2f(0,(playerText->getCharacterSize() / 1.8) * playerText->getString().getSize())));
	playerCommand.setColor(sf::Color::White);
	playerCommand.setRotation(angle);
	playerCommand.setFont(font);

	playerCommand.setString("");

	player->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));
	player->SetFollowState(true);
	player->SetCommand(playerCommand);

	return player;
}


Lazer* LineWriter::NewLazer(const sf::RenderWindow& window, const sf::Text& copyText, float angle, sf::Vector2f speed)
{
	std::cout << "Making Lazer pew pew pew" << std::endl;

	Lazer* lazer = new Lazer();
	sf::Text* lazerText = new sf::Text;

	lazerText->setCharacterSize(copyText.getCharacterSize());
	lazerText->setPosition(copyText.getPosition());
	lazerText->setColor(copyText.getColor());
	lazerText->setRotation(angle);
	lazerText->setFont(*copyText.getFont());
	lazerText->setString(copyText.getString());

	lazer->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));
	lazer->SetSpeed(speed);
	lazer->SetFollowState(true);
	lazer->SetText(lazerText);
	
	return lazer;

	lazer->~Lazer();
	delete lazerText;
}


Invader* LineWriter::NewInvader(const sf::RenderWindow& window, const sf::Text& copyText, float angle, sf::Vector2f speed, sf::Vector2f position)
{
	std::cout << "Making Lazer pew pew pew" << std::endl;

	Invader* invader = new Invader();
	sf::Text* invaderText = new sf::Text;

	invaderText->setCharacterSize(copyText.getCharacterSize());
	invaderText->setPosition(position);
	invaderText->setColor(copyText.getColor());
	invaderText->setRotation(angle);
	invaderText->setFont(*copyText.getFont());
	invaderText->setString(copyText.getString());

	invader->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));
	invader->SetSpeed(speed);
	invader->SetFollowState(true);
	invader->SetTrailState(true);
	invader->SetText(invaderText);
	return invader;

	invader->~Invader();
	delete invaderText;
}


Splosion* LineWriter::NewSplosion(const sf::RenderWindow& window, const sf::Text& copyText, float angle)
{
	Splosion* splosion = new Splosion();
	sf::Text* splosionText = new sf::Text;

	splosionText->setCharacterSize(copyText.getCharacterSize());
	splosionText->setPosition(copyText.getPosition());
	splosionText->setColor(copyText.getColor());
	splosionText->setRotation(angle);
	splosionText->setFont(*copyText.getFont());
	splosionText->setString(copyText.getString());

	splosion->SetWindowPos(sf::Vector2f(window.getPosition().x, window.getPosition().y));
	splosion->SetFollowState(true);
	splosion->SetText(splosionText);
	return splosion;

	splosion->~Splosion();
	delete splosionText;
}

