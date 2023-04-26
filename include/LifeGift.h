#pragma once
#include "AbstractGift.h"
#include "Factory.h"

class LifeGift : public AbstractGift
{
public:
	LifeGift(sf::Vector2f position);
	~LifeGift() = default;

protected:
	static bool m_registerit;
};

inline bool LifeGift::m_registerit = Factory::registeritGift(
	[](sf::Vector2f position) -> std::unique_ptr<AbstractGift> { return std::make_unique<LifeGift>(position); });
