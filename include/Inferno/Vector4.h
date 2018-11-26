//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_VECTOR4_H
#define INFERNO_VECTOR4_H

#include "Inferno.h"

namespace Inferno {
    struct Vector2;
    struct Vector3;
    
    struct INFERNO_API Vector4 {
        //Fields
    
        float x;
        float y;
        float z;
        float w;
    
        //Constructors
    
        Vector4();
        Vector4(float x, float y, float z, float w);
        Vector4(Vector2 value, float z, float w);
        Vector4(Vector3 value, float w);
        explicit Vector4(float value);
    
        //Methods
    
        float get_magnitude();
        float get_magnitude_squared();
        float dot(Vector4 b);
        float distance(Vector4 b);
    
        //Operators
    
        Vector4 operator+(Vector4 b);
        Vector4 operator+(int b);
        Vector4 operator+(float b);
        Vector4 operator-(Vector4 b);
        Vector4 operator-(int b);
        Vector4 operator-(float b);
        Vector4 operator*(Vector4 b);
        Vector4 operator*(int b);
        Vector4 operator*(float b);
        Vector4 operator/(Vector4 b);
        Vector4 operator/(int b);
        Vector4 operator/(float b);
        Vector4 operator-();
        bool operator==(Vector4 b);
        bool operator!=(Vector4 b);
    };
}

#endif //INFERNO_VECTOR4_H
