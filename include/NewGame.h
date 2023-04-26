#pragma once
#include "Button.h"

class NewGame : public Button
{
public:
	NewGame(string str, sf::Vector2f location);
	~NewGame() = default;
	virtual bool handleClick(sf::RenderWindow& window) override;

protected:

};
