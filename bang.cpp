#include "bang.h"
#include "game.h"
std::string Explosion::explosion_anim_files[] = {
	"fire2.png",
	"fire1.png",
};

Explosion::Explosion(sf::Vector2f pos) {
	texture.loadFromFile(IMAGES_FOLDER + explosion_anim_files[0]);
	sprite.setTexture(texture);
	position = pos;
	sprite.setPosition(position);
}
void Explosion::update() {
	sf::Time now = clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		frame++;
		if (frame < 2) {
			clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + explosion_anim_files[frame]);
			sprite.setTexture(texture);
			sprite.setPosition(position);
		}
		else {
			del = true;
		}
	}
}
bool Explosion::getDel() { return del; }
void Explosion::draw(sf::RenderWindow& window) { window.draw(sprite); }