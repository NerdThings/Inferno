//
// Created by Reece Mackie on 15/11/18.
//

#include <algorithm>
#include <cmath>

#include "Inferno/Scene.h"
#include "Inferno/Instance.h"

namespace Inferno {
    //Private methods
    
    void Scene::spatial_initialise() {
        //Check config
        if (spatialmode == SafeZone && !safezone_enabled)
            throw std::runtime_error("Safezone spatial mode requires safezone to be enabled.");
        
        //Calculate the size of the array
        int cols = abs(width / space_size);
        int rows = abs(height / space_size);
        
        _spatial_map.clear();
        
        //Fill the map with vectors
        for (int i = 0; i < cols * rows; i++) {
            _spatial_map.insert(std::pair<int, std::vector<Instance*>>(i, std::vector<Instance*>()));
        }
        
        //Register all instances into spaces
        for (Instance* instance : _instances) {
            if (instance != nullptr) {
                if (spatialmode == SafeZone && safezone_enabled) { //Check if within safezone
                    if (safezone.contains(instance->get_position())) {
                        spatial_register_instance(instance);
                    }
                } else {
                    spatial_register_instance(instance);
                }
            }
        }
    }
    
    void Scene::spatial_register_instance(Instance *instance) {
        std::vector<int> spaces = spatial_get_spaces(instance);
        for (int space : spaces) {
            _spatial_map[space].emplace_back(instance);
        }
    }
    
    void Scene::spatial_add_to_space(Vector2 position, std::vector<int>* spaces) {
        //Stop if out of range
        if (position.x < 0 || position.y < 0 || position.x > width || position.y > height)
            return;
        
        float w = float(width) / float(space_size);
        
        auto x_position = (int)floorf(position.x / space_size);
        auto y_position = (int)floorf(position.y / space_size);
        auto index = (int)(y_position * w + x_position);
        
        if (std::find(spaces->begin(), spaces->end(), index) == spaces->end()) {
            spaces->emplace_back(index);
        }
    }
    
    //Constructors
    
    Scene::Scene(Inferno::Game *parent_game, int width, int height) : parent_game(parent_game), height(height), width(width) {
    
    }
    
    //Methods
    
    void Scene::add_instance(Instance *instance) {
        //Add the instance to the state
        _instances.emplace_back(instance);
    }
    
    void Scene::begin_update() {
        spatial_initialise();
        
        for (Instance* instance : _instances) {
            if (instance != nullptr)
                if (instance->updates)
                    instance->begin_update();
        }
    }
    
    void Scene::draw(Graphics::Renderer *renderer) {
        //Draw background
        if (background != nullptr) {
            Rectangle back_src = background->get_source_rectangle();
            renderer->draw_texture(background->get_current_texture(), Vector2(), &back_src, background_depth,
                                   Graphics::Color::white, background->origin);
        }
        
        for (Instance* instance : _instances) {
            if (instance != nullptr)
                if (instance->draws)
                    instance->draw(renderer);
        }
    }
    
    void Scene::end_update() {
        for (Instance* instance : _instances) {
            if (instance != nullptr)
                if (instance->updates)
                    instance->end_update();
        }
    }
    
    std::vector<Instance*> Scene::get_instances_at(Vector2 position, bool bound_by_safezone) {
        std::vector<Instance*> ret;
        
        if (bound_by_safezone) {
            for (Instance* instance : _instances) {
                if (instance != nullptr) {
                    if (instance->get_position() == position) {
                        if (safezone.contains(instance->get_position())) {
                            ret.emplace_back(instance);
                        }
                    }
                }
            }
        } else {
            for (Instance* instance : _instances) {
                if (instance != nullptr) {
                    if (instance->get_position() == position) {
                        ret.emplace_back(instance);
                    }
                }
            }
        }
        
        return ret;
    }
    
    std::vector<Instance*> Scene::get_nearby_instances(Instance* instance) {
        std::vector<Instance*> ret;
        
        std::vector<int> spaces = spatial_get_spaces(instance);
        
        for (int space : spaces) {
            for (Instance* inst : _spatial_map[space]) {
                if (inst != nullptr) {
                    if (std::find(ret.begin(), ret.end(), inst) == ret.end()) {
                        ret.emplace_back(inst);
                    }
                }
            }
        }
        
        return ret;
    }
    
    void Scene::loaded() {
        //User can add code to load the state
    }
    
    void Scene::remove_instance(Instance *instance) {
        //Remove instance from state
        _instances.erase(std::remove(_instances.begin(), _instances.end(), instance), _instances.end());
    }
    
    std::vector<int> Scene::spatial_get_spaces(Instance* instance) {
        return spatial_get_spaces(instance->get_bounds());
    }
    
    std::vector<int> Scene::spatial_get_spaces(Rectangle rectangle) {
        std::vector<int> spaces_in;
        
        Vector2 topleft = Vector2(rectangle.get_left_coord(), rectangle.get_top_coord());
        Vector2 topright = Vector2(rectangle.get_right_coord(), rectangle.get_top_coord());
        Vector2 bottomleft = Vector2(rectangle.get_left_coord(), rectangle.get_bottom_coord());
        Vector2 bottomright = Vector2(rectangle.get_right_coord(), rectangle.get_bottom_coord());
        
        spatial_add_to_space(topleft, &spaces_in);
        spatial_add_to_space(topright, &spaces_in);
        spatial_add_to_space(bottomleft, &spaces_in);
        spatial_add_to_space(bottomright, &spaces_in);
        
        return spaces_in;
    }
    
    void Scene::spatial_move_instance(Rectangle old_bounds, Rectangle new_bounds, Instance* instance) {
        std::vector<int> old_spaces = spatial_get_spaces(old_bounds);
        std::vector<int> new_spaces = spatial_get_spaces(new_bounds);
        
        for (int old_space : old_spaces) {
            if (std::find(_spatial_map[old_space].begin(), _spatial_map[old_space].end(), instance) == _spatial_map[old_space].end())
                _spatial_map[old_space].erase(std::remove(_spatial_map[old_space].begin(), _spatial_map[old_space].end(), instance), _spatial_map[old_space].end());
        }
        
        for (int new_space : new_spaces) {
            _spatial_map[new_space].emplace_back(instance);
        }
    }
    
    void Scene::unloaded() {
        //User can add code to unload the state
    }
    
    void Scene::update() {
        for (Instance* instance : _instances) {
            if (instance != nullptr) {
                //Update instance
                if (instance->updates)
                    instance->update();
                
                //Update sprite
                if (instance->draws)
                    if (instance->sprite != nullptr)
                        instance->sprite->update();
            }
        }
    }
}