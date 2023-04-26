#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Resources.h"
using std::string;

class Button
{
public:
	Button(string str, sf::Vector2f location);
	~Button() = default;
	void drawOnWindow(sf::RenderWindow& window); //פונקציה שמציגה את התפריט על המסך
	virtual bool handleClick(sf::RenderWindow& window) = 0; //פונקציה שמקבלת ומטפלת באירוע של לחיצת כפתור
	sf::Sprite getSprite(); //פונקציה שמחזירה את התמונה

protected:
	sf::Sprite m_sprite; //משתנה ששומר את התמונות
};

