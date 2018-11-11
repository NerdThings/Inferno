#include "Scene.h"
#include "Instance.h"
#include "Graphics/Renderer.h"

namespace Inferno {
    
    using namespace Graphics;
    
    //Constructors

    Scene::Scene(Game* parent_game, int width, int height, int space_size) : camera(Camera(this))
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

    ///Instance Management
    
    void Scene::add_instance(Instance* instance)
    {
		_instances.push_back(instance);
    }
    
    void Scene::remove_instance(Instance* instance)
    {
    
    }
    
    void Scene::clear_instances()
    {
        _instances.clear();
    }
    
    std::vector<Instance*> Scene::get_instances_at(Vector2* position, bool bounds_safezone)
    {
        return std::vector<Instance*>();
    }
    
    ///Runtime

    void Scene::begin_update()
    {
        
    }

    void Scene::draw(Graphics::Renderer* renderer)
    {
        //Begin rendering with camera
        //TODO: Work out what is wrong with the camera.
        //renderer->begin(camera.get_translation_matrix());
        renderer->begin();
        
        //TODO: Backgrounds
        
        //TODO: Draw instances
        
        //Draw a rectangle for now so we know this works
        renderer->draw_rectangle(Rectangle(10, 10, 200, 200), Color(0.4f, 0.2f, 0.3f, 0.6f), 1);
        
        renderer->end();
        
        //TODO: UserInterface draw here
    }
    
    void Scene::end_update()
    {
    
    }
    
    void Scene::loaded() {
    
    }
    
    void Scene::unloaded() {
    
    }
    
    void Scene::update()
    {
    
    }

    ///Spatial Hashing
    
    std::vector<Instance*> Scene::get_nearby(Instance* instance)
    {
        return std::vector<Instance*>();
    }
    
    void Scene::spatial_add_to_space(Vector2* position, std::vector<int> spaces)
    {
    
    }
    
    void Scene::spatial_initialise()
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
    
    void Scene::spatial_move_instance(Rectangle* old_bounds, Rectangle* new_bounds, Instance* instance)
    {
    
    }
    
    void Scene::spatial_register_instance(Instance* instance)
    {
    
    }
}