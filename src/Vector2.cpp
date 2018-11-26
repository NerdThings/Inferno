//
// Created by Reece Mackie on 13/11/18.
//

#include <cmath>

#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    //Static Constants
    
    const Vector2 Vector2::zero = Vector2(0, 0);
    const Vector2 Vector2::unit_x = Vector2(1, 0);
    const Vector2 Vector2::unit_y = Vector2(0, 1);
    
    //Constructors
    
    Vector2::Vector2() : x(0), y(0) {}
    
    Vector2::Vector2(float x, float y) : x(x), y(y) {}
    
    Vector2::Vector2(float value) : x(value), y(value) {}
    
    //Static Methods
    
    Vector2 Vector2::transform(Vector2 vector, Matrix matrix) {
       return {(vector.x * matrix.m11) + (vector.y * matrix.m21) + matrix.m41,
                (vector.x * matrix.m12) + (vector.y * matrix.m22) + matrix.m42};
    }
    
    //Methods
    
    float Vector2::get_magnitude() {
        return sqrtf((x * x) + (y * y));
    }
    
    float Vector2::get_magnitude_squared() {
        return get_magnitude() * get_magnitude();
    }
    
    float Vector2::dot(Inferno::Vector2 b) {
        return (x * b.x) + (y * b.y);
    }
    
    float Vector2::distance(Inferno::Vector2 b) {
        return sqrtf((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
    
    //Operators
    
    Vector2 Vector2::operator+(Vector2 b) {
        return {x + b.x, y + b.y};
    }
    
    Vector2 Vector2::operator+(int b) {
        return {x + b, y + b};
    }
    
    Vector2 Vector2::operator+(float b) {
        return {x + b, y + b};
    }
    
    Vector2 Vector2::operator-(Vector2 b) {
        return {x - b.x, y - b.y};
    }
    
    Vector2 Vector2::operator-(int b) {
        return {x - b, y - b};
    }
    
    Vector2 Vector2::operator-(float b) {
        return {x - b, y - b};
    }
    
    Vector2 Vector2::operator*(Vector2 b) {
        return {x * b.x, y * b.y};
    }
    
    Vector2 Vector2::operator*(int b) {
        return {x * b, y * b};
    }
    
    Vector2 Vector2::operator*(float b) {
        return {x * b, y * b};
    }
    
    Vector2 Vector2::operator/(Vector2 b) {
        return {x / b.x, y / b.y};
    }
    
    Vector2 Vector2::operator/(int b) {
        return {x / b, y / b};
    }
    
    Vector2 Vector2::operator/(float b) {
        return {x / b, y / b};
    }
    
    Vector2 Vector2::operator-() {
        return {-x, -y};
    }
    
    bool Vector2::operator==(Vector2 b) {
        return (x == b.x && y == b.y);
    }
    
    bool Vector2::operator!=(Inferno::Vector2 b) {
        return !(*this == b);
    }
}