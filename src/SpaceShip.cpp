#include "SpaceShip.h"
#include<iostream>
//-------------------------------------------------------------------
SpaceShip::SpaceShip(sf::Vector2f position) : GameObject(position), m_life(3), m_score(0), m_isProtected(false), m_ProtectionClock()
{
	m_sprite.setTexture(Resources::getInstance().getImage("SpaceShip"));
}
//-------------------------------------------------------------------

void SpaceShip::handleEvent(sf::Keyboard::Key key)
{
	//static int i = 0;
	switch (key)
	{
	case sf::Keyboard::Key::Left:
		m_direction = { -1,0 };
		calculateSpeed(m_direction, SPACE_SHIP_SPEED);
		break;
	case sf::Keyboard::Key::Right:
		m_direction = { 1,0 };
		calculateSpeed(m_direction, SPACE_SHIP_SPEED);
		break;
	case sf::Keyboard::Key::Up:
		//if (i % 3 == 0)
		m_bullets.emplace_back(Factory::createBullet("DirectBullet", { m_sprite.getPosition().x + 39, m_sprite.getPosition().y - 25 }, true));
		//i++;
		break;
	case sf::Keyboard::Key::Down:
		m_direction = { 0,0 };
		break;
	case sf::Keyboard::Key::Space:
		break;
	}
}
//-------------------------------------------------------------------

void SpaceShip::calculateSpeed(sf::Vector2f& m_direction, int speed)
{
	m_direction.x *= speed;
	m_direction.y *= speed;
}
//-------------------------------------------------------------------

void SpaceShip::move(sf::Time deltaTime)
{
	if (isOutOfLimits((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		m_sprite.move(m_direction * deltaTime.asSeconds());
}
//-------------------------------------------------------------------
void SpaceShip::drawBullet(sf::RenderWindow& window)
{
	for (const auto& bullet : m_bullets)
		bullet->draw(window);
}
//-------------------------------------------------------------------
void SpaceShip::moveBullet(sf::Time deltaTime)
{
	for (const auto& bullet : m_bullets)
		bullet->move(deltaTime);
}
//-------------------------------------------------------------------
bool SpaceShip::isOutOfLimits(const sf::Vector2f& destination)
{
	return(destination.x >= 0 && destination.x + m_sprite.getGlobalBounds().width <= WIDTH_OF_WINDOW &&
		destination.y >= 0 && destination.y + m_sprite.getGlobalBounds().height <= HIGHT_OF_WINDOW);
}
//-------------------------------------------------------------------
sf::Vector2f SpaceShip::getPosition()
{
	return m_sprite.getPosition();
}
//-------------------------------------------------------------------
sf::FloatRect SpaceShip::returnGetGlobalBounsOfBullet(int index)
{
	return m_bullets[index]->returnGetGlobalBouns();
}
//-------------------------------------------------------------------
std::unique_ptr<AbstractBullet> SpaceShip::returnBullet(int index)
{
	return std::move(m_bullets[index]);
}
//-------------------------------------------------------------------
int SpaceShip::returnSizeOfBullets()
{
	return m_bullets.size();
}
//-------------------------------------------------------------------
void SpaceShip::deletBullet(int index)
{
	m_bullets.erase(m_bullets.begin() + index);
}
//-------------------------------------------------------------------
void SpaceShip::setProtected(bool protect)
{
	static int protectionTime = PROTECTION_TIME;
	m_isProtected = protect;
	setTexture();
	if (protectionTime - m_ProtectionClock.getElapsedTime().asSeconds() <= 0)
	{
		m_isProtected = false;
		protectionTime = PROTECTION_TIME;
		m_ProtectionClock.restart();
		setTexture();
	}
}
//-------------------------------------------------------------------
void SpaceShip::setLife(int num)
{
	m_life += num;
}
//-------------------------------------------------------------------
int SpaceShip::getLife()
{
	return m_life;
}
//-------------------------------------------------------------------
bool SpaceShip::getProtected()
{
	return m_isProtected;
}
//-------------------------------------------------------------------
void SpaceShip::setTexture()
{
	if (m_isProtected)
		m_sprite.setTexture(Resources::getInstance().getImage("ProtectedSpaceShip"), true);
	else
		m_sprite.setTexture(Resources::getInstance().getImage("SpaceShip"), true);
}
//-------------------------------------------------------------------
void SpaceShip::unProtected()
{
	m_isProtected = false;
}
//-------------------------------------------------------------------
void SpaceShip::addScore()
{
	m_score += ADD_SCORE;
}
//-------------------------------------------------------------------
int SpaceShip::getScore()
{
	return m_score;
}
