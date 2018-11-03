#include "Matrix.h"
#include "Vector3.h"

using namespace Inferno;

//Constants
Matrix* Matrix::Identity = new Matrix(1, 0, 0, 0,
											0, 1, 0, 0,
											0, 0, 1, 0,
											0, 0, 0, 1);

//Methods

Matrix* Matrix::CreateOrthographic(float width, float height, float zNear, float zFar)
{
	return CreateOrthographicOffCenter((-width / 2.0), width / 2.0f,
		(-height / 2.0f), height / 2.0f, zNear, zFar);
}

Matrix* Matrix::CreateOrthographicOffCenter(float left, float right, float bottom, float top, float zNear, float zFar)
{
	Matrix* result = new Matrix();
	const float num1 = (1.0f / (right - left));
	const float num2 = (1.0f / (top - bottom));
	const float num3 = (1.0f / (zFar - zNear));
	result->M11 = 2.0f * num1;
	result->M22 = 2.0f * num2;
	result->M33 = -2.0f * num3;
	result->M41 = -(right + left) * num1;
	result->M42 = -(top + bottom) * num2;
	result->M43 = -(zFar + zNear) * num3;
	return result;
}

float* Matrix::GetArray() const
{
	float* array = new float[16];

	array[0] = M11;
	array[1] = M12;
	array[2] = M13;
	array[3] = M14;
	array[4] = M21;
	array[5] = M22;
	array[6] = M23;
	array[7] = M24;
	array[8] = M31;
	array[9] = M32;
	array[10] = M33;
	array[11] = M34;
	array[12] = M41;
	array[13] = M42;
	array[14] = M43;
	array[15] = M44;

	return array;
}

Vector3* Matrix::GetBackwardVector() const
{
	return new Vector3(M31, M32, M33);
}

Vector3* Matrix::GetDownVector() const
{
	return new Vector3(-M21, -M22, -M23);
}

Vector3* Matrix::GetForwardVector() const
{
	return new Vector3(-M31, -M32, -M33);
}

Vector3* Matrix::GetLeftVector() const
{
	return new Vector3(-M11, -M12, -M13);
}

Vector3* Matrix::GetRightVector() const
{
	return new Vector3(M11, M12, M13);
}

Vector3* Matrix::GetScaleVector() const
{
	return new Vector3(M11, M22, M33);
}

Vector3* Matrix::GetTranslation() const
{
	return new Vector3(M41, M32, M43);
}

Vector3* Matrix::GetUpVector() const
{
	return new Vector3(M21, M22, M23);
}

Matrix* Matrix::Invert() const
{
	Matrix* result = new Matrix();

	const float num17 = M33 * M44 - M34 * M43;
	const float num18 = M32 * M44 - M34 * M42;
	const float num19 = M32 * M43 - M33 * M42;
	const float num20 = M31 * M44 - M34 * M41;
	const float num21 = M31 * M43 - M33 * M41;
	const float num22 = M31 * M42 - M32 * M41;
	const float num23 = M22 * num17 - M23 * num18 + M24 * num19;
	const float num24 = -(M21 * num17 - M23 * num20 + M24 * num21);
	const float num25 = M21 * num18 - M22 * num20 + M24 * num22;
	const float num26 = -(M21 * num19 - M22 * num21 + M23 * num22);
	const float num27 = (1.0f / (M11* num23 + M12 * num24 + M13 * num25 + M14 * num26));

	result->M11 = num23 * num27;
	result->M21 = num24 * num27;
	result->M31 = num25 * num27;
	result->M41 = num26 * num27;
	result->M12 = -(M12 * num17 - M13 * num18 + M14 * num19) * num27;
	result->M22 = (M11* num17 - M13 * num20 + M14 * num21) * num27;
	result->M32 = -(M11* num18 - M12 * num20 + M14 * num22) * num27;
	result->M42 = (M11* num19 - M12 * num21 + M13 * num22) * num27;
	const float num28 = (M23 * M44 - M24 * M43);
	const float num29 = (M22 * M44 - M24 * M42);
	const float num30 = (M22 * M43 - M23 * M42);
	const float num31 = (M21 * M44 - M24 * M41);
	const float num32 = (M21 * M43 - M23 * M41);
	const float num33 = (M21 * M42 - M22 * M41);
	result->M13 = (M12 * num28 - M13 * num29 + M14 * num30) * num27;
	result->M23 = -(M11* num28 - M13 * num31 + M14 * num32) * num27;
	result->M33 = (M11* num29 - M12 * num31 + M14 * num33) * num27;
	result->M43 = -(M11* num30 - M12 * num32 + M13 * num33) * num27;
	const float num34 = (M23 * M34 - M24 * M33);
	const float num35 = (M22 * M34 - M24 * M32);
	const float num36 = (M22 * M33 - M23 * M32);
	const float num37 = (M21 * M34 - M24 * M31);
	const float num38 = (M21 * M33 - M23 * M31);
	const float num39 = (M21 * M32 - M22 * M31);
	result->M14 = -(M12 * num34 - M13 * num35 + M14 * num36) * num27;
	result->M24 = (M11* num34 - M13 * num37 + M14 * num38) * num27;
	result->M34 = -(M11* num35 - M12 * num37 + M14 * num39) * num27;
	result->M44 = (M11* num36 - M12 * num38 + M13 * num39) * num27;

	return result;
}

//Operators

