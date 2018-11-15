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
        
        Renderer::Renderer(GraphicsDevice *graphics_device) : _graphics_device(graphics_device) {
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
        
        //TODO: Write methods for common code.
        
        void Renderer::draw_rectangle(Rectangle rect, Color color, float depth) {
#ifdef OPENGL
            //TODO: Update once graphics device has shader attrib and uniform features
    
            //Get matrix uniform location
            int matrix_loc = _graphics_device->shader_get_uniform("inf_matrix");
    
            //Set matrix data
            glUniformMatrix4fv(matrix_loc, 1, GL_FALSE, _graphics_device->get_complete_matrix().to_float_vector().data());
            
            //Bind blank texture
            glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
            
            //Set texture sampler
            int texture_sampler = _graphics_device->shader_get_uniform("inf_texture");
            glUniform1i(texture_sampler, 0);
            
            //Get shader attrib locations
            int position_loc = _graphics_device->shader_get_attrib("inf_position");
            int texcoord_loc = _graphics_device->shader_get_attrib("inf_texcoord");
            int color_loc = _graphics_device->shader_get_attrib("inf_color");
    
            //Check shaders have been configured correctly
            if (position_loc < 0 || texcoord_loc < 0 || color_loc < 0)
                throw "Shaders are not correctly configured.";
            
            //Get coords from the rectangle
            float left = rect.get_left_coord();
            float right = rect.get_right_coord();
            float top = rect.get_top_coord();
            float bottom = rect.get_bottom_coord();
            
            float buffer_data[] =
                    {
                        //XYZ   UV    RBGA
                        left, top, depth, 0, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                        right, top, depth, 1, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                        right, bottom, depth, 1, 1, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                        left, bottom, depth, 0, 1, color.get_r(), color.get_g(), color.get_b(), color.get_a()
                    };
            
            //Send data to buffer
            glBindBuffer(GL_ARRAY_BUFFER, _vertex_array);
            glBufferData(GL_ARRAY_BUFFER, sizeof(buffer_data), buffer_data, GL_STATIC_DRAW);
            
            //Enable attributes
            glEnableVertexAttribArray(position_loc);
            glEnableVertexAttribArray(texcoord_loc);
            glEnableVertexAttribArray(color_loc);
    
            //Configure attributes
            glVertexAttribPointer(position_loc, 3, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*) nullptr);
            glVertexAttribPointer(texcoord_loc, 2, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(3*sizeof(float)));
            glVertexAttribPointer(color_loc, 4, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(5*sizeof(float)));
            
            //Draw
            glDrawArrays(GL_QUADS, 0, 4);
            
            //Disable attributes
            glDisableVertexAttribArray(position_loc);
            glDisableVertexAttribArray(texcoord_loc);
            glDisableVertexAttribArray(color_loc);
            
            //Flush
            glFlush();
#endif
        }
    
        void Renderer::draw_render_target(RenderTarget* target, Vector2 position, Color color, float depth) {
            draw_render_target(target, Rectangle((int)position.x, (int)position.y, target->width, target->height), color, depth);
        }
    
        void Renderer::draw_render_target(RenderTarget* target, Rectangle destination_rectangle, Color color, float depth) {
#ifdef OPENGL
            //TODO: Update once graphics device has shader attrib and uniform features
        
            //Get matrix uniform location
            int matrix_loc = _graphics_device->shader_get_uniform("inf_matrix");
        
            //Set matrix data
            glUniformMatrix4fv(matrix_loc, 1, GL_FALSE, _graphics_device->get_complete_matrix().to_float_vector().data());
        
            //Bind blank texture
            glBindTexture(GL_TEXTURE_2D, target->rendered_texture);
        
            //Set texture sampler
            int texture_sampler = _graphics_device->shader_get_uniform("inf_texture");
            glUniform1i(texture_sampler, 0);
        
            //Get shader attrib locations
            int position_loc = _graphics_device->shader_get_attrib("inf_position");
            int texcoord_loc = _graphics_device->shader_get_attrib("inf_texcoord");
            int color_loc = _graphics_device->shader_get_attrib("inf_color");
        
            //Check shaders have been configured correctly
            if (position_loc < 0 || texcoord_loc < 0 || color_loc < 0)
                throw "Shaders are not correctly configured.";
        
            //Get coords from the rectangle
            float left = destination_rectangle.get_left_coord();
            float right = destination_rectangle.get_right_coord();
            float top = destination_rectangle.get_top_coord();
            float bottom = destination_rectangle.get_bottom_coord();
        
            float buffer_data[] =
                    {
                            //XYZ   UV    RBGA
                            left, top, depth, 0, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                            right, top, depth, 1, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                            right, bottom, depth, 1, 1, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                            left, bottom, depth, 0, 1, color.get_r(), color.get_g(), color.get_b(), color.get_a()
                    };
        
            //Send data to buffer
            glBindBuffer(GL_ARRAY_BUFFER, _vertex_array);
            glBufferData(GL_ARRAY_BUFFER, sizeof(buffer_data), buffer_data, GL_STATIC_DRAW);
        
            //Enable attributes
            glEnableVertexAttribArray(position_loc);
            glEnableVertexAttribArray(texcoord_loc);
            glEnableVertexAttribArray(color_loc);
        
            //Configure attributes
            glVertexAttribPointer(position_loc, 3, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*) nullptr);
            glVertexAttribPointer(texcoord_loc, 2, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(3*sizeof(float)));
            glVertexAttribPointer(color_loc, 4, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(5*sizeof(float)));
        
            //Draw
            glDrawArrays(GL_QUADS, 0, 4);
        
            //Disable attributes
            glDisableVertexAttribArray(position_loc);
            glDisableVertexAttribArray(texcoord_loc);
            glDisableVertexAttribArray(color_loc);
        
            //Flush
            glFlush();
