#include "Vector2.h"
#include <cmath>

namespace Inferno {
    //Constants
    const Vector2 Vector2::zero = Vector2(0, 0);
    const Vector2 Vector2::unit_x = Vector2(1, 0);
    const Vector2 Vector2::unit_y = Vector2(0, 1);

    //Constructors

    Vector2::Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector2::Vector2(float value) {
        this->x = value;
        this->y = value;
    }

    //Get functions

    float Vector2::get_magnitude() const {
        return sqrtf((x * x) + (y * y));
    }

    float Vector2::get_magnitude_squared() const {
        return get_magnitude() * get_magnitude();
    }

    float Vector2::dot(Vector2 b) const {
        return (x * b.x) + (y * b.y);
    }

    float Vector2::distance(Vector2 b) const {
        return sqrtf((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }

    //Operators

    //TODO: Improve these

    Vector2 Vector2::operator+(Vector2 b) const {
        return {x + b.x, y + b.y};
    }

    Vector2 Vector2::operator+(int b) const {
        return {x + b, y + b};
    }

    Vector2 Vector2::operator+(float b) const {
        return {x + b, y + b};
    }

    Vector2 Vector2::operator-(Vector2 b) const {
        return {x - b.x, y - b.y};
    }

    Vector2 Vector2::operator-(int b) const {
        return {x - b, y - b};
    }

    Vector2 Vector2::operator-(float b) const {
        return {x - b, y - b};
    }

    Vector2 Vector2::operator*(Vector2 b) const {
        return {x * b.x, y * b.y};
    }

    Vector2 Vector2::operator*(int b) const {
        return {x * b, y * b};
    }

    Vector2 Vector2::operator*(float b) const {
        return {x * b, y * b};
    }

    Vector2 Vector2::operator/(Vector2 b) const {
        return {x / b.x, y / b.y};
    }

    Vector2 Vector2::operator/(int b) const {
        return {x / b, y / b};
    }

    Vector2 Vector2::operator/(float b) const {
        return {x / b, y / b};
    }

    bool Vector2::operator==(Vector2 b) const {
        return (x == b.x && y == b.y);
    }

    //TODO: Matrix transform
}