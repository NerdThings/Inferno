//
// Created by Reece Mackie on 16/11/18.
//

#include <algorithm>

#include "Instance.h"
#include "Scene.h"

namespace Inferno {
    //Private methods
    
    bool Instance::both_per_pixel_check(Graphics::Sprite *sprite_a, Graphics::Sprite *sprite_b, Rectangle bounds_a, Rectangle bounds_b) {
        std::vector<Graphics::Color> colordata_a = sprite_a->get_current_texture()->get_data();
        std::vector<Graphics::Color> colordata_b = sprite_b->get_current_texture()->get_data();
        Rectangle source_a = sprite_a->get_source_rectangle();
        Rectangle source_b = sprite_b->get_source_rectangle();
        
        //Animation check
        //if (sprite_a->is_animated() || sprite_b->is_animated())
        //    throw "Cannot per pixel check animated sprites";
        
        //Build bounding box of collision area
        int left = std::max(bounds_a.get_left_coord(), bounds_b.get_left_coord());
        int top = std::max(bounds_a.get_top_coord(), bounds_b.get_top_coord());
        int width = std::min(bounds_a.get_right_coord(), bounds_b.get_right_coord()) - left;
        int height = std::min(bounds_a.get_bottom_coord(), bounds_b.get_bottom_coord()) - top;
        
        //Check pixels
        for (int x = left; x < left + width; x++) {
            for (int y = top; y < top + height; y++) {
                int color_a_x = x - bounds_a.get_left_coord() + source_a.get_left_coord();
                int color_a_y = y - bounds_a.get_top_coord() + source_a.get_top_coord();
                int color_a_i = color_a_y * sprite_a->get_current_texture()->get_width() + color_a_x;
                int color_b_x = x - bounds_b.get_left_coord() + source_b.get_left_coord();
                int color_b_y = y - bounds_b.get_top_coord() + source_b.get_top_coord();
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
        
        //Pixel to rectangle check
        if (collision_mode_a == PerPixel && collision_mode_b == BoundingRectangle) {
            return pixel_to_rectangle_check(sprite_a, bounds_a, bounds_b);
        }
        
        //Rectangle to pixel check
        if (collision_mode_a == BoundingRectangle && collision_mode_b == PerPixel) {
            return pixel_to_rectangle_check(sprite_b, bounds_b, bounds_a);
        }
        
        //Somehow?!?!
        return false;
    }
    
    bool Instance::pixel_to_rectangle_check(Graphics::Sprite *sprite, Rectangle bounds_a, Rectangle bounds_b){
        //Get sprite data
        std::vector<Graphics::Color> color_data = sprite->get_current_texture()->get_data();
        Rectangle source = sprite->get_source_rectangle();
    
        //Build bounding box of collision area
        int left = std::max(bounds_a.get_left_coord(), bounds_b.get_left_coord());
        int top = std::max(bounds_a.get_top_coord(), bounds_b.get_top_coord());
        int width = std::min(bounds_a.get_right_coord(), bounds_b.get_right_coord()) - left;
        int height = std::min(bounds_a.get_bottom_coord(), bounds_b.get_bottom_coord()) - top;
        
        //Check for animations
        //if (sprite->is_animated())
        //    throw "Cannot per pixel check animated sprites";
        
        //Look for collision
        for (int x = left; x < left + width; x++) {
            for (int y = top; y < top + height; y++) {
                int color_x = x - bounds_a.get_left_coord() + source.get_left_coord();
                int color_y = y - bounds_a.get_top_coord() + source.get_top_coord();
                int color_i = color_y * sprite->get_current_texture()->get_width() + color_x;
                
                Graphics::Color color = color_data[color_i];
                
                //Check for collision
                if (color.get_a() > 0 && bounds_b.contains(Vector2(x, y)))
                    return true;
            }
        }
        
        //No collision
        return false;
    }
    
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
        if (_collision_mask != nullptr)
            delete _collision_mask;
        if (collision_rectangle != nullptr)
            delete collision_rectangle;
        if (sprite != nullptr)
            delete sprite;
    }
    
    //Methods
    
    void Instance::begin_update() {}
    
    bool Instance::colliding(const std::type_info* instance_type) {
        return colliding(_position, instance_type);
    }
    
    bool Instance::colliding(Vector2 position, const std::type_info* instance_type) {
        //Check collision mask is valid
        if (get_collision_mask() != nullptr)
            if (get_collision_mask()->is_animated())
                throw "An instance collision mask cannot be animated.";
            
            //If the instance type is null, set it to Instance
            if (instance_type == nullptr)
                instance_type = &typeid(Instance);
            
            //Store current position
            Vector2 current_pos = _position;
            
            //Move to the target position (so bounds can be calculated)
            _position = position;
            
            //Get everything that is nearby
            //TODO
            
            return false;
    }
    
    void Instance::draw(Graphics::Renderer *renderer) {
        if (sprite != nullptr) {
            Rectangle bounds = get_bounds();
            renderer->draw_texture(sprite->get_current_texture(), Rectangle(bounds.x, bounds.y, sprite->width, sprite->height), sprite->get_source_rectangle(), sprite->origin, Graphics::Color(255, 255, 255, 255), 0);
        }
    }
    
    void Instance::end_update() {
        //Apply velocity
        _position = _position + velocity;
    }
    
    Rectangle Instance::get_bounds() {
        if (collision_rectangle != nullptr) {
            if (sprite == nullptr) {
                return Rectangle(int(_position.x + collision_rectangle->x), int(_position.y + collision_rectangle->y), collision_rectangle->width, collision_rectangle->height);
            }
        
            return Rectangle(int(_position.x - sprite->origin.x + collision_rectangle->x), int(_position.y - sprite->origin.y + collision_rectangle->y), collision_rectangle->width, collision_rectangle->height);
        } else {
            if (sprite == nullptr) {
                return Rectangle(int(_position.x), int(_position.y), get_width(), get_height());
            }
        
            return Rectangle(int(_position.x - sprite->origin.x), int(_position.y - sprite->origin.y), get_width(), get_height());
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
    
    void Instance::update() {
        if (sprite != nullptr)
            sprite->update();
    }
}