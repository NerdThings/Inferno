//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_SCENE_H
#define INFERNO_SCENE_H

#include "Inferno.h"

#include <vector>

#include "Instance.h"

namespace Inferno {
    class Game;
    
    namespace Graphics {
        class Renderer;
    }
    
    class INFERNO_API Scene {
    private:
        //Fields
        
        std::vector<Instance*> _instances;
    protected:
        //Fields
        
        int height;
        int width;
    public:
        //Fields
        
        Game* parent_game;
        
        //Constructors
        
        Scene(Game* parent_game, int width, int height);
        
        //Methods
        void add_instance(Instance* instance);
        virtual void begin_update();
        virtual void draw(Graphics::Renderer* renderer);
        virtual void end_update();
        virtual void loaded();
        void remove_instance(Instance* instance);
        virtual void unloaded();
        virtual void update();
    };
}

#endif //INFERNO_SCENE_H
