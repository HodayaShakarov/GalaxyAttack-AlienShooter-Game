#include "SmallEnemySpaceShip.h"
//---------------------------------------------------------------
SmallEnemySpaceShip::SmallEnemySpaceShip(sf::Vector2f position) : AbstractEnemySpaceShip(position)
{
	m_sprite.setTexture(Resources::getInstance().getImage("SmallEnemySpaceShip"));
	m_leftToDie = 1;
}
//---------------------------------------------------------------
void SmallEnemySpaceShip::creatBullet()
{
	m_vectorOfBullet.emplace_back(Factory::createBullet("DirectBullet", { m_sprite.getPosition().x + 92, m_sprite.getPosition().y + 45 }, false));
}
//---------------------------------------------------------------
void SmallEnemySpaceShip::move()
{
}
//---------------------------------------------------------------

