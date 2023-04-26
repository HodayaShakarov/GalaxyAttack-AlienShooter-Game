#pragma once
#include "GameObject.h"

class AbstractBullet : public GameObject
{
public:
	AbstractBullet(sf::Vector2f position);
	~AbstractBullet() = default;
	virtual void move() = 0;
	void move(sf::Time deltaTime);//����� ������
	void calculateSpeed(sf::Vector2f& m_direction, int speed);//����� ������ �� ������
protected:
	sf::Vector2f m_direction; //����� �����
};

