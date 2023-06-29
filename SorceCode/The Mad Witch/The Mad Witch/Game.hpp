#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Export.hpp>

#include "Player.hpp"
#include "Magic.hpp"
#include "Goblin.hpp"

using namespace sf;
using namespace std;

#define WindowDefault 0
#define WindowFullScreen 1

#define StateMenu 0
#define StateGame 1

#define DefualtMenu 0
#define ShowHowToPlay 1
#define ShowScore 2
#define ShowOption 3
#define EnterName 4

enum Keys {
	Esc,
	Space,
	A,
	D
};

struct MenuText {
	Text Play;
	Text HowToPlay;
	Text Score;
	Text Option;
	Text Exit;
	Text Back;
	Text FullScreen;
	Text Start;
};

struct Rank {
	Text Name;
	Text Score;
};

namespace Game {

	void Initialize();

	void InitView();

	void InitOnstacle();

	void InitWater();

	void InitText();

	void InitSound();

	void FormatView();

	void StartMenu();

	void StartGame();

	void MapCheck(Entity& entity);

	void Run();

	void PollEvent();

	void SystemManagement();

	void Update();

	void Render();

	void UpdateMenu();

	void RenderMenu();

	void UpdateGame();

	void PlayerControl();

	void RenderGame();

	namespace mouse {

		void Update();

		bool LeftClick();

		bool RightClick();

		bool Pointing(const RectangleShape& object);

		bool Pointing(const Sprite& object);

		bool Pointing(const Text& object);

		bool LeftClickOn(const RectangleShape& object);

		bool LeftClickOn(const Sprite& object);

		bool LeftClickOn(const Text& object);

		bool RightClickOn(const RectangleShape& object);

		bool RightClickOn(const Sprite& object);

		bool RightClickOn(const Text& object);
	}

	namespace keyboard {

		bool Press(int key);

		bool DoubleTap(int key);

		void Update();
	}
	
	namespace random {

		int Number(const unsigned int min, const unsigned int max);

		int Signed(const int x);

		float Signed(const float x);
	}

}

#endif