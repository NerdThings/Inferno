#ifndef Inferno_Rectangle
#define Inferno_Rectangle

#include "Inferno.h"

namespace Inferno
{
	struct Point;
	struct Vector2;
	struct INFERNO_API Rectangle
	{
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

		int getBottomCoord() const;

		Point* getCenter() const;

		int getLeftCoord() const;

		Point* getLocation() const;

		int getRightCoord() const;

		Point* getSize() const;

		int getTopCoord() const;

		bool intersects(Rectangle* value) const;

		bool touching(Rectangle* b) const;

		bool touchingBottom(Rectangle* b) const;

		bool touchingLeft(Rectangle* b) const;

		bool touchingRight(Rectangle* b) const;

		bool touchingTop(Rectangle* b) const;

		//Operators
		bool operator==(Rectangle *b) const;
		bool operator!=(Rectangle *b) const;
	};
}

#endif