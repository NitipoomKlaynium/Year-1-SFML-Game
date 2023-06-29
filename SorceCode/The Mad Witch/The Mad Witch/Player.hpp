#ifndef PLAYER_HPP
#define PALYER_HPP

#include "Entity.hpp"

class Player : public Entity {
	public :
		Player();
		~Player();

	public :

	public :

		void Reset();

		void Update();

		void Render(RenderTarget& target);

};


#endif
