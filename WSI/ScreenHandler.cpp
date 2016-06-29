#include "ScreenHandler.h"



ScreenHandler::ScreenHandler()
{
	m_screens.push_back(nullptr);
	m_screens.push_back(new MainScreen());
	m_screens.push_back(new GameOverScreen());
	m_screens.push_back(new Screen());
	m_screenIndex = 0;
}


ScreenHandler::~ScreenHandler()
{
}

void ScreenHandler::NextScreen()
{
	if (m_screenIndex < m_screens.size()-1)
	{
		m_screenIndex++;
	}
	else
	{
		m_screenIndex = 0;
	}
	std::cout << "screen index at this time: " << m_screenIndex << std::endl;
}

void ScreenHandler::UpdateScreen(sf::RenderWindow & window, float deltaTime)
{
	if (m_screens[m_screenIndex] != nullptr)
	{
		if (m_screens[m_screenIndex]->UpdateScreen(window, deltaTime))
		{
			NextScreen();
		}
	}
	
}

void ScreenHandler::SetScreen(unsigned index)
{
	m_screenIndex = index;
}
