#include <cmath>

#include "Matrix.h"
#include "Vector3.h"

namespace Inferno {
//Constants
	Matrix Matrix::identity = Matrix();

    //Constructors

	Matrix::Matrix() {
		m11 = 1;
		m12 = 0;
		m13 = 0;
		m14 = 0;
		m21 = 0;
		m22 = 1;
		m23 = 0;
		m24 = 0;
		m31 = 0;
		m32 = 0;
		m33 = 1;
		m34 = 0;
		m41 = 0;
		m42 = 0;
		m43 = 0;
		m44 = 1;
		
		this->initialised = true;
	}

	Matrix::Matrix(float m11, float m12, float m13, float m14,
				   float m21, float m22, float m23, float m24,
				   float m31, float m32, float m33, float m34,
				   float m41, float m42, float m43, float m44) {
		this->m11 = m11;
		this->m12 = m12;
		this->m13 = m13;
		this->m14 = m14;
		this->m21 = m21;
		this->m22 = m22;
		this->m23 = m23;
		this->m24 = m24;
		this->m31 = m31;
		this->m32 = m32;
		this->m33 = m33;
		this->m34 = m34;
		this->m41 = m41;
		this->m42 = m42;
		this->m43 = m43;
		this->m44 = m44;
		
		this->initialised = true;
	}

    //Methods

	Matrix Matrix::create_orthographic(float width, float height, float zNear, float zFar) {
		return create_orthographic_off_center((-width / 2.0), width / 2.0f,
											  (-height / 2.0f), height / 2.0f, zNear, zFar);
	}

	Matrix Matrix::create_orthographic_off_center(float left, float right, float bottom, float top, float zNear, float zFar) {
		Matrix result = Matrix();
		const float num1 = (1.0f / (right - left));
		const float num2 = (1.0f / (top - bottom));
		const float num3 = (1.0f / (zFar - zNear));
		result.m11 = 2.0f * num1;
		result.m22 = 2.0f * num2;
		result.m33 = -2.0f * num3;
		result.m41 = -(right + left) * num1;
		result.m42 = -(top + bottom) * num2;
		result.m43 = -(zFar + zNear) * num3;
		return result;
	}
	
	Matrix Matrix::create_rotation_x(float radians) {
		Matrix result = identity;
		
		float val1 = cosf(radians);
		float val2 = sinf(radians);
		
		result.m22 = val1;
		result.m23 = val2;
		result.m32 = -val2;
		result.m33 = val1;
		
		return result;
	}
	
	Matrix Matrix::create_rotation_y(float radians) {
        Matrix result = identity;
        
        float val1 = cosf(radians);
        float val2 = sinf(radians);
        
        result.m22 = val1;
        result.m23 = -val2;
        result.m32 = val2;
        result.m33 = val1;
        
        return result;
	}
	
	Matrix Matrix::create_rotation_z(float radians) {
        Matrix result = identity;
        
        float val1 = cosf(radians);
        float val2 = sinf(radians);
        
        result.m22 = val1;
        result.m23 = val2;
        result.m32 = -val2;
        result.m33 = val1;
        
        return result;
	}
	
	Matrix Matrix::create_scale(float scale){
	    return create_scale(scale, scale, scale);
	}
	
	Matrix Matrix::create_scale(Vector3 scale) {
	    return create_scale(scale.x, scale.y, scale.z);
	}
	
	Matrix Matrix::create_scale(float x_scale, float y_scale, float z_scale) {
	    return {x_scale, 0, 0, 0,
                0, y_scale, 0, 0,
                0, 0, z_scale, 0,
                0, 0, 0, 1};
	}
	
	Matrix Matrix::create_translation(Vector3 position) {
	    return create_translation(position.x, position.y, position.z);
	}
	
	Matrix Matrix::create_translation(float x_pos, float y_pos, float z_pos) {
	    return {1, 0, 0, 0,
	            0, 1, 0, 0,
	            0, 0, 1, 0,
	            x_pos, y_pos, z_pos, 1};
	}

	float *Matrix::get_array() const {
		float *array = new float[16];

		array[0] = m11;
		array[1] = m12;
		array[2] = m13;
		array[3] = m14;
		array[4] = m21;
		array[5] = m22;
		array[6] = m23;
		array[7] = m24;
		array[8] = m31;
		array[9] = m32;
		array[10] = m33;
		array[11] = m34;
		array[12] = m41;
		array[13] = m42;
		array[14] = m43;
		array[15] = m44;

		return array;
	}

	Vector3 Matrix::get_backward_vector() const {
		return  Vector3(m31, m32, m33);
	}

	Vector3 Matrix::get_down_vector() const {
		return  Vector3(-m21, -m22, -m23);
	}

	Vector3 Matrix::get_forward_vector() const {
		return  Vector3(-m31, -m32, -m33);
	}

	Vector3 Matrix::get_left_vector() const {
		return  Vector3(-m11, -m12, -m13);
	}

	Vector3 Matrix::get_right_vector() const {
		return  Vector3(m11, m12, m13);
	}

