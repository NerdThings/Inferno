#ifndef Inferno_Vector2
#define Inferno_Vector2

#include "Inferno.h"

namespace Inferno
{
	struct INFERNO_API Vector2
	{
		//Constants

		static const Vector2* Zero;
		static const Vector2* UnitX;
		static const Vector2* UnitY;

		//Fields

		float X;
		float Y;

		Vector2(float x, float y);

		Vector2(float value);

		//Get Functions

		float GetMagnitude() const;

		float GetMagnitudeSquared() const;

		float Dot(Vector2* b) const;

		float Distance(Vector2* b) const;

		//Operators

		Vector2* operator+(Vector2* b) const;

		Vector2* operator+(int b) const;

		Vector2* operator+(float b) const;

		Vector2* operator-(Vector2* b) const;

		Vector2* operator-(int b) const;

		Vector2* operator-(float b) const;

		Vector2* operator*(Vector2* b) const;

		Vector2* operator*(int b) const;

		Vector2* operator*(float b) const;

		Vector2* operator/(Vector2* b) const;

		Vector2* operator/(int b) const;

		Vector2* operator/(float b) const;

		bool operator==(Vector2* b) const;

		//TODO: Matrix Transform
	};
}

#endif