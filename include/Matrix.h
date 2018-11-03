#ifndef Inferno_Matrix
#define Inferno_Matrix

#include "Inferno.h"

namespace Inferno
{
	struct Vector3;
	struct INFERNO_API Matrix
	{
		//Constants

		static Matrix* Identity;

		//Fields

		float M11;
		float M12;
		float M13;
		float M14;
		float M21;
		float M22;
		float M23;
		float M24;
		float M31;
		float M32;
		float M33;
		float M34;
		float M41;
		float M42;
		float M43;
		float M44;

		Matrix()
		{
			M11 = 1;
			M12 = 0;
			M13 = 0;
			M14 = 0;
			M21 = 0;
			M22 = 1;
			M23 = 0;
			M24 = 0;
			M31 = 0;
			M32 = 0;
			M33 = 1;
			M34 = 0;
			M41 = 0;
			M42 = 0;
			M43 = 0;
			M44 = 1;
		}

		Matrix(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44)
		{
			M11 = m11;
			M12 = m12;
			M13 = m13;
			M14 = m14;
			M21 = m21;
			M22 = m22;
			M23 = m23;
			M24 = m24;
			M31 = m31;
			M32 = m32;
			M33 = m33;
			M34 = m34;
			M41 = m41;
			M42 = m42;
			M43 = m43;
			M44 = m44;
		}

		//Methods

		static Matrix* CreateOrthographic(float width, float height, float zNear, float zFar);

		static Matrix* CreateOrthographicOffCenter(float left, float right, float bottom, float top, float zNear, float zFar);

		float* GetArray() const;

		Vector3* GetBackwardVector() const;

		Vector3* GetDownVector() const;

		Vector3* GetForwardVector() const;

		Vector3* GetLeftVector() const;

		Vector3* GetRightVector() const;

		Vector3* GetScaleVector() const;

		Vector3* GetTranslation() const;

		Vector3* GetUpVector() const;

		Matrix* Invert() const;

		//Operators

		Matrix* operator+(Matrix* b) const;

		Matrix* operator-(Matrix* b) const;

		Matrix* operator/(Matrix* b) const;

		Matrix* operator/(int b) const;

		Matrix* operator/(float b) const;

		Matrix* operator*(Matrix* b) const;

		Matrix* operator*(int b) const;

		Matrix* operator*(float b) const;
	};
}

#endif