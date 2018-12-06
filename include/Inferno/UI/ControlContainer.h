//
// Created by Reece Mackie on 04/12/18.
//

#ifndef INFERNO_CONTROLCONTAINER_H
#define INFERNO_CONTROLCONTAINER_H

#include <vector>

#include "Inferno/UI/Control.h"
#include "Inferno/Inferno.h"
#include "Inferno/Vector2.h"

namespace Inferno {
    namespace UI {
        /*
         * A Basic UI Control Container
         */
        class INFERNO_API ControlContainer : public Control {
            //Fields
            
            /*
             * This is the vector of controls the container contains
             */
            std::vector<Control*> _controls;
            
        public:
            //Constructors
            
            /*
             * Create a new Control Container
             */
            ControlContainer(Game* parent_game, Vector2 position, float width, float height);
            
            //Methods
            
            /*
             * Add a control to the container
             */
            void add_control(Control* control);
            
            /*
             * Clear all controls from the container
             */
            void clear_controls();
            
            /*
             * Draw all the controls in the container
             */
            void draw(Graphics::Renderer* renderer) override;
            
            /*
             * Update all the controls in the container
             */
            void update() override;
        };
    }
}

#endif //INFERNO_CONTROLCONTAINER_H
