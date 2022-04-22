#pragma once
#include "SFML/Graphics.hpp"
class Islands {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string islands_file_names[];
	float speedx, speedy;

public:
	Islands();
	void update();
	void draw(sf::RenderWindow&);
	void spawn();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
};
