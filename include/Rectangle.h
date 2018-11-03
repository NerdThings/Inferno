#ifndef Inferno_Rectangle
#define Inferno_Rectangle

#include "Inferno.h"

namespace Inferno
{
	struct Point;
	struct Vector2;
	struct INFERNO_API Rectangle
	{
		int x;
		int y;
		int width;
		int height;
	};
}

#endif