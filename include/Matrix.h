#ifndef Inferno_Matrix
#define Inferno_Matrix

namespace Inferno
{
	struct Matrix
	{
		static Matrix Identity()
		{
			return { 1, 0, 0, 0,
					 0, 1, 0, 0,
					 0, 0, 1, 0,
					 0, 0, 0, 1 };
		}

		static Matrix Invert(Matrix matrix)
		{
			Matrix result = Matrix();

			const float num1 = matrix.M11;
			const float num2 = matrix.M12;
			const float num3 = matrix.M13;
			const float num4 = matrix.M14;
			const float num5 = matrix.M21;
			const float num6 = matrix.M22;
			const float num7 = matrix.M23;
			const float num8 = matrix.M24;
			const float num9 = matrix.M31;
			const float num10 = matrix.M32;
			const float num11 = matrix.M33;
			const float num12 = matrix.M34;
			const float num13 = matrix.M41;
			const float num14 = matrix.M42;
			const float num15 = matrix.M43;
			const float num16 = matrix.M44;
			const float num17 = num11 * num16 - num12 * num15;
			const float num18 = num10 * num16 - num12 * num14;
			const float num19 = num10 * num15 - num11 * num14;
			const float num20 = num9 * num16 - num12 * num13;
			const float num21 = num9 * num15 - num11 * num13;
			const float num22 = num9 * num14 - num10 * num13;
			const float num23 = num6 * num17 - num7 * num18 + num8 * num19;
			const float num24 = -(num5 * num17 - num7 * num20 + num8 * num21);
			const float num25 = num5 * num18 - num6 * num20 + num8 * num22;
			const float num26 = -(num5 * num19 - num6 * num21 + num7 * num22);
			const float num27 = (1.0f / (num1 * num23 + num2 * num24 + num3 * num25 + num4 * num26));

			result.M11 = num23 * num27;
			result.M21 = num24 * num27;
			result.M31 = num25 * num27;
			result.M41 = num26 * num27;
			result.M12 = -(num2 * num17 - num3 * num18 + num4 * num19) * num27;
			result.M22 = (num1 * num17 - num3 * num20 + num4 * num21) * num27;
			result.M32 = -(num1 * num18 - num2 * num20 + num4 * num22) * num27;
			result.M42 = (num1 * num19 - num2 * num21 + num3 * num22) * num27;
			const float num28 = (num7 * num16 - num8 * num15);
			const float num29 = (num6 * num16 - num8 * num14);
			const float num30 = (num6 * num15 - num7 * num14);
			const float num31 = (num5 * num16 - num8 * num13);
			const float num32 = (num5 * num15 - num7 * num13);
			const float num33 = (num5 * num14 - num6 * num13);
			result.M13 = (num2 * num28 - num3 * num29 + num4 * num30) * num27;
			result.M23 = -(num1 * num28 - num3 * num31 + num4 * num32) * num27;
			result.M33 = (num1 * num29 - num2 * num31 + num4 * num33) * num27;
			result.M43 = -(num1 * num30 - num2 * num32 + num3 * num33) * num27;
			const float num34 = (num7 * num12 - num8 * num11);
			const float num35 = (num6 * num12 - num8 * num10);
			const float num36 = (num6 * num11 - num7 * num10);
			const float num37 = (num5 * num12 - num8 * num9);
			const float num38 = (num5 * num11 - num7 * num9);
			const float num39 = (num5 * num10 - num6 * num9);
			result.M14 = -(num2 * num34 - num3 * num35 + num4 * num36) * num27;
			result.M24 = (num1 * num34 - num3 * num37 + num4 * num38) * num27;
			result.M34 = -(num1 * num35 - num2 * num37 + num4 * num39) * num27;
			result.M44 = (num1 * num36 - num2 * num38 + num3 * num39) * num27;

			return result;
		}

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

		static Matrix CreateOrthographic(float width, float height, float zNear, float zFar)
		{
			return CreateOrthographicOffCenter((-width / 2.0), width / 2.0f,
				(-height / 2.0f), height / 2.0f, zNear, zFar);
		}

		static Matrix CreateOrthographicOffCenter(float left, float right, float bottom, float top, float zNear, float zFar)
		{
			Matrix result = Matrix();
			const float num1 = (1.0f / (right - left));
			const float num2 = (1.0f / (top - bottom));
			const float num3 = (1.0f / (zFar - zNear));
			result.M11 = 2.0f * num1;
			result.M22 = 2.0f * num2;
			result.M33 = -2.0f * num3;
			result.M41 = -(right + left) * num1;
			result.M42 = -(top + bottom) * num2;
			result.M43 = -(zFar + zNear) * num3;
			return result;
		}

		//Operators

		Matrix operator+(Matrix b) const
		{
			Matrix ret = Identity();
			ret.M11 = M11 + b.M11;
			ret.M12 = M12 + b.M12;
			ret.M13 = M13 + b.M13;
			ret.M14 = M14 + b.M14;
			ret.M21 = M21 + b.M21;
			ret.M22 = M22 + b.M22;
			ret.M23 = M23 + b.M23;
			ret.M24 = M24 + b.M24;
			ret.M31 = M31 + b.M31;
			ret.M32 = M32 + b.M32;
			ret.M33 = M33 + b.M33;
			ret.M34 = M34 + b.M34;
			ret.M41 = M41 + b.M41;
			ret.M42 = M42 + b.M42;
			ret.M43 = M43 + b.M43;
			ret.M44 = M44 + b.M44;

			return ret;
		}

