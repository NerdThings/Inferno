//
// Created by Reece Mackie on 12/12/18.
//

#include "Inferno/Physics/BaseCollider.h"
#include "Inferno/World/Instance.h"

namespace Inferno {
    namespace Physics {
        //Private Methods
        
        bool BaseCollider::run_check(bool fire_events) {
            //This is the default action
            
            //Pass variable
            bool pass = false;
    
            //Get the current scene
            Scene* current_scene = _parent_instance->parent_scene;
    
            //Get all instances spatially near the parent instance
            std::vector<World::Instance*> nearby = current_scene->get_nearby_instances(_parent_instance);
    
            //Search for a rectangle collision with other colliders
            for (World::Instance* instance : nearby) {
                //This looks pointless, but it fixes some very strange loop issues
                if (dynamic_cast<World::Instance*>(instance) == nullptr)
                    continue;
                
                //Skip our parent and instances that don't fit the correct type
                if (instance == _parent_instance || instance->type != colliding_instance_type)
                    continue;
        
                //Check using our logic if there is a collision
                pass = is_colliding(instance->collider);
        
                //Check using the other collider logic if there is a collision
                //This is good so that custom colliders can interact with base colliders
                if (!pass)
                    pass = instance->collider->is_colliding(this);
        
                if (pass) {
                    if (fire_events) {
                        on_collide.invoke(CollisionActionArgs(instance));
                    } else {
                        break;
                    }
                }
            }
    
            return pass;
        }
        
        //Constructors
        
        BaseCollider::BaseCollider(World::Instance *parent_instance) {
            _parent_instance = parent_instance;
        }
        
        //Methods
        
        bool BaseCollider::check_collisions(){
            //Default action
            return run_check();
        }
    
        /*
         * Check collisions with the player at position.
         * THIS WILL NOT CHANGE ANYTHING OTHER THAN THE PLAYER POSITION TO ACCOUNT FOR POSITION PROVIDED!
         */
        bool BaseCollider::check_collisions(Vector2 position){
            //This is the default action
            
            //Save current position
            Vector2 last_position = _parent_instance->get_position();
    
            //Set to target position
            _parent_instance->set_position(position);
    
            //Check for collision
            bool pass = run_check();
    
            //Restore position
            _parent_instance->set_position(last_position);
    
            return pass;
        }
        
        bool BaseCollider::is_colliding(BaseCollider* b) {
            //Return false, this collider is just a base
            return false;
        }
        
        void BaseCollider::update() {
            run_check(true);
        }
    }
}
