#ifndef Inferno_Point
#define Inferno_Point

#include "Inferno.h"

namespace Inferno
{
	struct Vector2;
	struct INFERNO_API Point
	{
		//Fields

		int x;
		int y;

		//Constructor

		Point(int x, int y);

		//Methods

		Vector2* toVector() const;

		//Operators

		Point* operator+(Point* b) const;

		Point* operator+(int b) const;

		Point* operator-(Point* b) const;

		Point* operator-(int b) const;

		Point* operator*(Point* b) const;

		Point* operator*(int b) const;

		Point* operator/(Point* b) const;

		Point* operator/(int b) const;

		bool operator==(Point* b) const;
	};
}

#endif