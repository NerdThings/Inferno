//
// Created by Reece Mackie on 17/11/18.
//

#ifdef SDL
#include "SDL.h"
#endif

#include "Inferno/Input/Keyboard.h"

namespace Inferno {
    namespace Input {
#ifdef INFERNO
        std::vector<Key> Keyboard::internal_keys;
#endif
        
        //Methods
        
        KeyboardState Keyboard::get_state() {
#ifdef SDL
            SDL_Keymod mods = SDL_GetModState();
            bool caps = (mods & KMOD_CAPS) == KMOD_CAPS;
            bool num = (mods & KMOD_NUM) == KMOD_NUM;
            return {internal_keys, caps, num};
#endif
        }
    }
}