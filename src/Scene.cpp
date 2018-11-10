#include "Scene.h"
#include "Instance.h"

namespace Inferno {
    //Constructors

    Scene::Scene(Game* parent_game, int width, int height, int space_size)
    {
        //Set parameter arguments
		this->parent_game = parent_game;
		this->width = width;
		this->height = height;
		this->space_size = space_size;

        //Set other defaults
		this->background_depth = 99.0f;
		this->safezone_enabled = false;
		this->safezone = nullptr;
		this->_instances = std::vector<Instance*>();

    }

    //Methods

    void Scene::add_instance(Instance* instance)
    {
		_instances.push_back(instance);
    }

    void Scene::begin_update()
    {
        
    }

    void Scene::clear_instances()
    {
		_instances.clear();
    }

    void Scene::draw()
    {
        
    }

    void Scene::end_update()
    {
        
    }

    std::vector<Instance*> Scene::get_instances_at(Vector2* position, bool bounds_safezone)
    {
		return std::vector<Instance*>();
    }

    std::vector<Instance*> Scene::get_nearby(Instance* instance)
    {
		return std::vector<Instance*>();
    }

    void Scene::remove_instance(Instance* instance)
    {
        
    }

    void Scene::spatial_add_to_space(Vector2* position, std::vector<int> spaces)
    {
        
    }

    std::vector<int> Scene::spatial_get_spaces(Instance* instance)
    {
		return std::vector<int>();
    }

    std::vector<int> Scene::spatial_get_spaces(Rectangle* rect)
    {
		return std::vector<int>();
    }

    void Scene::spatial_initialise()
    {
        
    }

    void Scene::spatial_move_instance(Rectangle* old_bounds, Rectangle* new_bounds, Instance* instance)
    {
        
    }

    void Scene::spatial_register_instance(Instance* instance)
    {
        
    }

    void Scene::update()
    {
        
    }


}