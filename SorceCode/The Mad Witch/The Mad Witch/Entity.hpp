#ifndef	ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Entity {
	public :
		Entity();
		~Entity();

	public :

		int Face;

		float MaxHealth, Health;
		float Mana, MaxMana;

		float Attack;
		float MovementSpeed;

		float AnimationFrame;

		RectangleShape HitBlock;
		RectangleShape Top, Left, Right, Buttom;
		
		Texture texture;
		Sprite sprite;

		RectangleShape HealthBar;
		RectangleShape HealthBarHealth;
		
		Vector2f Motion;

	public :

		void Load(string file);

		void Move();

		void Move(float x, float y);

		void Move(Vector2f S);

		void Walk(float x, float y);

		void Walk(Vector2f S);

		void SetPosition(float x, float y);

		void SetPosition(Vector2f Pos);

		void Update();

		void Render(RenderTarget& target);

		void RenderHitBlock(RenderTarget& target);
};

#endif