	Vector3 Matrix::get_scale_vector() const {
		return Vector3(m11, m22, m33);
	}

	Vector3 Matrix::get_translation_vector() const {
		return Vector3(m41, m32, m43);
	}

	Vector3 Matrix::get_up_vector() const {
		return Vector3(m21, m22, m23);
	}

	Matrix Matrix::invert(Matrix matrix) {
		Matrix result = Matrix();

		const float num17 = matrix.m33 * matrix.m44 - matrix.m34 * matrix.m43;
		const float num18 = matrix.m32 * matrix.m44 - matrix.m34 * matrix.m42;
		const float num19 = matrix.m32 * matrix.m43 - matrix.m33 * matrix.m42;
		const float num20 = matrix.m31 * matrix.m44 - matrix.m34 * matrix.m41;
		const float num21 = matrix.m31 * matrix.m43 - matrix.m33 * matrix.m41;
		const float num22 = matrix.m31 * matrix.m42 - matrix.m32 * matrix.m41;
		const float num23 = matrix.m22 * num17 - matrix.m23 * num18 + matrix.m24 * num19;
		const float num24 = -(matrix.m21 * num17 - matrix.m23 * num20 + matrix.m24 * num21);
		const float num25 = matrix.m21 * num18 - matrix.m22 * num20 + matrix.m24 * num22;
		const float num26 = -(matrix.m21 * num19 - matrix.m22 * num21 + matrix.m23 * num22);
		const float num27 = (1.0f / (matrix.m11 * num23 + matrix.m12 * num24 + matrix.m13 * num25 + matrix.m14 * num26));

		result.m11 = num23 * num27;
		result.m21 = num24 * num27;
		result.m31 = num25 * num27;
		result.m41 = num26 * num27;
		result.m12 = -(matrix.m12 * num17 - matrix.m13 * num18 + matrix.m14 * num19) * num27;
		result.m22 = (matrix.m11 * num17 - matrix.m13 * num20 + matrix.m14 * num21) * num27;
		result.m32 = -(matrix.m11 * num18 - matrix.m12 * num20 + matrix.m14 * num22) * num27;
		result.m42 = (matrix.m11 * num19 - matrix.m12 * num21 + matrix.m13 * num22) * num27;
		const float num28 = (matrix.m23 * matrix.m44 - matrix.m24 * matrix.m43);
		const float num29 = (matrix.m22 * matrix.m44 - matrix.m24 * matrix.m42);
		const float num30 = (matrix.m22 * matrix.m43 - matrix.m23 * matrix.m42);
		const float num31 = (matrix.m21 * matrix.m44 - matrix.m24 * matrix.m41);
		const float num32 = (matrix.m21 * matrix.m43 - matrix.m23 * matrix.m41);
		const float num33 = (matrix.m21 * matrix.m42 - matrix.m22 * matrix.m41);
		result.m13 = (matrix.m12 * num28 - matrix.m13 * num29 + matrix.m14 * num30) * num27;
		result.m23 = -(matrix.m11 * num28 - matrix.m13 * num31 + matrix.m14 * num32) * num27;
		result.m33 = (matrix.m11 * num29 - matrix.m12 * num31 + matrix.m14 * num33) * num27;
		result.m43 = -(matrix.m11 * num30 - matrix.m12 * num32 + matrix.m13 * num33) * num27;
		const float num34 = (matrix.m23 * matrix.m34 - matrix.m24 * matrix.m33);
		const float num35 = (matrix.m22 * matrix.m34 - matrix.m24 * matrix.m32);
		const float num36 = (matrix.m22 * matrix.m33 - matrix.m23 * matrix.m32);
		const float num37 = (matrix.m21 * matrix.m34 - matrix.m24 * matrix.m31);
		const float num38 = (matrix.m21 * matrix.m33 - matrix.m23 * matrix.m31);
		const float num39 = (matrix.m21 * matrix.m32 - matrix.m22 * matrix.m31);
		result.m14 = -(matrix.m12 * num34 - matrix.m13 * num35 + matrix.m14 * num36) * num27;
		result.m24 = (matrix.m11 * num34 - matrix.m13 * num37 + matrix.m14 * num38) * num27;
		result.m34 = -(matrix.m11 * num35 - matrix.m12 * num37 + matrix.m14 * num39) * num27;
		result.m44 = (matrix.m11 * num36 - matrix.m12 * num38 + matrix.m13 * num39) * num27;

		return result;
	}

    //Operators

	Matrix Matrix::operator+(Matrix b) const {
		Matrix ret = Matrix();
		ret.m11 = m11 + b.m11;
		ret.m12 = m12 + b.m12;
		ret.m13 = m13 + b.m13;
		ret.m14 = m14 + b.m14;
		ret.m21 = m21 + b.m21;
		ret.m22 = m22 + b.m22;
		ret.m23 = m23 + b.m23;
		ret.m24 = m24 + b.m24;
		ret.m31 = m31 + b.m31;
		ret.m32 = m32 + b.m32;
		ret.m33 = m33 + b.m33;
		ret.m34 = m34 + b.m34;
		ret.m41 = m41 + b.m41;
		ret.m42 = m42 + b.m42;
		ret.m43 = m43 + b.m43;
		ret.m44 = m44 + b.m44;

		return ret;
	}

