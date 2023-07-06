#include"Object.h"

namespace fr {

	Object::Object() {

		initialize();
	}

	Object::Object(Vec2 pos) {

		initialize();
	}

	Object::~Object() {

	}

	void Object::initialize() {

		size = zeroVec2;
		position = zeroVec2;
		velocity = zeroVec2;
		acceleration = zeroVec2;
		collisionSize = 0;
		degree = .0f;
		isActive = false;
	}

	void Object::update() {

		velocity += acceleration;
		position += velocity;
	}
}
