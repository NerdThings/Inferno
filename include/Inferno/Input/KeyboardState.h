//
// Created by Reece Mackie on 17/11/18.
//

#ifndef INFERNO_KEYBOARDSTATE_H
#define INFERNO_KEYBOARDSTATE_H

#include "Inferno/Inferno.h"

#include <vector>

#include "Key.h"

namespace Inferno {
    namespace Input {
        /*
         * The keyboard state
         */
        struct INFERNO_API KeyboardState {
        private:
            //Fields
            
            /*
             * The bytes that store key statuses
             */
            unsigned int keys0, keys1, keys2, keys3, keys4, keys5, keys6, keys7;
            
            //Methods
            
            /*
             * Get the status of a key
             */
            bool private_get_key(Key key);
            
            /*
             * Set the status of a key
             */
            void private_set_key(Key key);
            
            /*
             * Clear the status of a key
             */
            void private_clear_key(Key key);
            
            /*
             * Clear the status of all keys
             */
            void private_clear_all_keys();
        public:
            //Fields
            
            /*
             * Caps lock status
             */
            bool caps_lock = false;
            
            /*
             * Num lock status
             */
            bool num_lock = false;
            
            //Constructors
            
            /*
             * Create a new KeyboardState
             */
            explicit KeyboardState(std::vector<Key> keys, bool caps_lock = false, bool num_lock = false);
            
            //Methods
            
            /*
             * Is the provided key down
             */
            bool is_key_down(Key key);
            
            /*
             * Is the provided key up
             */
            bool is_key_up(Key key);
            
            //Operators
            
            bool operator==(KeyboardState b);
            bool operator!=(KeyboardState b);
        };
    }
}

#endif //INFERNO_KEYBOARDSTATE_H
