#pragma once
#include <string>
class CommandMemento
{
public:
	CommandMemento(std::string string);
	~CommandMemento();

	std::string GetString();
private:
	std::string m_string;
};

