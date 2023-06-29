#ifndef MAGIC_HPP
#define MAGIC_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Magic {
	public :
		Magic();
		~Magic();

	public :

		int Age;
		int Face;
		int Damage;

		Texture texture;
		Sprite sprite;

		RectangleShape HitBlock;

	public :

		void Move();

		void Move(float x, float y);

		void Update();
	
};

#endif