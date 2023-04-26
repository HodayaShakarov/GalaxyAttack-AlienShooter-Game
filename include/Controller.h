#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Const.h"
#include "Game.h"

class Controller
{
public:
	Controller();
	~Controller() = default;
	void run(); //פונקציה שמנהלת את המשחק

protected:
	sf::RenderWindow m_window; //חלון המשחק
	Menu m_menu; //תפריט

};



