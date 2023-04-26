#include "Controller.h"
#include <iostream>
using std::cout;

Controller::Controller() : m_window(sf::VideoMode(WIDTH_OF_WINDOW, HIGHT_OF_WINDOW), "Galaxy attack: Alien shooter"), m_menu()
{
}

void Controller::run()
{
	while (true)
	{
		m_window.clear();
		m_menu.CheckMenuEvents(m_window);
		Game gameManager;
		gameManager.startGame(m_window);
	}
}
