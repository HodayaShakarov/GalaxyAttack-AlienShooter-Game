#include "AbstractEnemySpaceShip.h"
//------------------------------------------------------------------------
AbstractEnemySpaceShip::AbstractEnemySpaceShip(sf::Vector2f position) : GameObject(position), m_leftForGift()
{

}
//------------------------------------------------------------------------
void AbstractEnemySpaceShip::moveOfBullet()
{
	for (const auto& Bullet : m_vectorOfBullet)
		Bullet->move();
}
//-------------------------------------------------------------------------
void AbstractEnemySpaceShip::drawBullet(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_vectorOfBullet.size(); i++)
			m_vectorOfBullet[i]->draw(window);
}
//-------------------------------------------------------------------------
void AbstractEnemySpaceShip::setDirection(int directionX)
{
	if (m_direction.x == -directionX)
		m_direction.x = directionX;
	else
		m_direction.x = -directionX;
}
//-------------------------------------------------------------------------
sf::FloatRect AbstractEnemySpaceShip::returnGetGlobalBounsOfBullet(int index)
{
	return m_vectorOfBullet[index]->returnGetGlobalBouns();
}
//-------------------------------------------------------------------------
std::unique_ptr<AbstractBullet> AbstractEnemySpaceShip::returnBullet(int index)
{
	return std::move(m_vectorOfBullet[index]);
	
}
//-------------------------------------------------------------------------
int AbstractEnemySpaceShip::returnSizeOfBullets()
{
	return m_vectorOfBullet.size();
}
//-------------------------------------------------------------------------
 sf::Vector2f AbstractEnemySpaceShip::getImagePosition()
 {
	return sf::Vector2f( m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 3.8,
						 m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2);
 }

 void AbstractEnemySpaceShip::deleteBullet(int index)
 {
	 m_vectorOfBullet.erase(m_vectorOfBullet.begin() + index);
 }

 void AbstractEnemySpaceShip::setLeftToDie()
 {
	 m_leftToDie--;
 }

 int AbstractEnemySpaceShip::getLeftToDie()
 {
	 return m_leftToDie;
 }

