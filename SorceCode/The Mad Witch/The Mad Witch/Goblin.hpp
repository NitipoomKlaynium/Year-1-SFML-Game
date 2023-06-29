#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Entity.hpp"

class Goblin : public Entity {
	public :
		Goblin();
		~Goblin();

	public :

		void Update();

		void MeleeAttaack(Entity& entity);
};

#endif