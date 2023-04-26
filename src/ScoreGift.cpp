#include "ScoreGift.h"

ScoreGift::ScoreGift(sf::Vector2f position) : AbstractGift(position)
{
	m_sprite.setTexture(Resources::getInstance().getImage("ScoreGift"));
}
