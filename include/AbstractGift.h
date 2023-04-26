#pragma once
#include "GameObject.h"

class AbstractGift : public GameObject
{
public:
	AbstractGift(sf::Vector2f position);
	~AbstractGift() = default;
	void move();

protected:

};

