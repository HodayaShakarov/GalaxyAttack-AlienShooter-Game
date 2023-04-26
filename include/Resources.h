#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
using std::string;

class Resources
{
public:
	~Resources() = default;
	static Resources& getInstance();
	sf::Texture& getImage(string str);
	void setSound(string sound);
	sf::Font m_font;
	sf::Music m_music;
	sf::Sound m_sound;

private:
	Resources();
	Resources(const Resources& other) = default;
	Resources& operator=(const Resources& other) = default;
	void insertImageToMap();

	std::map<string, sf::Texture> m_images; //map of images.
	sf::Texture m_image;
	std::map<std::string, sf::SoundBuffer> m_soundBuffer; //map of sounds.
};