#pragma once
const int SIZE_OF_VECTOR = 4;
const int SMALL_ENEMY_SPACESHIP_SIZE = 100;
const int X_BIG_ENEMY_SPACESHIP = 500;
const int Y_BIG_ENEMY_SPACESHIP = 10;
const auto SMALL_ENEMY_SPACESHIP = 's';
const int NUMBER_OF_LEVELS = 3;
//const auto MEDUM_ENEMY_SPACESHIP = 'm';
const auto BIG_ENEMY_SPACESHIP = 'b';
const auto SPACE = ' ';
const auto METEOR = 'm';
const int SIZE_OF_ENEMY_SPACESHIP = 2;
const int X = 500;
const int Y = 600;
const auto WIDTH_OF_WINDOW = 1200;
const auto HIGHT_OF_WINDOW = 800;
const auto SPACE_SHIP_SPEED = 300;
const auto DIRECT_BULLET_SPEED = 200;
const auto METEOR_SPEED = 200;
const auto DIRECT_BULLET_OF_SPACESHIP_SPEED = 20;
const auto BIG_ENEMY_SPACESHIP_SPEED = 500;
const auto STRONG_BULLET_SPEED = 300;
const auto NUMBER = 25;
const auto PROTECTION_TIME = 30;
const auto GIFT_SPEED = 100;
const int TIME = 2000;
const sf::Vector2f WIN_POSITION = {400, 330};
const sf::Vector2f LOSE_POSITION = { 300, 330 };
const auto ADD_SCORE = 100;

enum Directions
{
	left,
	right,
	up,
	down,
	Default
};