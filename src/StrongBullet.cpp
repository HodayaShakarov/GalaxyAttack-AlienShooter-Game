#include "StrongBullet.h"
#include<iostream>
//----------------------------------------------------------------------
StrongBulllet::StrongBulllet(sf::Vector2f position, bool flag) : AbstractBullet(position)
{
	m_sprite.setTexture(Resources::getInstance().getImage("Bullet"));
}
//----------------------------------------------------------------------
void StrongBulllet::move()
{
		m_direction = { 0,STRONG_BULLET_SPEED };
		m_sprite.move(m_direction * (getDeltaTime2().asSeconds()));	
}
//----------------------------------------------------------------------
