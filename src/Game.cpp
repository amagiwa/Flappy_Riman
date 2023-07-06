#include"Game.h"

namespace fr {

	Game::Game() {

		mode = 0;
		font = Font{ 48 };
		stage = new Stage();
	}

	void Game::title() {

		stage->draw();
		font(U"Flappy Riman").drawAt(scnSize.x / 2,
				scnSize.y / 8);
		if (KeySpace.down()) {
			++mode;
		}
	}

	void Game::game() {

		if (stage->update()) {
			++mode;
		}
		font(stage->draw()).drawAt(scnSize.x / 2,
			scnSize.y / 8);
	}

	void Game::result() {

		font(stage->draw()).drawAt(scnSize.x / 2,
			scnSize.y / 8 + 100);
		font(U"Result").drawAt(scnSize.x / 2,
				scnSize.y / 8);
		if (KeySpace.down()) {
			delete stage;
			stage = new Stage();
			mode = 0;
		}
	}

	void Game::update() {

		if (mode == 0) {
			title();
		}
		else if (mode == 1) {
			game();
		}
		else if (mode == 2) {
			result();
		}
		else {
			System::Exit();
		}
	}

	Game::~Game() {

		delete stage;
	}
}
