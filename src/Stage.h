#pragma once
#include"Player.h"
#include"Block.h"

namespace fr {
	//オブジェクトを制御するStageクラス
	class Stage {

	private:
		Vec2 position;
		Vec2 size;
		Image background;
		Player* player;
		Block* block[BlockNum];
		Vec2 blockSize;
		int count;
		int score;
		double blockPosX[BlockNum];

	private:
		Image paintBackground();
		void buildBlock();
		void breakBlock();
		void flyPlayer();
		bool checkCollision();
		void countScore();

	public:
		Stage();
		~Stage();
		int draw();
		bool update();
		bool gameover();
	};
}
