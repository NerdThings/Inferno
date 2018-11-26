//
// Created by Reece Mackie on 17/11/18.
//

#include "Inferno/Input/MouseState.h"

namespace Inferno {
    namespace Input {
        //Constructors
        
        MouseState::MouseState() {
            this->x = 0;
            this->y = 0;
            this->scroll_wheel_x = 0;
            this->scroll_wheel_y = 0;
            this->left_button = Released;
            this->middle_button = Released;
            this->right_button = Released;
            this->x_button_1 = Released;
            this->x_button_2 = Released;
        }
        
        MouseState::MouseState(int x, int y, int scrollx, int scrolly, ButtonState left, ButtonState middle, ButtonState right, ButtonState x1, ButtonState x2) {
            this->x = x;
            this->y = y;
            this->scroll_wheel_x = scrollx;
            this->scroll_wheel_y = scrolly;
            this->left_button = left;
            this->middle_button = middle;
            this->right_button = right;
            this->x_button_1 = x1;
            this->x_button_2 = x2;
        }
    }
}