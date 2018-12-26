//
// Created by Reece Mackie on 15/12/18.
//

#include "Inferno/Physics/CircleCollider.h"
#include "Inferno/Physics/RectangleCollider.h"
#include "Inferno/Physics/SpriteCollider.h"
#include "Inferno/World/Instance.h"
#include <stdexcept>

namespace Inferno {
    namespace Physics {
        //Private Methods
    
        bool SpriteCollider::per_pixel(Graphics::Sprite *sprite_a, Graphics::Sprite *sprite_b, Rectangle bounds_a, Rectangle bounds_b) {
            std::vector<Graphics::Color> colordata_a = sprite_a->get_current_texture()->get_data();
            std::vector<Graphics::Color> colordata_b = sprite_b->get_current_texture()->get_data();
            Rectangle source_a = sprite_a->get_source_rectangle();
            Rectangle source_b = sprite_b->get_source_rectangle();
    
            //Animation check
            if (sprite_a->is_animated() || sprite_b->is_animated())
                throw std::runtime_error("Cannot per pixel check animated sprites.");
            
            //Build bounding box of collision area
            int left = MathHelper::maximum(bounds_a.x, bounds_b.x);
            int top = MathHelper::maximum(bounds_a.y, bounds_b.y);
            int width = MathHelper::minimum(bounds_a.width, bounds_b.width);
            int height = MathHelper::minimum(bounds_a.height, bounds_b.height);
    
            //Check pixels
            for (int x = left; x < left + width; x++) {
                for (int y = top; y < top + height; y++) {
                    int color_a_x = x - bounds_a.x + source_a.x;
                    int color_a_y = y - bounds_a.y + source_a.y;
                    int color_a_i = color_a_y * sprite_a->get_current_texture()->width() + color_a_x;
                    int color_b_x = x - bounds_b.x + source_b.x;
                    int color_b_y = y - bounds_b.y + source_b.y;
                    int color_b_i = color_b_y * sprite_b->get_current_texture()->width() + color_b_x;
            
                    Graphics::Color color_a = colordata_a[color_a_i];
                    Graphics::Color color_b = colordata_b[color_b_i];
            
                    if (color_a.a() > 0 && color_b.a() > 0)
                        return true;
                }
            }
    
            //No collision
            return false;
        }
    
        bool SpriteCollider::pixel_to_rectangle(Graphics::Sprite *sprite, Rectangle bounds_a, Rectangle bounds_b) {
            //Get sprite data
            std::vector<Graphics::Color> color_data = sprite->get_current_texture()->get_data();
            Rectangle source = sprite->get_source_rectangle();
            
            //Build bounding box of collision area
            int left = MathHelper::maximum(bounds_a.top_left().x, bounds_b.top_left().x);
            int top = MathHelper::maximum(bounds_a.top_left().y, bounds_b.top_left().y);
            int width = MathHelper::minimum(bounds_a.bottom_right().x, bounds_b.bottom_right().x) - left;
            int height = MathHelper::minimum(bounds_a.bottom_right().y, bounds_b.bottom_right().y) - top;
            
            //Check for animations
            if (sprite->is_animated())
                throw std::runtime_error("Cannot per pixel check animated sprites");
            
            //Look for collision
            for (int x = left; x < left + width; x++) {
                for (int y = top; y < top + height; y++) {
                    int color_x = x - bounds_a.top_left().x + source.top_left().x;
                    int color_y = y - bounds_a.top_left().y + source.top_left().y;
                    int color_i = color_y * sprite->get_current_texture()->width() + color_x;
                    
                    Graphics::Color color = color_data[color_i];
                    
                    //Check for collision
                    if (color.a() > 0 && bounds_b.contains(Vector2(x, y)))
                        return true;
                }
            }
    
            //No collision
            return false;
        }
        
        //Constructors
        
        SpriteCollider::SpriteCollider(World::Instance *instance) : BaseCollider(instance), sprite(instance->sprite) {}
        
        SpriteCollider::SpriteCollider(World::Instance *instance, Graphics::Sprite *sprite) : BaseCollider(instance), sprite(sprite) {}
        
        //Methods
        
        Rectangle SpriteCollider::create_rectangle() {
            Rectangle inst_bounds = _parent_instance->get_bounds();
            return Rectangle(inst_bounds.top_left(), Vector2(sprite->width, sprite->height));
        }
        
        bool SpriteCollider::is_colliding(BaseCollider *b) {
            if (sprite == nullptr)
                return false;
            
            //Get colliders
            auto* circle_collider = b->as<CircleCollider>();
            auto* sprite_collider = b->as<SpriteCollider>();
            auto* rect_collider = b->as<RectangleCollider>();
    
            //Collider types
            if (rect_collider != nullptr) {
                //Per pixel collision
                //This check makes sure everything is axis aligned
                if (rect_collider->get_rectangle().axis_aligned()) {
                    if (_parent_instance->get_bounds().axis_aligned()) {
                        if (sprite->get_source_rectangle().axis_aligned()) {
                            return pixel_to_rectangle(sprite, create_rectangle(), rect_collider->get_rectangle());
                        }
                    }
                }
                
                //Rectangle based collision
                if (create_rectangle().intersects(rect_collider->get_rectangle())) {
                    return true;
                }
            } else if (sprite_collider != nullptr) {
                //Per pixel collision
                //This check makes sure everything is axis aligned
                if (sprite_collider->_parent_instance->get_bounds().axis_aligned()) {
                    if (_parent_instance->get_bounds().axis_aligned()) {
                        if (sprite_collider->sprite->get_source_rectangle().axis_aligned()) {
                            if (sprite->get_source_rectangle().axis_aligned()) {
                                return per_pixel(sprite, sprite_collider->sprite, create_rectangle(), sprite_collider->create_rectangle());
                            }
                        }
                    }
                }
                
                //Do rectangle collision check
                if (create_rectangle().intersects(sprite_collider->create_rectangle())) {
                    return true;
                }
            } else if (circle_collider != nullptr) {
                if (circle_collider->circle.intersects(create_rectangle())) {
                    return true;
                }
            } else {
                //TODO: Do collision checks for other colliders
            }
    
            return false;
        }
    }
}