//
// Created by Reece Mackie on 25/11/18.
//

#include "Inferno/UI/Control.h"

namespace Inferno {
    namespace UI {
        //Constructors
        
        Control::Control(Game* parent_game, Vector2 position) : _parent_game(parent_game), position(position) {
        
        }
        
        //Methods
        
        void Control::draw(Inferno::Graphics::Renderer *renderer) {
            //Offset position
            Vector2 pos = position + container_offset;
            
            //Draw back color
            renderer->draw_rectangle(get_bounds(), back_color);
            
            //Draw background
            if (background != nullptr) {
                Rectangle back_src = background->get_source_rectangle();
                renderer->draw_texture(background->get_current_texture(), pos, &back_src, 0, 0, Graphics::Color::white, background->origin);
            }
            
            //Draw highlight
            if (highlight_on_hover && highlight != nullptr) {
                if (state == Hover) {
                    Rectangle highlight_src = highlight->get_source_rectangle();
                    renderer->draw_texture(highlight->get_current_texture(), pos, &highlight_src, 0, 0, Graphics::Color::white, highlight->origin);
                }
            }
            
            //Draw border
            if (border_width > 0) {
                auto border_x = (int) (pos.x - border_width);
                auto border_y = (int) (pos.y - border_width);
                auto border_x2 = (int) (pos.x + get_bounds().width + border_width);
                auto border_y2 = (int) (pos.y + get_bounds().height + border_width);
    
                //renderer->draw_rectangle(Rectangle(border_x, border_y, border_x2, border_y2), border_color, false,
                //                         border_width);
            }
        }
        
        Rectangle Control::get_bounds() {
            return {position.x + container_offset.x, position.y + container_offset.y, width, height};
        }

        void Control::update() {
            //Get mouse state
            Input::MouseState state = Input::Mouse::get_state(_parent_game);
    
            //Control state checks
            if (get_bounds().contains(Vector2(state.x, state.y))) {
                if (state.left_button == Input::Pressed) {
                    //Change state
                    this->state = Click;
            
                    //Fire event
                    onclick.invoke();
            
                    //Clear left button
                    Input::Mouse::clear_left_button();
                } else {
                    //Change state
                    this->state = Hover;
            
                    //Fire event
                    onhover.invoke();
                }
            } else {
                this->state = None;
            }
            
            //Update background
            if (background != nullptr)
                background->update();
            
            //Update highlight
            if (highlight != nullptr)
                highlight->update();
        }
    }
}