//
// Created by Reece Mackie on 13/11/18.
//

#include <cmath>

#include "Inferno/MathHelper.h"

namespace Inferno {
    double MathHelper::clamp(double value, double min, double max) {
        value = (value > max) ? max : value;
        value = (value < min) ? min : value;
        return value;
    }
    
    float MathHelper::clamp(float value, float min, float max) {
        value = (value > max) ? max : value;
        value = (value < min) ? min : value;
        return value;
    }
    
    int MathHelper::clamp(int value, int min, int max) {
        value = (value > max) ? max : value;
        value = (value < min) ? min : value;
        return value;
    }
    
    double MathHelper::distance(double value1, double value2) {
        return fabs(value1 - value2);
    }
    
    float MathHelper::distance(float value1, float value2) {
        return fabsf(value1 - value2);
    }
    
    int MathHelper::distance(int value1, int value2) {
        return fabsf(value1 - value2);
    }
    
    double MathHelper::nearest_multiple(double number, double multiple) {
        return round((number / float(multiple))) * multiple;
    }
    
    float MathHelper::nearest_multiple(float number, float multiple) {
        return roundf((number / multiple)) * multiple;
    }
    
    int MathHelper::nearest_multiple(int number, int multiple) {
        return (int)round((double(number) / multiple)) * multiple;
    }
}