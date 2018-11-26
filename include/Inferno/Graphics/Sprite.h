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
        class INFERNO_API Sprite {
            //Fields
            
            std::vector<Texture2D*> _textures;
            bool _spritesheet = true;

        public:
            //Fields
            
            float animation_timer = 0;
            int current_frame = 0;
            int frame_width = 0;
            int frame_height = 0;
            int height = 0;
            float image_speed = 0;
            Vector2 origin = Vector2(0, 0);
            float rotation;
            int width = 0;
            
            //Constructors
            
            Sprite();
            Sprite(Texture2D* texture, Vector2 origin);
            Sprite(Texture2D* texture, Vector2 origin, int frame_width, int frame_height, float image_speed = 30, int starting_frame = 0, double rotation = 0);
            
            //Disabled for now
            //Sprite(std::vector<Texture2D*> textures, Vector2 origin, float image_speed = 30, int starting_frame = 0, double rotation = 0);
            
            //Deconstructors
            
            ~Sprite();
            
            //Methods
    
            Texture2D* get_current_texture();
            int get_frame_x();
            int get_frame_y();
            Rectangle get_source_rectangle();
            bool is_animated();
            void update();
        };
    }
}

#endif //INFERNO_SPRITE_H
