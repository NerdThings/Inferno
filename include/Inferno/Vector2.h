//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_VECTOR2_H
#define INFERNO_VECTOR2_H

#include "Inferno.h"

namespace Inferno {
    struct Matrix;
    
    struct INFERNO_API Vector2 {
        //Static Constants
        
        static const Vector2 zero;
        static const Vector2 unit_x;
        static const Vector2 unit_y;
        
        //Fields
        
        float x;
        float y;
        
        //Constructors
        
        Vector2();
        Vector2(float x, float y);
        explicit Vector2(float value);
        
        //Static Methods
        
        static Vector2 transform(Vector2 vector, Matrix matrix);
        
        //Methods
        
        float get_magnitude();
        float get_magnitude_squared();
        float dot(Vector2 b);
        float distance(Vector2 b);
        
        //Operators
        
        Vector2 operator+(Vector2 b);
        Vector2 operator+(int b);
        Vector2 operator+(float b);
        Vector2 operator-(Vector2 b);
        Vector2 operator-(int b);
        Vector2 operator-(float b);
        Vector2 operator/(Vector2 b);
        Vector2 operator/(int b);
        Vector2 operator/(float b);
        Vector2 operator*(Vector2 b);
        Vector2 operator*(int b);
        Vector2 operator*(float b);
        Vector2 operator-();
        bool operator==(Vector2 b);
        bool operator!=(Vector2 b);
    };
}

#endif //INFERNO_VECTOR2_H
