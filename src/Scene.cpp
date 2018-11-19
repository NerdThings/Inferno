//
// Created by Reece Mackie on 15/11/18.
//

#include <algorithm>

#include "Scene.h"

namespace Inferno {
    //Constructors
    
    Scene::Scene(Inferno::Game *parent_game, int width, int height) : parent_game(parent_game), height(height), width(width) {
    
    }
    
    //Methods
    
    void Scene::add_instance(Instance *instance) {
        //Add the instance to the state
        _instances.emplace_back(instance);
    }
    
    void Scene::begin_update() {
        for (Instance* instance : _instances) {
            if (instance != nullptr)
                instance->begin_update();
        }
    }
    
    void Scene::draw(Graphics::Renderer *renderer) {
        for (Instance* instance : _instances) {
            if (instance != nullptr)
                instance->draw(renderer);
        }
    }
    
    void Scene::end_update() {
        for (Instance* instance : _instances) {
            if (instance != nullptr)
                instance->end_update();
        }
    }
    
    void Scene::loaded() {
        //User can add code to load the state
    }
    
    void Scene::remove_instance(Instance *instance) {
        //Remove instance from state
        _instances.erase(std::remove(_instances.begin(), _instances.end(), instance), _instances.end());
    }
    
    void Scene::unloaded() {
        //User can add code to unload the state
    }
    
    void Scene::update() {
        for (Instance* instance : _instances) {
            if (instance != nullptr)
                instance->update();
        }
    }
}