//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_INSTANCE_H
#define INFERNO_INSTANCE_H

#include "Inferno.h"

#include "Graphics/Renderer.h"
#include "Graphics/Sprite.h"
#include "Vector2.h"

namespace Inferno {
    class Scene;
    
    class INFERNO_API Instance {
        //Fields
        
        Graphics::Sprite* _collision_mask = nullptr;
        int _height;
        Vector2 _position = Vector2(0, 0);
        int _width;
        
    protected:
        //Fields
        
        bool affected_by_gravity = false;
        Rectangle* collision_rectangle = nullptr;
        float depth = 0;
        bool draws = false;
        Scene* parent_scene = nullptr;
        float roughness = 0;
        Graphics::Sprite* sprite = nullptr;
        bool updates = false;
        Vector2 velocity = Vector2(0, 0);
        
        //Constructors
        
        Instance(Scene* parent_scene);
        Instance(Scene* parent_scene, Vector2 position, float depth = 0, bool updates = false, bool draws = false);
        
        //Deconstructors
        
        ~Instance();
        
        //Methods
        
        virtual void begin_update();
        //TODO: Collisions
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
