#pragma once
#include "GameObject.h"
#include "AbstractBullet.h"

class AbstractEnemySpaceShip : public GameObject
{
public:
	AbstractEnemySpaceShip(sf::Vector2f position);
    ~AbstractEnemySpaceShip() = default;
	void moveOfBullet();//קוראת לפונקצית מוב של היריות
	virtual void creatBullet() = 0;//יוצרת יריות
	virtual void move() = 0;//תזוזה של החלליות אויב
	void drawBullet(sf::RenderWindow& window) const;//עוברת על הוקטור של החלליות  אויב ומציגה את היריות של כל חללית אויב
    void setDirection(int);
    sf::FloatRect returnGetGlobalBounsOfBullet(int index);//מחזירה מלבן חוסם של האובייקט
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

