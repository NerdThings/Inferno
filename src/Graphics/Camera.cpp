#include "Game.h"
#include "Scene.h"
#include "Graphics/Camera.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        Camera::Camera(Scene* parent_scene, float zoom) {
            _parent_scene = parent_scene;
            zoom = zoom;
            rotation = 0;
        }
        
        //Methods
        
        void Camera::center_on(Inferno::Vector2 position) {
            //TODO: Calculate if the outside will be visible
            position = position;
        }
        
        Matrix Camera::get_translation_matrix() {
            return Matrix::create_translation(-(int)position.x, -(int)position.y, 0)
                   * Matrix::create_rotation_z(rotation)
                   * Matrix::create_scale(zoom, zoom, 1)
                   * Matrix::create_translation(Vector3(get_viewport_center(), 0));
        }
        
        Rectangle Camera::get_viewport_boundary() {
            Vector2 viewport_corner = screen_to_world(Vector2(0, 0));
            Vector2 viewport_bottom_corner = screen_to_world(Vector2(get_viewport_width(), get_viewport_height()));
            
            return {(int)viewport_corner.x,
                    (int)viewport_corner.y,
                    (int)(viewport_bottom_corner.x - viewport_corner.x),
                    (int)(viewport_bottom_corner.y - viewport_corner.y)};
        }
        
        Vector2 Camera::get_viewport_center() {
            return {get_viewport_width() * 0.5f,
                    get_viewport_height() * 0.5f};
        }
        
        int Camera::get_viewport_height() {
            Point dimensions = _parent_scene->parent_game->get_virtual_dimensions();
            return dimensions.y;
        }
        
        int Camera::get_viewport_width() {
            Point dimensions = _parent_scene->parent_game->get_virtual_dimensions();
            return dimensions.y;
        }
        
        Vector2 Camera::screen_to_world(Inferno::Vector2 screen_position) {
            return Vector2::transform(screen_position, Matrix::invert(get_translation_matrix()));
        }
        
        Vector2 Camera::world_to_screen(Inferno::Vector2 world_position) {
            return Vector2::transform(world_position, get_translation_matrix());
        }
    }
}