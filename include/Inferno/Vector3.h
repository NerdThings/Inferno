//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_VECTOR3_H
#define INFERNO_VECTOR3_H

#include "Inferno.h"

namespace Inferno {
    struct Matrix;
    struct Vector2;
    
    struct INFERNO_API Vector3 {
        //Fields
    
        float x;
        float y;
        float z;
    
        //Constructors
        Vector3();
        Vector3(float x, float y, float z);
        Vector3(Vector2 value, float z);
        explicit Vector3(float value);
    
        //Static Methods
    
        static Vector3 transform(Vector3 vector, Matrix matrix);
    
        //Methods
    
        float get_magnitude();
        float get_magnitude_squared();
        float dot(Vector3 b);
        float distance(Vector3 b);
    
        //Operators
        Vector3 operator+(Vector3 b);
        Vector3 operator+(int b);
        Vector3 operator+(float b);
        Vector3 operator-(Vector3 b);
        Vector3 operator-(int b);
        Vector3 operator-(float b);
        Vector3 operator*(Vector3 b);
        Vector3 operator*(int b);
        Vector3 operator*(float b);
        Vector3 operator/(Vector3 b);
        Vector3 operator/(int b);
        Vector3 operator/(float b);
        Vector3 operator-();
        bool operator==(Vector3 b);
        bool operator!=(Vector3 b);
    };
}

#endif //INFERNO_VECTOR3_H
