//
// Created by Reece Mackie on 25/11/18.
//

#ifndef INFERNO_CAMERA_H
#define INFERNO_CAMERA_H

#include "Inferno/Game.h"
#include "Inferno/Inferno.h"
#include "Inferno/Matrix.h"
#include "Inferno/Point.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Scene.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"

namespace Inferno {
    namespace Graphics {
        
        /*
         * A View Camera
         */
        class INFERNO_API Camera {
        private:
            //Fields
            
            const Scene* _parent_scene = nullptr;
        public:
            //Fields
            
            Vector2 position = Vector2(0, 0);
            float rotation = 0;
            float zoom = 1;
            
            //Constructors
            
            /*
             * Create a new Camera
             */
            explicit Camera(Scene* parent_scene, float zoom = 1);
            
            //Methods
            
            /*
             * Center the camera on a specific position
             */
            void center_on(Vector2 position);
            
            /*
             * Get the final translation matrix.
             * This will be passed to the graphics device as the view matrix
             */
            Matrix get_translation_matrix();
            
            /*
             * Get the center of the viewport
             */
            Vector2 get_viewport_center();
            
            /*
             * Get the height of the viewport
             */
            int get_viewport_height();
            
            /*
             * Get the width of the viewport
             */
            int get_viewport_width();
            
            /*
             * Get the boundaries of the viewport
             */
            Rectangle get_viewport_world_boundary();
            
            /*
             * Convert a screen coordinate to a world coordinate using the camera matrix
             */
            Vector2 screen_to_world(Vector2 screen_position);
            
            /*
             * Convert a world coordinate to a screen coordinate using the camera matrix
             */
            Vector2 world_to_screen(Vector2 world_position);
            
            /*
             * Determine if something is visible in the camera
             */
            bool drawable(Rectangle rect);
        };
    }
}

#endif //INFERNO_CAMERA_H
