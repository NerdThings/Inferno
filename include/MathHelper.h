//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_MATHHELPER_H
#define INFERNO_MATHHELPER_H

#include "Inferno.h"

namespace Inferno {
    class INFERNO_API MathHelper {
    public:
        static double clamp(double value, double min, double max);
        static float clamp(float value, float min, float max);
        static int clamp(int value, int min, int max);
        static double distance(double value1, double value2);
        static float distance(float value1, float value2);
        static int distance(int value1, int value2);
        //static double lerp(double value1, double value2, double amount);
        //static float lerp(float value1, float value2, float amount);
        //static int lerp(int value1, int value2, int amount);
        //static double lerp_precise(double value1, double value2, double amount);
        //static float lerp_precise(float value1, float value2, float amount);
        //static int lerp_precise(int value1, int value2, int amount);
        static double nearest_multiple(double number, double multiple);
        static float nearest_multiple(float number, float multiple);
        static int nearest_multiple(int number, int multiple);
    };
}

#endif //INFERNO_MATHHELPER_H
