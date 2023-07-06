#include"Player.h"

namespace fr {

	Player::Player(Vec2 pos) {

		texture = Texture{ U"../player.png" };
		position = pos;
		collisionSize = 20;
	}

	Player::~Player() {

	}
}
