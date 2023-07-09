#include"Block.h"

namespace fr {
	//コンストラクタ
	Block::Block() {

		size = Vec2{ 60,200 };
	}
	//Blockのゲームオブジェクトを返す
	Rect Block::getTexture() {

		return Rect{ (int)(position.x - size.x / 2), (int)(position.y - size.y / 2),
			(int)size.x, (int)size.y };
	}
	//デストラクタ
	Block::~Block() {
		//空
	}
}
