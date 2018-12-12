//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/CircleCollider.h"
#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Instance.h"
#include "Inferno/Scene.h"

namespace Inferno {
    namespace Physics {
        //Private methods
        
        bool CircleCollider::run_check(bool fire_events) {
            //Pass variable
            bool pass = false;
            
            //Get the current scene
            Scene* current_scene = _parent_instance->parent_scene;
    
            //Get all instances spatially near the parent instance
            std::vector<Instance*> nearby = current_scene->get_nearby_instances(_parent_instance);
    
            //Search for a rectangle collision with other colliders
            for (Instance* instance : nearby) {
                if (instance == _parent_instance || instance->type != colliding_instance_type)
                    continue;
        
                //Get colliders
                CircleCollider* circle_collider = instance->collider->as<CircleCollider>();
                RectangleCollider* rect_collider = instance->collider->as<RectangleCollider>();
        
                //Collider types
                if (circle_collider != nullptr) {
                    if (circle.intersects(circle_collider->circle)) {
                        pass = true;
                        if (fire_events) {
                            on_collide.invoke(CollisionActionArgs(instance));
                        } else {
                            break;
                        }
                    }
                } else if (rect_collider != nullptr) {
                    Rectangle test = rect_collider->get_rectangle();
                    if (circle.intersects(test)) {
                        pass = true;
                        if (fire_events) {
                            on_collide.invoke(CollisionActionArgs(instance));
                        } else {
                            break;
                        }
                    }
                } else {
                    //TODO: Do collision checks for other colliders
                }
            }
            return pass;
        }
        
        //Constructors
        
        CircleCollider::CircleCollider(Inferno::Instance *instance) : BaseCollider(instance) {}
        
        //Methods
        
        bool CircleCollider::check_collisions() {
            return run_check();
        }
        
        bool CircleCollider::check_collisions(Inferno::Vector2 position) {
            //Save current position
            Vector2 last_position = _parent_instance->get_position();
            
            //Set to target position
            _parent_instance->set_position(position);
    
            //Run check
            bool collide = run_check();
    
            //Restore position
            _parent_instance->set_position(last_position);
    
            return collide;
        }
        
        void CircleCollider::update() {
            run_check(true);
        }
    }
}