#pragma once
#include "AbstractBullet.h"
#include "Factory.h"
#include "SpaceShip.h"

class StrongBulllet : public AbstractBullet
{
public:
	StrongBulllet(sf::Vector2f position, bool flag);
	~StrongBulllet() = default;
	void move();

protected:
	static bool m_registerit;
};

inline bool StrongBulllet::m_registerit = Factory::registeritBullet("StrongBulllet",
	[](sf::Vector2f position, bool flag) -> std::unique_ptr<AbstractBullet> { return std::make_unique<StrongBulllet>(position, flag); });
