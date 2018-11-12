#include <cstdio>
#include <Graphics/Shader.h>
#include "Graphics/Color.h"
#include "Graphics/Renderer.h"
#include "Graphics/RenderItem.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/RenderTarget.h"
#include "Rectangle.h"
#include "GameWindow.h"
#include "Point.h"

#ifdef OPENGL
#include "glad/glad.h"
#endif

#ifdef SDL
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {
        //Private Methods
        
        float* Renderer::build_array(std::vector<Vector2> vectors) {
            float* array = new float[vectors.size() * 3];
            
            for (int i = 0; i < vectors.size() * 3; i += 3) {
                int vector = i / 3;
                array[i] = vectors.at(vector).x;
                array[i+1] = vectors.at(vector).y;
                array[i+2] = 0;
            }
            
            return array;
        }
    
        float* Renderer::build_array(std::vector<Vector3> vectors) {
            float* array = new float[vectors.size() * 3];
        
            for (int i = 0; i < vectors.size() * 3; i += 3) {
                int vector = i / 3;
                array[i] = vectors.at(vector).x;
                array[i+1] = vectors.at(vector).y;
                array[i+2] = vectors.at(vector).z;
            }
        
            return array;
        }
        
        //Constructor

        Renderer::Renderer(GraphicsDevice* graphics_device) : _graphics_device(graphics_device) {
            //Create blank white texture
            Color* data = new Color[1];
            data[0] = Color(255, 255, 255, 255);
            
            _blank_texture = new Texture2D(_graphics_device, 1, 1, data);

#if OPENGL
            //Create vertex array
            glGenVertexArrays(1, &_vertex_array);
            glBindVertexArray(_vertex_array);
#endif
        }
        
        //Methods
        
        void Renderer::draw_rectangle(Rectangle rect, Color color, float depth) {
#ifdef OPENGL
            //Set matrix
            int smatrix = _graphics_device->shader_get_uniform("inf_projection_matrix");
            glUniformMatrix4fv(smatrix, 1, GL_FALSE, _graphics_device->get_projection_matrix().get_array());
            
            //Bind blank texture
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
            //Set texture sampler
            int stex = _graphics_device->shader_get_uniform("inf_texture");
            glUniform1i(stex, 0);
            
            //Get shader attrib locations
            int sposition = _graphics_device->shader_get_attribute("inf_position");
            int scolor = _graphics_device->shader_get_attribute("inf_color");
            int stexcoord = _graphics_device->shader_get_attribute("inf_texcoord");
            
            //Check locations
            if (sposition < 0 || scolor < 0)
                throw "Shaders are not correctly configured.";
    
            //Get coords
            float left = rect.get_left_coord();
            float right = rect.get_right_coord();
            float top = rect.get_top_coord();
            float bottom = rect.get_bottom_coord();
    
            //Convert to float array
            float bufferData[] =
                    {
                        //X,Y,Z  U,V    R,G,B,A
                        left, top, depth, 0, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                        right, top, depth, 0, 0, color.get_r(), color.get_g(), color.get_b(),  color.get_a(),
                        right, bottom, depth, 0, 0, color.get_r(), color.get_g(), color.get_b(),  color.get_a(),
                        left, bottom, depth, 0, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a()
                    };
    
            //Send data to buffer
            glBindBuffer(GL_ARRAY_BUFFER, _vertex_array);
            glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);
    
            //Enable attribs
            glEnableVertexAttribArray(sposition);
            glEnableVertexAttribArray(stexcoord);
            glEnableVertexAttribArray(scolor);
    
            //Configure attribs
            glVertexAttribPointer(sposition, 3, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*) nullptr);
            glVertexAttribPointer(stexcoord, 2, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(3*sizeof(float)));
            glVertexAttribPointer(scolor, 4, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(5*sizeof(float)));
    
            //Draw
            glDrawArrays(GL_QUADS, 0, 4);
    
            //Disable attribs
            glDisableVertexAttribArray(sposition);
            glDisableVertexAttribArray(stexcoord);
            glDisableVertexAttribArray(scolor);
            
            //Flush
            glFlush();
#endif
        }
        
    }
}