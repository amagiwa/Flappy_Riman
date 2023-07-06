#pragma once
#include"Player.h"
#include"Block.h"

namespace fr {

	class Stage {

	private:
		Vec2 position;
		Vec2 size;
		Image background;
		Player* player;
		Block* block[blockNum];
		Vec2 blockSize;
		int count;
		int score;
		double blockPosX[blockNum];

	private:
		Image paintBg();
		void buildBlock();
		void breakBlock();
		void flyPlayer();
		bool checkCol();
		void countScore();

	public:
		Stage();
		~Stage();
		int draw();
		bool update();
	};
}
