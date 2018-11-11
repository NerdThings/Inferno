#ifndef Inferno_Graphics_Camera
#define Inferno_Graphics_Camera

#include "Inferno.h"

#include "Matrix.h"
#include "Rectangle.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Inferno {
    struct Scene;
    
    namespace Graphics {
        class Camera {
            //Fields
    
            const Scene* _parent_scene = nullptr;

        public:
            //Fields
    
            Vector2 position = Vector2(0, 0);
    
            float zoom = 1.0f;
    
            float rotation = 0.0f;
    
            //Constructors
    
            Camera(Scene* parent_scene, float zoom = 1.0f);
    
            //Methods
    
            void center_on(Vector2 position);
    
            Matrix get_translation_matrix();
    
            Rectangle get_viewport_boundary();
    
            Vector2 get_viewport_center();
    
            int get_viewport_height();
    
            int get_viewport_width();
    
            Vector2 screen_to_world(Vector2 screen_position);
    
            Vector2 world_to_screen(Vector2 world_position);
        };
    }
}

#endif