	Matrix Matrix::operator-(Matrix b) const {
		Matrix ret = Matrix();
		ret.m11 = m11 - b.m11;
		ret.m12 = m12 - b.m12;
		ret.m13 = m13 - b.m13;
		ret.m14 = m14 - b.m14;
		ret.m21 = m21 - b.m21;
		ret.m22 = m22 - b.m22;
		ret.m23 = m23 - b.m23;
		ret.m24 = m24 - b.m24;
		ret.m31 = m31 - b.m31;
		ret.m32 = m32 - b.m32;
		ret.m33 = m33 - b.m33;
		ret.m34 = m34 - b.m34;
		ret.m41 = m41 - b.m41;
		ret.m42 = m42 - b.m42;
		ret.m43 = m43 - b.m43;
		ret.m44 = m44 - b.m44;

		return ret;
	}

	Matrix Matrix::operator/(Matrix b) const {
		return *(this) * invert(b);
	}

	Matrix Matrix::operator/(int b) const {
		return (*this) * (1 / b);
	}

	Matrix Matrix::operator/(float b) const {
		return (*this) * (1.0f / b);
	}

	Matrix Matrix::operator*(Matrix b) const {
		Matrix result = Matrix();

		result.m11 = (((m11 * b.m11) + (m12 * b.m21)) + (m13 * b.m31)) + (m14 * b.m41);
		result.m12 = (((m11 * b.m12) + (m12 * b.m22)) + (m13 * b.m32)) + (m14 * b.m42);
		result.m13 = (((m11 * b.m13) + (m12 * b.m23)) + (m13 * b.m33)) + (m14 * b.m43);
		result.m14 = (((m11 * b.m14) + (m12 * b.m24)) + (m13 * b.m34)) + (m14 * b.m44);
		result.m21 = (((m21 * b.m11) + (m22 * b.m21)) + (m23 * b.m31)) + (m24 * b.m41);
		result.m22 = (((m21 * b.m12) + (m22 * b.m22)) + (m23 * b.m32)) + (m24 * b.m42);
		result.m23 = (((m21 * b.m13) + (m22 * b.m23)) + (m23 * b.m33)) + (m24 * b.m43);
		result.m24 = (((m21 * b.m14) + (m22 * b.m24)) + (m23 * b.m34)) + (m24 * b.m44);
		result.m31 = (((m31 * b.m11) + (m32 * b.m21)) + (m33 * b.m31)) + (m34 * b.m41);
		result.m32 = (((m31 * b.m12) + (m32 * b.m22)) + (m33 * b.m32)) + (m34 * b.m42);
		result.m33 = (((m31 * b.m13) + (m32 * b.m23)) + (m33 * b.m33)) + (m34 * b.m43);
		result.m34 = (((m31 * b.m14) + (m32 * b.m24)) + (m33 * b.m34)) + (m34 * b.m44);
		result.m41 = (((m41 * b.m11) + (m42 * b.m21)) + (m43 * b.m31)) + (m44 * b.m41);
		result.m42 = (((m41 * b.m12) + (m42 * b.m22)) + (m43 * b.m32)) + (m44 * b.m42);
		result.m43 = (((m41 * b.m13) + (m42 * b.m23)) + (m43 * b.m33)) + (m44 * b.m43);
		result.m44 = (((m41 * b.m14) + (m42 * b.m24)) + (m43 * b.m34)) + (m44 * b.m44);

		return result;
	}

	Matrix Matrix::operator*(int b) const {
		Matrix result = Matrix();

		result.m11 = m11 * b;
		result.m12 = m12 * b;
		result.m13 = m13 * b;
		result.m14 = m14 * b;
		result.m21 = m21 * b;
		result.m22 = m22 * b;
		result.m23 = m23 * b;
		result.m24 = m24 * b;
		result.m31 = m31 * b;
		result.m32 = m32 * b;
		result.m33 = m33 * b;
		result.m34 = m34 * b;
		result.m41 = m41 * b;
		result.m42 = m42 * b;
		result.m43 = m43 * b;
		result.m44 = m44 * b;

		return result;
	}

	Matrix Matrix::operator*(float b) const {
		Matrix result = Matrix();

		result.m11 = m11 * b;
		result.m12 = m12 * b;
		result.m13 = m13 * b;
		result.m14 = m14 * b;
		result.m21 = m21 * b;
		result.m22 = m22 * b;
		result.m23 = m23 * b;
		result.m24 = m24 * b;
		result.m31 = m31 * b;
		result.m32 = m32 * b;
		result.m33 = m33 * b;
		result.m34 = m34 * b;
		result.m41 = m41 * b;
		result.m42 = m42 * b;
		result.m43 = m43 * b;
		result.m44 = m44 * b;

		return result;
	}
}