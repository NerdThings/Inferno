//
// Created by Reece Mackie on 12/12/18.
//

#include <cmath>

#include "Inferno/MathHelper.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Circle.h"

namespace Inferno {
    //Constructors
    
    Circle::Circle() : centre(Vector2()), radius(0) {}
    
    Circle::Circle(Inferno::Vector2 centre, float radius) : centre(centre), radius(radius) {}
    
    //Methods
    
    bool Circle::contains(Inferno::Vector2 point) {
        float distance = centre.distance(point);
        return distance <= radius;
    }
    
    bool Circle::intersects(Inferno::Circle b) {
        float distance = centre.distance(b.centre);
        return distance <= radius + b.radius;
    }
    
    bool Circle::intersects(Inferno::Rectangle b) {
        //TODO
        return false;
    }
    
    //Operators
    
    bool Circle::operator==(Circle b){
        return radius == b.radius && centre == b.centre;
    }
    
    bool Circle::operator!=(Circle b){
        return !(*this == b);
    }
}