//
// Created by Reece Mackie on 04/12/18.
//

#include "Inferno/UI/ControlContainer.h"

namespace Inferno {
    namespace UI {
        //Constructors
        
        ControlContainer::ControlContainer(Game *parent_game, Vector2 position, float width, float height) : Control(parent_game, position) {
            back_color = Graphics::Color::transparent;
            border_color = Graphics::Color::transparent;
            border_width = 0;
            fore_color = Graphics::Color::transparent;
            highlight_color = Graphics::Color::transparent;
            
            this->width = width;
            this->height = height;
        }
        
        //Methods
        
        void ControlContainer::add_control(Control *control) {
            _controls.emplace_back(control);
        }
        
        void ControlContainer::clear_controls() {
            _controls.clear();
        }
        
        void ControlContainer::draw(Graphics::Renderer *renderer) {
            Control::draw(renderer);
            for (Control* c : _controls) {
                //Check that the control is within the container
                if (get_bounds().contains(c->position + position))
                    c->draw(renderer);
            }
        }
        
        void ControlContainer::update() {
            Control::update();
            for (Control* c : _controls) {
                //TODO: Make it so that we can disable click events for controls outside the container
                c->container_offset = position;
                c->update();
            }
        }
    }
}