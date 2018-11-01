#ifndef Inferno_Vector2
#define Inferno_Vector2

#include <cmath>

namespace Inferno
{
	struct Vector2
	{
		static Vector2 Zero()
		{
			return { 0, 0 };
		}

		//Fields

		float X;
		float Y;

		Vector2(float x, float y)
		{
			X = x;
			Y = y;
		}

		Vector2(float value)
		{
			X = value;
			Y = value;
		}

		//Get Functions

		float GetMagnitude() const
		{
			return sqrt((X * X) + (Y * Y));
		}

		float GetMagnitudeSquared() const
		{
			return GetMagnitude() * GetMagnitude();
		}

		float Dot(Vector2 b) const
		{
			return (X * b.X) + (Y * b.Y);
		}

		float Distance(Vector2 b) const
		{
			return sqrtf((X - b.X) * (X - b.X) + (Y - b.Y) * (Y - b.Y));
		}

		//Operators

		Vector2 operator+(Vector2 b) const
		{
			return { X + b.X, Y + b.Y };
		}

		Vector2 operator+(int b) const
		{
			return { X + b, Y + b };
		}

		Vector2 operator+(float b) const
		{
			return { X + b, Y + b };
		}

		Vector2 operator-(Vector2 b) const
		{
			return { X - b.X, Y - b.Y };
		}

		Vector2 operator-(int b) const
		{
			return { X - b, Y - b };
		}

		Vector2 operator-(float b) const
		{
			return { X - b, Y - b };
		}

		Vector2 operator*(Vector2 b) const
		{
			return { X * b.X, Y * b.Y };
		}

		Vector2 operator*(int b) const
		{
			return { X * b, Y * b };
		}

		Vector2 operator*(float b) const
		{
			return { X * b, Y * b };
		}

		Vector2 operator/(Vector2 b) const
		{
			return { X / b.X, Y / b.Y };
		}

		Vector2 operator/(int b) const
		{
			return { X / b, Y / b };
		}

		Vector2 operator/(float b) const
		{
			return { X / b, Y / b };
		}

		bool operator==(Vector2 b) const
		{
			return (X == b.X && Y == b.Y);
		}

		//TODO: Matrix Transform
	};
}

#endif