//
// Created by Reece Mackie on 14/12/18.
//

#ifndef INFERNO_SPRITECOLLIDER_H
#define INFERNO_SPRITECOLLIDER_H

#include "Inferno/Graphics/Sprite.h"
#include "Inferno/Physics/BaseCollider.h"
#include "Inferno/Inferno.h"

namespace Inferno {
    namespace Physics {
        /*
         * A Sprite Collider will check for collisions with an instance using a sprite.
         */
        class INFERNO_API SpriteCollider : public BaseCollider {
            //Methods
            
            bool per_pixel(Graphics::Sprite *sprite_a, Graphics::Sprite *sprite_b, Rectangle bounds_a, Rectangle bounds_b);
            bool pixel_to_rectangle(Graphics::Sprite *sprite, Rectangle bounds_a, Rectangle bounds_b);
        public:
            //Fields
            
            /*
             * The sprite used for sprite collisions
             */
            Graphics::Sprite* sprite = nullptr;
            
            //Constructors
            
            /*
             * Create a new Sprite Collider using the instance's texture
             */
            SpriteCollider(World::Instance* instance);
       
            /*
             * Create a new Sprite Collider using a custom sprite
             */
            SpriteCollider(World::Instance* instance, Graphics::Sprite* sprite);
            
            //Methods
            
            Rectangle create_rectangle();
            
            bool is_colliding(BaseCollider* b) override;
        };
    }
}

#endif //INFERNO_SPRITECOLLIDER_H
