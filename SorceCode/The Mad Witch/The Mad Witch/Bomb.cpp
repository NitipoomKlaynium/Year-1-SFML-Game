#include "Bomb.hpp"

Bomb::Bomb() {
	texture.loadFromFile("particle/bomb.png");
	for (int i = 0; i < 3; i++) {
		bombSprite[i].sprite.setTexture(texture);
		bombSprite[i].sprite.setTextureRect(IntRect(0, 0, 48, 48));
		bombSprite[i].AnimationFrame = 7;
	}
}

Bomb::~Bomb() {

}

void Bomb::Generate(float x, float y) {
	bombSprite[Counter].sprite.setPosition(x, y);
	bombSprite[Counter].AnimationFrame = 0;
	Counter++;
}

void Bomb::Generate(Vector2f Pos) {
	bombSprite[Counter].sprite.setPosition(Pos.x, Pos.y);
	bombSprite[Counter].AnimationFrame = 0;
	Counter++;
}

void Bomb::Update() {
	for (int i = 0; i < 3; i++) {
		if (bombSprite[i].AnimationFrame < 7) {
			bombSprite[i].AnimationFrame += 0.25;
		}
		bombSprite[i].sprite.setTextureRect(IntRect(0, int(bombSprite[i].AnimationFrame) * 48, 48, 48));
	}
}

void Bomb::Render(RenderTarget& target) {
	for (int i = 0; i < 3; i++) {
		target.draw(bombSprite[i].sprite);
	}
}

