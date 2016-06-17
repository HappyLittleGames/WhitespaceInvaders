#include "LineWriter.h"



LineWriter::LineWriter()
{
}


LineWriter::~LineWriter()
{
}


Player* LineWriter::NewPlayer(const sf::RenderWindow& window, sf::Font& font)
{
	Player* player = new Player();
	sf::Text* playerText = new sf::Text();

	playerText->setCharacterSize(18);
	playerText->setPosition((window.getSize().x / 2 - (playerText->getCharacterSize()/2)), window.getSize().y - 16);
	playerText->setColor(sf::Color::White);
	playerText->setRotation(-90);
	playerText->setFont(font);

	playerText->setString("Fransmän: ");

	player->SetText(playerText);
	// sort the fucker out
	sf::Text playerCommand = sf::Text();

	playerCommand.setCharacterSize(18);
	playerCommand.setPosition((playerText->getPosition() - sf::Vector2f(0,(playerText->getCharacterSize() / 1.7) * playerText->getString().getSize())));
	playerCommand.setColor(sf::Color::White);
	playerCommand.setRotation(-90);
	playerCommand.setFont(font);

	playerCommand.setString("textext");

	player->SetCommand(playerCommand);

	return player;
}


Lazer* LineWriter::NewLazer(const sf::RenderWindow& window, const sf::Text& copyText)
{
	std::cout << "Making Lazer pew pew pew" << std::endl;

	Lazer* lazer = new Lazer();
	sf::Text* lazerText = new sf::Text();

	lazerText->setCharacterSize(copyText.getCharacterSize());
	lazerText->setPosition(copyText.getPosition());
	lazerText->setColor(copyText.getColor());
	lazerText->setRotation(copyText.getRotation());
	lazerText->setFont(*copyText.getFont());
	lazerText->setString(copyText.getString());

	lazer->SetFollowState(true);
	lazer->SetText(lazerText);
	return lazer;
}

Invader* LineWriter::NewInvader(const sf::RenderWindow & window, sf::Font & font, sf::Vector2f spawnPos)
{
	Invader* invader = new Invader();
	sf::Text* invaderText = new sf::Text();

	invaderText->setCharacterSize(18);
	invaderText->setPosition(spawnPos);
	invaderText->setColor(sf::Color::White);
	invaderText->setRotation(90);
	invaderText->setFont(font);
	invaderText->setString("Invade();");

	invader->SetText(invaderText);

	return invader;
}

