#include "GameObject.h"
#include <iostream>
GameObject::GameObject(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}
//-----------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//-----------------------------------------------------------------------------
sf::Time GameObject::getDeltaTime()
{
	return m_clock.getElapsedTime();
}
//-----------------------------------------------------------------------------
sf::Time GameObject::getDeltaTime2()
{
	auto deltaTime=m_clock.restart();
	return deltaTime;
}
//-----------------------------------------------------------------------------
sf::FloatRect GameObject::returnGetGlobalBouns()
{
	return m_sprite.getGlobalBounds();
}
