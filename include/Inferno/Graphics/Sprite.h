//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_SPRITE_H
#define INFERNO_SPRITE_H

#include "Inferno/Inferno.h"

#include <vector>

#include "Renderer.h"
#include "Texture2D.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    namespace Graphics {
        /*
         * A graphics sprite.
         * This is an extended texture effectively.
         */
        class INFERNO_API Sprite {
            //Fields
            
            /*
             * The list of textures
             */
            std::vector<Texture2D*> _textures;
            
            /*
             * Whether or not this is a spritesheet
             */
            bool _spritesheet = true;

        public:
            //Fields
            
            /*
             * The animation timer
             */
            float animation_timer = 0;
            
            /*
             * The current frame
             */
            int current_frame = 0;
            
            /*
             * The width of a frame
             */
            int frame_width = 0;
            
            /*
             * The height of a frame
             */
            int frame_height = 0;
            
            /*
             * The sprite height
             */
            int height = 0;
            
            /*
             * The sprite image speed
             */
            float image_speed = 0;
            
            /*
             * The sprite origin
             */
            Vector2 origin = Vector2(0, 0);
            
            /*
             * The sprite width
             */
            int width = 0;
            
            //Constructors
            
            /*
             * Create a new Sprite
             */
            Sprite();
            
            /*
             * Create a new Sprite
             */
            Sprite(Texture2D* texture, Vector2 origin);
            
            /*
             * Create a new Sprite
             */
            Sprite(Texture2D* texture, Vector2 origin, int frame_width, int frame_height, float image_speed = 30, int starting_frame = 0);
            
            //Disabled for now
            //Sprite(std::vector<Texture2D*> textures, Vector2 origin, float image_speed = 30, int starting_frame = 0, double rotation = 0);
            
            //Deconstructors
            
            /*
             * Cleanup a Deleted Sprite
             */
            ~Sprite();
            
            //Methods
    
            /*
             * Get the current texture
             */
            Texture2D* get_current_texture();
            
            /*
             * Get the frame x coordinate
             */
            int get_frame_x();
            
            /*
             * Get the frame y coordinate
             */
            int get_frame_y();
            
            /*
             * Get the source rectangle
             */
            Rectangle get_source_rectangle();
            
            /*
             * Whether or not the sprite is animated
             */
            bool is_animated();
            
            /*
             * Update the sprite
             */
            void update();
        };
    }
}

#endif //INFERNO_SPRITE_H
