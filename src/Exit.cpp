#include "Exit.h"

Exit::Exit(string str, sf::Vector2f location) : Button(str, location)
{
}

bool Exit::handleClick(sf::RenderWindow& window)
{
	window.close();
	exit(EXIT_SUCCESS);
	return false;
}
