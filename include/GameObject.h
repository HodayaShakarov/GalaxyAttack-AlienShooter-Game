#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Const.h"

class GameObject
{
public:
	GameObject(sf::Vector2f position);
	virtual ~GameObject() = default;
    void draw(sf::RenderWindow& window) const;// פונקציה שמציגה את האובייקט
	sf::Time getDeltaTime();
	sf::Time getDeltaTime2();
	sf::FloatRect returnGetGlobalBouns();//פונקציה שמחזירה מלבן חוסם של האובייקט

protected:
	sf::Sprite m_sprite;
	sf::Clock m_clock;
	sf::Vector2f m_direction; //כיוון נוכחי
};