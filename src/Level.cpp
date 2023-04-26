#include "Level.h"
//------------------------------------------------------------------
Level::Level() : m_background1(Resources::getInstance().getImage("Background")),
m_background2(Resources::getInstance().getImage("Background")), m_displayData(), m_clock(), m_events(false), m_meteor(false)
{
	m_background1.setPosition({ 0,0 });
	m_background2.setPosition({ 0,-HIGHT_OF_WINDOW });
	Resources::getInstance().m_music.play();
	Resources::getInstance().m_music.setVolume(40);
	Resources::getInstance().m_music.setLoop(true);
}
//------------------------------------------------------------------
void Level::readFromFile(std::string levelFile)
{
	int x, y, row, col;
	m_file.tellg();
	m_file.open(levelFile);
	if (!m_file.is_open())
		throw std::runtime_error("file not open");
	m_file >> row;
	m_file >> col;
	std::string line;
	sf::Vector2f position;
	std::getline(m_file, line);
	for (int i = 0; i < row; ++i)
	{

		std::getline(m_file, line);
		for (int j = 0; j < line.size(); ++j)
		{
			switch (line[j])
			{
			case BIG_ENEMY_SPACESHIP:
				position.x = X_BIG_ENEMY_SPACESHIP;
				position.y = Y_BIG_ENEMY_SPACESHIP + 50;
				m_vectorOfEnemySpaceShip.emplace_back(Factory::createEnemySpaceShip("BigEnemySpaceShip", position));
				break;
			case SMALL_ENEMY_SPACESHIP:
				position.x = j * SMALL_ENEMY_SPACESHIP_SIZE;
				position.y = i * SMALL_ENEMY_SPACESHIP_SIZE + 50;
				m_vectorOfEnemySpaceShip.emplace_back(Factory::createEnemySpaceShip("SmallEnemySpaceShip", position));
				break;
			case METEOR:
				m_meteor = true;
				break;
			}
		}
	}
	m_file.seekg(0);
}
//------------------------------------------------------------------
bool Level::run(sf::RenderWindow& window, SpaceShip& spaceShip, int level)
{
	spaceShip.unProtected();
	spaceShip.setTexture();
	while (true)
	{
		window.clear();
		drawObject(window, spaceShip);
		m_displayData.displayData(window, spaceShip.getLife(), level, spaceShip.getScore());
		move(getDeltaTime(), spaceShip);
		CheckLevelEvents(window, spaceShip);
		creatBulletOfEnemySpaceShip();//פונקציה שקוראת לפונקציה שנמצאת בחלליות אויב ויוצרת יריות במחלקה של החלליות אויב
		checkEvent(spaceShip);
		if (m_meteor)//בדיקה האם השלב הסתיים בהצלחה
		{
			if (creatMeteor())//יצירת מטאורים
				return true;
		}
		if (!m_meteor)
		{
			if (m_vectorOfEnemySpaceShip.size() == 0)//בדיקה האם השלב הסתיים בהצלחה
				return true;
		}
		if (spaceShip.getLife() == 0)//בדיקה האם השלב הסתיים בכישלון
			return false;
		window.display();
	}
}
//------------------------------------------------------------------

