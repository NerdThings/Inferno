//
// Created by Reece Mackie on 25/11/18.
//

#ifndef INFERNO_CONTROL_H
#define INFERNO_CONTROL_H

#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/Sprite.h"
#include "Inferno/Input/Mouse.h"
#include "Inferno/Inferno.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    namespace UI {
        enum ControlState {
            None,
            Hover,
            Click
        };
        
        class INFERNO_API Control {
        public:
            //Fields
            
            Graphics::Color back_color = Graphics::Color::gray;
            Graphics::Sprite* background = nullptr;
            Graphics::Color border_color = Graphics::Color::black;
            int border_width = 1;
            Graphics::Color fore_color = Graphics::Color::black;
            Graphics::Sprite* highlight = nullptr;
            bool highlight_on_hover = false;
            ControlState state = None;
            Vector2 position = Vector2(0, 0);
            int height = 0;
            int width = 0;
            
            //Constructors
            
            explicit Control(Vector2 position);
            
            //Methods
            
            virtual void draw(Graphics::Renderer* renderer);
            Rectangle get_bounds();
            virtual void update();
        };
    }
}

#endif //INFERNO_CONTROL_H
