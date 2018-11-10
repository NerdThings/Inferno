#ifndef INFERNO_SCENE
#define INFERNO_SCENE

#include "Inferno.h"
#include <vector>
#include <map>

namespace Inferno {
    
    namespace Graphics {
        class Renderer;
    }
    
    class Instance;
    class Game;

    struct Rectangle;
	struct Vector2;

    class INFERNO_API Scene {
        //Fields

        std::vector<Instance*> _instances;

        std::map<int, std::vector<Instance*>> _spatial_map;

        //Methods

        ///Spatial Hashing

        void spatial_register_instance(Instance* instance);

        void spatial_add_to_space(Vector2* position, std::vector<int> spaces);

    public:
        //Fields

        int width;

        int height;

        float background_depth;

        int space_size;

        const Game* parent_game;

        //Background

        bool safezone_enabled;

        Rectangle* safezone;

        //Mode Enums

        //Camera

        //User interface

        //Constructors

        Scene(Game* parent_game, int width = 0, int height = 0, int space_size = 32);

        //Methods

        ///Instance Management

        void add_instance(Instance* instance);

        void remove_instance(Instance* instance);

        void clear_instances();

        std::vector<Instance*> get_instances_at(Vector2* position, bool bounds_safezone = false);

        ///Runtime
    
        virtual void begin_update();
    
        virtual void draw(Graphics::Renderer* renderer);
    
        virtual void end_update();
    
        virtual void loaded();
    
        virtual void unloaded();
        
        virtual void update();

        ///Spatial Hashing
    
        std::vector<Instance*> get_nearby(Instance* instance);
    
        void spatial_initialise();

        std::vector<int> spatial_get_spaces(Instance* instance);

        std::vector<int> spatial_get_spaces(Rectangle* rect);

        void spatial_move_instance(Rectangle* old_bounds, Rectangle* new_bounds, Instance* instance);

    };
}

#endif
