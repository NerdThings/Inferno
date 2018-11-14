//
// Created by Reece Mackie on 14/11/18.
//

#include "Graphics/Color.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Renderer.h"
#include "Graphics/RenderTarget.h"
#include "Graphics/Texture2D.h"
#include "Rectangle.h"
#include "Matrix.h"
#include "Vector2.h"
#include "Vector3.h"

#ifdef OPENGL
#include "glad/glad.h"
#endif

#ifdef SDL
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        Renderer::Renderer(Inferno::Graphics::GraphicsDevice *graphics_device) : _graphics_device(graphics_device) {
            //Create blank white texture for shaders
            _blank_texture = new Texture2D(_graphics_device, 1, 1, Color(255, 255, 255, 255));

#ifdef OPENGL
            //Create vertex array
            glGenVertexArrays(1, &_vertex_array);
            glBindVertexArray(_vertex_array);
#endif
        }
        
        //Deconstructors
        
        Renderer::~Renderer() {
            //Destroy vertex array
            glDeleteVertexArrays(1, &_vertex_array);
            _vertex_array = 0;
            
            //Destroy texture
            delete _blank_texture;
        }
        
        //Methods
        
        void Renderer::draw_rectangle(Rectangle rect, Color color, float depth) {
#ifdef OPENGL
            //TODO: Update once graphics device has shader attrib and uniform features
            
            //Set matrix
            int matrix_loc = _graphics_device->shader_get_uniform("inf_matrix");
            glUniformMatrix4fv(matrix_loc, 1, GL_FALSE< _graphics_device->get_complete_matrix().to_float_array());
            
            //Bind blank texture
            glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
            
            //Set texture sampler
            int texture_sampler = _graphics_device->shader_get_uniform("inf_texture");
            glUniform1i(texture_sampler, 0);
            
            //Get shader attrib locations
            int position_loc = _graphics_device->shader_get_attrib("inf_position");
            int color_loc = _graphics_device->shader_get_attrib("inf_color");
            int texcoord_loc = _graphics_device->shader_get_attrib("inf_texcoord");
            
            //TODO: Finish tomorrow
#endif
        }
    }
}