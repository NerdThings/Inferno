#include "Vector2.h"
#include <cmath>

using namespace Inferno;

//Constants
const Vector2* Vector2::Zero = new Vector2(0, 0);
const Vector2* Vector2::UnitX = new Vector2(1, 0);
const Vector2* Vector2::UnitY = new Vector2(0, 1);

//Constructors

Vector2::Vector2(float x, float y)
{
	X = x;
	Y = y;
}

Vector2::Vector2(float value)
{
	X = value;
	Y = value;
}

//Get functions

float Vector2::GetMagnitude() const
{
	return sqrt((X * X) + (Y * Y));
}

float Vector2::GetMagnitudeSquared() const
{
	return GetMagnitude() * GetMagnitude();
}

float Vector2::Dot(Vector2* b) const
{
	return (X * b->X) + (Y * b->Y);
}

float Vector2::Distance(Vector2* b) const
{
	return sqrtf((X - b->X) * (X - b->X) + (Y - b->Y) * (Y - b->Y));
}

//Operators

//TODO: Improve these

Vector2* Vector2::operator+(Vector2* b) const
{
	return new Vector2(X + b->X, Y + b->Y);
}

Vector2* Vector2::operator+(int b) const
{
	return new Vector2(X + b, Y + b);
}

Vector2* Vector2::operator+(float b) const
{
	return new Vector2(X + b, Y + b);
}

Vector2* Vector2::operator-(Vector2* b) const
{
	return new Vector2(X - b->X, Y - b->Y);
}

Vector2* Vector2::operator-(int b) const
{
	return new Vector2(X - b, Y - b);
}

Vector2* Vector2::operator-(float b) const
{
	return new Vector2(X - b, Y - b);
}

Vector2* Vector2::operator*(Vector2* b) const
{
	return new Vector2(X * b->X, Y * b->Y);
}

Vector2* Vector2::operator*(int b) const
{
	return new Vector2(X * b, Y * b);
}

Vector2* Vector2::operator*(float b) const
{
	return new Vector2(X * b, Y * b);
}

Vector2* Vector2::operator/(Vector2* b) const
{
	return new Vector2(X / b->X, Y / b->Y);
}

Vector2* Vector2::operator/(int b) const
{
	return new Vector2(X / b, Y / b);
}

Vector2* Vector2::operator/(float b) const
{
	return new Vector2(X / b, Y / b);
}

bool Vector2::operator==(Vector2* b) const
{
	return (X == b->X && Y == b->Y);
}