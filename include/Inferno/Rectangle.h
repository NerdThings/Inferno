//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_RECTANGLE_H
#define INFERNO_RECTANGLE_H

#include "Inferno/Inferno.h"
#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"

namespace Inferno {
    struct Point;
    struct Vector2;
    
    struct INFERNO_API Rectangle {
    private:
        //Methods
        
        Matrix get_matrix(bool invert = false);
    public:
        //Fields
        
        float height;
        float rotation;
        Vector2 rotation_origin;
        float width;
        float x;
        float y;
        
        //Constructors
        
        Rectangle(float x, float y, float width, float height, float rotation = 0, Vector2 rotation_origin = Vector2());
        Rectangle(Vector2 position, Vector2 dimensions, float rotation = 0, Vector2 rotation_origin = Vector2());
        
        //Methods
        
        Vector2 bottom_left();
        Vector2 bottom_right();
        Vector2 center();
        bool contains(Vector2 point);
        bool intersects(Rectangle b);
        Vector2 top_left();
        Vector2 top_right();
        
        //Operators
        
        bool operator==(Rectangle b);
        bool operator!=(Rectangle b);
    };
}

#endif //INFERNO_RECTANGLE_H
