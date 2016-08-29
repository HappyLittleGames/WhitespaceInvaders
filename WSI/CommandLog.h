#pragma once
#include <stack>
#include "CommandMemento.h"
#include <iostream>

class CommandLog
{
public:
	static CommandLog* GetInstance();

	void InputString(std::string string);
	std::string CycleUp();
	std::string CycleDown();
private:
	static CommandLog* m_instance;
	CommandLog();

	std::stack<CommandMemento*> m_upwardsLog;
	std::stack<CommandMemento*> m_downwardsLog;
};

