//
// Created by Reece Mackie on 25/11/18.
//

#ifndef INFERNO_CONTROL_H
#define INFERNO_CONTROL_H

#include "Inferno/Events/EventHandler.h"
#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/Sprite.h"
#include "Inferno/Input/Mouse.h"
#include "Inferno/Inferno.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    namespace UI {
        /*
         * The state of a UI Control
         */
        enum ControlState {
            /*
             * The control is not hovered or clicked.
             */
            None,
            
            /*
             * The control is being hovered over.
             */
            Hover,
            
            /*
             * The control has been clicked
             */
            Click
        };
        
        /*
         * A Basic UI Control
         */
        class INFERNO_API Control {
            //Fields
    
            Game* _parent_game = nullptr;
        public:
            //Fields
            
            /*
             * Background Color
             */
            Graphics::Color back_color = Graphics::Color::gray;
            
            /*
             * Background
             */
            Graphics::Sprite* background = nullptr;
            
            /*
             * Border color
             */
            Graphics::Color border_color = Graphics::Color::black;
            
            /*
             * Border width
             */
            int border_width = 1;
    
            /*
             * Offset added based on the container position
             */
            Vector2 container_offset = Vector2();
            
            /*
             * Foreground color (text)
             */
            Graphics::Color fore_color = Graphics::Color::black;
            
            /*
             * Highlight sprite
             */
            Graphics::Sprite* highlight = nullptr;
            
            /*
             * Highlight color
             */
            Graphics::Color highlight_color = Graphics::Color::white;
            
            /*
             * Apply highlight when hovered
             */
            bool highlight_on_hover = false;
            
            /*
             * An event that is called when the control is clicked
             */
            Events::EventHandler<Events::Action> onclick;
            
            /*
             * An event that is called when the control is hovered over
             */
            Events::EventHandler<Events::Action> onhover;
            
            /*
             * The state of the control
             */
            ControlState state = None;
            
            /*
             * The position of the control within its container
             */
            Vector2 position = Vector2(0, 0);
            
            /*
             * The width of the control
             */
            float height = 0;
            
            /*
             * The height of the control
             */
            float width = 0;
            
            //Constructors
            
            /*
             * Create a new control
             */
            Control(Game* parent_game, Vector2 position);
            
            //Methods
            
            /*
             * Draw the control
             */
            virtual void draw(Graphics::Renderer* renderer);
            
            /*
             * Get the bounds of the control
             */
            Rectangle get_bounds();
            
            /*
             * Update the control
             */
            virtual void update();
        };
    }
}

#endif //INFERNO_CONTROL_H
