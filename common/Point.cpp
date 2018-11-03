#include "Point.h"
#include "Vector2.h"

using namespace Inferno;

//Constructor

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

//Methods

Vector2* Point::to_vector() const
{
	return new Vector2(x, y);
}


//Operators

Point* Point::operator+(Point* b) const
{
	return new Point(x + b->x, y + b->y);
}

Point* Point::operator+(int b) const
{
	return new Point(x + b, y + b);
}

Point* Point::operator-(Point* b) const
{
	return new Point(x - b->x, y - b->y);
}

Point* Point::operator-(int b) const
{
	return new Point(x - b, y - b);
}

Point* Point::operator*(Point* b) const
{
	return new Point(x * b->x, y * b->y);
}

Point* Point::operator*(int b) const
{
	return new Point(x * b, y * b);
}

Point* Point::operator/(Point* b) const
{
	return new Point(x / b->x, y / b->y);
}

Point* Point::operator/(int b) const
{
	return new Point(x / b, y / b);
}

bool Point::operator==(Point* b) const
{
	return (x == b->x && y == b->y);
}
