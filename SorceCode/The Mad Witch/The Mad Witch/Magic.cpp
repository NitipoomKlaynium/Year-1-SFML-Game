#include "Magic.hpp"

Magic::Magic() {
	Age = 24;
	Damage = 20;

	texture.loadFromFile("character/magic.png");
	sprite.setTexture(texture);
	sprite.setOrigin(24, 24);
	sprite.setTextureRect(IntRect(0, 0, 48, 48));

	HitBlock.setSize(Vector2f(24, 24));
	HitBlock.setOrigin(12, 12);
}

Magic::~Magic() {

}

void Magic::Move() {
	sprite.setPosition(HitBlock.getPosition());
}

void Magic::Move(float x, float y) {
	HitBlock.move(x, y);
	Move();
}

void Magic::Update() {
	if (Face == 0) {
		Move(0, 16);
	}
	if (Face == 1) {
		Move(-16, 0);
	}
	if (Face == 2) {
		Move(16, 0);
	}
	if (Face == 3) {
		Move(0, -16);
	}
	if (Age > 0) Age--;
}
