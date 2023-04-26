#pragma once
#include "AbstractEnemySpaceShip.h"
#include "Factory.h"

class BigEnemySpaceShip : public AbstractEnemySpaceShip
{
public:
	BigEnemySpaceShip(sf::Vector2f position);
	~BigEnemySpaceShip() = default;
	void creatBullet();
	void move();
	bool isInLimits(const sf::Vector2f& destination);

protected:
	static bool m_registerit;
};

inline bool BigEnemySpaceShip::m_registerit = Factory::registeritEnemySpaceShip("BigEnemySpaceShip",
	[](sf::Vector2f position) -> std::unique_ptr<AbstractEnemySpaceShip> { return std::make_unique<BigEnemySpaceShip>(position); });

