#include "Vector2.h"
#include "Vector3.h"
#include <cmath>

using namespace Inferno;

//Constructors

Vector3::Vector3(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

Vector3::Vector3(Vector2* value, float z)
{
	X = value->X;
	Y = value->Y;
	Z = z;
}

Vector3::Vector3(float value)
{
	X = value;
	Y = value;
	Z = value;
}

//Get functions

float Vector3::GetMagnitude() const
{
	return sqrt((X * X) + (Y * Y) + (Z * Z));
}

float Vector3::GetMagnitudeSquared() const
{
	return GetMagnitude() * GetMagnitude();
}

float Vector3::Dot(Vector3* b) const
{
	return (X * b->X) + (Y * b->Y) + (Z * b->Z);
}

float Vector3::Distance(Vector3* b) const
{
	return sqrtf((X - b->X) * (X - b->X) + (Y - b->Y) * (Y - b->Y) + (Z - b->Z) * (Z - b->Z));
}

//Operators

//TODO: Improve these

Vector3* Vector3::operator+(Vector3* b) const
{
	return new Vector3(X + b->X, Y + b->Y, Z + b->Z);
}

Vector3* Vector3::operator+(int b) const
{
	return new Vector3(X + b, Y + b, Z + b);
}

Vector3* Vector3::operator+(float b) const
{
	return new Vector3(X + b, Y + b, Z + b);
}

Vector3* Vector3::operator-(Vector3* b) const
{
	return new Vector3(- b->X, Y - b->Y, Z - b->Z);
}

Vector3* Vector3::operator-(int b) const
{
	return new Vector3(X - b, Y - b, Z - b);
}

Vector3* Vector3::operator-(float b) const
{
	return new Vector3(X - b, Y - b, Z - b);
}

Vector3* Vector3::operator*(Vector3* b) const
{
	return new Vector3(X * b->X, Y * b->Y, Z * b->Z);
}

Vector3* Vector3::operator*(int b) const
{
	return new Vector3(X * b, Y * b, Z * b);
}

Vector3* Vector3::operator*(float b) const
{
	return new Vector3(X * b, Y * b, Z * b);
}

Vector3* Vector3::operator/(Vector3* b) const
{
	return new Vector3(X / b->X, Y / b->Y, Z / b->Z);
}

Vector3* Vector3::operator/(int b) const
{
	return new Vector3(X / b, Y / b, Z / b);
}

Vector3* Vector3::operator/(float b) const
{
	return new Vector3( X / b, Y / b, Z / b);
}

bool Vector3::operator==(Vector3* b) const
{
	return (X == b->X && Y == b->Y && Z == b->Z);
}