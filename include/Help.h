#pragma once
#include "Button.h"
#include "Const.h"

class Help : public Button
{
public:
	Help(string str, sf::Vector2f location);
	~Help() = default;
	virtual bool handleClick(sf::RenderWindow& window) override;

protected:

};
