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

int Rectangle::get_bottom_coord() const
{
	return y + height;
}

Point* Rectangle::get_center() const
{
	return new Point(x + width / 2.0f, y + height / 2.0f);
}

int Rectangle::get_left_coord() const
{
	return x;
}

Point* Rectangle::get_location() const
{
	return new Point(x, y);
}

int Rectangle::get_right_coord() const
{
	return x + width;
}

Point* Rectangle::get_size() const
{
	return new Point(width, height);
}

int Rectangle::get_top_coord() const
{
	return y;
}

bool Rectangle::intersects(Rectangle* value) const
{
	return value->get_left_coord() < get_right_coord() &&
		get_left_coord() < value->get_right_coord() &&
		value->get_top_coord() < get_bottom_coord() &&
		get_top_coord() < value->get_bottom_coord();
}

bool Rectangle::touching(Rectangle* b) const
{
	return touching_bottom(b) || touching_left(b) || touching_right(b) || touching_left(b);
}

bool Rectangle::touching_bottom(Rectangle* b) const
{
	return get_top_coord() < b->get_bottom_coord() &&
		get_bottom_coord() > b->get_bottom_coord() &&
		get_right_coord() > b->get_left_coord() &&
		get_left_coord() < b->get_right_coord();
}

bool Rectangle::touching_left(Rectangle* b) const
{
	return get_right_coord() > b->get_left_coord() &&
		get_left_coord() < b->get_left_coord() &&
		get_bottom_coord() > b->get_top_coord() &&
		get_top_coord() < b->get_bottom_coord();
}

bool Rectangle::touching_right(Rectangle* b) const
{
	return get_left_coord() < b->get_right_coord() &&
		get_right_coord() > b->get_right_coord() &&
		get_bottom_coord() > b->get_top_coord() &&
		get_top_coord() < b->get_bottom_coord();
}

bool Rectangle::touching_top(Rectangle* b) const
{
	return get_bottom_coord() > b->get_top_coord() &&
		get_top_coord() < b->get_top_coord() &&
		get_right_coord() > b->get_left_coord() &&
		get_left_coord() < b->get_right_coord();
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
