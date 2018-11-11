#include "Vector2.h"
#include "Vector3.h"
#include <cmath>

namespace Inferno {
	//Constructors

	Vector3::Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3::Vector3(Vector2 value, float z) {
		this->x = value.x;
		this->y = value.y;
		this->z = z;
	}

	Vector3::Vector3(float value) {
		this->x = value;
		this->y = value;
		this->z = value;
	}

	//Get functions

	float Vector3::get_magnitude() const {
		return sqrtf((x * x) + (y * y) + (z * z));
	}

	float Vector3::get_magnitude_squared() const {
		return get_magnitude() * get_magnitude();
	}

	float Vector3::dot(Vector3 b) const {
		return (x * b.x) + (y * b.y) + (z * b.z);
	}

	float Vector3::distance(Vector3 b) const {
		return sqrtf((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y) + (z - b.z) * (z - b.z));
	}

	//Operators

	//TODO: Improve these

	Vector3 Vector3::operator+(Vector3 b) const {
		return {x + b.x, y + b.y, z + b.z};
	}

	Vector3 Vector3::operator+(int b) const {
		return {x + b, y + b, z + b};
	}

	Vector3 Vector3::operator+(float b) const {
		return {x + b, y + b, z + b};
	}

	Vector3 Vector3::operator-(Vector3 b) const {
		return {x - b.x, y - b.y, z - b.z};
	}

	Vector3 Vector3::operator-(int b) const {
		return {x - b, y - b, z - b};
	}

	Vector3 Vector3::operator-(float b) const {
		return {x - b, y - b, z - b};
	}

	Vector3 Vector3::operator*(Vector3 b) const {
		return {x * b.x, y * b.y, z * b.z};
	}

	Vector3 Vector3::operator*(int b) const {
		return {x * b, y * b, z * b};
	}

	Vector3 Vector3::operator*(float b) const {
		return {x * b, y * b, z * b};
	}

	Vector3 Vector3::operator/(Vector3 b) const {
		return {x / b.x, y / b.y, z / b.z};
	}

	Vector3 Vector3::operator/(int b) const {
		return {x / b, y / b, z / b};
	}

	Vector3 Vector3::operator/(float b) const {
		return {x / b, y / b, z / b};
	}

	bool Vector3::operator==(Vector3 b) const {
		return (x == b.x && y == b.y && z == b.z);
	}

	//TODO: Matrix transform
}