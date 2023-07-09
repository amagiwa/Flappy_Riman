#include"Stage.h"

namespace fr {
	//コンストラクタ
	Stage::Stage() {
		//Stageの初期化
		position = ZeroVec2;
		size = ScnSize;
		count = 0;
		score = 0;
		//Playerインスタンス生成&初期化
		player = new Player(
			Vec2{ position.x + size.x / 4, position.y + size.y / 2 });
		player->setAcceleration(Vec2{ 0,0.7f });
		player->setIsActive(true);
		//Blockインスタンス生成&オブジェクトプールを用意
		for (int i = 0; i < BlockNum; ++i) {
			block[i] = new Block();
			block[i]->setVelocity(Vec2{ -4,0 });
			blockPosX[i] = block[i]->getPosition().x;
		}
		blockSize = block[0]->getSize();
	}
	//未使用
	Image Stage::paintBackground() {

		PerlinNoise noise;
		Image image{ 640, 480 };

		for (int y = 0; y < image.height(); ++y) {
			for (int x = 0; x < image.width(); ++x) {
				image[y][x] = HSV(
					220, 0.5f + 0.4f * noise.octave2D0_1(
						x / 160.0f, Abs(y / 120.0f - 4.0f),8), 0.8f);
			}
		}
		return image;
	}
	//ゲームオブジェクト:ブロックを生成
	void Stage::buildBlock() {

		double upper = blockSize.y / 2 - Random(blockSize.y / 2);

		for (auto &b:block) {
			if (!b->getIsActive()) {
				b->setPosition(
					Vec2{ position.x + size.x + blockSize.x / 2, upper});
				b->setIsActive(true);
				break;
			}
		}

		for (auto &b:block) {
			if (!b->getIsActive()) {
				b->setPosition(
					Vec2{ position.x + size.x + blockSize.x / 2, upper + blockSize.y + 180 });
				b->setIsActive(true);
				break;
			}
		}
	}
	//画面外に行ったブロックを片付ける
	void Stage::breakBlock() {

		for (auto &b:block) {
			if (b->getIsActive()) {
				if (b->getPosition().x < -blockSize.x / 2) {
					b->setIsActive(false);
				}
			}
		}
	}
	//ゲームオブジェクト:プレイヤーが飛ぶ
	void Stage::flyPlayer() {

		if (KeySpace.pressed()) {
			player->setVelocity(Vec2{ 0,-10 });
		}
	}
	//プレイヤーの当たり判定
	bool Stage::checkCollision() {

		Circle plrCol = Circle{ player->getPosition(), player->getCollisionSize() };

		for (auto& b : block) {
			if (b->getIsActive()) {
				if (b->getTexture().intersects(plrCol)) {
					return true;
				}
			}
		}

		if (player->getPosition().y<0 ||
			player->getPosition().y>ScnSize.y) {
			return true;
		}

		return false;
	}
	//スコアを計算する
	void Stage::countScore() {

		for (int i = 0; i < BlockNum; ++i) {
			if (block[i]->getIsActive() &&
				player->getPosition().x < blockPosX[i] &&
				player->getPosition().x >= block[i]->getPosition().x) {	
				++score;
				break;
			}
		}

		for (int i = 0; i < BlockNum; ++i) {
			if (block[i]->getIsActive()) {
				blockPosX[i] = block[i]->getPosition().x;
			}
		}
	}
	//ゲームオブジェクトの描画
	int Stage::draw() {

		for (auto& b:block) {
			if (b->getIsActive()) {
				b->getTexture().draw(Palette::Limegreen);
			}
		}

		if (player->getIsActive()) {

			player->getTexture().rotated(player->getDegree()).drawAt(player->getPosition());
		}

		return score;
	}
	//ゲームオブジェクトの更新
	bool Stage::update() {

		if (++count % 90 == 0) {
			buildBlock();
			count = 0;
		}
		breakBlock();

		flyPlayer();
		player->update();
		double deg = player->getVelocity().y / ((Abs(player->getVelocity().y) + 1));
		player->setDegree(deg);

		for (auto& b : block) {
			if (b->getIsActive()) {
				b->update();
			}
		}
		countScore();

		return checkCollision();
	}
	//ゲームオーバー時演出
	bool Stage::gameover() {

		static bool isInit = true;
		if (isInit) {
			count = 0;
			player->setVelocity(ZeroVec2);
			isInit = !isInit;
		}
		player->setDegree(player->getDegree() + 0.3f);
		player->update();

		if (++count > 60) {
			return true;
		}

		return false;
	}
	//デストラクタ
	Stage::~Stage() {

		delete player;
		for (auto& b : block) {
			delete b;
		}
	}
}