#endif
        }
        
        void Renderer::draw_texture(Texture2D* texture, Vector2 position, Color color, float depth) {
            draw_texture(texture, Rectangle((int)position.x, (int)position.y, texture->get_width(), texture->get_height()), color, depth);
        }
        
        void Renderer::draw_texture(Texture2D* texture, Rectangle destination_rectangle, Color color, float depth) {
#ifdef OPENGL
            //TODO: Update once graphics device has shader attrib and uniform features
    
            //Get matrix uniform location
            int matrix_loc = _graphics_device->shader_get_uniform("inf_matrix");
            
            //Set matrix data
            glUniformMatrix4fv(matrix_loc, 1, GL_FALSE, _graphics_device->get_complete_matrix().to_float_vector().data());
            
            //Bind blank texture
            glBindTexture(GL_TEXTURE_2D, texture->id);
    
            //Set texture sampler
            int texture_sampler = _graphics_device->shader_get_uniform("inf_texture");
            glUniform1i(texture_sampler, 0);
    
            //Get shader attrib locations
            int position_loc = _graphics_device->shader_get_attrib("inf_position");
            int texcoord_loc = _graphics_device->shader_get_attrib("inf_texcoord");
            int color_loc = _graphics_device->shader_get_attrib("inf_color");
    
            //Check shaders have been configured correctly
            if (position_loc < 0 || texcoord_loc < 0 || color_loc < 0)
                throw "Shaders are not correctly configured.";
    
            //Get coords from the rectangle
            float left = destination_rectangle.get_left_coord();
            float right = destination_rectangle.get_right_coord();
            float top = destination_rectangle.get_top_coord();
            float bottom = destination_rectangle.get_bottom_coord();
    
            float buffer_data[] =
                    {
                            //XYZ   UV    RBGA
                            left, top, depth, 0, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                            right, top, depth, 1, 0, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                            right, bottom, depth, 1, 1, color.get_r(), color.get_g(), color.get_b(), color.get_a(),
                            left, bottom, depth, 0, 1, color.get_r(), color.get_g(), color.get_b(), color.get_a()
                    };
    
            //Send data to buffer
            glBindBuffer(GL_ARRAY_BUFFER, _vertex_array);
            glBufferData(GL_ARRAY_BUFFER, sizeof(buffer_data), buffer_data, GL_STATIC_DRAW);
    
            //Enable attributes
            glEnableVertexAttribArray(position_loc);
            glEnableVertexAttribArray(texcoord_loc);
            glEnableVertexAttribArray(color_loc);
    
            //Configure attributes
            glVertexAttribPointer(position_loc, 3, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*) nullptr);
            glVertexAttribPointer(texcoord_loc, 2, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(3*sizeof(float)));
            glVertexAttribPointer(color_loc, 4, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(5*sizeof(float)));
    
            //Draw
            glDrawArrays(GL_QUADS, 0, 4);
    
            //Disable attributes
            glDisableVertexAttribArray(position_loc);
            glDisableVertexAttribArray(texcoord_loc);
            glDisableVertexAttribArray(color_loc);
    
            //Flush
            glFlush();
#endif
        }
    }
}
