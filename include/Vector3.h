#ifndef Inferno_Vector3
#define Inferno_Vector3

#include "Inferno.h"

namespace Inferno
{
	struct Vector2;
	struct INFERNO_API Vector3
	{
		//Fields

		float X;
		float Y;
		float Z;

		//Constructors

		Vector3(float x, float y, float z);
		Vector3(Vector2* value, float z);
		Vector3(float value);

		//Get Functions

		float GetMagnitude() const;

		float GetMagnitudeSquared() const;

		float Dot(Vector3* b) const;

		float Distance(Vector3* b) const;

		//Operators

		Vector3* operator+(Vector3* b) const;

		Vector3* operator+(int b) const;

		Vector3* operator+(float b) const;

		Vector3* operator-(Vector3* b) const;

		Vector3* operator-(int b) const;

		Vector3* operator-(float b) const;

		Vector3* operator*(Vector3* b) const;

		Vector3* operator*(int b) const;

		Vector3* operator*(float b) const;

		Vector3* operator/(Vector3* b) const;

		Vector3* operator/(int b) const;

		Vector3* operator/(float b) const;

		bool operator==(Vector3* b) const;

		//TODO: Matrix Transform
	};
}

#endif