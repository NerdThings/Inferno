#ifndef Inferno_Vector4
#define Inferno_Vector4

#include "Inferno.h"

namespace Inferno
{
	struct Vector2;
	struct Vector3;
	struct INFERNO_API Vector4
	{
		//Fields

		float x;
		float y;
		float z;
		float w;

		//Constructors

		Vector4(float x, float y, float z, float w);
		Vector4(Vector2* value, float z, float w);
		Vector4(Vector3* value, float w);
		Vector4(float value);

		//Methods

		float getMagnitude() const;

		float getMagnitudeSquared() const;

		float dot(Vector4* b) const;

		float distance(Vector4* b) const;

		//Operators

		Vector4* operator+(Vector4* b) const;

		Vector4* operator+(int b) const;

		Vector4* operator+(float b) const;

		Vector4* operator-(Vector4* b) const;

		Vector4* operator-(int b) const;

		Vector4* operator-(float b) const;

		Vector4* operator*(Vector4* b) const;

		Vector4* operator*(int b) const;

		Vector4* operator*(float b) const;

		Vector4* operator/(Vector4* b) const;

		Vector4* operator/(int b) const;

		Vector4* operator/(float b) const;

		bool operator==(Vector4* b) const;

		//TODO: Matrix Transform
	};
}

#endif