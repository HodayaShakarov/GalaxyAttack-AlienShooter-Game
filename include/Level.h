#pragma once
#include <fstream>
#include "Resources.h"
#include "Factory.h"
#include "Const.h"
#include "DisplayData.h"
#include "SmallEnemySpaceShip.h"
#include "BigEnemySpaceShip.h"
#include "AbstractEnemySpaceShip.h"
#include "Meteor.h"
#include "AbstractGift.h"
#include "SpaceShip.h"
#include "SmallEnemySpaceShip.h"
#include "BigEnemySpaceShip.h"
#include "CollisionHandling.h"
#include <iostream>
using std::cout;

class Level
{
public:
	Level();
	~Level() = default;
	void readFromFile(std::string levelFile);//������� ������ ����� �� �������
	bool run(sf::RenderWindow& window, SpaceShip& spaceShip,int level);//������� ����� ������ �� ����
	void CheckLevelEvents(sf::RenderWindow& window, SpaceShip& spaceShip);
	sf::Time getDeltaTime();
	void drawObject(sf::RenderWindow& window, SpaceShip& spaceShip);//����� ��������� ������� ���������� ��������� ��� ����� ����
	void updateBackgroundPosition();
	void move(sf::Time deltaTime, SpaceShip& spaceShip);//����� ��������� ������� ���������� ��������� ��� ����� ����
	void creatBulletOfEnemySpaceShip();//������� ������ �������� ������ ������� ���� ������ ����� ������ �� ������� ����
	void collisionBulletOfEnemySpaceShip_spaceShip(SpaceShip& spaceShip);
	void collisionMeteor_spaceShip(SpaceShip& spaceShip);
	void collisionBulletOfSpaceShip_enemySpaceShip(SpaceShip& spaceShip);
	void collisionBulletOfSpaceShip_meteor(SpaceShip& spaceShip);
	void collisionSpaceShip_gift(SpaceShip& spaceShip);
	bool creatMeteor();//����� �������
	void checkEvent(SpaceShip& spaceShip);//����� ����� ������ ����
	
protected:
	std::ifstream m_file;
	std::vector< std::unique_ptr<AbstractEnemySpaceShip>> m_vectorOfEnemySpaceShip;
	std::vector<std::unique_ptr<Meteor>> m_vectorOfMeteor;
	std::vector<std::unique_ptr<AbstractGift>> m_vectorOfGifts;
	sf::Sprite m_background1;
	sf::Sprite m_background2;
	DisplayData m_displayData;
	sf::Clock m_clock;
	bool m_events;
	bool m_meteor;
};

