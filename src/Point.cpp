//
// Created by Reece Mackie on 13/11/18.
//

#include "Inferno/Point.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    //Constructors
    
    Point::Point(int x, int y) : x(x), y(y) {}
    
    Point::Point(int value) : x(value), y(value) {}
    
    //Methods
    
    Vector2 Point::to_vector() {
        return {(float) x, (float) y};
    }
    
    //Operators
    
    Point Point::operator+(Point b) {
        return {x + b.x, y + b.y};
    }
    
    Point Point::operator+(int b) {
        return {x + b, y + b};
    }
    
    Point Point::operator-(Point b) {
        return {x - b.x, y - b.y};
    }
    
    Point Point::operator-(int b) {
        return {x - b, y - b};
    }
    
    Point Point::operator*(Point b) {
        return {x * b.x, y * b.y};
    }
    
    Point Point::operator*(int b) {
        return {x * b, y * b};
    }
    
    Point Point::operator/(Point b) {
        return {x / b.x, y / b.y};
    }
    
    Point Point::operator/(int b) {
        return {x / b, y / b};
    }
    
    Point Point::operator-() {
        return {-x, -y};
    }
    
    bool Point::operator==(Point b) {
        return (x == b.x && y == b.y);
    }
    
    bool Point::operator!=(Inferno::Point b) {
        return !(*this == b);
    }
}