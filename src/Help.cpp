#include "Help.h"

Help::Help(string str, sf::Vector2f location) : Button(str, location)
{
}

bool Help::handleClick(sf::RenderWindow& window)
{
	sf::RenderWindow helpWindow(sf::VideoMode(WIDTH_OF_WINDOW, HIGHT_OF_WINDOW), "Help"); //����� ���� ����� �����
	sf::Sprite sprite;
	sprite.setTexture(Resources::getInstance().getImage("HelpScreen"));

	while (helpWindow.isOpen()) //�� ��� ����� ���� ���� ������
	{
		helpWindow.clear();
		helpWindow.draw(sprite);
		helpWindow.display();
		if (auto event = sf::Event{}; helpWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				helpWindow.close();
				break;
			}
			default:
				break;
			}
		}
	}
	return false;
}
