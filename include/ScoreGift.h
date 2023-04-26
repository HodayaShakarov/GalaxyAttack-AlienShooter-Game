#pragma once
#include "AbstractGift.h"
#include "Factory.h"

class ScoreGift : public AbstractGift
{
public:
	ScoreGift(sf::Vector2f position);
	~ScoreGift() = default;

protected:
	static bool m_registerit;
};

inline bool ScoreGift::m_registerit = Factory::registeritGift(
	[](sf::Vector2f position) -> std::unique_ptr<AbstractGift> { return std::make_unique<ScoreGift>(position); });
