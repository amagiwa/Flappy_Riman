#include"Stage.h"

namespace fr {

	Stage::Stage() {

		position = zeroVec2;
		size = scnSize;
		player = new Player(Vec2{ position.x + size.x / 4,
			position.y + size.y / 2 });
		player->setAcceleration(Vec2{ 0,0.7f });
		player->setIsActive(true);
		for (int i = 0; i < blockNum; ++i) {
			block[i] = new Block();
			block[i]->setVelocity(Vec2{ -4,0 });
			blockPosX[i] = block[i]->getPosition().x;
		}
		blockSize = block[0]->getSize();
		count = 0;
		score = 0;
	}

	Image Stage::paintBg() {

		PerlinNoise noise;
		Image image{ 640, 480 };

		for (int y = 0; y < image.height(); ++y) {
			for (int x = 0; x < image.width(); ++x) {
				image[y][x] = HSV(220,
					0.5f + 0.4f * noise.octave2D0_1(x / 160.0f, Abs(y / 120.0f - 4.0f),
						8), 0.8f);
			}
		}
		return image;
	}

	void Stage::buildBlock() {

		double upper = blockSize.y / 2 - Random(blockSize.y / 2);

		for (int i = 0; i < blockNum; ++i) {
			if (!block[i]->getIsActive()) {
				block[i]->setPosition(Vec2{ position.x + size.x + blockSize.x / 2,
					 upper});
				block[i]->setIsActive(true);
				break;
			}
		}

		for (int i = 0; i < blockNum; ++i) {
			if (!block[i]->getIsActive()) {
				block[i]->setPosition(Vec2{ position.x + size.x + blockSize.x / 2,
				upper + blockSize.y + 180 });
				block[i]->setIsActive(true);
				break;
			}
		}
	}

	void Stage::breakBlock() {

		for (int i = 0; i < blockNum; ++i) {
			if (block[i]->getIsActive()) {
				if (block[i]->getPosition().x < -blockSize.x / 2) {
					block[i]->setIsActive(false);
				}
			}
		}
	}

	void Stage::flyPlayer() {

		if (KeySpace.pressed()) {
			player->setVelocity(Vec2{ 0,-10 });
		}
	}

	bool Stage::checkCol() {

		Circle plrCol = Circle{ player->getPosition(), player->getCollisionSize() };

		for (int i = 0; i < blockNum; ++i) {
			if (block[i]->getIsActive()) {
				if (block[i]->getTexture().intersects(plrCol)) {
					return true;
				}
			}
		}

		if (player->getPosition().y<0 ||
			player->getPosition().y>scnSize.y) {
			return true;
		}
		return false;
	}

	void Stage::countScore() {

		for (int i = 0; i < blockNum; ++i) {
			if (block[i]->getIsActive() &&
				player->getPosition().x < blockPosX[i] &&
				player->getPosition().x >= block[i]->getPosition().x) {	
				++score;
				break;
			}
		}

		for (int i = 0; i < blockNum; ++i) {
			if (block[i]->getIsActive()) {
				blockPosX[i] = block[i]->getPosition().x;
			}
		}
	}

	int Stage::draw() {

		if (player->getIsActive()) {
			double deg = player->getVelocity().y / ((Abs(player->getVelocity().y) + 1));
			player->getTexture().rotated(1.2f*deg).drawAt(player->getPosition());
		}

		for (int i = 0; i < blockNum; ++i) {
			if (block[i]->getIsActive()) {
				block[i]->getTexture().draw(Palette::Limegreen);
			}
		}
		return score;
	}

	bool Stage::update() {

		if (++count % 90 == 0) {
			buildBlock();
			count = 0;
		}
		breakBlock();

		flyPlayer();
		player->update();
		for (int i = 0; i < blockNum; ++i) {
			if (block[i]->getIsActive()) {
				block[i]->update();
			}
		}
		countScore();

		return checkCol();
	}

	Stage::~Stage() {

		delete player;
		for (int i = 0; i < blockNum; ++i) {
			delete block[i];
		}
	}
}
