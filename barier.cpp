#include "barier.h"
#include"const.h"
std::string Barier::barier_file_names[] = {
//"meteorGrey_small2.png",
	"meteorGrey_tiny2.png" ,
	//"rw.png",
	"meteorGrey_tiny1.png",
	//"op.png",
	//"rf.png",
	//"rt.png",
	"tile_66.png",
	"tile_67.png",
	"ship (11).png",
	"hullLarge (1).png",
	"hullLarge (2).png",
	"ship (2).png",
};
Barier::Barier() {
	size_t num = rand() % BARIER_TYPE;
	texture.loadFromFile(IMAGES_FOLDER + barier_file_names[num]);
	sprite.setTexture(texture);
	spawn();
}
void Barier::update() {
	sprite.move(speedx, speedy);
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	if (sprite.getPosition().x < 0 - g_bound.width ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT)
	{
		spawn();
	}
}
void Barier::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Barier::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
		float x = rand() % (static_cast<size_t>(WINDOW_WIDTH) -
		static_cast<size_t>(g_bound.width));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT;
	sprite.setPosition(x, y);
	speedx = 0;
	speedy = 6;
}
sf::FloatRect Barier::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Barier::getPosition() { return sprite.getPosition(); }