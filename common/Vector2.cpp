#include "Vector2.h"
#include <cmath>

using namespace Inferno;

//Constants
const Vector2* Vector2::zero = new Vector2(0, 0);
const Vector2* Vector2::unit_x = new Vector2(1, 0);
const Vector2* Vector2::unit_y = new Vector2(0, 1);

//Constructors

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(float value)
{
	this->x = value;
	this->y = value;
}

//Get functions

float Vector2::get_magnitude() const
{
	return sqrt((x * x) + (y * y));
}

float Vector2::get_magnitude_squared() const
{
	return get_magnitude() * get_magnitude();
}

float Vector2::dot(Vector2* b) const
{
	return (x * b->x) + (y * b->y);
}

float Vector2::distance(Vector2* b) const
{
	return sqrtf((x - b->x) * (x - b->x) + (y - b->y) * (y - b->y));
}

//Operators

//TODO: Improve these

Vector2* Vector2::operator+(Vector2* b) const
{
	return new Vector2(x + b->x, y + b->y);
}

Vector2* Vector2::operator+(int b) const
{
	return new Vector2(x + b, y + b);
}

Vector2* Vector2::operator+(float b) const
{
	return new Vector2(x + b, y + b);
}

Vector2* Vector2::operator-(Vector2* b) const
{
	return new Vector2(x - b->x, y - b->y);
}

Vector2* Vector2::operator-(int b) const
{
	return new Vector2(x - b, y - b);
}

Vector2* Vector2::operator-(float b) const
{
	return new Vector2(x - b, y - b);
}

Vector2* Vector2::operator*(Vector2* b) const
{
	return new Vector2(x * b->x, y * b->y);
}

Vector2* Vector2::operator*(int b) const
{
	return new Vector2(x * b, y * b);
}

Vector2* Vector2::operator*(float b) const
{
	return new Vector2(x * b, y * b);
}

Vector2* Vector2::operator/(Vector2* b) const
{
	return new Vector2(x / b->x, y / b->y);
}

Vector2* Vector2::operator/(int b) const
{
	return new Vector2(x / b, y / b);
}

Vector2* Vector2::operator/(float b) const
{
	return new Vector2(x / b, y / b);
}

bool Vector2::operator==(Vector2* b) const
{
	return (x == b->x && y == b->y);
}

//TODO: Matrix transform