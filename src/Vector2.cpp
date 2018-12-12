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
    
    bool Vector2::intersects(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2) {
        //Needs testing properly
        float denominator = (a1.x - a2.x)*(b1.y - b2.y) - (a1.y - a2.y)*(b1.x, b2.x);
        return denominator != 0;
    
    }
    
    //Operators
    
    Vector2 Vector2::operator+(Vector2 b) {
        return {x + b.x, y + b.y};
    }
    
    Vector2 Vector2::operator+(float b) {
        return {x + b, y + b};
    }
    
    void Vector2::operator+=(Vector2 b) {
        x += b.x;
        y += b.y;
    }
    
    void Vector2::operator+=(float b) {
        x += b;
        y += b;
    }
    
    Vector2 Vector2::operator-(Vector2 b) {
        return {x - b.x, y - b.y};
    }
    
    Vector2 Vector2::operator-(float b) {
        return {x - b, y - b};
    }
    
    void Vector2::operator-=(Vector2 b) {
        x -= b.x;
        y -= b.y;
    }
    
    void Vector2::operator-=(float b) {
        x -= b;
        y -= b;
    }
    
    Vector2 Vector2::operator*(Vector2 b) {
        return {x * b.x, y * b.y};
    }
    
    Vector2 Vector2::operator*(float b) {
        return {x * b, y * b};
    }
    
    void Vector2::operator*=(Vector2 b) {
        x *= b.x;
        y *= b.y;
    }
    
    void Vector2::operator*=(float b) {
        x *= b;
        y *= b;
    }
    
    Vector2 Vector2::operator/(Vector2 b) {
        return {x / b.x, y / b.y};
    }
    
    Vector2 Vector2::operator/(float b) {
        return {x / b, y / b};
    }
    
    void Vector2::operator/=(Vector2 b) {
        x /= b.x;
        y /= b.y;
    }
    
    void Vector2::operator/=(float b) {
        x /= b;
        y /= b;
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