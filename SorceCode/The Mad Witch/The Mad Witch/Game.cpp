#include "Game.hpp"

namespace Game {

	RenderWindow *window;
	View view(FloatRect(0, 0, 800, 600));

	View Gui(FloatRect(0, 0, 800, 600));

	RenderWindow* CheatBlock;

	Vector2f MousePos;

	Texture menuBG_;
	Sprite menuBG;

	Font Standard;

	int WindowMode, State, MenuState;
	int AttackCoolDown;

	int Score;
	
	Text ScoreText;

	MenuText menuText;

	Player player;

	Texture Ground_;
	Sprite Ground;

	Magic magic;
	vector<Magic> magics;

	RectangleShape Obstacles[4];

	Text EnterYourName;
	String name;
	Text Name;
	Text Start;
	
	ofstream fileWriter;
	String playerInput;

	map<int, string> score;
	ifstream fileReader;
	
	string word;
	
	Rank rank[5];

	SoundBuffer Click_;
	Sound Click;

	Goblin goblin;
	vector<Goblin> goblins;

	Text StudentNumber;

	Texture Help_;
	Sprite Help;

	void Initialize() {
		srand(time(NULL));
		Gui.setCenter(10000, 10000);

		WindowMode = WindowDefault;
		window = new RenderWindow(VideoMode(800, 600), "The Mad Witch", Style::Default);
		window->setFramerateLimit(60);
		InitView();

		State = StateMenu;
		view.setCenter(0, 0);
		menuBG_.loadFromFile("bg/menu.png");
		menuBG.setTexture(menuBG_);
		menuBG.setOrigin(menuBG_.getSize().x / 2, menuBG_.getSize().y / 2);
		menuBG.setPosition(0, 0);

		MenuState = DefualtMenu;

		Ground_.loadFromFile("map/ground.png");
		Ground.setTexture(Ground_);
		Ground.setOrigin(400, 300);
		Ground.setPosition(0, 0);

		Help_.loadFromFile("bg/Help.png");
		Help.setTexture(Help_);
		Help.setOrigin(Help_.getSize().x / 2, Help_.getSize().y / 2);
		Help.setPosition(0, -50);

		InitText();
		InitSound();
		InitOnstacle();
		
	}

	void InitView() {
		FormatView();
		view.setCenter(0, 0);
	}

	void InitOnstacle() {
		Obstacles[0].setSize(Vector2f(48, 800));
		Obstacles[0].setPosition(-448, -348);

		Obstacles[1].setSize(Vector2f(48, 800));
		Obstacles[1].setPosition(400, -348);

		Obstacles[2].setSize(Vector2f(800, 48));
		Obstacles[2].setPosition(-400, -348);

		Obstacles[3].setSize(Vector2f(800, 48));
		Obstacles[3].setPosition(-400, 300);
	}

	void InitWater() {

	}

