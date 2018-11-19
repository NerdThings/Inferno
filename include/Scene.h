//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_SCENE_H
#define INFERNO_SCENE_H

#include "Inferno.h"

#include <map>
#include <vector>

#include "Instance.h"

namespace Inferno {
    class Game;
    
    namespace Graphics {
        class Renderer;
        class Sprite;
    }
    
    enum SpatialMode {
        Regular,
        SafeZone
    };
    
    class INFERNO_API Scene {
    private:
        //Fields
        
        std::vector<Instance*> _instances;
        std::map<int, std::vector<Instance*>> _spatial_map;
    
        //Methods
    
        void spatial_initialise();
        void spatial_register_instance(Instance* instance);
        void spatial_add_to_space(Vector2 position, std::vector<int>* spaces);
    protected:
        //Fields
        
        int height = 0;
        float background_depth = -99;
        int space_size = 32;
        Graphics::Sprite* background = nullptr;
        bool safezone_enabled = false;
        Rectangle safezone = Rectangle(0, 0, 0, 0);
        SpatialMode spatialmode = Regular;
        int width = 0;
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
        std::vector<Instance*> get_instances_at(Vector2 position, bool bound_by_safezone = false);
        std::vector<Instance*> get_nearby_instances(Instance* instance);
        virtual void loaded();
        void remove_instance(Instance* instance);
        std::vector<int> spatial_get_spaces(Instance* instance);
        std::vector<int> spatial_get_spaces(Rectangle instance);
        void spatial_move_instance(Rectangle old_bounds, Rectangle new_bounds, Instance* instance);
        virtual void unloaded();
        virtual void update();
    };
}

#endif //INFERNO_SCENE_H
