#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <vector>

class DisplayData
{
public:
	DisplayData();
	~DisplayData() = default;
	void displayData(sf::RenderWindow& window, const int life, const int level, const int score);
	void setData(sf::Text& text, int size, sf::Vector2f position, sf::Color color);

protected:
	std::vector<sf::Texture> m_life;
	sf::Text m_level;
};