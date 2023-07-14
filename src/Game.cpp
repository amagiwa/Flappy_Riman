#include"Game.h"

namespace fr {
	//コンストラクタ
	Game::Game() {

		font = Font{ 48 };
		stage = new Stage();
		current = &Game::title;
	}
	//タイトルシーン
	void Game::title() {

		stage->draw();
		font(U"Flappy Riman").drawAt(
			ScnSize.x / 2, ScnSize.y / 8);
		if (KeySpace.down()) {
			current = &Game::play;
		}
	}
	//ゲームプレイシーン
	void Game::play() {

		if (stage->update()) {
			current = &Game::gameover;
		}
		font(stage->draw()).drawAt(
			ScnSize.x / 2, ScnSize.y / 8);
	}
	//ゲームオーバーシーン
	void Game::gameover() {

		stage->draw();
		if (stage->gameover()) {
			current = &Game::result;
		}
	}
	//リザルトシーン
	void Game::result() {

		font(stage->draw()).drawAt(
			ScnSize.x / 2, ScnSize.y / 8 + 100);
		font(U"Result").drawAt(
			ScnSize.x / 2, ScnSize.y / 8);
		if (KeySpace.down()) {
			delete stage;
			stage = new Stage();
			current = &Game::title;
		}
	}
	//ゲームの画面更新
	void Game::update() {

		(this->*current)();
	}
	//デストラクタ
	Game::~Game() {

		delete stage;
	}
}
