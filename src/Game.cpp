#include"Game.h"
//------------------------------------------------------------
Game::Game() :m_spaceShip({ X,Y }), m_gameOver(Resources::getInstance().getImage("Background")),
	m_youWin(Resources::getInstance().getImage("Background")),
	m_numOfLevel(Resources::getInstance().getImage("Background"))
{
}
//------------------------------------------------------------
void Game::startGame(sf::RenderWindow& window)
{
	int i = 1; //משתנה שמציין את מספר השלב
	std::string nameFile; bool flag;
	while (true)
	{
		Level level;
		while (true)
		{
			window.clear();
			window.draw(m_numOfLevel);
			printNumOfLevel(window, i);
			window.display();
			_sleep(TIME);
			break;
		}
		nameFile = std::string("level") + std::to_string(i) + std::string(".txt");
		level.readFromFile(nameFile);
		flag = level.run(window, m_spaceShip,i);
		if (!flag)
		{
			while (true)
			{
				window.clear();
				window.draw(m_gameOver);
				printResult(window, "GAME OVER", LOSE_POSITION, false);
				window.display();
				_sleep(TIME);
				break;
			}
			break;
		}
		else
		{
			if (i == NUMBER_OF_LEVELS)
			{
				while (true)
				{
					window.clear();
					window.draw(m_youWin);
					printResult(window, "WINNER", WIN_POSITION, true);
					window.display();
					_sleep(TIME);
					break;
				}
				break;
			}
			else
				++i;
		}
	}
	return;
}
//------------------------------------------------------------
void Game::printResult(sf::RenderWindow& window, std::string str, const sf::Vector2f& location, bool flag)
{
	Resources::getInstance().m_music.stop();
	if (flag)
		Resources::getInstance().setSound("WinnerMusic");
	else
		Resources::getInstance().setSound("GameOverMusic");
	m_gameResult = sf::Text(str, Resources::getInstance().m_font);
	m_gameResult.setPosition(location);
	m_gameResult.setCharacterSize(100);
	m_gameResult.setColor(sf::Color::White);
	window.draw(m_gameResult);
}
//------------------------------------------------------------
void Game::printNumOfLevel(sf::RenderWindow& window, int numOfLevel)
{
	std::string numLevel;
	numLevel = std::string("LEVEL ") + std::to_string(numOfLevel);
	m_numOfLevelInWord = sf::Text(numLevel, Resources::getInstance().m_font);
	m_numOfLevelInWord.setPosition(470, 350);
	m_numOfLevelInWord.setCharacterSize(70);
	m_numOfLevelInWord.setColor(sf::Color::White);
	window.draw(m_numOfLevelInWord);
}
