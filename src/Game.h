#pragma once
#include"Stage.h"

namespace fr {
	//ゲーム本体であるGameクラス
	class Game {

	private:
		Font font;
		Stage* stage;
		void (Game::* current)();

	private:
		void title();
		void play();
		void gameover();
		void result();

	public:
		Game();
		~Game();
		void update();
	};
}
