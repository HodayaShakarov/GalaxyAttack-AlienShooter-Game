#pragma once
#include "AbstractEnemySpaceShip.h"
#include "Factory.h"

class SmallEnemySpaceShip : public AbstractEnemySpaceShip
{
public:
	SmallEnemySpaceShip(sf::Vector2f position);
	~SmallEnemySpaceShip() = default;
	void creatBullet();//יצירת יריות לחלליחןת אויב הקטנות
	void move();

protected:
	static bool m_registerit;
};

inline bool SmallEnemySpaceShip::m_registerit = Factory::registeritEnemySpaceShip("SmallEnemySpaceShip",
	[](sf::Vector2f position) -> std::unique_ptr<AbstractEnemySpaceShip> { return std::make_unique<SmallEnemySpaceShip>(position); });
