#include "Menu.h"

//----------------------------------------------------------------------------------------
Menu::Menu() : m_sprite(Resources::getInstance().getImage("MenuScreen"))
{
	m_buttons.emplace_back(std::make_unique<NewGame>("NewGame", sf::Vector2f(500, 520)));
	m_buttons.emplace_back(std::make_unique<Help>("Help", sf::Vector2f(500, 600)));
	m_buttons.emplace_back(std::make_unique<Exit>("ExitGame", sf::Vector2f(500, 680)));
}
//----------------------------------------------------------------------------------------
bool Menu::CheckMenuEvents(sf::RenderWindow& window)
{
	while (window.isOpen()) //כל עוד החלון פתוח נכנס ללולאה
	{
		window.clear();
		drawMenuWindow(window);
		window.display();
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				exit(EXIT_SUCCESS);
				break;

			case sf::Event::MouseButtonReleased:
			{
				for (const auto& button : m_buttons)
				{
					if (isContain(event.mouseButton, window, *button)) //אם הלחיצה הייתה על אחד הכפתורים
					{
						if(button->handleClick(window))
							return true;
					}
				}
			}
			default:
				break;
			}
		}
	}
	return false;
}
//----------------------------------------------------------------------------------------
void Menu::drawMenuWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite); //ציור הרקע
	for (const auto& button : m_buttons) //ציור הכפתורים על התמונה
		button->drawOnWindow(window);
}
//----------------------------------------------------------------------------------------
bool Menu::isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window, Button& button)
{
	if (button.getSprite().getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
		return true;
	return false;
}