void Level::CheckLevelEvents(sf::RenderWindow& window, SpaceShip& spaceShip)
{
	auto event = sf::Event{};
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(EXIT_SUCCESS);
			break;
		case sf::Event::KeyPressed:
		{
			spaceShip.handleEvent(event.key.code);
			m_events = true;
			spaceShip.move(getDeltaTime());
			break;
		}
		default:
			break;
		}
	}
}
//------------------------------------------------------------------
sf::Time Level::getDeltaTime()
{
	auto deltaTime = m_clock.restart();
	return deltaTime;
}
//-------------------------------------------------------------------------
void Level::creatBulletOfEnemySpaceShip()
{
	int num;
	for (const auto& enemySpaceShip : m_vectorOfEnemySpaceShip)
	{
		if (m_vectorOfEnemySpaceShip.size() == 1)
			num = rand() % 600;
		else
			num = rand() % 10000;

		if (num == 1)
			enemySpaceShip->creatBullet();
	}
}
//-------------------------------------------------------------------------
bool Level::creatMeteor()
{
	static int amountOfMeteor = 0;
	if (amountOfMeteor == 100)
		return true;
	sf::Vector2f position;
	position.y = -10;
	position.x = rand() % 1200;
	int num = rand() % 300;
	if (num == 70)
	{
		m_vectorOfMeteor.emplace_back(Factory::createMeteor("Meteor", position));
		amountOfMeteor++;
	}
	return false;
}
//-------------------------------------------------------------------------
void Level::checkEvent(SpaceShip& spaceShip)
{
	if (!spaceShip.getProtected())
	{
		collisionBulletOfEnemySpaceShip_spaceShip(spaceShip);//התנגשות בין ירייה של חללית אויב לבין שחקן
	}
	spaceShip.setProtected(spaceShip.getProtected());
	if (m_events == true)
		collisionBulletOfSpaceShip_enemySpaceShip(spaceShip);//התנגשות בין ירייה של שחקן לבין חללית אויב
	collisionMeteor_spaceShip(spaceShip);//התנגשות בין מטאור לבין שחקן
	collisionBulletOfSpaceShip_meteor(spaceShip);//התנגשות בין ירייה של שחקן לבין מטאור
	collisionSpaceShip_gift(spaceShip);
}
//-------------------------------------------------------------------------
void Level::drawObject(sf::RenderWindow& window, SpaceShip& spaceShip)
{
	updateBackgroundPosition(); //הצגת הרקע
	window.draw(m_background1);
	window.draw(m_background2);

	spaceShip.drawBullet(window); //הצגת יריות של השחקן
	spaceShip.draw(window); //הצגת חללית השחקן

	for (const auto& gift : m_vectorOfGifts) //הצגת המתנות
		gift->draw(window);

	for (const auto& enemySpaceShip : m_vectorOfEnemySpaceShip) //הצגת היריות של חלליות האויב
		enemySpaceShip->drawBullet(window);

	for (const auto& enemySpaceShip : m_vectorOfEnemySpaceShip) //מציג את חלליות האויב
		enemySpaceShip->draw(window);

	for (const auto& Meteor : m_vectorOfMeteor) //הצגת המטאורים
		Meteor->draw(window);
}
//-------------------------------------------------------------------------
void Level::updateBackgroundPosition()
{
	sf::Vector2f startingPosition = { 0,-HIGHT_OF_WINDOW };
	if (m_background1.getPosition().y >= HIGHT_OF_WINDOW)
		m_background1.setPosition(startingPosition);
	if (m_background2.getPosition().y >= HIGHT_OF_WINDOW)
		m_background2.setPosition(startingPosition);
}
//-------------------------------------------------------------------------
void Level::move(sf::Time deltaTime, SpaceShip& spaceShip)
{
	m_background1.move({ 0, 100 * deltaTime.asSeconds() }); //הוזזת רקע
	m_background2.move({ 0, 100 * deltaTime.asSeconds() }); //הוזזת רקע

	spaceShip.move(deltaTime); //תזוזה של השחקן
	spaceShip.moveBullet(deltaTime); //תזוזת היריות של השחקן

	for (const auto& enemySpaceShip : m_vectorOfEnemySpaceShip) //מוזיז את היריות של החלליות אויב
		enemySpaceShip->moveOfBullet();

	for (const auto& enemySpaceShip : m_vectorOfEnemySpaceShip)//הוזזה של החלליות אויב
		enemySpaceShip->move();

	for (const auto& Meteor : m_vectorOfMeteor) //הוזזה של המטאורים
		Meteor->move();

	for (const auto& gift : m_vectorOfGifts) //הוזזה של המתנות
		gift->move();
}
//-------------------------------------------------------------------------
void Level::collisionBulletOfEnemySpaceShip_spaceShip(SpaceShip& spaceShip)//התנגשות בין ירייה של חללית אויב לבין השחקן
{
	for (const auto& enemySpaceShip : m_vectorOfEnemySpaceShip)
	{
		for (int j = 0; j < enemySpaceShip->returnSizeOfBullets(); j++)
		{
			if ((enemySpaceShip->returnGetGlobalBounsOfBullet(j)).intersects(spaceShip.returnGetGlobalBouns()))
			{
				enemySpaceShip->deleteBullet(j);
				j--;
				spaceShip.setLife(-1);
				break;
			}

		}
	}

}
//-------------------------------------------------------------------------
void Level::collisionMeteor_spaceShip(SpaceShip& spaceShip)//התנגשות בין מטאור לשחקן
{
	for (int i = 0; i < m_vectorOfMeteor.size(); i++)
	{
		if ((m_vectorOfMeteor[i]->returnGetGlobalBouns()).intersects(spaceShip.returnGetGlobalBouns()))
		{
			m_vectorOfMeteor.erase(m_vectorOfMeteor.begin() + i);
			i--;
			spaceShip.setLife(-1);
		}
	}

}
//-------------------------------------------------------------------------
void Level::collisionBulletOfSpaceShip_enemySpaceShip(SpaceShip& spaceShip)//התנגשות בין ירייה של השחקן לבין חללית אויב
{
	for (int i = 0; i < m_vectorOfEnemySpaceShip.size(); i++)
	{
		for (int j = 0; j < spaceShip.returnSizeOfBullets(); j++)
		{
			if ((m_vectorOfEnemySpaceShip[i]->returnGetGlobalBouns()).intersects(spaceShip.returnGetGlobalBounsOfBullet(j)))
			{
				Resources::getInstance().setSound("Shoot");
				int num = rand() % 4;
				if (num == 1)
					m_vectorOfGifts.emplace_back(Factory::createGift(m_vectorOfEnemySpaceShip[i]->getImagePosition()));
				spaceShip.addScore();
				m_vectorOfEnemySpaceShip[i]->setLeftToDie();
				if (m_vectorOfEnemySpaceShip[i]->getLeftToDie() == 0)
				{
					m_vectorOfEnemySpaceShip.erase(m_vectorOfEnemySpaceShip.begin() + i);
					i--;
				}
				spaceShip.deletBullet(j);
				j--;
				break;
			}
		}
	}
}
//-------------------------------------------------------------------------
void Level::collisionBulletOfSpaceShip_meteor(SpaceShip& spaceShip)//התנגשות בין ירייה של שחקן לבין מטאור
{
	for (int i = 0; i < m_vectorOfMeteor.size(); i++)
	{
		for (int j = 0; j < spaceShip.returnSizeOfBullets(); j++)
		{
			if ((m_vectorOfMeteor[i]->returnGetGlobalBouns()).intersects(spaceShip.returnGetGlobalBounsOfBullet(j)))
			{
				Resources::getInstance().setSound("Shoot");
				m_vectorOfMeteor[i]->setLeftToDie();
				if (m_vectorOfMeteor[i]->getLeftToDie() == 0)
				{
					spaceShip.addScore();
					m_vectorOfMeteor.erase(m_vectorOfMeteor.begin() + i);
					i--;
				}
				spaceShip.deletBullet(j);
				j--;
				break;
			}
		}
	}
}
//-------------------------------------------------------------------------
void Level::collisionSpaceShip_gift(SpaceShip& spaceShip)
{
	for (int i = 0; i < m_vectorOfGifts.size(); i++)
	{
		if (spaceShip.returnGetGlobalBouns().intersects(m_vectorOfGifts[i]->returnGetGlobalBouns()))
		{
			processCollision(spaceShip, *m_vectorOfGifts[i]);
			m_vectorOfGifts.erase(m_vectorOfGifts.begin() + i);
			i--;
		}
	}
}
