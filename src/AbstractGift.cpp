#include "AbstractGift.h"

AbstractGift::AbstractGift(sf::Vector2f position) : GameObject(position)
{
}

void AbstractGift::move()
{
	m_direction = { 0,GIFT_SPEED };
	m_sprite.move(m_direction * getDeltaTime2().asSeconds());
}
