#include "Graphics/RenderItem.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        RenderItem::RenderItem() : color(Color(0, 0, 0, 1)),
                                   source_rectangle(Rectangle(0, 0, 0, 0)),
                                   destination_rectangle(Rectangle(0, 0, 0, 0)),
                                   origin(Vector2(0, 0)) {
            //Define defaults for things
            type = nothing;
            rotation = 0;
            verticies = {};
            dispose = false;
            line_width = 1;
            radius = 0;
            precision = 0;
            fragment_shader = nullptr;
            vertex_shader = nullptr;
        }
    }
}