#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Resources.h"
using std::string;

class Button
{
public:
	Button(string str, sf::Vector2f location);
	~Button() = default;
	void drawOnWindow(sf::RenderWindow& window); //������� ������ �� ������ �� ����
	virtual bool handleClick(sf::RenderWindow& window) = 0; //������� ������ ������ ������ �� ����� �����
	sf::Sprite getSprite(); //������� ������� �� ������

protected:
	sf::Sprite m_sprite; //����� ����� �� �������
};

