#include "DirectBullet.h"

DirectBullet::DirectBullet(sf::Vector2f position, bool flag) : AbstractBullet(position), m_type(flag)
{
	if(flag)
		m_sprite.setTexture(Resources::getInstance().getImage("DirectBullet"));
	else
		m_sprite.setTexture(Resources::getInstance().getImage("StrongBulllet"));
}
//--------------------------------------------------------------------
void DirectBullet::move()
{
	m_direction.x = 0;
	m_direction.y = DIRECT_BULLET_SPEED;
	m_sprite.move(m_direction * (getDeltaTime2().asSeconds()));
}
//----------------------------------------------------------------------
void DirectBullet::setTexture()
{

}