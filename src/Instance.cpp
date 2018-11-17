//
// Created by Reece Mackie on 16/11/18.
//

#include "Instance.h"

namespace Inferno {
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
        if (_collision_mask != nullptr)
            delete _collision_mask;
        if (collision_rectangle != nullptr)
            delete collision_rectangle;
        if (sprite != nullptr)
            delete sprite;
    }
    
    //Methods
    
    void Instance::begin_update() {}
    
    void Instance::draw(Graphics::Renderer *renderer) {
        if (sprite != nullptr) {
            renderer->draw_texture(sprite->get_current_texture(), get_bounds(), sprite->get_source_rectangle(), sprite->origin, Graphics::Color(255, 255, 255, 255), 0);
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
                return Rectangle(int(_position.x), int(_position.y), _width, _height);
            }
        
            return Rectangle(int(_position.x - sprite->origin.x), int(_position.y - sprite->origin.y), _width, _height);
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
        Rectangle oldBounds = get_bounds();
        
        //Update height
        if (sprite != nullptr)
            sprite->height = height;
        else
            _height = height;
        
        //TODO: Update spatial hashing
    }
    
    void Instance::set_position(Vector2 position) {
        //Save old bounds for spatial recalculation
        Rectangle oldBounds = get_bounds();
        
        //Update position
        _position = position;
    
        //TODO: Update spatial hashing
    }
    
    void Instance::set_width(int width) {
        //Save old bounds for spatial recalculation
        Rectangle oldBounds = get_bounds();
    
        //Update height
        if (sprite != nullptr)
            sprite->width = width;
        else
            _width = width;
    
        //TODO: Update spatial hashing
    }
    
    void Instance::update() {}
}