#include"Object.h"

namespace fr {
	//コンストラクタ
	Object::Object() {

		initialize();
	}
	//コンストラクタ
	Object::Object(Vec2 pos) {

		initialize();
	}
	//デストラクタ
	Object::~Object() {
		//空
	}
	//イニシャライザ
	void Object::initialize() {

		size = ZeroVec2;
		position = ZeroVec2;
		velocity = ZeroVec2;
		acceleration = ZeroVec2;
		collisionSize = 0;
		degree = .0f;
		isActive = false;
	}
	//座標更新、毎フレーム呼び出す
	void Object::update() {

		velocity += acceleration;
		position += velocity;
	}
}