		Matrix operator-(Matrix b) const
		{
			Matrix ret = Identity();
			ret.M11 = M11 - b.M11;
			ret.M12 = M12 - b.M12;
			ret.M13 = M13 - b.M13;
			ret.M14 = M14 - b.M14;
			ret.M21 = M21 - b.M21;
			ret.M22 = M22 - b.M22;
			ret.M23 = M23 - b.M23;
			ret.M24 = M24 - b.M24;
			ret.M31 = M31 - b.M31;
			ret.M32 = M32 - b.M32;
			ret.M33 = M33 - b.M33;
			ret.M34 = M34 - b.M34;
			ret.M41 = M41 - b.M41;
			ret.M42 = M42 - b.M42;
			ret.M43 = M43 - b.M43;
			ret.M44 = M44 - b.M44;

			return ret;
		}

		Matrix operator/(Matrix b) const
		{
			return *(this) * Invert(b);
		}

		Matrix operator/(int b) const
		{
			return (*this) * (1 / b);
		}

		Matrix operator/(float b) const
		{
			return (*this) * (1.0f / b);
		}

		Matrix operator*(Matrix b) const
		{
			Matrix result = Matrix();

			result.M11 = (((M11 * b.M11) + (M12 * b.M21)) + (M13 * b.M31)) + (M14 * b.M41);
			result.M12 = (((M11 * b.M12) + (M12 * b.M22)) + (M13 * b.M32)) + (M14 * b.M42);
			result.M13 = (((M11 * b.M13) + (M12 * b.M23)) + (M13 * b.M33)) + (M14 * b.M43);
			result.M14 = (((M11 * b.M14) + (M12 * b.M24)) + (M13 * b.M34)) + (M14 * b.M44);
			result.M21 = (((M21 * b.M11) + (M22 * b.M21)) + (M23 * b.M31)) + (M24 * b.M41);
			result.M22 = (((M21 * b.M12) + (M22 * b.M22)) + (M23 * b.M32)) + (M24 * b.M42);
			result.M23 = (((M21 * b.M13) + (M22 * b.M23)) + (M23 * b.M33)) + (M24 * b.M43);
			result.M24 = (((M21 * b.M14) + (M22 * b.M24)) + (M23 * b.M34)) + (M24 * b.M44);
			result.M31 = (((M31 * b.M11) + (M32 * b.M21)) + (M33 * b.M31)) + (M34 * b.M41);
			result.M32 = (((M31 * b.M12) + (M32 * b.M22)) + (M33 * b.M32)) + (M34 * b.M42);
			result.M33 = (((M31 * b.M13) + (M32 * b.M23)) + (M33 * b.M33)) + (M34 * b.M43);
			result.M34 = (((M31 * b.M14) + (M32 * b.M24)) + (M33 * b.M34)) + (M34 * b.M44);
			result.M41 = (((M41 * b.M11) + (M42 * b.M21)) + (M43 * b.M31)) + (M44 * b.M41);
			result.M42 = (((M41 * b.M12) + (M42 * b.M22)) + (M43 * b.M32)) + (M44 * b.M42);
			result.M43 = (((M41 * b.M13) + (M42 * b.M23)) + (M43 * b.M33)) + (M44 * b.M43);
			result.M44 = (((M41 * b.M14) + (M42 * b.M24)) + (M43 * b.M34)) + (M44 * b.M44);

			return result;
		}

		Matrix operator*(int b) const
		{
			Matrix result = Matrix();

			result.M11 = M11 * b;
			result.M12 = M12 * b;
			result.M13 = M13 * b;
			result.M14 = M14 * b;
			result.M21 = M21 * b;
			result.M22 = M22 * b;
			result.M23 = M23 * b;
			result.M24 = M24 * b;
			result.M31 = M31 * b;
			result.M32 = M32 * b;
			result.M33 = M33 * b;
			result.M34 = M34 * b;
			result.M41 = M41 * b;
			result.M42 = M42 * b;
			result.M43 = M43 * b;
			result.M44 = M44 * b;

			return result;
		}

		Matrix operator*(float b) const
		{
			Matrix result = Matrix();

			result.M11 = M11 * b;
			result.M12 = M12 * b;
			result.M13 = M13 * b;
			result.M14 = M14 * b;
			result.M21 = M21 * b;
			result.M22 = M22 * b;
			result.M23 = M23 * b;
			result.M24 = M24 * b;
			result.M31 = M31 * b;
			result.M32 = M32 * b;
			result.M33 = M33 * b;
			result.M34 = M34 * b;
			result.M41 = M41 * b;
			result.M42 = M42 * b;
			result.M43 = M43 * b;
			result.M44 = M44 * b;

			return result;
		}
	};
}

#endif