Matrix* Matrix::operator+(Matrix* b) const
{
	Matrix* ret = new Matrix();
	ret->M11 = M11 + b->M11;
	ret->M12 = M12 + b->M12;
	ret->M13 = M13 + b->M13;
	ret->M14 = M14 + b->M14;
	ret->M21 = M21 + b->M21;
	ret->M22 = M22 + b->M22;
	ret->M23 = M23 + b->M23;
	ret->M24 = M24 + b->M24;
	ret->M31 = M31 + b->M31;
	ret->M32 = M32 + b->M32;
	ret->M33 = M33 + b->M33;
	ret->M34 = M34 + b->M34;
	ret->M41 = M41 + b->M41;
	ret->M42 = M42 + b->M42;
	ret->M43 = M43 + b->M43;
	ret->M44 = M44 + b->M44;

	return ret;
}

Matrix* Matrix::operator-(Matrix* b) const
{
	Matrix* ret = new Matrix();
	ret->M11 = M11 - b->M11;
	ret->M12 = M12 - b->M12;
	ret->M13 = M13 - b->M13;
	ret->M14 = M14 - b->M14;
	ret->M21 = M21 - b->M21;
	ret->M22 = M22 - b->M22;
	ret->M23 = M23 - b->M23;
	ret->M24 = M24 - b->M24;
	ret->M31 = M31 - b->M31;
	ret->M32 = M32 - b->M32;
	ret->M33 = M33 - b->M33;
	ret->M34 = M34 - b->M34;
	ret->M41 = M41 - b->M41;
	ret->M42 = M42 - b->M42;
	ret->M43 = M43 - b->M43;
	ret->M44 = M44 - b->M44;

	return ret;
}

Matrix* Matrix::operator/(Matrix* b) const
{
	return *(this) * b->Invert();
}

Matrix* Matrix::operator/(int b) const
{
	return (*this) * (1 / b);
}

Matrix* Matrix::operator/(float b) const
{
	return (*this) * (1.0f / b);
}

Matrix* Matrix::operator*(Matrix* b) const
{
	Matrix* result = new Matrix();

	result->M11 = (((M11 * b->M11) + (M12 * b->M21)) + (M13 * b->M31)) + (M14 * b->M41);
	result->M12 = (((M11 * b->M12) + (M12 * b->M22)) + (M13 * b->M32)) + (M14 * b->M42);
	result->M13 = (((M11 * b->M13) + (M12 * b->M23)) + (M13 * b->M33)) + (M14 * b->M43);
	result->M14 = (((M11 * b->M14) + (M12 * b->M24)) + (M13 * b->M34)) + (M14 * b->M44);
	result->M21 = (((M21 * b->M11) + (M22 * b->M21)) + (M23 * b->M31)) + (M24 * b->M41);
	result->M22 = (((M21 * b->M12) + (M22 * b->M22)) + (M23 * b->M32)) + (M24 * b->M42);
	result->M23 = (((M21 * b->M13) + (M22 * b->M23)) + (M23 * b->M33)) + (M24 * b->M43);
	result->M24 = (((M21 * b->M14) + (M22 * b->M24)) + (M23 * b->M34)) + (M24 * b->M44);
	result->M31 = (((M31 * b->M11) + (M32 * b->M21)) + (M33 * b->M31)) + (M34 * b->M41);
	result->M32 = (((M31 * b->M12) + (M32 * b->M22)) + (M33 * b->M32)) + (M34 * b->M42);
	result->M33 = (((M31 * b->M13) + (M32 * b->M23)) + (M33 * b->M33)) + (M34 * b->M43);
	result->M34 = (((M31 * b->M14) + (M32 * b->M24)) + (M33 * b->M34)) + (M34 * b->M44);
	result->M41 = (((M41 * b->M11) + (M42 * b->M21)) + (M43 * b->M31)) + (M44 * b->M41);
	result->M42 = (((M41 * b->M12) + (M42 * b->M22)) + (M43 * b->M32)) + (M44 * b->M42);
	result->M43 = (((M41 * b->M13) + (M42 * b->M23)) + (M43 * b->M33)) + (M44 * b->M43);
	result->M44 = (((M41 * b->M14) + (M42 * b->M24)) + (M43 * b->M34)) + (M44 * b->M44);

	return result;
}

Matrix* Matrix::operator*(int b) const
{
	Matrix* result = new Matrix();

	result->M11 = M11 * b;
	result->M12 = M12 * b;
	result->M13 = M13 * b;
	result->M14 = M14 * b;
	result->M21 = M21 * b;
	result->M22 = M22 * b;
	result->M23 = M23 * b;
	result->M24 = M24 * b;
	result->M31 = M31 * b;
	result->M32 = M32 * b;
	result->M33 = M33 * b;
	result->M34 = M34 * b;
	result->M41 = M41 * b;
	result->M42 = M42 * b;
	result->M43 = M43 * b;
	result->M44 = M44 * b;

	return result;
}

Matrix* Matrix::operator*(float b) const
{
	Matrix* result = new Matrix();

	result->M11 = M11 * b;
	result->M12 = M12 * b;
	result->M13 = M13 * b;
	result->M14 = M14 * b;
	result->M21 = M21 * b;
	result->M22 = M22 * b;
	result->M23 = M23 * b;
	result->M24 = M24 * b;
	result->M31 = M31 * b;
	result->M32 = M32 * b;
	result->M33 = M33 * b;
	result->M34 = M34 * b;
	result->M41 = M41 * b;
	result->M42 = M42 * b;
	result->M43 = M43 * b;
	result->M44 = M44 * b;

	return result;
}