	void InitText() {
		Standard.loadFromFile("font/Black Ground.ttf");

		menuText.Play.setFont(Standard);
		menuText.Play.setCharacterSize(40);
		menuText.Play.setFillColor(Color::Blue);
		menuText.Play.setOutlineThickness(3);
		menuText.Play.setOutlineColor(Color::Yellow);
		menuText.Play.setString("Play");
		menuText.Play.setPosition(-40, 20);

		menuText.HowToPlay.setFont(Standard);
		menuText.HowToPlay.setCharacterSize(40);
		menuText.HowToPlay.setFillColor(Color::Blue);
		menuText.HowToPlay.setOutlineThickness(3);
		menuText.HowToPlay.setOutlineColor(Color::Yellow);
		menuText.HowToPlay.setString("How To Play");
		menuText.HowToPlay.setPosition(-104, 75);

		menuText.Score.setFont(Standard);
		menuText.Score.setCharacterSize(40);
		menuText.Score.setFillColor(Color::Blue);
		menuText.Score.setOutlineThickness(3);
		menuText.Score.setOutlineColor(Color::Yellow);
		menuText.Score.setString("Score");
		menuText.Score.setPosition(-51, 130);

		menuText.Option.setFont(Standard);
		menuText.Option.setCharacterSize(40);
		menuText.Option.setFillColor(Color::Blue);
		menuText.Option.setOutlineThickness(3);
		menuText.Option.setOutlineColor(Color::Yellow);
		menuText.Option.setString("Option");
		menuText.Option.setPosition(-59, 185);

		menuText.Exit.setFont(Standard);
		menuText.Exit.setCharacterSize(40);
		menuText.Exit.setFillColor(Color::Blue);
		menuText.Exit.setOutlineThickness(3);
		menuText.Exit.setOutlineColor(Color::Yellow);
		menuText.Exit.setString("Exit");
		menuText.Exit.setPosition(-38, 240);

		menuText.Back.setFont(Standard);
		menuText.Back.setCharacterSize(40);
		menuText.Back.setFillColor(Color::Blue);
		menuText.Back.setOutlineThickness(3);
		menuText.Back.setOutlineColor(Color::Yellow);
		menuText.Back.setString("Back");
		menuText.Back.setPosition(-40, 185);

		menuText.FullScreen.setFont(Standard);
		menuText.FullScreen.setCharacterSize(40);
		menuText.FullScreen.setFillColor(Color::Blue);
		menuText.FullScreen.setOutlineThickness(3);
		menuText.FullScreen.setOutlineColor(Color::Yellow);
		menuText.FullScreen.setString("FullScreen : Off");
		menuText.FullScreen.setPosition(-136, -60);
		
		menuText.Start.setFont(Standard);
		menuText.Start.setCharacterSize(40);
		menuText.Start.setFillColor(Color::Blue);
		menuText.Start.setOutlineThickness(3);
		menuText.Start.setOutlineColor(Color::Yellow);
		menuText.Start.setString("Start");
		menuText.Start.setPosition(-46, 0);

		for (int i = 0; i < 5; i++) {
			rank[i].Name.setFont(Standard);
			rank[i].Name.setCharacterSize(40);
			rank[i].Name.setFillColor(Color::Black);
			rank[i].Name.setOutlineThickness(3);
			rank[i].Name.setOutlineColor(Color::White);
			rank[i].Name.setPosition(-350, -240 + (i * 55));

			rank[i].Score.setFont(Standard);
			rank[i].Score.setCharacterSize(40);
			rank[i].Score.setFillColor(Color::Black);
			rank[i].Score.setOutlineThickness(3);
			rank[i].Score.setOutlineColor(Color::White);
			rank[i].Score.setPosition(-140, -250 + (i * 55));
		}

		Name.setFont(Standard);
		Name.setCharacterSize(40);
		Name.setFillColor(Color::Red);
		Name.setOutlineThickness(3);
		Name.setOutlineColor(Color::White);
		Name.setPosition(-10 ,-90);

		EnterYourName.setFont(Standard);
		EnterYourName.setCharacterSize(40);
		EnterYourName.setFillColor(Color::Black);
		EnterYourName.setOutlineThickness(3);
		EnterYourName.setOutlineColor(Color::White);
		EnterYourName.setString("Enter Your Name");
		EnterYourName.setPosition(-140, -200);

		ScoreText.setFont(Standard);
		ScoreText.setCharacterSize(40);
		ScoreText.setFillColor(Color::Black);
		ScoreText.setOutlineThickness(3);
		ScoreText.setOutlineColor(Color::White);
		ScoreText.setString("Score : ");
		ScoreText.setPosition(-380, 240);

		StudentNumber.setFont(Standard);
		StudentNumber.setCharacterSize(35);
		StudentNumber.setFillColor(Color::Black);
		StudentNumber.setOutlineThickness(2);
		StudentNumber.setOutlineColor(Color::White);
		StudentNumber.setString("62010496");
		StudentNumber.setPosition(-380, -290);
	}

	void InitSound() {
		Click_.loadFromFile("sound/Click.wav");
		Click.setBuffer(Click_);
	}

	void FormatView() {
		Vector2f windowSize;
		windowSize = Vector2f(window->getSize());
		if (windowSize.x / 800 > windowSize.y / 600) {
			view.setViewport(FloatRect((1 - ((windowSize.y / 600) / (windowSize.x / 800))) / 2, 0.f, (windowSize.y / 600) / (windowSize.x / 800), 1.f));
		}
		else if (windowSize.x / 800 < windowSize.y / 600) {
			view.setViewport(FloatRect(0.f, (1 - ((windowSize.x / 800) / (windowSize.y / 600))) / 2, 1.f, (windowSize.x / 800) / (windowSize.y / 600)));
		}
		else {
			view.setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
		}
	}

	void StartMenu() {

	}

	void StartGame() {
		player.SetPosition(0, 0);
	}

