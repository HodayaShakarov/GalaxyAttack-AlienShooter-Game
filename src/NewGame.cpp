#include "NewGame.h"

NewGame::NewGame(string str, sf::Vector2f location) : Button(str, location)
{
}

bool NewGame::handleClick(sf::RenderWindow& window)
{
	return true;
}

