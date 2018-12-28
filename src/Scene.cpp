//
// Created by Reece Mackie on 15/11/18.
//

#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "Inferno/Scene.h"
#include "Inferno/World/Instance.h"
#include "Inferno/World/UpdatableInstance.h"

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
            _spatial_map.insert(std::pair<int, std::vector<World::Instance*>>(i, std::vector<World::Instance*>()));
        }
        
        //Register all instances into spaces
        for (World::Instance* instance : _instances) {
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
    
    void Scene::spatial_register_instance(World::Instance *instance) {
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
    
    void Scene::add_instance(World::Instance *instance) {
        //Add the instance to the state
        _instances.emplace_back(instance);

        //Add if updatable
        auto updatable = dynamic_cast<World::UpdatableInstance*>(instance);
        if (updatable != nullptr)
            _instances_updatable.emplace_back(updatable);
    }
    
    void Scene::begin_update() {
        spatial_initialise();
        
        for (World::UpdatableInstance* instance : _instances_updatable) {
            if (instance != nullptr)
                instance->begin_update();
        }
    }
    
    void Scene::draw(Graphics::Renderer *renderer) {
        //Draw background
        if (background != nullptr) {
            Rectangle back_src = background->get_source_rectangle();
            renderer->draw_texture(background->get_current_texture(), Vector2(), &back_src, background_depth, 0,
                                   Graphics::Color::white, background->origin);
        }
        
        for (World::Instance* instance : _instances) {
            if (instance != nullptr) {
                if (safezone_enabled) {
                    if (!safezone.intersects(instance->get_bounds())) {
                        if (!draw_outside_safezone) {
                            continue;
                        }
                    }
                }

                instance->draw(renderer);
            }
        }
    }
    
    void Scene::end_update() {
        for (World::UpdatableInstance* instance : _instances_updatable) {
            if (instance != nullptr)
                instance->end_update();
        }
    }
    
    std::vector<World::Instance*> Scene::get_instances_at(Vector2 position, bool bound_by_safezone) {
        std::vector<World::Instance*> ret;
        
        if (bound_by_safezone) {
            for (World::Instance* instance : _instances) {
                if (instance != nullptr) {
                    if (instance->get_position() == position) {
                        if (safezone.contains(instance->get_position())) {
                            ret.emplace_back(instance);
                        }
                    }
                }
            }
        } else {
            for (World::Instance* instance : _instances) {
                if (instance != nullptr) {
                    if (instance->get_position() == position) {
                        ret.emplace_back(instance);
                    }
                }
            }
        }
        
        return ret;
    }
    
    std::vector<World::Instance*> Scene::get_nearby_instances(World::Instance* instance) {
        std::vector<World::Instance*> ret;
        
        std::vector<int> spaces = spatial_get_spaces(instance);
        
        for (int space : spaces) {
            for (World::Instance* inst : _spatial_map[space]) {
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
    
    void Scene::remove_instance(World::Instance *instance) {
        //Remove instance from state
        _instances.erase(std::remove(_instances.begin(), _instances.end(), instance), _instances.end());

        //Remove if updatable
        auto updatable = dynamic_cast<World::UpdatableInstance*>(instance);
        if (updatable != nullptr)
            _instances_updatable.erase(std::remove(_instances_updatable.begin(), _instances_updatable.end(), updatable), _instances_updatable.end());
    }
    
    std::vector<int> Scene::spatial_get_spaces(World::Instance* instance) {
        return spatial_get_spaces(instance->get_bounds());
    }
    
    std::vector<int> Scene::spatial_get_spaces(Rectangle rectangle) {
        std::vector<int> spaces_in;
        
        Vector2 topleft = rectangle.top_left();
        Vector2 topright = rectangle.top_right();
        Vector2 bottomleft = rectangle.bottom_left();
        Vector2 bottomright = rectangle.bottom_right();
        
        spatial_add_to_space(topleft, &spaces_in);
        spatial_add_to_space(topright, &spaces_in);
        spatial_add_to_space(bottomleft, &spaces_in);
        spatial_add_to_space(bottomright, &spaces_in);
        
        return spaces_in;
    }
    
    void Scene::spatial_move_instance(Rectangle old_bounds, Rectangle new_bounds, World::Instance* instance) {
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
        for (World::UpdatableInstance* instance : _instances_updatable) {
            if (instance != nullptr)
                instance->update();
        }

        for (World::Instance* instance : _instances) {
            if (instance != nullptr) {
                //Update sprite
                if (instance->sprite != nullptr)
                    instance->sprite->update();
            }
        }
    }
}