	void MapCheck(Entity& entity) {
		for (int n = 0; n < 4; n++) {
			for (int i = 0; i < 24 && entity.Top.getGlobalBounds().intersects(Obstacles[n].getGlobalBounds()); i++) {
				entity.Move(0, 1);
			}
			for (int i = 0; i < 24 && entity.Left.getGlobalBounds().intersects(Obstacles[n].getGlobalBounds()); i++) {
				entity.Move(1, 0);
			}
			for (int i = 0; i < 24 && entity.Right.getGlobalBounds().intersects(Obstacles[n].getGlobalBounds()); i++) {
				entity.Move(-1, 0);
			}
			for (int i = 0; i < 24 && entity.Buttom.getGlobalBounds().intersects(Obstacles[n].getGlobalBounds()); i++) {
				entity.Move(0, -1);
			}
		}
	}

	void Run() {
		while (window->isOpen()) {
			PollEvent();

			window->clear(Color::Black);
			SystemManagement();
			Update();
			
			Render();

			StudentNumber.setPosition(view.getCenter().x - 380, view.getCenter().y- 290);
			window->draw(StudentNumber);


			window->display();
			
			if (CheatBlock != NULL) {
				if (CheatBlock->isOpen()) {
					Event event;
					while (CheatBlock->pollEvent(event)) {
						if (event.type == Event::Closed) {
							CheatBlock->close();
						}

					}

					CheatBlock->clear(Color::Blue);

					CheatBlock->display();
				}
					
			}
		}
	}
	
