#include "Entity.hpp"

Entity::Entity() {

	Entity::MaxHealth = 100;
	Entity::Health = 100;
	Entity::MaxMana = 80;
	Entity::Mana = 80;
	Entity::MovementSpeed = 5;
	Entity::Attack = 10;

	HitBlock.setSize(Vector2f(48, 48));
	Top.setSize(Vector2f(24, 1));
	Left.setSize(Vector2f(1, 24));
	Right.setSize(Vector2f(1, 24));
	Buttom.setSize(Vector2f(24, 1));

	HitBlock.setOrigin(24, 24);
	Top.setOrigin(12, 0);
	Left.setOrigin(0, 12);
	Right.setOrigin(0, 12);
	Buttom.setOrigin(12, 0);

	HealthBar.setSize(Vector2f(48, 6));
	HealthBar.setFillColor(Color(0, 0, 0, 0));
	HealthBar.setOutlineThickness(2);
	HealthBar.setOutlineColor(Color::White);

	HealthBarHealth.setSize(Vector2f(48, 6));
	HealthBarHealth.setFillColor(Color::Green);

	Move();
}

Entity::~Entity() {

}

void Entity::Load(string file) {
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 48, 48));
	sprite.setOrigin(24, 24);
}

void Entity::Move() {
	HitBlock.setPosition(sprite.getPosition());
	Top.setPosition(sprite.getPosition().x, sprite.getPosition().y - 24);
	Left.setPosition(sprite.getPosition().x - 24, sprite.getPosition().y);
	Right.setPosition(sprite.getPosition().x + 24, sprite.getPosition().y);
	Buttom.setPosition(sprite.getPosition().x, sprite.getPosition().y + 24);

	HealthBar.setPosition(HitBlock.getPosition().x - 24 , HitBlock.getPosition().y - 36);
	HealthBarHealth.setPosition(HitBlock.getPosition().x - 24, HitBlock.getPosition().y - 36);
}

void Entity::Move(float x, float y) {
	sprite.move(x, y);
	Move();
}

void Entity::Move(Vector2f S) {
	Move(S.x, S.y);
}

void Entity::Walk(float x, float y) {
	Move(x, y);
	if (y > 0) Face = 0;
	if (y < 0) Face = 3;
	if (x > 0) Face = 2;
	if (x < 0) Face = 1;
	AnimationFrame += (abs(x) + abs(y)) / 50;
}

void Entity::Walk(Vector2f S) {
	Walk(S.x, S.y);
}

void Entity::SetPosition(float x, float y) {
	sprite.setPosition(x, y);
	Move();
}

void Entity::SetPosition(Vector2f Pos) {
	SetPosition(Pos.x, Pos.y);
}

void Entity::Update() {
	if (AnimationFrame >= 3) AnimationFrame = 0;
	sprite.setTextureRect(IntRect(int(AnimationFrame) * 48, Face * 48, 48, 48));

	if (Health > MaxHealth) Health = MaxHealth;
	if (Mana > MaxMana) Mana = MaxMana;

	HealthBarHealth.setSize(Vector2f((Health / MaxHealth) * 48, 8));

	if (abs(Motion.x) > 0) {
		Motion.x *= 0.25;
	}
	if (abs(Motion.y) > 0) {
		Motion.y *= 0.25;
	}

	if (abs(Motion.x) < 0.25) {
		Motion.x = 0;
	}
	if (abs(Motion.y) < 0.25) {
		Motion.y = 0;
	}

	Entity::Move(Motion);
}

void Entity::Render(RenderTarget& target) {
	target.draw(sprite);
	target.draw(HealthBarHealth);
	target.draw(HealthBar);
}

void Entity::RenderHitBlock(RenderTarget& target) {
	target.draw(Top);
	target.draw(Left);
	target.draw(Right);
	target.draw(Buttom);
}
