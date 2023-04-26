#include "AbstractBullet.h"

AbstractBullet::AbstractBullet(sf::Vector2f position) : GameObject(position)
{
}
//----------------------------------------------------------------------

void AbstractBullet::move(sf::Time deltaTime)
{
	m_direction = { 0,-1 };
	calculateSpeed(m_direction, DIRECT_BULLET_SPEED);
	m_sprite.move(m_direction * getDeltaTime2().asSeconds());
}
//----------------------------------------------------------------------

void AbstractBullet::calculateSpeed(sf::Vector2f& m_direction, int speed)
{
	m_direction.x *= speed;
	m_direction.y *= speed;
}