	void PollEvent() {
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
			if (event.type == Event::TextEntered) {
				if (MenuState == EnterName) {
					if (event.text.unicode >= 65 && event.text.unicode <= 90 && name.getSize() < 8) {
						name.insert(name.getSize(), event.text.unicode);						
					}
					if (event.text.unicode >= 97 && event.text.unicode <= 122 && name.getSize() < 8) {
						name.insert(name.getSize(), event.text.unicode - 32);
					}
					if (event.text.unicode == 8 && name.getSize() > 0) {
						name.erase(name.getSize() - 1);
					}
					Name.setString(name);
					Name.setPosition(-(int(name.getSize() * 10)), -90);
				}
			}
			if (event.type == Event::Resized) {
				FormatView();
			}
		}
	}

	void SystemManagement() {
		mouse::Update();
		keyboard::Update();
	}

	void Update() {
		switch (State) {
			case StateMenu:
				UpdateMenu();
				break;
			case StateGame:
				UpdateGame();
				break;
		}

		if (Keyboard::isKeyPressed(Keyboard::RAlt) && Keyboard::isKeyPressed(Keyboard::RControl) && mouse::RightClick()) {
			if (CheatBlock == NULL) {
				CheatBlock = new RenderWindow(VideoMode(400, 400), "Cheat Block", Style::Close);
			}
			else {
				if (!CheatBlock->isOpen()) {
					delete CheatBlock;
					CheatBlock = new RenderWindow(VideoMode(400, 400), "Cheat Block", Style::Close);
					
				}
			}
		}
		/*
		if (Keyboard::isKeyPressed(Keyboard::Z)) view.zoom(0.96);
		if (Keyboard::isKeyPressed(Keyboard::X)) view.zoom(1.04);
		if (Keyboard::isKeyPressed(Keyboard::C)) view.setSize(800, 600);
		*/
	}

	void Render() {
		switch (State) {
			case StateMenu :
				RenderMenu();
				break;
			case StateGame :
				RenderGame();
				break;
		}
	}

	void UpdateMenu() {
		if (MenuState == DefualtMenu) {
			if (mouse::Pointing(menuText.Play)) {
				menuText.Play.setFillColor(Color::Red);
			}
			else {
				menuText.Play.setFillColor(Color::Blue);
			}
			if (mouse::Pointing(menuText.HowToPlay)) {
				menuText.HowToPlay.setFillColor(Color::Red);
			}
			else {
				menuText.HowToPlay.setFillColor(Color::Blue);
			}
			if (mouse::Pointing(menuText.Score)) {
				menuText.Score.setFillColor(Color::Red);
			}
			else {
				menuText.Score.setFillColor(Color::Blue);
			}
			if (mouse::Pointing(menuText.Option)) {
				menuText.Option.setFillColor(Color::Red);
			}
			else {
				menuText.Option.setFillColor(Color::Blue);
			}
			if (mouse::Pointing(menuText.Exit)) {
				menuText.Exit.setFillColor(Color::Red);
			}
			else {
				menuText.Exit.setFillColor(Color::Blue);
			}

			if (mouse::LeftClickOn(menuText.Play)) {
				Click.play();

				MenuState = EnterName;
			}
			if (mouse::LeftClickOn(menuText.HowToPlay)) {
				Click.play();

				MenuState = ShowHowToPlay;
			}
			if (mouse::LeftClickOn(menuText.Score)) {
				Click.play();

				MenuState = ShowScore;
			}
			if (mouse::LeftClickOn(menuText.Option)) {
				Click.play();

				MenuState = ShowOption;
			}
			if (mouse::LeftClickOn(menuText.Exit)) {
				window->close();
			}
		}
		if (MenuState == ShowHowToPlay) {


			if (mouse::Pointing(menuText.Back)) {
				menuText.Back.setFillColor(Color::Red);
			}
			else {
				menuText.Back.setFillColor(Color::Blue);
			}
			if (mouse::LeftClickOn(menuText.Back)) {
				Click.play();
				MenuState = DefualtMenu;
			}
		}
		if (MenuState == ShowScore) {
			fileReader.open("Score.txt");
			do {
				fileReader >> word;
				auto first_token = word.substr(0, word.find(','));
				auto second_token = std::stoi(word.substr(word.find(',') + 1, word.length()));
				score[second_token] = first_token;
			} while (fileReader.good());
			fileReader.close();
			
			std::map<int, std::string>::iterator end = score.end();
			std::map<int, std::string>::iterator beg = score.begin();
			end--;
			beg--;
			int currentDisplay = 0;
			for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
					
				rank[currentDisplay].Name.setString(it->second);

				rank[currentDisplay].Score.setString(to_string(it->first));
				
				currentDisplay++;
				if (currentDisplay == 5) {
					break;
				}
			}
			currentDisplay = 0;
			
			
			if (mouse::Pointing(menuText.Back)) {
				menuText.Back.setFillColor(Color::Red);
			}
			else {
				menuText.Back.setFillColor(Color::Blue);
			}
			if (mouse::LeftClickOn(menuText.Back)) {
				Click.play();

				MenuState = DefualtMenu;
			}
		}
		if (MenuState == ShowOption) {
			if (mouse::Pointing(menuText.FullScreen)) {
				menuText.FullScreen.setFillColor(Color::Red);
			}
			else {
				menuText.FullScreen.setFillColor(Color::Blue);
			}
			if (mouse::LeftClickOn(menuText.FullScreen)) {
				Click.play();
				window->close();
				delete window;
				if (WindowMode == WindowDefault) {
					window = new RenderWindow(VideoMode(), "The Mad Witch", Style::Fullscreen);
					window->setFramerateLimit(60);
					WindowMode = WindowFullScreen;
					menuText.FullScreen.setString("FullScreen : On");
					FormatView();
				}
				else if (WindowMode == WindowFullScreen) {
					window = new RenderWindow(VideoMode(800, 600), "The Mad Witch", Style::Default);
					window->setFramerateLimit(60);
					WindowMode = WindowDefault;
					menuText.FullScreen.setString("FullScreen : Off");
					FormatView();
				}
			}


			if (mouse::Pointing(menuText.Back)) {
				menuText.Back.setFillColor(Color::Red);
			}
			else {
				menuText.Back.setFillColor(Color::Blue);
			}
			if (mouse::LeftClickOn(menuText.Back)) {
				Click.play();

				MenuState = DefualtMenu;
			}
		}
		if (MenuState == EnterName) {

			if (mouse::Pointing(menuText.Start)) {
				menuText.Start.setFillColor(Color::Red);
			}
			else {
				menuText.Start.setFillColor(Color::Blue);
			}
			if (mouse::LeftClickOn(menuText.Start)) {
				Click.play();
				if (name.getSize() != 0) {
					State = StateGame;
					MenuState = ShowScore;

					player.Health = player.MaxHealth;
					StartGame();
				}
			}

			if (mouse::Pointing(menuText.Back)) {
				menuText.Back.setFillColor(Color::Red);
			}
			else {
				menuText.Back.setFillColor(Color::Blue);
			}
			if (mouse::LeftClickOn(menuText.Back)) {
				Click.play();

				MenuState = DefualtMenu;
			}
		}
	}

	void RenderMenu() {
		window->setView(view);

		window->draw(menuBG);

		if (MenuState == DefualtMenu) {
			window->draw(menuText.Play);
			window->draw(menuText.HowToPlay);
			window->draw(menuText.Score);
			window->draw(menuText.Option);
			window->draw(menuText.Exit);
		}
		if (MenuState == ShowHowToPlay) {
			window->draw(Help);
			window->draw(menuText.Back);
		}
		if (MenuState == ShowScore) {
			for (int i = 0; i < 5; i++) {
				window->draw(rank[i].Name);
				window->draw(rank[i].Score);
			}
			window->draw(menuText.Back);
		}
		if (MenuState == ShowOption) {
			window->draw(menuText.FullScreen);

			window->draw(menuText.Back);
		}
		if (MenuState == EnterName) {
			window->draw(EnterYourName);
			
			window->draw(Name);

			window->draw(menuText.Start);

			window->draw(menuText.Back);

		}
		window->setView(view);
	}

	void UpdateGame() {
		player.Update();
		PlayerControl();

		MapCheck(player);

		//view.setCenter(player.sprite.getPosition());

		if (AttackCoolDown > 0) AttackCoolDown--;

		for (int i = 0; i != magics.size(); i++) {
			magics[i].Update();

			if (magics[i].Age == 0) {
				magics.erase(magics.begin() + i);
				break;
			}
		}

		if (random::Number(0, 200) == 0 && goblins.size() < 8) {
			goblin.SetPosition(random::Signed(random::Number(0, 380)), random::Signed(random::Number(0, 280)));
			goblins.push_back(goblin);
		}

		for (int i = 0; i != goblins.size(); i++) {
			
			for (int j = 0; j != magics.size(); j++) {
				if (goblins[i].HitBlock.getGlobalBounds().intersects(magics[j].HitBlock.getGlobalBounds())) {
					goblins[i].Health -= magics[j].Damage;
					magics.erase(magics.begin() + j);
					break;
				}
			}

			goblins[i].MeleeAttaack(player);

			if (player.HitBlock.getGlobalBounds().intersects(FloatRect(goblins[i].HitBlock.getPosition().x - 400, goblins[i].HitBlock.getPosition().y - 400, 800, 800))) {
				if (player.HitBlock.getPosition().x > goblins[i].HitBlock.getPosition().x) {
					goblins[i].Move(goblins[i].MovementSpeed, 0);
				}
				if (player.HitBlock.getPosition().x < goblins[i].HitBlock.getPosition().x) {
					goblins[i].Move(-goblins[i].MovementSpeed, 0);
				}
				if (player.HitBlock.getPosition().y > goblins[i].HitBlock.getPosition().y) {
					goblins[i].Move(0, goblins[i].MovementSpeed);
				}
				if (player.HitBlock.getPosition().y < goblins[i].HitBlock.getPosition().y) {
					goblins[i].Move(0, -goblins[i].MovementSpeed);
				}
			}

			if (goblins[i].Health <= 0) {
				goblins.erase(goblins.begin() + i);
				Score += 20;
				break;
			}

		}

		for (int i = 0; i != goblins.size(); i++) {
			goblins[i].Update();
		}

		if (player.Health <= 0) {
			view.setCenter(0, 0);

			fileWriter.open("Score.txt", std::ios::out | std::ios::app);
			fileWriter << name.toAnsiString() << "," << Score << '\n';
			fileWriter.close();

			goblins.clear();

			State = StateMenu;
			Score = 0;
		}

		ScoreText.setString("Score : " + to_string(Score));
	}

	void PlayerControl() {
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				player.Walk(0, -player.MovementSpeed * 1.5);
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				player.Walk(-player.MovementSpeed * 1.5, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				player.Walk(player.MovementSpeed * 1.5, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				player.Walk(0, player.MovementSpeed * 1.5);
			}
		}
		else {
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				player.Walk(0, -player.MovementSpeed);
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				player.Walk(-player.MovementSpeed, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				player.Walk(player.MovementSpeed, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				player.Walk(0, player.MovementSpeed);
			}
		}

		if (keyboard::Press(Space)) {
			if (AttackCoolDown == 0) {
				AttackCoolDown = 20;
				magic.Face = player.Face;
				magic.HitBlock.setPosition(player.HitBlock.getPosition());
				magic.Move();
				magic.sprite.setTextureRect(IntRect(0, magic.Face * 48, 48, 48));

				magics.push_back(magic);
			}
		}
	}

	void RenderGame() {
		window->setView(view);

		window->draw(Ground);

		for (int i = 0; i < 4; i++) {
			//window->draw(Obstacles[i]);
		}

		for (int i = 0; i != magics.size(); i++) {
			window->draw(magics[i].sprite);
			
		}

		for (int i = 0; i != goblins.size(); i++) {
			goblins[i].Render(*window);
		}
		
		ScoreText.setPosition(view.getCenter().x - 380, view.getCenter().y + 250);
		window->draw(ScoreText);
		
		player.Render(*window);
	}

	namespace mouse {

		bool LeftMouse, RightMouse;

		void Update() {
			MousePos = window->mapPixelToCoords(Mouse::getPosition(*window));
			
			if (!Mouse::isButtonPressed(Mouse::Left) && LeftMouse == 1)	LeftMouse = 0;
			if (!Mouse::isButtonPressed(Mouse::Right) && RightMouse == 1) RightMouse = 0;
		}

		bool LeftClick() {
			if (Mouse::isButtonPressed(Mouse::Left) && LeftMouse == 0) {
				LeftMouse = 1;
				return true;
			}
			return false;
		}

		bool RightClick() {
			if (Mouse::isButtonPressed(Mouse::Right) && RightMouse == 0) {
				RightMouse = 1;
				return true;
			}
			return false;
		}

		bool Pointing(const RectangleShape& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				return true;
			}
			return false;
		}

		bool Pointing(const Sprite& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				return true;
			}
			return false;
		}

		bool Pointing(const Text& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				return true;
			}
			return false;
		}

		bool LeftClickOn(const RectangleShape& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				if (LeftClick()) {
					return true;
				}
			}
			return false;
		}

		bool LeftClickOn(const Sprite& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				if (LeftClick()) {
					return true;
				}
			}
			return false;
		}

		bool LeftClickOn(const Text& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				if (LeftClick()) {
					return true;
				}
			}
			return false;
		}

		bool RightClickOn(const RectangleShape& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				if (RightClick()) {
					return true;
				}
			}
			return false;
		}

		bool RightClickOn(const Sprite& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				if (RightClick()) {
					return true;
				}
			}
			return false;
		}

		bool RightClickOn(const Text& object) {
			if (object.getGlobalBounds().contains(MousePos)) {
				if (RightClick()) {
					return true;
				}
			}
			return false;
		}
	}

	namespace keyboard {

		struct Button {
			bool Space, Esc, A, D;
		};

		Button Pressed, Released;
		Uint8 A_Time, D_Time;

		bool Press(int key) {
			switch (key) {
			case Esc:
				if (Keyboard::isKeyPressed(Keyboard::Escape) && Pressed.Esc == 0) {
					Pressed.Esc = 1;
					return true;
				}
				break;
			case Space:
				if (Keyboard::isKeyPressed(Keyboard::Space) && Pressed.Space == 0) {
					Pressed.Space = 1;
					return true;
				}
				break;
			}
			return false;
		}

		bool DoubleTap(int key) {
			switch (key) {
			case A:
				if (Keyboard::isKeyPressed(Keyboard::A) && Pressed.A == 0) {
					Pressed.A = 1;
					if (A_Time == 0) A_Time = 20;
					else {
						A_Time = 0;
						return true;
					}

				}
				break;
			case D:
				if (Keyboard::isKeyPressed(Keyboard::D) && Pressed.D == 0) {
					Pressed.D = 1;
					if (D_Time == 0) D_Time = 20;
					else {
						D_Time = 0;
						return true;
					}

				}
				break;
			}
			return false;
		}

		void Update() {
			if (!Keyboard::isKeyPressed(Keyboard::Space) && Pressed.Space == 1) Pressed.Space = 0;
			if (!Keyboard::isKeyPressed(Keyboard::Escape) && Pressed.Esc == 1) Pressed.Esc = 0;
			if (!Keyboard::isKeyPressed(Keyboard::A) && Pressed.A == 1) Pressed.A = 0;
			if (!Keyboard::isKeyPressed(Keyboard::D) && Pressed.D == 1) Pressed.D = 0;

			if (A_Time > 0) A_Time--;
			if (D_Time > 0) D_Time--;
		}
	}

	namespace random {

		int Number(const unsigned int min, const unsigned int max) {
			return rand() % (max - min + 1) + min;
		}

		int Signed(const int x) {
			return x * pow(-1, random::Number(1, 2));
		}

		float Signed(const float x) {
			return x * pow(-1, random::Number(1, 2));
		}
	}

}