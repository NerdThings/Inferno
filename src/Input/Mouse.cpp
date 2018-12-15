//
// Created by Reece Mackie on 17/11/18.
//

#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Input/Mouse.h"
#include "Inferno/Game.h"
#include "Inferno/GameWindow.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    namespace Input {
        //Internal static fields
#ifdef INFERNO
        int Mouse::internal_scroll_x = 0;
        int Mouse::internal_scroll_y = 0;
        bool Mouse::internal_left = false;
        bool Mouse::internal_middle = false;
        bool Mouse::internal_right = false;
        bool Mouse::internal_x1 = false;
        bool Mouse::internal_x2 = false;
        int Mouse::internal_x = 0;
        int Mouse::internal_y = 0;
        Matrix Mouse::transform_matrix = Matrix();
#endif
        
        //Static Methods
        
        void Mouse::clear_left_button() {
            internal_left = false;
        }
        
        void Mouse::clear_middle_button(){
            internal_middle = false;
        }
        
        void Mouse::clear_right_button() {
            internal_right = false;
        }
        
        void Mouse::clear_x_button_1() {
            internal_x1 = false;
        }
        
        void Mouse::clear_x_button_2() {
            internal_x2 = false;
        }
        
        MouseState Mouse::get_state(Game* current_game) {
            //Initial position
            Vector2 pos = Vector2(internal_x, internal_y);
            
            //Account for resolution independance
            
            //Get window dimensions
            Vector2 window_size = current_game->game_window->get_size();
            Vector2 virtual_size = current_game->get_virtual_dimensions();
    
            //Set view size
            float view_width = window_size.x;
            float view_height = window_size.y;
    
            //Calculate ratios
            float output_aspect = window_size.x / float(window_size.y);
            float preferred_aspect = virtual_size.x / float(virtual_size.y);
    
            //Init bar dimensions
            float bar_width = 0;
            float bar_height = 0;
    
            //Calculate view
            if (output_aspect <= preferred_aspect) {
                view_height = int(window_size.x / preferred_aspect + 0.5f);
                bar_height = (window_size.y - view_height) / 2;
            } else {
                view_width = int(window_size.y * preferred_aspect + 0.5f);
                bar_width = (window_size.x - view_width) / 2;
            }
            
            //Apply translation
            pos.x -= bar_width;
            pos.y -= bar_height;
            pos.x *= virtual_size.x;
            pos.x /= view_width;
            pos.y *= virtual_size.y;
            pos.y /= view_height;
            
            //Apply graphics device view matrix
            pos = Vector2::transform(pos, transform_matrix);
            
            //Create state
            MouseState state;
            state.x = int(pos.x);
            state.y = int(pos.y);
            state.left_button = internal_left ? Pressed : Released;
            state.middle_button = internal_middle ? Pressed : Released;
            state.right_button = internal_right ? Pressed : Released;
            state.x_button_1 = internal_x1 ? Pressed : Released;
            state.x_button_2 = internal_x2 ? Pressed : Released;
            state.scroll_wheel_y = internal_scroll_y;
            state.scroll_wheel_x = internal_scroll_x;
            
            return state;
        }
        
        void Mouse::use_camera(Graphics::Camera *camera) {
            transform_matrix = Matrix::invert(camera->get_translation_matrix());
        }
        
        void Mouse::use_transform_matrix(Matrix matrix) {
            transform_matrix = matrix;
        }
    }
}