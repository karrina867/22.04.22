#pragma once
#include "SFML/Graphics.hpp"
class Barier {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string barier_file_names[];
	float speedx, speedy;
public:
	Barier();
	void update();
	void draw(sf::RenderWindow&);
	void spawn();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
};