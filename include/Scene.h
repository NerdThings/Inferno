//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_SCENE_H
#define INFERNO_SCENE_H

#include "Inferno.h"

#include <vector>

namespace Inferno {
    class Game;
    
    namespace Graphics {
        class Renderer;
    }
    
    class INFERNO_API Scene {
    protected:
        //Fields
        
        //std::vector<Instance> _instances;
        int height;
        Game* parent_game;
        int width;
    public:
        //Constructors
        
        Scene(Game* parent_game, int width, int height);
        
        //Methods
        
        virtual void begin_update();
        virtual void draw(Graphics::Renderer* renderer);
        virtual void end_update();
        virtual void loaded();
        virtual void unloaded();
        virtual void update();
    };
}

#endif //INFERNO_SCENE_H
