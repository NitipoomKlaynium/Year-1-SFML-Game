#include "Player.hpp"

Player::Player() {
	MaxHealth = 100;
	Health = 100;
	MaxMana = 80;
	Mana = 80;
	MovementSpeed = 6;
	Entity::Load("character/player.png");
}

Player::~Player() {

}

void Player::Reset() {
	Entity::MaxHealth = 100;
	Entity::Health = 100;
	Entity::MaxMana = 80;
	Entity::Mana = 80;
}

void Player::Update() {
	Entity::Update();
}

void Player::Render(RenderTarget& target) {
	Entity::Render(target);
	//Entity::RenderHitBlock(target);
}
