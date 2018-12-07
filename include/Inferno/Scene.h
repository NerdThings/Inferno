//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_SCENE_H
#define INFERNO_SCENE_H

#include <map>
#include <vector>

#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/Sprite.h"
#include "Inferno/Inferno.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    class Instance;
    class Game;
    
    /*
     * Spatial hashing mode
     */
    enum SpatialMode {
        Regular,
        SafeZone
    };
    
    /*
     * A game scene
     */
    //TODO: Update to use events
    class INFERNO_API Scene {
    private:
        //Fields
        
        /*
         * The instances within the scene
         */
        std::vector<Instance*> _instances;
        
        /*
         * Spatial hashing map
         */
        std::map<int, std::vector<Instance*>> _spatial_map;
    
        //Methods
    
        /*
         * Initialise spatial hashing
         */
        void spatial_initialise();
        
        /*
         * Register an instance into spatial hashing
         */
        void spatial_register_instance(Instance* instance);
        
        /*
         * Add a space to a list of spaces
         */
        void spatial_add_to_space(Vector2 position, std::vector<int>* spaces);
    protected:
        //Fields
        
        /*
         * The state height
         */
        int height = 0;
        
        /*
         * The state background draw depth
         */
        float background_depth = -0.9f;
        
        /*
         * The spatial space size
         */
        int space_size = 32;
        
        /*
         * The state background
         */
        Graphics::Sprite* background = nullptr;
        
        /*
         * Whether or not the safezone is enabled
         */
        bool safezone_enabled = false;
        
        /*
         * The safezone
         */
        Rectangle safezone = Rectangle(0, 0, 0, 0);
        
        /*
         * The state spatial mode
         */
        SpatialMode spatialmode = Regular;
        
        /*
         * The state width
         */
        int width = 0;
    public:
        //Fields
        
        /*
         * The state parent game
         */
        Game* parent_game;
        
        //Constructors
        
        /*
         * Create a new Scene
         */
        Scene(Game* parent_game, int width, int height);
        
        //Methods
        
        /*
         * Add an instance
         */
        void add_instance(Instance* instance);
        
        /*
         * Begin update
         */
        virtual void begin_update();
        
        /*
         * Draw
         */
        virtual void draw(Graphics::Renderer* renderer);
        
        /*
         * End update
         */
        virtual void end_update();
        
        /*
         * Get instances at the given position
         */
        std::vector<Instance*> get_instances_at(Vector2 position, bool bound_by_safezone = false);
        
        /*
         * Get instances near another
         */
        std::vector<Instance*> get_nearby_instances(Instance* instance);
        
        /*
         * Loaded event
         */
        virtual void loaded();
        
        /*
         * Remove instance
         */
        void remove_instance(Instance* instance);
        
        /*
         * Get spaces for an instance
         */
        std::vector<int> spatial_get_spaces(Instance* instance);
        
        /*
         * Get spaces for a rectangle
         */
        std::vector<int> spatial_get_spaces(Rectangle instance);
        
        /*
         * Update the position of an instance
         */
        void spatial_move_instance(Rectangle old_bounds, Rectangle new_bounds, Instance* instance);
        
        /*
         * Unloaded event
         */
        virtual void unloaded();
        
        /*
         * Update
         */
        virtual void update();
    };
}

#endif //INFERNO_SCENE_H
