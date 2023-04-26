#include "LifeGift.h"

LifeGift::LifeGift(sf::Vector2f position) : AbstractGift(position)
{
	m_sprite.setTexture(Resources::getInstance().getImage("LifeGift"));
}
