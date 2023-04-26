#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Resources.h"
#include "NewGame.h"
#include "Help.h"
#include "Exit.h"

class Menu
{
public:
	Menu();
	~Menu() = default;
	bool CheckMenuEvents(sf::RenderWindow& window);
	void drawMenuWindow(sf::RenderWindow& window);
	bool isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window, Button& button); //פונקציה שבודקת אם הלחיצה נעשתה על הכפתור

private:
	sf::Sprite m_sprite;
	std::vector <std::unique_ptr<Button>> m_buttons;
};
