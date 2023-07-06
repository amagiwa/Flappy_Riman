#pragma once

namespace fr {

	const Vec2 scnSize = Vec2{ 640,480 };
	const Vec2 zeroVec2 = Vec2{ 0,0 };
	const int blockNum = 10;

	class Object {

	protected:
		Texture texture;
		Vec2 size;
		Vec2 position;
		Vec2 velocity;
		Vec2 acceleration;
		int collisionSize;
		double degree;
		bool isActive;

	public:
		Object();
		Object(Vec2);
		virtual ~Object();
		void initialize();
		void update();

		inline Texture getTexture() const {

			return texture;
		}

		inline Vec2 getSize() const {

			return size;
		}

		inline void setSize(Vec2 size) {

			this->size = size;
		}

		inline Vec2 getPosition() const {

			return position;
		}

		inline void setPosition(Vec2 position) {

			this->position = position;
		}

		inline Vec2 getVelocity() const {

			return velocity;
		}

		inline void setVelocity(Vec2 velocity) {

			this->velocity = velocity;
		}

		inline Vec2 getAcceleration() const {

			return acceleration;
		}

		inline void setAcceleration(Vec2 acceleration) {

			this->acceleration = acceleration;
		}

		inline int getCollisionSize() const {

			return collisionSize;
		}

		inline void setCollisionSize(int collisionSize) {

			this->collisionSize = collisionSize;
		}

		inline double getDegree() const {

			return degree;
		}

		inline void setDegree(double degree) {

			this->degree = degree;
		}

		inline bool getIsActive() const {

			return isActive;
		}

		inline void setIsActive(bool isActive) {

			this->isActive = isActive;
		}
	};
}
