#pragma once
#include "GameObject.h"
#include "Factory.h"

class Meteor : public GameObject
{
public:
	Meteor(sf::Vector2f position);
	~Meteor() = default;
	void move();
	void setLeftToDie();
	int getLeftToDie();

protected:
	static bool m_registerit;
	int m_leftToDie;
};

inline bool Meteor::m_registerit = Factory::registeritMeteor("Meteor",
	[](sf::Vector2f position) -> std::unique_ptr<Meteor> { return std::make_unique<Meteor>(position); });
