#include "CommandLog.h"

CommandLog* CommandLog::m_instance = nullptr;

CommandLog * CommandLog::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CommandLog();
	}
	return m_instance;
}

void CommandLog::InputString(std::string string)
{
	m_upwardsLog.push(new CommandMemento(string));
	printf("memorizing string ");
}

std::string CommandLog::CycleUp()
{
	if (m_upwardsLog.size() > 0)
	{
		std::string tempCommand = m_upwardsLog.top()->GetString();
		m_upwardsLog.pop();
		m_downwardsLog.push(new CommandMemento(tempCommand));
		return tempCommand;
	}
	else
	{
		printf("attempting to cycle up through empty vector");
		return "";
	}
}

std::string CommandLog::CycleDown()
{
	if (m_downwardsLog.size() > 0)
	{
		std::string tempCommand = m_downwardsLog.top()->GetString();
		m_downwardsLog.pop();
		m_upwardsLog.push(new CommandMemento(tempCommand));
		return tempCommand;
	}
	else
	{
		printf("attempting to cycle down through empty vector");
		return "";
	}
}

CommandLog::CommandLog()
{
}

