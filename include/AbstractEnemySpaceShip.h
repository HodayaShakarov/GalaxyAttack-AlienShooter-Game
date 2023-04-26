#pragma once
#include "GameObject.h"
#include "AbstractBullet.h"

class AbstractEnemySpaceShip : public GameObject
{
public:
	AbstractEnemySpaceShip(sf::Vector2f position);
    ~AbstractEnemySpaceShip() = default;
	void moveOfBullet();//����� �������� ��� �� ������
	virtual void creatBullet() = 0;//����� �����
	virtual void move() = 0;//����� �� ������� ����
	void drawBullet(sf::RenderWindow& window) const;//����� �� ������ �� �������  ���� ������ �� ������ �� �� ����� ����
    void setDirection(int);
    sf::FloatRect returnGetGlobalBounsOfBullet(int index);//������ ���� ���� �� ��������
	std::unique_ptr<AbstractBullet> returnBullet(int index);
	int returnSizeOfBullets();
	sf::Vector2f getImagePosition();
	void deleteBullet(int);
	void setLeftToDie();
	int getLeftToDie();
protected:
	std::vector<std::unique_ptr<AbstractBullet>> m_vectorOfBullet;
	int m_leftToDie;
	int m_leftForGift;
};

