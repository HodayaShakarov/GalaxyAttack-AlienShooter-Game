#include "Resources.h"
//--------------------------------------------------------------------
Resources& Resources::getInstance()
{
	static Resources m_instance;
	return m_instance;
}
//---------------------------------------------------------------------
sf::Texture& Resources::getImage(string str)
{
	return m_images.find(str)->second;
}
//----------------------------------------------------------------------
void Resources::setSound(string sound)
{
	m_sound.setBuffer(m_soundBuffer[sound]);
	m_sound.play();
}
//----------------------------------------------------------------------
Resources::Resources()
{
	insertImageToMap();
}
//-----------------------------------------------------------------------
void Resources::insertImageToMap()
{
	if (!m_image.loadFromFile("Background.jpg"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("Background", m_image));

	if (!m_image.loadFromFile("BigEnemySpaceShip.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("BigEnemySpaceShip", m_image));

	if (!m_image.loadFromFile("Bullet.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("Bullet", m_image));

	if (!m_image.loadFromFile("BulletProofGift.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("BulletProofGift", m_image));

	if (!m_image.loadFromFile("DirectBullet.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("DirectBullet", m_image));

	if (!m_image.loadFromFile("ExitGame.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("ExitGame", m_image));

	if (!m_image.loadFromFile("gameOver.jpg"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("gameOver", m_image));

	if (!m_image.loadFromFile("Help.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("Help", m_image));

	if (!m_image.loadFromFile("HelpScreen.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("HelpScreen", m_image));

	if (!m_image.loadFromFile("Life.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("Life", m_image));

	if (!m_image.loadFromFile("LifeGift.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("LifeGift", m_image));

	if (!m_image.loadFromFile("MenuScreen.jpg"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("MenuScreen", m_image));

	if (!m_image.loadFromFile("Meteor.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("Meteor", m_image));

	if (!m_image.loadFromFile("NewGame.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("NewGame", m_image));

	if (!m_image.loadFromFile("ProtectedSpaceShip.PNG"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("ProtectedSpaceShip", m_image));

	if (!m_image.loadFromFile("ScoreGift.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("ScoreGift", m_image));

	if (!m_image.loadFromFile("SmallEnemySpaceShip.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("SmallEnemySpaceShip", m_image));

	if (!m_image.loadFromFile("SpaceShip.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("SpaceShip", m_image));

	if (!m_image.loadFromFile("StrongBulllet.png"))
		throw std::runtime_error("load From File no success");
	m_images.insert(std::make_pair("StrongBulllet", m_image));

	if (!m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
		throw std::runtime_error("load From File no success");

	m_music.openFromFile("Galaxy Attack_ Space Shooter OST.flac");

	m_soundBuffer["WinnerMusic"] = sf::SoundBuffer();
	m_soundBuffer["WinnerMusic"].loadFromFile("WinnerMusic.wav");

	m_soundBuffer["GameOverMusic"] = sf::SoundBuffer();
	m_soundBuffer["GameOverMusic"].loadFromFile("GameOverMusic.wav");

	m_soundBuffer["Shoot"] = sf::SoundBuffer();
	m_soundBuffer["Shoot"].loadFromFile("Shoot.wav");
}
