#ifndef Inferno_Rectangle
#define Inferno_Rectangle

#include "Inferno.h"

namespace Inferno {
	struct Point;
	struct Vector2;

	struct INFERNO_API Rectangle {
		//Fields

		int x;
		int y;
		int width;
		int height;

		//Constructors

		Rectangle(int x, int y, int width, int height);
		Rectangle(Point* position, Point* size);

		//Methods

		bool contains(float x, float y) const;

		bool contains(int x, int y) const;

		bool contains(Point* value) const;

		bool contains(Vector2* value) const;

		int get_bottom_coord() const;

		Point* get_center() const;

		int get_left_coord() const;

		Point* get_location() const;

		int get_right_coord() const;

		Point* get_size() const;

		int get_top_coord() const;

		bool intersects(Rectangle* value) const;

		bool touching(Rectangle* b) const;

		bool touching_bottom(Rectangle* b) const;

		bool touching_left(Rectangle* b) const;

		bool touching_right(Rectangle* b) const;

		bool touching_top(Rectangle* b) const;

		//Operators
		bool operator==(Rectangle *b) const;
		bool operator!=(Rectangle *b) const;
	};
}

#endif