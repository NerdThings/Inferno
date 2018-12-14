//
// Created by Reece Mackie on 13/12/18.
//

#include <cmath>

#include "Inferno/Line.h"
#include "Inferno/MathHelper.h"

namespace Inferno {
    //Constructors
    
    Line::Line() = default;
    
    Line::Line(Vector2 p1, Vector2 p2) : p1(p1), p2(p2) {}
    
    //Methods
    
    float Line::gradient() {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
    
    bool sameSign(float a, float b) {
        return MathHelper::sign(a) == MathHelper::sign(b);
    }
    
    bool Line::intersects(Line b) {
        float x1 = p1.x;
        float y1 = p1.y;
        float x2 = p2.x;
        float y2 = p2.y;
        float x3 = b.p1.x;
        float y3 = b.p1.y;
        float x4 = b.p2.x;
        float y4 = b.p2.y;
        
        float ua = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
        float ub = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);
        
        float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
        
        if (fabsf(denom) <= 0.00001f) {
            if (fabsf(ua) <= 0.00001f && fabsf(ub) <= 0.00001f) {
                return true;
            }
        } else {
            ua /= denom;
            ub /= denom;
            
            if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1)
                return true;
        }
        
        return false;
    }
    
    //Operators
    
    bool Line::operator==(Inferno::Line b) {
        return p1 == b.p1 && p2 == b.p2;
    }
    
    bool Line::operator!=(Inferno::Line b) {
        return !(*this == b);
    }
}