//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_INSTANCE_H
#define INFERNO_INSTANCE_H

#include "Inferno.h"

#include <typeinfo>

#include "Graphics/Renderer.h"
#include "Graphics/Sprite.h"
#include "Vector2.h"

namespace Inferno {
    class Scene;
    
    enum CollisionMode {
        BoundingRectangle,
        PerPixel
    };
    
    class INFERNO_API Instance {
        //Fields
        
        Graphics::Sprite* _collision_mask = nullptr;
        int _height;
        Vector2 _position = Vector2(0, 0);
        int _width;
        
        //Methods
        
        bool both_per_pixel_check(Graphics::Sprite* sprite_a, Graphics::Sprite* sprite_b, Rectangle bounds_a, Rectangle bounds_b);
        bool collision_check(Graphics::Sprite* sprite_a, Graphics::Sprite* sprite_b, Rectangle bounds_a, Rectangle bounds_b, CollisionMode collision_mode_a, CollisionMode collision_mode_b);
        bool pixel_to_rectangle_check(Graphics::Sprite* sprite, Rectangle bounds_a, Rectangle bounds_b);
        
    public:
        //Fields
        
        bool affected_by_gravity = false;
        CollisionMode collision_mode = BoundingRectangle;
        Rectangle* collision_rectangle = nullptr;
        float depth = 0;
        bool draws = false;
        Scene* parent_scene = nullptr;
        float roughness = 0;
        Graphics::Sprite* sprite = nullptr;
        bool updates = false;
        Vector2 velocity = Vector2(0, 0);
        
        //Constructors
        
        explicit Instance(Scene* parent_scene);
        Instance(Scene* parent_scene, Vector2 position, float depth = 0, bool updates = false, bool draws = false);
        
        //Deconstructors
        
        ~Instance();
        
        //Methods
        
        virtual void begin_update();
        bool colliding(const std::type_info* instance_type);
        bool colliding(Vector2 position, const std::type_info* instance_type);
        virtual void draw(Graphics::Renderer* renderer);
        virtual void end_update();
        Rectangle get_bounds();
        Graphics::Sprite* get_collision_mask();
        int get_height();
        Vector2 get_next_position();
        Vector2 get_position();
        int get_width();
        void set_collision_mask(Graphics::Sprite* collision_mask);
        void set_height(int height);
        void set_position(Vector2 position);
        void set_width(int width);
        virtual void update();
    };
}

#endif //INFERNO_INSTANCE_H
