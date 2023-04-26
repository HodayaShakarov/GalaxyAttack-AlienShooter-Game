#include "Button.h"

Button::Button(std::string str, sf::Vector2f location) : m_sprite(Resources::getInstance().getImage(str))
{
	m_sprite.setPosition(location);
}

void Button::drawOnWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::Sprite Button::getSprite()
{
	return m_sprite;
}
