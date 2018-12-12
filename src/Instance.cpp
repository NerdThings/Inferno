//
// Created by Reece Mackie on 16/11/18.
//

#include <algorithm>
#include <type_traits>

#include "Inferno/Instance.h"
#include "Inferno/MathHelper.h"
#include "Inferno/Scene.h"

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
        delete sprite;
    }
    
    //Methods
    
    void Instance::begin_update() {
        //Check for collisions so that the code can handle it
        collider->update();
    }
    
    void Instance::draw(Graphics::Renderer *renderer) {
        if (sprite != nullptr) {
            Rectangle bounds = get_bounds();
            Rectangle src = sprite->get_source_rectangle();
            renderer->draw_texture(sprite->get_current_texture(), Rectangle(bounds.x, bounds.y, sprite->width, sprite->height), &src, 0, rotation, Graphics::Color(255, 255, 255, 255), sprite->origin);
        }
    }
    
    void Instance::end_update() {
        //Apply velocity
        _position = _position + velocity;
    }
    
    Rectangle Instance::get_bounds() {
        if (sprite == nullptr) {
            return Rectangle(int(get_position().x), int(get_position().y), get_width(), get_height(), rotation, rotation_origin);
        }
    
        return Rectangle(int(get_position().x - sprite->origin.x), int(get_position().y - sprite->origin.y), get_width(), get_height(), rotation, rotation_origin);
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