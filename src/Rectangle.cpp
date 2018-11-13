//
// Created by Reece Mackie on 13/11/18.
//

#include "Point.h"
#include "Rectangle.h"
#include "Vector2.h"

namespace Inferno {
    //Constructors
    
    Rectangle::Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
    
    Rectangle::Rectangle(Inferno::Point position, Inferno::Point size) : x(position.x), y(position.y), width(size.x), height(size.x) {}
    
    //Methods
    
    bool Rectangle::contains(float x, float y) {
        return this->x <= x && x < this->x + this->width && this->y <= y && y < this->y + this->height;
    }
    
    bool Rectangle::contains(int x, int y) {
        return contains(float(x), float(y));
    }
    
    bool Rectangle::contains(Point value) {
        return contains(value.x, value.y);
    }
    
    bool Rectangle::contains(Vector2 value) {
        return contains(value.x, value.y);
    }
    
    int Rectangle::get_bottom_coord() {
        return y + height;
    }
    
    Point Rectangle::get_center() {
        return {x + width / 2, y + height / 2};
    }
    
    int Rectangle::get_left_coord() {
        return x;
    }
    
    Point Rectangle::get_location() {
        return {x, y};
    }
    
    int Rectangle::get_right_coord() {
        return x + width;
    }
    
    Point Rectangle::get_size() {
        return {width, height};
    }
    
    int Rectangle::get_top_coord() {
        return y;
    }
    
    bool Rectangle::intersects(Rectangle value) {
        return value.get_left_coord() < get_right_coord() &&
               get_left_coord() < value.get_right_coord() &&
               value.get_top_coord() < get_bottom_coord() &&
               get_top_coord() < value.get_bottom_coord();
    }
    
    bool Rectangle::touching(Rectangle b) {
        return touching_bottom(b) || touching_left(b) || touching_right(b) || touching_left(b);
    }
    
    bool Rectangle::touching_bottom(Rectangle b) {
        return get_top_coord() < b.get_bottom_coord() &&
               get_bottom_coord() > b.get_bottom_coord() &&
               get_right_coord() > b.get_left_coord() &&
               get_left_coord() < b.get_right_coord();
    }
    
    bool Rectangle::touching_left(Rectangle b) {
        return get_right_coord() > b.get_left_coord() &&
               get_left_coord() < b.get_left_coord() &&
               get_bottom_coord() > b.get_top_coord() &&
               get_top_coord() < b.get_bottom_coord();
    }
    
    bool Rectangle::touching_right(Rectangle b) {
        return get_left_coord() < b.get_right_coord() &&
               get_right_coord() > b.get_right_coord() &&
               get_bottom_coord() > b.get_top_coord() &&
               get_top_coord() < b.get_bottom_coord();
    }
    
    bool Rectangle::touching_top(Rectangle b) {
        return get_bottom_coord() > b.get_top_coord() &&
               get_top_coord() < b.get_top_coord() &&
               get_right_coord() > b.get_left_coord() &&
               get_left_coord() < b.get_right_coord();
    }
    
    //Operators
    
    bool Rectangle::operator==(Inferno::Rectangle b) {
        return (x == b.x &&
                y == b.y &&
                width == b.width &&
                height == b.height);
    }
    
    bool Rectangle::operator!=(Inferno::Rectangle b) {
        return !(*this == b);
    }
}