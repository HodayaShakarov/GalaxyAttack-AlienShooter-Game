#include "DisplayData.h"

DisplayData::DisplayData()
{
	for (int i = 0; i < 3; i++)
		m_life.emplace_back(Resources::getInstance().getImage("Life"));

	m_level = sf::Text("Level: ", Resources::getInstance().m_font);
	setData(m_level, 30, { 1075,10 }, sf::Color::White);
}

void DisplayData::displayData(sf::RenderWindow& window, const int life, const int level, const int score)
{
	sf::Sprite sprite;
	sf::Vector2f startPosition = { 20,10 };
	sprite.setTexture(m_life[0]);
	for (int i = 0; i < life; i++)
	{
		sprite.setPosition(startPosition);
		startPosition.x += (sprite.getGlobalBounds().width);
		window.draw(sprite);
	}

	window.draw(m_level); //הדפסה של הטקסט
	auto text = sf::Text(std::to_string(level), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setData(text, 30, { 1075 + m_level.getGlobalBounds().width, 10 }, sf::Color::White);
	window.draw(text);

	text = sf::Text(std::to_string(score), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setData(text, 30, { 980,10 }, sf::Color::White);
	window.draw(text);
}

void DisplayData::setData(sf::Text& text, int size, sf::Vector2f position, sf::Color color)
{
	text.setCharacterSize(size); //משנה גודל
	text.setPosition(position); //משנה מקום
	text.setColor(color); //משנה צבע
}
