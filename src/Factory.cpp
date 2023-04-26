#include "Factory.h"
#include "Meteor.h"
//-----------------------------------------------------------------------
std::unique_ptr<AbstractEnemySpaceShip> Factory::createEnemySpaceShip(const std::string& name, sf::Vector2f position)
{
	auto it = getMapOfEnemySpaceShip().find(name);
	if (it == getMapOfEnemySpaceShip().end())
		return nullptr;
	return it->second(position);
}
//-----------------------------------------------------------------------
bool Factory::registeritEnemySpaceShip(const std::string& name, std::unique_ptr<AbstractEnemySpaceShip>(*f)(sf::Vector2f position))
{
	getMapOfEnemySpaceShip().emplace(name, f);
	return true;
}
//-----------------------------------------------------------------------
std::unique_ptr<AbstractBullet> Factory::createBullet(const std::string& name, sf::Vector2f position, bool flag)
{
	auto it = getMapOfBullet().find(name);
	if (it == getMapOfBullet().end())
		return nullptr;
	return it->second(position, flag);
}
//-----------------------------------------------------------------------
bool Factory::registeritBullet(const std::string& name, std::unique_ptr<AbstractBullet>(*f)(sf::Vector2f position, bool flag))
{
	getMapOfBullet().emplace(name, f);
	return true;
}
//-----------------------------------------------------------------------
std::unique_ptr<Meteor> Factory::createMeteor(const std::string& name, sf::Vector2f position)
{
	auto it = getMapOfMeteor().find(name);
	if (it == getMapOfMeteor().end())
		return nullptr;
	return it->second(position);
}
//-----------------------------------------------------------------------
bool Factory::registeritMeteor(const std::string& name, std::unique_ptr<Meteor>(*f)(sf::Vector2f position))
{
	getMapOfMeteor().emplace(name, f);
	return true;
}
//-----------------------------------------------------------------------
std::unique_ptr<AbstractGift> Factory::createGift(sf::Vector2f position)
{
	int it = rand() % getGifts().size();
	return getGifts()[it](position);
}
//-----------------------------------------------------------------------
bool Factory::registeritGift(std::unique_ptr<AbstractGift>(*f)(sf::Vector2f position))
{
	getGifts().emplace_back(f);
	return true;
}
//-----------------------------------------------------------------------
mapOfEnemySpaceShip& Factory::getMapOfEnemySpaceShip()
{
	static mapOfEnemySpaceShip m_mapOfEnemySpaceShip;
	return m_mapOfEnemySpaceShip;
}
//-----------------------------------------------------------------------
mapOfBullet& Factory::getMapOfBullet()
{
	static mapOfBullet m_mapOfBullet;
	return m_mapOfBullet;
}
//-----------------------------------------------------------------------
mapOfMeteor& Factory::getMapOfMeteor()
{
	static mapOfMeteor m_mapOfMeteor;
	return m_mapOfMeteor;
}
//-----------------------------------------------------------------------
gifts& Factory::getGifts()
{
	static gifts m_gifts;
	return m_gifts;
}
