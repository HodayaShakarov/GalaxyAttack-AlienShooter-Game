#include "BigEnemySpaceship.h"
#include<iostream>
//---------------------------------------------------------------
BigEnemySpaceShip::BigEnemySpaceShip(sf::Vector2f position) : AbstractEnemySpaceShip(position)
{
	m_sprite.setTexture(Resources::getInstance().getImage("BigEnemySpaceShip"));
	m_direction = { BIG_ENEMY_SPACESHIP_SPEED,0 };
	m_leftToDie = 80;
}
//---------------------------------------------------------------
void BigEnemySpaceShip::creatBullet()
{
	m_vectorOfBullet.emplace_back(Factory::createBullet("StrongBulllet", { m_sprite.getPosition().x + 136, m_sprite.getPosition().y + 290 }, false));
}
//---------------------------------------------------------------
void BigEnemySpaceShip::move()
{
	
	if (!(isInLimits(m_direction * getDeltaTime2().asSeconds() + m_sprite.getPosition())))
		setDirection(m_direction.x);
	std::cout << m_direction.x << " " << m_direction.y;
	m_sprite.move(m_direction * (getDeltaTime2().asSeconds()));
}
//---------------------------------------------------------------
bool BigEnemySpaceShip::isInLimits(const sf::Vector2f& destination)
{
	return(destination.x >= 0 && destination.x + m_sprite.getGlobalBounds().width <= WIDTH_OF_WINDOW &&
		destination.y >= 0 && destination.y + m_sprite.getGlobalBounds().height <= 400);
}

