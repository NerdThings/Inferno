//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_POINT_H
#define INFERNO_POINT_H

#include "Inferno.h"

namespace Inferno {
    struct Vector2;
    
    struct INFERNO_API Point {
        //Fields
        
        int x;
        int y;
        
        //Constructors
        
        Point(int x, int y);
        Point(int value);
        
        //Methods
        
        Vector2 to_vector();
        
        //Operators
    
        Point operator+(Point b);
        Point operator+(int b);
        Point operator-(Point b);
        Point operator-(int b);
        Point operator*(Point b);
        Point operator*(int b);
        Point operator/(Point b);
        Point operator/(int b);
        Point operator-();
        bool operator==(Point b);
        bool operator!=(Point b);
    };
}

#endif //INFERNO_POINT_H
