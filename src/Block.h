#pragma once
#include "Object.h";

namespace fr {

	class Block :public Object {

	protected:

	public:
		Block();
		~Block();
		Rect getTexture();
	};
}
