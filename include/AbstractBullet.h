#pragma once
#include "GameObject.h"

class AbstractBullet : public GameObject
{
public:
	AbstractBullet(sf::Vector2f position);
	~AbstractBullet() = default;
	virtual void move() = 0;
	void move(sf::Time deltaTime);//הוזזת היריות
	void calculateSpeed(sf::Vector2f& m_direction, int speed);//מחשבת מהירות של התזוזה
protected:
	sf::Vector2f m_direction; //כיוון נוכחי
};

