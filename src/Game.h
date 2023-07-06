#pragma once
#include"Stage.h"

namespace fr {

	class Game {

	private:
		int mode;
		Font font;
		Stage* stage;

	private:
		void title();
		void game();
		void result();

	public:
		Game();
		~Game();
		void update();
	};
}
