//
// Created by Reece Mackie on 25/11/18.
//

#include "Inferno/UI/Control.h"

namespace Inferno {
    namespace UI {
        //Constructors
        
        Control::Control(Inferno::Vector2 position) : position(position) {
        
        }
        
        //Methods
        
        void Control::draw(Inferno::Graphics::Renderer *renderer) {
            //Draw back color
            renderer->draw_rectangle(get_bounds(), back_color);
            
            //Draw background
            if (background != nullptr) {
                Rectangle back_src = background->get_source_rectangle();
                renderer->draw_texture(background->get_current_texture(), position, &back_src, 0, Graphics::Color::white, background->origin);
            }
            
            //Draw highlight
            if (highlight_on_hover && highlight != nullptr) {
                if (state == Hover) {
                    Rectangle highlight_src = highlight->get_source_rectangle();
                    renderer->draw_texture(highlight->get_current_texture(), position, &highlight_src, 0, Graphics::Color::white, highlight->origin);
                }
            }
            
            //Draw border
            if (border_width > 0) {
                auto border_x = (int) (position.x - border_width);
                auto border_y = (int) (position.y - border_width);
                auto border_x2 = (int) (position.x + get_bounds().width + border_width);
                auto border_y2 = (int) (position.y + get_bounds().height + border_width);
    
                renderer->draw_rectangle(Rectangle(border_x, border_y, border_x2, border_y2), border_color, 0, false,
                                         border_width);
            }
        }
        
        Rectangle Control::get_bounds() {
            return {(int)position.x, (int)position.y, width, height};
        }
        
        void Control::update() {
            //Get mouse state
            //Input::MouseState state = Input::Mouse::get_state();
        }
    }
}