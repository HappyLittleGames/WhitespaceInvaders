#pragma once
#include "ObjectHandler.h"
#include "LineWriter.h"
#include "ScreenHandler.h"

static class Commands
{
public:

	static void EnterCommand(sf::RenderWindow& window, const std::string& command, sf::Event event);
	static std::vector<std::string> GetCommands();
	static std::string GetError();
};

