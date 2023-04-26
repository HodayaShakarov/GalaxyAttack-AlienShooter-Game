#pragma once
#include "GameObject.h"
#include "Factory.h"
#include <vector>
using std::vector;

class SpaceShip : public GameObject
{
public:
	SpaceShip(sf::Vector2f position);
	~SpaceShip() = default;
	void handleEvent(sf::Keyboard::Key key);
	void calculateSpeed(sf::Vector2f& m_direction, int speed);
	void move(sf::Time deltaTime);
	void drawBullet(sf::RenderWindow& window);
	void moveBullet(sf::Time deltaTime);
	bool isOutOfLimits(const sf::Vector2f& destination);
	sf::Vector2f getPosition();
	sf::FloatRect returnGetGlobalBounsOfBullet(int);
	std::unique_ptr<AbstractBullet> returnBullet(int);
	int returnSizeOfBullets();
	void deletBullet(int);
	void setProtected(bool protect);
	void setLife(int num);
	int getLife();
	bool getProtected();
	void setTexture();
	void unProtected();
	void addScore();
	int getScore();

protected:
	vector<std::unique_ptr<AbstractBullet>> m_bullets;
	int m_life;
	int m_score;
	bool m_isProtected;
	sf::Clock m_ProtectionClock;
};

