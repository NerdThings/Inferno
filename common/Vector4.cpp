#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <cmath>

using namespace Inferno;

//Constructors

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z= z;
	w = w;
}

Vector4::Vector4(Vector2* value, float z, float w)
{
	this->x = value->x;
	this->y = value->y;
	this->z = z;
	this->w = w;
}

Vector4::Vector4(Vector3* value, float w)
{
	this->x = value->x;
	this->y = value->y;
	this->z = value->z;
	this->w = w;
}

Vector4::Vector4(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
	this->w = value;
}

//Get functions

float Vector4::getMagnitude() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

float Vector4::getMagnitudeSquared() const
{
	return getMagnitude() * getMagnitude();
}

float Vector4::dot(Vector4* b) const
{
	return (x * b->x) + (y * b->y) + (z * b->z);
}

float Vector4::distance(Vector4* b) const
{
	return sqrtf((x - b->x) * (x - b->x) + (y - b->y) * (y - b->y) + (z - b->z) * (z - b->z));
}

//Operators

//TODO: Improve these

Vector4* Vector4::operator+(Vector4* b) const
{
	return new Vector4(x + b->x, y + b->y, z + b->z, w + b->w);
}

Vector4* Vector4::operator+(int b) const
{
	return new Vector4(x + b, y + b, z + b, w + b);
}

Vector4* Vector4::operator+(float b) const
{
	return new Vector4(x + b, y + b, z + b, w + b);
}

Vector4* Vector4::operator-(Vector4* b) const
{
	return new Vector4(x - b->x, y - b->y, z - b->z, w - b->w);
}

Vector4* Vector4::operator-(int b) const
{
	return new Vector4(x - b, y - b, z - b, w - b);
}

Vector4* Vector4::operator-(float b) const
{
	return new Vector4(x - b, y - b, z - b, w - b);
}

Vector4* Vector4::operator*(Vector4* b) const
{
	return new Vector4(x * b->x, y * b->y, z * b->z, w * b->w);
}

Vector4* Vector4::operator*(int b) const
{
	return new Vector4(x * b, y * b, z * b, w * b);
}

Vector4* Vector4::operator*(float b) const
{
	return new Vector4(x * b, y * b, z * b, w * b);
}

Vector4* Vector4::operator/(Vector4* b) const
{
	return new Vector4(x / b->x, y / b->y, z / b->z, w / b->w);
}

Vector4* Vector4::operator/(int b) const
{
	return new Vector4(x / b, y / b, z / b, w / b);
}

Vector4* Vector4::operator/(float b) const
{
	return new Vector4(x / b, y / b, z / b, w / b);
}

bool Vector4::operator==(Vector4* b) const
{
	return (x == b->x && y == b->y && z == b->z && w == b->w);
}

//TODO: Matrix transform