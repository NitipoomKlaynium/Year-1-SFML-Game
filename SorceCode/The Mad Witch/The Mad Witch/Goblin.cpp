#include "Goblin.hpp"

Goblin::Goblin() {
	MaxHealth = 50;
	Health = 50;
	MaxMana = 0;
	Mana = 0;
	MovementSpeed = 3;
	Entity::Load("character/goblin.png");
}

Goblin::~Goblin() {

}

void Goblin::Update() {
	Entity::Update();
}

void Goblin::MeleeAttaack(Entity& entity) {
	if (this->Top.getGlobalBounds().intersects(entity.HitBlock.getGlobalBounds())) {
		entity.Motion.y = -24;
		entity.Health -= this->Attack;
	}
	if (this->Left.getGlobalBounds().intersects(entity.HitBlock.getGlobalBounds())) {
		entity.Motion.x = -24;
		entity.Health -= this->Attack;
	}
	if (this->Right.getGlobalBounds().intersects(entity.HitBlock.getGlobalBounds())) {
		entity.Motion.x = 24;
		entity.Health -= this->Attack;
	}
	if (this->Buttom.getGlobalBounds().intersects(entity.HitBlock.getGlobalBounds())) {
		entity.Motion.y = 24;
		entity.Health -= this->Attack;
	}
}
