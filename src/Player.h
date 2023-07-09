#pragma once
#include "Object.h"

namespace fr {
	//Playerクラス
	class Player :public Object {

	protected:

	public:
		Player() = default;
		Player(Vec2);
		~Player();
	};
}
