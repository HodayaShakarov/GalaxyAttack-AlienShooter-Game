#pragma once
#include "AbstractBullet.h"
#include "Factory.h"
class DirectBullet : public AbstractBullet
{
public:
	DirectBullet(sf::Vector2f position, bool flag);
	~DirectBullet() = default;
	void move();
	void setTexture();

protected:
	static bool m_registerit;
	bool m_type;
};

inline bool DirectBullet::m_registerit = Factory::registeritBullet("DirectBullet",
	[](sf::Vector2f position, bool flag) -> std::unique_ptr<AbstractBullet> { return std::make_unique<DirectBullet>(position, flag); });
