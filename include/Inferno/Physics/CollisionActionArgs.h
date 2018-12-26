//
// Created by Reece Mackie on 12/12/18.
//

#ifndef INFERNO_COLLISIONACTIONARGS_H
#define INFERNO_COLLISIONACTIONARGS_H

namespace Inferno {
    namespace World {
        class Instance;
    }
    
    namespace Physics {
        struct CollisionActionArgs {
            World::Instance* colliding_instance;
            
            //Constructors
            
            CollisionActionArgs() {
                colliding_instance = nullptr;
            }
    
            explicit CollisionActionArgs(World::Instance* instance) {
                colliding_instance = instance;
            }
        };
    }
}

#endif //INFERNO_COLLISIONACTIONARGS_H
