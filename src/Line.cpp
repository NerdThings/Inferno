//
// Created by Reece Mackie on 13/12/18.
//

#include "Inferno/Line.h"

namespace Inferno {
    //Constructors
    
    Line::Line() = default;
    
    Line::Line(Vector2 p1, Vector2 p2) : p1(p1), p2(p2) {}
    
    //Methods
    
    float Line::gradient() {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
    
    bool Line::intersects(Line b) {
        //Dont really understand this stuffs
        float denom = ((b.p2.y - b.p1.y) * (p2.x - p1.x)) - ((b.p2.x - b.p1.x) * (p2.y - p1.y));
        if (denom == 0) return false;
        float ua = (((b.p2.x - b.p1.x) * (p1.y - b.p1.y)) -
                   ((b.p2.y - b.p1.y) * (p1.x - b.p1.x))) / denom;
        float ub = (((p2.x - p1.x) * (p1.y - b.p1.y)) -
                   ((p2.y - p1.y) * (p1.x - b.p1.x))) / denom;
        return !(ua < 0 || ua > 1 || ub < 0 || ub > 1);
    }
    
    //Operators
    
    bool Line::operator==(Inferno::Line b) {
        return p1 == b.p1 && p2 == b.p2;
    }
    
    bool Line::operator!=(Inferno::Line b) {
        return !(*this == b);
    }
}