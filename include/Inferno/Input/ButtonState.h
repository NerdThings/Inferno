//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_BUTTONSTATE_H
#define INFERNO_BUTTONSTATE_H

#include "Inferno/Inferno.h"

namespace Inferno {
    namespace Input {
        /*
         * The state of a button
         */
        enum INFERNO_API ButtonState {
            Pressed,
            Released
        };
    }
}

#endif //INFERNO_BUTTONSTATE_H
