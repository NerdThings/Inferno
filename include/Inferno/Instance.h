//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_INSTANCE_H
#define INFERNO_INSTANCE_H

#include <algorithm>
#include <vector>

#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/Sprite.h"
#include "Inferno/Inferno.h"
#include "Inferno/Scene.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    /*
     * An Instance Collision Mode
     */
    enum CollisionMode {
        BoundingRectangle,
        PerPixel
    };
    
    /*
     * A game instance
     */
    class INFERNO_API Instance {
        //Fields
        
        /*
         * The instance collision mask
         */
        Graphics::Sprite* _collision_mask = nullptr;
        
        /*
         * The instance height
         */
        int _height;
        
        /*
         * The instance position
         */
        Vector2 _position = Vector2(0, 0);
        
        /*
         * The instance width
         */
        int _width;
        
        //Methods
        
        /*
         * Check per pixel collisions
         */
        bool both_per_pixel_check(Graphics::Sprite* sprite_a, Graphics::Sprite* sprite_b, Rectangle bounds_a, Rectangle bounds_b);
        
        /*
         * Run a collision check
         */
        bool collision_check(Graphics::Sprite* sprite_a, Graphics::Sprite* sprite_b, Rectangle bounds_a, Rectangle bounds_b, CollisionMode collision_mode_a, CollisionMode collision_mode_b);
        
    public:
        //Fields
        
        /*
         * Whether or not the instance is affected by gravity
         */
        bool affected_by_gravity = false;
        
        /*
         * The instance collision mode
         */
        CollisionMode collision_mode = BoundingRectangle;
        
        /*
         * The instance collision rectangle
         */
        Rectangle* collision_rectangle = nullptr;
        
        /*
         * The instance depth
         */
        float depth = 0;
        
        /*
         * Whether or not the instance uses draw calls
         */
        bool draws = false;
        
        /*
         * The instance parent scene
         */
        Scene* parent_scene = nullptr;
        
        /*
         * The instance rotation
         */
        float rotation = 0;
        
        /*
         * This is the point from which the instance will rotate from.
         * This will not be applied to the sprite, use sprite->origin for that.
         */
        Vector2 rotation_origin = Vector2();
        
        /*
         * The roughness of the instance
         */
        float roughness = 0;
        
        /*
         * The instance sprite
         */
        Graphics::Sprite* sprite = nullptr;
        
        /*
         * Whether or not the instance uses update calls
         */
        bool updates = false;
        
        /*
         * The instance velocity
         * This is added to the position at the end of every frame
         */
        Vector2 velocity = Vector2(0, 0);
        
        //Constructors
        
        /*
         * Create a new Instance
         */
        explicit Instance(Scene* parent_scene);
        
        /*
         * Create a new Instance
         */
        Instance(Scene* parent_scene, Vector2 position, float depth = 0, bool updates = false, bool draws = false);
        
        //Deconstructors
        
        /*
         * Clean up a Deleted Instance
         */
        ~Instance();
        
        //Methods
        
        /*
         * Begin updating the instance
         */
        virtual void begin_update();
        
        /*
         * Test for a collision with another instance
         */
        template <typename instance_type> bool colliding() {
            return colliding<instance_type>(_position);
        }
        
        /*
         * Test for a collision with another instance at a specified position
         */
        template <typename instance_type> bool colliding(Vector2 position) {
            //Check collision mask is valid
            if (get_collision_mask() != nullptr)
                if (collision_mode == PerPixel)
                    if (get_collision_mask()->is_animated())
                        throw std::runtime_error("An instance collision mask cannot be animated.");
            
            //Store current position
            Vector2 current_pos = _position;
    
            //Move to the target position (so bounds can be calculated)
            _position = position;
    
            //Get everything that is nearby
			std::vector<Instance*> nearby = parent_scene->get_nearby_instances(this);
    
            //Search for collision
            for (Instance* inst : nearby) {
                //Skip invalid instances
                if (dynamic_cast<instance_type*>(inst) == nullptr || inst == this)
                    continue;
        
                if (!collision_check(get_collision_mask(), inst->get_collision_mask(), get_bounds(), inst->get_bounds(), collision_mode, inst->collision_mode))
                    continue;
        
                //Reset and return
                _position = current_pos;
                return true;
            }
    
            //Reset and return
            _position = current_pos;
            return false;
        }
        
        /*
         * Draw the instance
         */
        virtual void draw(Graphics::Renderer* renderer);
        
        /*
         * End instance update
         */
        virtual void end_update();
        
        /*
         * Get the instance bounds
         */
        virtual Rectangle get_bounds();
        
        /*
         * Get the instance collision mask
         */
        Graphics::Sprite* get_collision_mask();
        
        /*
         * Get the instance height
         */
        int get_height();
        
        /*
         * Get the next position
         */
        virtual Vector2 get_next_position();
        
        /*
         * Get the current position
         */
        virtual Vector2 get_position();
        
        /*
         * Get the instance width
         */
        int get_width();
        
        /*
         * Set the instance collision mask
         */
        void set_collision_mask(Graphics::Sprite* collision_mask);
        
        /*
         * Set the instance height
         */
        void set_height(int height);
        
        /*
         * Set the instance position
         */
        virtual void set_position(Vector2 position);
        
        /*
         * Set the instance width
         */
        void set_width(int width);
        
        /*
         * Update the instance
         */
        virtual void update();
    };
}

#endif //INFERNO_INSTANCE_H
