//
// Created by Reece Mackie on 25/11/18.
//

#include "Inferno/Graphics/Camera.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        Camera::Camera(Scene* parent_scene, float zoom) : _parent_scene(parent_scene), zoom(zoom) {
            position = get_viewport_center();
        }
        
        //Methods
        
        void Camera::center_on(Vector2 position) {
            this->position = position;
        }
        
        Matrix Camera::get_translation_matrix() {
            Matrix ret;
            ret = ret * Matrix::create_translation(-(int)position.x, -(int)position.y, 0);
            ret = ret * Matrix::create_rotation_z(rotation);
            ret = ret * Matrix::create_scale(zoom, zoom, 1);
            ret = ret * Matrix::create_translation(Vector3(get_viewport_center(), 0));
            return ret;
        }
        
        Vector2 Camera::get_viewport_center() {
            return { get_viewport_width() * 0.5f, get_viewport_height() * 0.5f};
        }
        
        int Camera::get_viewport_height() {
            return _parent_scene->parent_game->get_virtual_dimensions().y;
        }
    
        int Camera::get_viewport_width() {
            return _parent_scene->parent_game->get_virtual_dimensions().x;
        }
        
        Rectangle Camera::get_viewport_world_boundary() {
            Vector2 viewport_corner = screen_to_world(Vector2());
            Vector2 viewport_bottom_corner = screen_to_world(Vector2(get_viewport_width(), get_viewport_height()));
            
            return {viewport_corner.x, viewport_corner.y, (viewport_bottom_corner.x - viewport_corner.x), (viewport_bottom_corner.y - viewport_corner.y)};
        }
        
        Vector2 Camera::screen_to_world(Vector2 screen_position) {
            return Vector2::transform(screen_position, Matrix::invert(get_translation_matrix()));
        }
        
        Vector2 Camera::world_to_screen(Vector2 world_position) {
            return Vector2::transform(world_position, get_translation_matrix());
        }
        
        bool Camera::drawable(Inferno::Rectangle rect) {
            Vector2 top_left = rect.top_left();
            Vector2 top_right = rect.top_right();
            Vector2 bottom_left = rect.bottom_left();
            Vector2 bottom_right = rect.bottom_right();
            
            Rectangle boundary = get_viewport_world_boundary();
    
            return boundary.contains(top_left) || boundary.contains(top_right) || boundary.contains(bottom_left) || boundary.contains(bottom_right);
        }
    }
}