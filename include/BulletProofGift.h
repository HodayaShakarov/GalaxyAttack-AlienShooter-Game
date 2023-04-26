#pragma once
#include "AbstractGift.h"
#include "Factory.h"

class BulletProofGift : public AbstractGift
{
public:
	BulletProofGift(sf::Vector2f position);
	~BulletProofGift() = default;

protected:
	static inline bool m_registerit = Factory::registeritGift(
		[](sf::Vector2f position) -> std::unique_ptr<AbstractGift> { return std::make_unique<BulletProofGift>(position); });

};
