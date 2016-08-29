#include "CommandMemento.h"



CommandMemento::CommandMemento(std::string string)
{
	m_string = string;
}


CommandMemento::~CommandMemento()
{
}

std::string CommandMemento::GetString()
{
	return m_string;
}
