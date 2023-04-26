#pragma once
#include "GameObject.h"
#include "AbstractEnemySpaceShip.h"
#include "AbstractGift.h"
#include "AbstractBullet.h"
#include <vector>

class Meteor;

typedef std::map<std::string, std::unique_ptr<AbstractEnemySpaceShip>(*)(sf::Vector2f position)> mapOfEnemySpaceShip;
typedef std::map<std::string, std::unique_ptr<AbstractBullet>(*)(sf::Vector2f position, bool flag)> mapOfBullet;
typedef std::map<std::string, std::unique_ptr<Meteor>(*)(sf::Vector2f position)> mapOfMeteor;
typedef std::vector<std::unique_ptr<AbstractGift>(*)(sf::Vector2f position)> gifts;

class Factory
{
public:
	Factory() = default;
	~Factory() = default;
	static std::unique_ptr<AbstractEnemySpaceShip> createEnemySpaceShip(const std::string& name, sf::Vector2f position);
	static bool registeritEnemySpaceShip(const std::string& name, std::unique_ptr<AbstractEnemySpaceShip>(*)(sf::Vector2f position));
	static std::unique_ptr<AbstractBullet> createBullet(const std::string& name, sf::Vector2f position, bool flag);
	static bool registeritBullet(const std::string& name, std::unique_ptr<AbstractBullet>(*)(sf::Vector2f position, bool flag));
	static std::unique_ptr<Meteor> createMeteor(const std::string& name, sf::Vector2f position);
	static bool registeritMeteor(const std::string& name, std::unique_ptr<Meteor>(*)(sf::Vector2f position));
	static std::unique_ptr<AbstractGift> createGift(sf::Vector2f position);
	static bool registeritGift(std::unique_ptr<AbstractGift>(*)(sf::Vector2f position));
	
protected:
	static mapOfEnemySpaceShip& getMapOfEnemySpaceShip();
	
	static mapOfBullet& getMapOfBullet();
	
	static mapOfMeteor& getMapOfMeteor();

	static gifts& getGifts();
};

