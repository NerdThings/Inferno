#include "Rectangle.h"
#include "Point.h"
#include "Vector2.h"

using namespace Inferno;

//Constructors
Rectangle::Rectangle(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(Point* position, Point* size)
{
	this->x = position->x;
	this->y = position->y;
	this->width = size->x;
	this->height = size->y;
}

//Methods

bool Rectangle::contains(float x, float y) const
{
	return this->x <= x && x < this->x + this->width && this->y <= y && y < this->y + this->height;
}

bool Rectangle::contains(int x, int y) const
{
	return contains(float(x), float(y));
}

bool Rectangle::contains(Point* value) const
{
	return contains(value->x, value->y);
}

bool Rectangle::contains(Vector2* value) const
{
	return contains(value->x, value->y);
}

int Rectangle::getBottomCoord() const
{
	return y + height;
}

Point* Rectangle::getCenter() const
{
	return new Point(x + width / 2.0f, y + height / 2.0f);
}

int Rectangle::getLeftCoord() const
{
	return x;
}

Point* Rectangle::getLocation() const
{
	return new Point(x, y);
}

int Rectangle::getRightCoord() const
{
	return x + width;
}

Point* Rectangle::getSize() const
{
	return new Point(width, height);
}

int Rectangle::getTopCoord() const
{
	return y;
}

bool Rectangle::intersects(Rectangle* value) const
{
	return value->getLeftCoord() < getRightCoord() &&
		getLeftCoord() < value->getRightCoord() &&
		value->getTopCoord() < getBottomCoord() &&
		getTopCoord() < value->getBottomCoord();
}

bool Rectangle::touching(Rectangle* b) const
{
	return touchingBottom(b) || touchingLeft(b) || touchingRight(b) || touchingLeft(b);
}

bool Rectangle::touchingBottom(Rectangle* b) const
{
	return getTopCoord() < b->getBottomCoord() &&
		getBottomCoord() > b->getBottomCoord() &&
		getRightCoord() > b->getLeftCoord() &&
		getLeftCoord() < b->getRightCoord();
}

bool Rectangle::touchingLeft(Rectangle* b) const
{
	return getRightCoord() > b->getLeftCoord() &&
		getLeftCoord() < b->getLeftCoord() &&
		getBottomCoord() > b->getTopCoord() &&
		getTopCoord() < b->getBottomCoord();
}

bool Rectangle::touchingRight(Rectangle* b) const
{
	return getLeftCoord() < b->getRightCoord() &&
		getRightCoord() > b->getRightCoord() &&
		getBottomCoord() > b->getTopCoord() &&
		getTopCoord() < b->getBottomCoord();
}

bool Rectangle::touchingTop(Rectangle* b) const
{
	return getBottomCoord() > b->getTopCoord() &&
		getTopCoord() < b->getTopCoord() &&
		getRightCoord() > b->getLeftCoord() &&
		getLeftCoord() < b->getRightCoord();
}

//Operators

bool Rectangle::operator==(Rectangle *b) const
{
	return (x == b->x && y == b->y && width == b->width && height == b->height);
}

bool Rectangle::operator!=(Rectangle* b) const
{
	return !(this == b);
}
