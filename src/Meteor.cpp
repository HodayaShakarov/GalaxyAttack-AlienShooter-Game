#include "Meteor.h"
//--------------------------------------------------------------
Meteor::Meteor(sf::Vector2f position) : GameObject(position), m_leftToDie(2)
{
	m_sprite.setTexture(Resources::getInstance().getImage("Meteor"));
}
//--------------------------------------------------------------
void Meteor::move()
{
	m_direction.x = 0;
	m_direction.y = METEOR_SPEED;
	m_sprite.move(m_direction * (getDeltaTime2().asSeconds()));
}
//--------------------------------------------------------------
void Meteor::setLeftToDie()
{
	m_leftToDie--;
}
//--------------------------------------------------------------
int Meteor::getLeftToDie()
{
	return m_leftToDie;
}