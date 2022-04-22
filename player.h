#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"
class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int hp = PLAYER_HP;
	bool del = false;
public:
	Player();
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void setDel(bool);
	bool getDel();
	void decreaseHp(size_t);
	void increaseHp(size_t);
	int getHp();
};