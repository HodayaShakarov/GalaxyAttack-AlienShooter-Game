#pragma once
#include "Button.h"

class Exit : public Button
{
public:
	Exit(string str, sf::Vector2f location);
	~Exit() = default;
	virtual bool handleClick(sf::RenderWindow& window) override;

protected:

};

