#pragma once
#include"SpaceShip.h"
#include"Const.h"
#include"Factory.h"
#include"Level.h"
#include"StrongBullet.h"
class Game
{
public:
	Game();
	~Game() = default;
	void startGame(sf::RenderWindow& window);//�������� ������ �� ����� ���� ����� �� ������ 
	void printResult(sf::RenderWindow& window, std::string str, const sf::Vector2f& location, bool flag);//������ �� ����� �����
	void printNumOfLevel(sf::RenderWindow&, int);//����� ���� �� ���� ����
protected:
	SpaceShip m_spaceShip;
	sf::Sprite m_youWin;
	sf::Sprite m_gameOver;
	sf::Sprite m_numOfLevel;
	sf::Text m_numOfLevelInWord;
	sf::Text m_youWinInWord;
	sf::Text m_gameOverinInWord;
	sf::Text m_gameResult;

};

