#include"Block.h"

namespace fr {

	Block::Block() {

		size = Vec2{ 60,200 };
	}

	Rect Block::getTexture() {

		return Rect{ (int)(position.x - size.x / 2), (int)(position.y - size.y / 2),
			(int)size.x, (int)size.y };
	}

	Block::~Block() {

	}
}
