//
// Created by Reece Mackie on 16/11/18.
//

#include <algorithm>
#include <type_traits>

#include "Inferno/Instance.h"
#include "Inferno/MathHelper.h"
#include "Inferno/Scene.h"

namespace Inferno {
    //Private methods
    
    bool Instance::both_per_pixel_check(Graphics::Sprite *sprite_a, Graphics::Sprite *sprite_b, Rectangle bounds_a, Rectangle bounds_b) {
        std::vector<Graphics::Color> colordata_a = sprite_a->get_current_texture()->get_data();
        std::vector<Graphics::Color> colordata_b = sprite_b->get_current_texture()->get_data();
        Rectangle source_a = sprite_a->get_source_rectangle();
        Rectangle source_b = sprite_b->get_source_rectangle();
        
        //Animation check
        if (sprite_a->is_animated() || sprite_b->is_animated())
            throw std::runtime_error("Cannot per pixel check animated sprites.");
        
        //Rotation check (This is temporary)
        //TODO: No rotation check
        if (bounds_a.rotation != 0 || bounds_b.rotation != 0)
            throw std::runtime_error("Cannot currently per pixel check rotated instances.");
        
        //Build bounding box of collision area
        int left = MathHelper::maximum(bounds_a.x, bounds_b.x);
        int top = MathHelper::maximum(bounds_a.y, bounds_b.y);
        int width = MathHelper::minimum(bounds_a.width, bounds_b.width);
        int height = MathHelper::minimum(bounds_a.height, bounds_b.height);
        
        //Check pixels
        for (int x = left; x < left + width; x++) {
            for (int y = top; y < top + height; y++) {
                int color_a_x = x - bounds_a.x + source_a.x;
                int color_a_y = y - bounds_a.y + source_a.y;
                int color_a_i = color_a_y * sprite_a->get_current_texture()->get_width() + color_a_x;
                int color_b_x = x - bounds_b.x + source_b.x;
                int color_b_y = y - bounds_b.y + source_b.y;
                int color_b_i = color_b_y * sprite_b->get_current_texture()->get_width() + color_b_x;
                
                Graphics::Color color_a = colordata_a[color_a_i];
                Graphics::Color color_b = colordata_b[color_b_i];
                
                if (color_a.get_a() > 0 && color_b.get_a() > 0)
                    return true;
            }
        }
        
        //No collision
        return false;
    }
    
    bool Instance::collision_check(Graphics::Sprite *sprite_a, Graphics::Sprite *sprite_b, Rectangle bounds_a, Rectangle bounds_b, CollisionMode collision_mode_a, CollisionMode collision_mode_b) {
        //Simple rectangle check
        if (collision_mode_a == BoundingRectangle && collision_mode_b == BoundingRectangle) {
            return bounds_a.intersects(bounds_b);
        }
        
        //Pixel to pixel check
        if (collision_mode_a == PerPixel && collision_mode_b == PerPixel) {
            return both_per_pixel_check(sprite_a, sprite_b, bounds_a, bounds_b);
        }
        
        //Just default to a standard rectangle check
        if ((collision_mode_a == PerPixel && collision_mode_b == BoundingRectangle)
            || (collision_mode_a == BoundingRectangle && collision_mode_b == PerPixel)) {
            return bounds_a.intersects(bounds_b);
        }
        
        //Somehow?!?!
        return false;
    }
    
    //Constructors
    
    Instance::Instance(Scene *parent_scene) : parent_scene(parent_scene) {}
    
    Instance::Instance(Scene *parent_scene, Vector2 position, float depth, bool updates, bool draws) {
        this->parent_scene = parent_scene;
        this->_position = position;
        this->depth = depth;
        this->updates = updates;
        this->draws = draws;
    }
    
    //Deconstructors
    
    Instance::~Instance() {
        //Delete all attached pointers (exception for parent and parent_scene)
        delete _collision_mask;
        delete collision_rectangle;
        delete sprite;
    }
    
    //Methods
    
    void Instance::begin_update() {}
    
    void Instance::draw(Graphics::Renderer *renderer) {
        if (sprite != nullptr) {
            Rectangle bounds = get_bounds();
            Rectangle src = sprite->get_source_rectangle();
            renderer->draw_texture(sprite->get_current_texture(), Rectangle(bounds.x, bounds.y, sprite->width, sprite->height), &src, 0, sprite->rotation, Graphics::Color(255, 255, 255, 255), sprite->origin);
        }
    }
    
    void Instance::end_update() {
        //Apply velocity
        _position = _position + velocity;
    }
    
    Rectangle Instance::get_bounds() {
        if (collision_rectangle != nullptr) {
            if (sprite == nullptr) {
                return Rectangle(int(_position.x + collision_rectangle->x), int(_position.y + collision_rectangle->y), collision_rectangle->width, collision_rectangle->height, rotation, rotation_origin);
            }
        
            return Rectangle(int(_position.x - sprite->origin.x + collision_rectangle->x), int(_position.y - sprite->origin.y + collision_rectangle->y), collision_rectangle->width, collision_rectangle->height, rotation, rotation_origin);
        } else {
            if (sprite == nullptr) {
                return Rectangle(int(_position.x), int(_position.y), get_width(), get_height(), rotation, rotation_origin);
            }
        
            return Rectangle(int(_position.x - sprite->origin.x), int(_position.y - sprite->origin.y), get_width(), get_height(), rotation, rotation_origin);
        }
    }
    
    Graphics::Sprite* Instance::get_collision_mask()  {
        if (_collision_mask != nullptr) {
            return _collision_mask;
        } else if (sprite != nullptr) {
            return sprite;
        } else {
            return nullptr;
        }
    }
    
    int Instance::get_height() {
        if (sprite != nullptr)
            return sprite->height;
        return _height;
    }
    
    Vector2 Instance::get_next_position() {
        return _position + velocity;
    }
    
    Vector2 Instance::get_position() {
        return _position;
    }
    
    int Instance::get_width() {
        if (sprite != nullptr)
            return sprite->width;
        return _width;
    }
    
    void Instance::set_collision_mask(Graphics::Sprite *collision_mask) {
        _collision_mask = collision_mask;
    }
    
    void Instance::set_height(int height) {
        //Save old bounds for spatial recalculation
        Rectangle old_bounds = get_bounds();
        
        //Update height
        if (sprite != nullptr)
            sprite->height = height;
        else
            _height = height;
        
        parent_scene->spatial_move_instance(old_bounds, get_bounds(), this);
    }
    
    void Instance::set_position(Vector2 position) {
        //Save old bounds for spatial recalculation
        Rectangle old_bounds = get_bounds();
        
        //Update position
        _position = position;
    
        parent_scene->spatial_move_instance(old_bounds, get_bounds(), this);
    }
    
    void Instance::set_width(int width) {
        //Save old bounds for spatial recalculation
        Rectangle old_bounds = get_bounds();
    
        //Update height
        if (sprite != nullptr)
            sprite->width = width;
        else
            _width = width;
    
        parent_scene->spatial_move_instance(old_bounds, get_bounds(), this);
    }
    
    void Instance::update() {}
}