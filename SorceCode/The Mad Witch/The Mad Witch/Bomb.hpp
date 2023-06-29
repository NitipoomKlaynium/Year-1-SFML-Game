#ifndef BOMB_HPP
#define BOMB_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct BombSprite {
	float AnimationFrame;
	Sprite sprite;
};

class Bomb {
	public:

		Bomb();
		~Bomb();
	public:

		int Counter;

		Texture texture;
		
		BombSprite bombSprite[3];
		
	public:

		void Generate(float x, float y);

		void Generate(Vector2f Pos);

		void Update();

		void Render(RenderTarget& target);
};

#endif
