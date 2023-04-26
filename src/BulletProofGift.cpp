#include "BulletProofGift.h"

BulletProofGift::BulletProofGift(sf::Vector2f position) : AbstractGift(position)
{
	m_sprite.setTexture(Resources::getInstance().getImage("BulletProofGift"));
}
