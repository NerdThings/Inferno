//
// Created by Reece Mackie on 13/11/18.
//

#include <cmath>

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Inferno {
    //Constructors
    
    Vector4::Vector4() : x(0), y(0), z(0), w(0) {}
    
    Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    
    Vector4::Vector4(Vector2 value, float z, float w) : x(value.x), y(value.y), z(z), w(w) {}
    
    Vector4::Vector4(Vector3 value, float w) : x(value.x), y(value.y), z(value.z), w(w) {}
    
    Vector4::Vector4(float value) : x(value), y(value), z(value), w(value) {}
    
    //Methods
    
    float Vector4::get_magnitude() {
        return sqrtf((x * x) + (y * y) + (z * z));
    }
    
    float Vector4::get_magnitude_squared() {
        return get_magnitude() * get_magnitude();
    }
    
    float Vector4::dot(Vector4 b) {
        return (x * b.x) + (y * b.y) + (z * b.z);
    }
    
    float Vector4::distance(Vector4 b) {
        return sqrtf((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y) + (z - b.z) * (z - b.z));
    }
    
    //Operators
    
    Vector4 Vector4::operator+(Vector4 b) {
        return {x + b.x, y + b.y, z + b.z, w + b.w};
    }
    
    Vector4 Vector4::operator+(int b) {
        return {x + b, y + b, z + b, w + b};
    }
    
    Vector4 Vector4::operator+(float b) {
        return {x + b, y + b, z + b, w + b};
    }
    
    Vector4 Vector4::operator-(Vector4 b) {
        return {x - b.x, y - b.y, z - b.z, w - b.w};
    }
    
    Vector4 Vector4::operator-(int b) {
        return {x - b, y - b, z - b, w - b};
    }
    
    Vector4 Vector4::operator-(float b) {
        return {x - b, y - b, z - b, w - b};
    }
    
    Vector4 Vector4::operator*(Vector4 b) {
        return {x * b.x, y * b.y, z * b.z, w * b.w};
    }
    
    Vector4 Vector4::operator*(int b) {
        return {x * b, y * b, z * b, w * b};
    }
    
    Vector4 Vector4::operator*(float b) {
        return {x * b, y * b, z * b, w * b};
    }
    
    Vector4 Vector4::operator/(Vector4 b) {
        return {x / b.x, y / b.y, z / b.z, w / b.w};
    }
    
    Vector4 Vector4::operator/(int b) {
        return {x / b, y / b, z / b, w / b};
    }
    
    Vector4 Vector4::operator/(float b) {
        return {x / b, y / b, z / b, w / b};
    }
    
    Vector4 Vector4::operator-() {
        return {-x, -y, -z, -w};
    }
    
    bool Vector4::operator==(Vector4 b) {
        return (x == b.x && y == b.y && z == b.z && w == b.w);
    }
    
    bool Vector4::operator!=(Vector4 b) {
        return !(*this == b);
    }
}
