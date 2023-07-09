#include"Player.h"

namespace fr {
	//コンストラクタ
	Player::Player(Vec2 pos) {

		texture = Texture{ U"../player.png" };
		position = pos;
		collisionSize = 20;
	}
	//デストラクタ
	Player::~Player() {
		//空
	}
}
