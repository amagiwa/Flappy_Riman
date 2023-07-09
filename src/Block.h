#pragma once
#include "Object.h";

namespace fr {
	//Blockクラス
	class Block :public Object {

	protected:

	public:
		Block();
		~Block();
		Rect getTexture();
	};
}
