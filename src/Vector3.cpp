//
// Created by Reece Mackie on 13/11/18.
//

#include <cmath>

#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"

namespace Inferno {
    //Constructors
    
    Vector3::Vector3() : x(0), y(0), z(0) {}
    
    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    Vector3::Vector3(Inferno::Vector2 value, float z) : x(value.x), y(value.y), z(z) {}
    
    Vector3::Vector3(float value) : x(value), y(value), z(value) {}
    
    //Static Methods
    
    Vector3 Vector3::transform(Vector3 vector, Matrix matrix) {
        return {(vector.x * matrix.m11) + (vector.y * matrix.m21) + (vector.z * matrix.m31) + matrix.m41,
                (vector.x * matrix.m12) + (vector.y * matrix.m22) + (vector.z * matrix.m32) + matrix.m42,
                (vector.x * matrix.m13) + (vector.y * matrix.m23) + (vector.z * matrix.m33) + matrix.m43};
    }
    
    //Methods
    
    float Vector3::get_magnitude() {
        return sqrtf((x * x) + (y * y) + (z * z));
    }
    
    float Vector3::get_magnitude_squared() {
        return get_magnitude() * get_magnitude();
    }
    
    float Vector3::dot(Inferno::Vector3 b) {
        return (x * b.x) + (y * b.y) + (z * b.z);
    }
    
    float Vector3::distance(Inferno::Vector3 b) {
        return sqrtf((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y) + (z - b.z) * (z - b.z));
    }
    
    //Operators
    
    Vector3 Vector3::operator+(Vector3 b) {
        return {x + b.x, y + b.y, z + b.z};
    }
    
    Vector3 Vector3::operator+(int b) {
        return {x + b, y + b, z + b};
    }
    
    Vector3 Vector3::operator+(float b) {
        return {x + b, y + b, z + b};
    }
    
    Vector3 Vector3::operator-(Vector3 b) {
        return {x - b.x, y - b.y, z - b.z};
    }
    
    Vector3 Vector3::operator-(int b) {
        return {x - b, y - b, z - b};
    }
    
    Vector3 Vector3::operator-(float b) {
        return {x - b, y - b, z - b};
    }
    
    Vector3 Vector3::operator*(Vector3 b) {
        return {x * b.x, y * b.y, z * b.z};
    }
    
    Vector3 Vector3::operator*(int b) {
        return {x * b, y * b, z * b};
    }
    
    Vector3 Vector3::operator*(float b) {
        return {x * b, y * b, z * b};
    }
    
    Vector3 Vector3::operator/(Vector3 b) {
        return {x / b.x, y / b.y, z / b.z};
    }
    
    Vector3 Vector3::operator/(int b) {
        return {x / b, y / b, z / b};
    }
    
    Vector3 Vector3::operator/(float b) {
        return {x / b, y / b, z / b};
    }
    
    bool Vector3::operator==(Vector3 b) {
        return (x == b.x && y == b.y && z == b.z);
    }
}