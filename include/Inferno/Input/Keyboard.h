//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_KEYBOARD_H
#define INFERNO_KEYBOARD_H

#include "Inferno/Inferno.h"

#include <vector>

#include "Key.h"
#include "KeyboardState.h"

namespace Inferno {
    namespace Input {
        /*
         * Keyboard input host
         */
        class INFERNO_API Keyboard {
        public:
#ifdef INFERNO
            /*
             * The internal list of keys
             */
            static std::vector<Key> internal_keys;
#endif
            
            //Methods
            
            /*
             * Get the keyboard state
             */
            static KeyboardState get_state();
        };
    }
}

#endif //INFERNO_KEYBOARD_H
