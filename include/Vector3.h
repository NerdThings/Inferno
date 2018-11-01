#ifndef Inferno_Vector3
#define Inferno_Vector3

#include <cmath>

namespace Inferno
{
	struct Vector3
	{
		//Fields

		float X;
		float Y;
		float Z;

		//Constructors

		Vector3(float x, float y, float z)
		{
			X = x;
			Y = y;
			Z = z;
		}

		//Get Functions

		float GetMagnitude() const
		{
			return sqrt((X * X) + (Y * Y) + (Z * Z));
		}

		float GetMagnitudeSquared() const
		{
			return GetMagnitude() * GetMagnitude();
		}

		float Dot(Vector3 b) const
		{
			return (X * b.X) + (Y * b.Y) + (Z * b.Z);
		}

		float Distance(Vector3 b) const
		{
			return sqrtf((X - b.X) * (X - b.X) + (Y - b.Y) * (Y - b.Y) + (Z - b.Z) * (Z - b.Z));
		}

		//Operators

		Vector3 operator+(Vector3 b) const
		{
			return { X + b.X, Y + b.Y, Z + b.Z };
		}

		Vector3 operator+(int b) const
		{
			return { X + b, Y + b, Z + b };
		}

		Vector3 operator+(float b) const
		{
			return { X + b, Y + b, Z + b };
		}

		Vector3 operator-(Vector3 b) const
		{
			return { X - b.X, Y - b.Y, Z - b.Z };
		}

		Vector3 operator-(int b) const
		{
			return { X - b, Y - b, Z - b };
		}

		Vector3 operator-(float b) const
		{
			return { X - b, Y - b, Z - b };
		}

		Vector3 operator*(Vector3 b) const
		{
			return { X * b.X, Y * b.Y, Z * b.Z };
		}

		Vector3 operator*(int b) const
		{
			return { X * b, Y * b, Z * b };
		}

		Vector3 operator*(float b) const
		{
			return { X * b, Y * b, Z * b };
		}

		Vector3 operator/(Vector3 b) const
		{
			return { X / b.X, Y / b.Y, Z / b.Z };
		}

		Vector3 operator/(int b) const
		{
			return { X / b, Y / b, Z / b };
		}

		Vector3 operator/(float b) const
		{
			return { X / b, Y / b, Z / b };
		}

		bool operator==(Vector3 b) const
		{
			return (X == b.X && Y == b.Y && Z == b.Z);
		}

		//TODO: Matrix Transform
	};
}

#endif