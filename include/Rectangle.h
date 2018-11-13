//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_RECTANGLE_H
#define INFERNO_RECTANGLE_H

#include "Inferno.h"

namespace Inferno {
    struct Point;
    struct Vector2;
    
    struct INFERNO_API Rectangle {
        //Fields
        
        int x;
        int y;
        int width;
        int height;
        
        //Constructors
        
        Rectangle(int x, int y, int width, int height);
        Rectangle(Point position, Point size);
        
        //Methods
        
        bool contains(float x, float y);
        bool contains(int x, int y);
        bool contains(Point value);
        bool contains(Vector2 value);
        int get_bottom_coord();
        Point get_center();
        int get_left_coord();
        Point get_location();
        int get_right_coord();
        Point get_size();
        int get_top_coord();
        bool intersects(Rectangle b);
        bool touching(Rectangle b);
        bool touching_bottom(Rectangle b);
        bool touching_left(Rectangle b);
        bool touching_right(Rectangle b);
        bool touching_top(Rectangle b);
        
        //Operators
        
        /*
         * Do we need more of these???
         */
        
        bool operator==(Rectangle b);
        bool operator!=(Rectangle b);
    };
}

#endif //INFERNO_RECTANGLE_H
