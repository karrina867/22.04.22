#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"
class River {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed{ sf::Vector2f(RIVER_SPEED_X, RIVER_SPEED_Y) };
	int tim = 0;
public:
	River(float x, float y) {
		texture.loadFromFile(IMAGES_FOLDER + RIVER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setScale(RIVER_X, RIVER_Y);
		sprite.setPosition(x, y);
	}
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
	void decreaseTim(size_t);
	void increaseTim(size_t);
	int getTim();
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(0.f, -WINDOW_HEIGHT);
			tim=tim+10;
		}
	}
};
void River::increaseTim(size_t add_tim) { tim = add_tim++; }
int River::getTim() { return tim; }