//
// Created by Reece Mackie on 16/11/18.
//

#include "Inferno/Graphics/Sprite.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        Sprite::Sprite() = default;
        
        Sprite::Sprite(Texture2D* texture, Vector2 origin) : origin(origin), _spritesheet(true), width(texture->width()), height(
                texture->height()), frame_width(
                texture->width()), frame_height(texture->height()) {
            //Add texture
            _textures.emplace_back(texture);
        }
        
        Sprite::Sprite(Texture2D* texture, Vector2 origin, int frame_width, int frame_height, float image_speed, int starting_frame) : origin(origin), width(frame_width), height(frame_height), frame_width(frame_width), frame_height(frame_height), image_speed(image_speed), current_frame(starting_frame), _spritesheet(true) {
            //Add texture
            _textures.emplace_back(texture);
        }
        
        //Sprite::Sprite(std::vector<Texture2D*> textures, Vector2 origin, float image_speed, int starting_frame, double rotation) : _textures(textures), origin(origin), image_speed(image_speed), current_frame(starting_frame), _spritesheet(false) {}
        
        //Deconstructors
        
        Sprite::~Sprite() {
            _textures.clear();
        }
        
        //Methods
    
        Texture2D* Sprite::get_current_texture() {
            if (_spritesheet)
                return _textures.at(0);
            else
                return _textures.at(current_frame);
        }
        
        int Sprite::get_frame_x() {
            if (!_spritesheet)
                return 0;
    
            int x = 0;
            for (int i = 0; i < current_frame; i++) {
                x += frame_width;
                if (x > get_current_texture()->width())
                    x = 0;
            }
    
            return x;
        }
        
        int Sprite::get_frame_y() {
            if (!_spritesheet)
                return 0;
    
            int x = 0;
            int y = 0;
            for (int i = 0; i < current_frame; i++) {
                x += frame_width;
                if (x > get_current_texture()->width()) {
                    x = 0;
                    y += frame_height;
                }
            }
    
            return y;
        }
        
        Rectangle Sprite::get_source_rectangle() {
            if (_spritesheet) {
                return Rectangle(get_frame_x(), get_frame_y(), frame_width, frame_height);
            } else {
                return Rectangle(0, 0, get_current_texture()->width(), get_current_texture()->height());
            }
        }
        
        bool Sprite::is_animated() {
            return (frame_height != get_current_texture()->height() || frame_width != get_current_texture()->width());
        }
        
        void Sprite::update() {
            if (!is_animated())
                return;
            
            //Increment timer
            animation_timer++;
            
            //If we didn't the goal, leave
            if (animation_timer <= image_speed)
                return;
            
            //Reset timer
            animation_timer = 0;
            
            //Increase current frame
            current_frame++;
            
            //Reset if out of range
            if (_spritesheet) {
                int count = (get_current_texture()->width() / frame_width) * (get_current_texture()->height() / frame_height);
                
                if (current_frame > count - 1)
                    current_frame = 0;
            } else {
                if (current_frame > _textures.size() - 1)
                    current_frame = 0;
            }
        }
    }
}