//
// Created by Reece Mackie on 15/11/18.
//

#ifndef INFERNO_SPRITE_H
#define INFERNO_SPRITE_H

#include "Inferno.h"

#include <vector>

#include "Graphics/Renderer.h"
#include "Graphics/Texture2D.h"
#include "Rectangle.h"
#include "Vector2.h"

namespace Inferno {
    namespace Graphics {
        class INFERNO_API Sprite {
            //Fields
            
            std::vector<Texture2D*> _textures;
            bool _spritesheet;

        public:
            //Fields
            
            float animation_timer;
            int current_frame;
            int frame_width;
            int frame_height;
            int height;
            float image_speed;
            Vector2 origin;
            //float rotation; Will be implemented once rotation is supported
            int width;
            
            //Constructors
            
            Sprite();
            Sprite(Texture2D* texture, Vector2 origin);
            Sprite(Texture2D* texture, Vector2 origin, int frame_width, int frame_height, float image_speed = 30, int starting_frame = 0, double rotation = 0);
            Sprite(std::vector<Texture2D*> textures, Vector2 origin, float image_speed = 30, int starting_frame = 0, double rotation = 0);
            
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
