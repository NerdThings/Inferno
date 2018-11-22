//
// Created by Reece Mackie on 14/11/18.
//

#define _USE_MATH_DEFINES
#include <cmath>

#include "Graphics/Color.h"
#include "Graphics/Font.h"
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
        //Private Methods
        
        void Renderer::add_to_buffer(Vector3 position, Vector2 texcoord, Color color, std::vector<float>* data) {
            //X,Y,Z
            data->emplace_back(position.x);
            data->emplace_back(position.y);
            data->emplace_back(position.z);
    
            //U,V
            data->emplace_back(texcoord.x);
            data->emplace_back(texcoord.y);
    
            //R,G,B,A
            data->emplace_back(color.get_r());
            data->emplace_back(color.get_g());
            data->emplace_back(color.get_b());
            data->emplace_back(color.get_a());
        }
        
        void Renderer::set_matrix(Vector2 translation) {
            //Get original matrix
            Matrix matrix = _graphics_device->get_complete_matrix();
    
            //Apply translation for origin
            matrix = Matrix::create_translation(Vector3(translation.x, translation.y, 0)) * matrix;
            
            //Set matrix
            _graphics_device->shader_uniform_set("inf_matrix", matrix);
        }

#ifdef OPENGL

        void Renderer::gl_draw_buffer(int drawmode, std::vector<float> data){
            //Get shader attrib locations
            int position_loc = _graphics_device->shader_get_attrib("inf_position");
            int texcoord_loc = _graphics_device->shader_get_attrib("inf_texcoord");
            int color_loc = _graphics_device->shader_get_attrib("inf_color");
    
            //Check shaders have been configured correctly
            if (position_loc < 0 || texcoord_loc < 0 || color_loc < 0)
                throw "Shaders are not correctly configured.";
            
            //Get data from vector
            float* dat = data.data();
            
            //Send data to buffer
            glBindBuffer(GL_ARRAY_BUFFER, _vertex_array);
            glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), dat, GL_STATIC_DRAW);
    
            //Enable attributes
            glEnableVertexAttribArray(position_loc);
            glEnableVertexAttribArray(texcoord_loc);
            glEnableVertexAttribArray(color_loc);
    
            //Configure attributes
            glVertexAttribPointer(position_loc, 3, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*) nullptr);
            glVertexAttribPointer(texcoord_loc, 2, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(3*sizeof(float)));
            glVertexAttribPointer(color_loc, 4, GL_FLOAT, GL_FALSE, 9*sizeof(float), (void*)(5*sizeof(float)));
    
            //Draw
            glDrawArrays(drawmode, 0, data.size() / 9);
    
            //Disable attributes
            glDisableVertexAttribArray(position_loc);
            glDisableVertexAttribArray(texcoord_loc);
            glDisableVertexAttribArray(color_loc);
    
            //Flush
            glFlush();
        }

#endif
        
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
        
        void Renderer::draw_circle(Vector2 position, float radius, Color color, float depth, bool filled, int line_width, int circle_precision) {
            if (filled) {
#ifdef OPENGL
                //Bind blank texture
                glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
                //Set texture sampler
                _graphics_device->shader_uniform_set("inf_texture", 0);
                
                float x = position.x;
                float y = position.y;
                
                std::vector<float> data;
                
                for (float i = 0; i < 2 * M_PI; i += M_PI / circle_precision)
                    add_to_buffer(Vector3(x + (cosf(i) * radius), y + (sinf(i) * radius), depth), Vector2(0, 0), color, &data);
                
                set_matrix(Vector2(0, 0));
                gl_draw_buffer(GL_POLYGON, data);
#endif
            } else {
#ifdef OPENGL
                //TODO: Fix scaling issue
                //Bind blank texture
                glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
                //Set texture sampler
                _graphics_device->shader_uniform_set("inf_texture", 0);
    
                //Line width
                glLineWidth(line_width);
                
                std::vector<float> data;
                
                for (float i = 0; i < circle_precision; i++) {
                    float theta = 2.0f * float(M_PI) * i / float(circle_precision);
                    
                    float x = radius * cosf(theta);
                    float y = radius * sinf(theta);
    
                    add_to_buffer(Vector3(position.x + x, position.y + y, depth), Vector2(0, 0), color, &data);
                }
    
                gl_draw_buffer(GL_LINE_LOOP, data);
#endif
            }
        }
        
        void Renderer::draw_line(Vector2 pos_a, Vector2 pos_b, Color color, int line_width, float depth) {
            std::vector<Vector2> points;
            points.emplace_back(pos_a);
            points.emplace_back(pos_b);
            draw_lines(points, color, line_width, depth);
        }
        
        void Renderer::draw_lines(std::vector<Vector2> points, Color color, int line_width, float depth) {
#ifdef OPENGL
            //Bind blank texture
            glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
            //Set texture sampler
            _graphics_device->shader_uniform_set("inf_texture", 0);
            
            //Line width
            glLineWidth(line_width);
            
            std::vector<float> data;
            
            for (Vector2 point : points) {
                add_to_buffer(Vector3(point.x, point.y, depth), Vector2(0, 0), color, &data);
            }
            
            gl_draw_buffer(GL_LINES, data);
#endif
        }
        
        void Renderer::draw_rectangle(Rectangle rect, Color color, float depth, bool filled, int line_width) {
#ifdef OPENGL
            //Get coords from the rectangle
            float left = rect.get_left_coord();
            float right = rect.get_right_coord();
            float top = rect.get_top_coord();
            float bottom = rect.get_bottom_coord();
            
            if (filled) {
                //Set matrix
                set_matrix(Vector2(0, 0));
    
                //Bind blank texture
                glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
                //Set texture sampler
                _graphics_device->shader_uniform_set("inf_texture", 0);
    
                std::vector<float> data;
    
                add_to_buffer(Vector3(left, top, depth), Vector2(0, 0), color, &data);
                add_to_buffer(Vector3(right, top, depth), Vector2(1, 0), color, &data);
                add_to_buffer(Vector3(right, bottom, depth), Vector2(1, 1), color, &data);
                add_to_buffer(Vector3(left, bottom, depth), Vector2(0, 1), color, &data);
    
                //Load buffer
                gl_draw_buffer(GL_QUADS, data);
            } else {
                std::vector<Vector2> points;
                points.emplace_back(Vector2(left, top));
                points.emplace_back(Vector2(right, top));
                points.emplace_back(Vector2(right, top));
                points.emplace_back(Vector2(right, bottom));
                points.emplace_back(Vector2(right, bottom));
                points.emplace_back(Vector2(left, bottom));
                points.emplace_back(Vector2(left, bottom));
                points.emplace_back(Vector2(left, top));
                draw_lines(points, color, line_width, depth);
            }
#endif
        }
        
        void Renderer::draw_render_target(RenderTarget* target, Vector2 pos, Rectangle* source_rectangle, float depth, Color color) {
            draw_render_target(target, Rectangle((int) pos.x, (int) pos.y, target->width, target->height), source_rectangle, depth, color);
        }
        
        void Renderer::draw_render_target(RenderTarget* target, Rectangle destination_rectangle, Rectangle* source_rectangle, float depth, Color color) {
#ifdef OPENGL
            //Set matrix
            set_matrix(Vector2(0, 0));
    
            //Bind rendered texture
            glBindTexture(GL_TEXTURE_2D, target->rendered_texture);
    
            //Set texture sampler
            _graphics_device->shader_uniform_set("inf_texture", 0);
    
            //Get coords from the destination rectangle
            float left = destination_rectangle.get_left_coord();
            float right = destination_rectangle.get_right_coord();
            float top = destination_rectangle.get_top_coord();
            float bottom = destination_rectangle.get_bottom_coord();
            
            //Calculate source rectangle texcoords
            float tex_left = 0;
            float tex_right = 1;
            float tex_top = 1;
            float tex_bottom = 0;
            if (source_rectangle != nullptr) {
                tex_left = float(source_rectangle->x) / target->width;
                tex_right = tex_left + float(source_rectangle->width) / target->width;
                tex_bottom = float(source_rectangle->y) / target->height;
                tex_top = tex_bottom + float(source_rectangle->height) / target->height;
            }
    
            //Build buffer
            std::vector<float> data;
            
            add_to_buffer(Vector3(left, top, depth), Vector2(tex_left, tex_top), color, &data);
            add_to_buffer(Vector3(right, top, depth), Vector2(tex_right, tex_top), color, &data);
            add_to_buffer(Vector3(right, bottom, depth), Vector2(tex_right, tex_bottom), color, &data);
            add_to_buffer(Vector3(left, bottom, depth), Vector2(tex_left, tex_bottom), color, &data);
            
            //Draw
            gl_draw_buffer(GL_QUADS, data);
#endif
        }
        
        void Renderer::draw_text(std::string text, Vector2 position, Font font, Color color, float depth) {
            float tx = position.x;
            float ty = position.y;
            for (int i = 0; i < text.size(); i++) {
                if (text[i] == '\n') {
                    ty += font.glyphs['A'].size.y + font.glyphs['A'].bearing.y;
                    tx = position.x;
                    continue;
                }
                
                Glyph g = font.glyphs[text[i]];
                
                float x = tx + g.bearing.x;
                float y = ty - g.bearing.y;
                float w = g.size.x;
                float h = g.size.y;
                
                draw_texture(g.texture, Rectangle(x, y, w, h), nullptr, depth, color, Vector2());
    
                tx += g.size.x;
            }
        }
        
        void Renderer::draw_texture(Texture2D* texture, Vector2 position, Rectangle* source_rectangle, float depth, Color color, Vector2 origin) {
            draw_texture(texture, Rectangle((int) position.x, (int) position.y, texture->get_width(), texture->get_height()), source_rectangle, depth, color, origin);
        }
        
        void Renderer::draw_texture(Texture2D* texture, Rectangle destination_rectangle, Rectangle* source_rectangle, float depth, Color color, Vector2 origin) {
#ifdef OPENGL
            //Set matrix
            set_matrix(Vector2(-origin.x, -origin.y));
            
            //Bind rendered texture
            glBindTexture(GL_TEXTURE_2D, texture->id);
            
            //Set texture sampler
            _graphics_device->shader_uniform_set("inf_texture", 0);
            
            //Get coords from the destination rectangle
            float left = destination_rectangle.get_left_coord();
            float right = destination_rectangle.get_right_coord();
            float top = destination_rectangle.get_top_coord();
            float bottom = destination_rectangle.get_bottom_coord();
            
            //Calculate source rectangle texcoords
            float tex_left = 0;
            float tex_right = 1;
            float tex_top = 0;
            float tex_bottom = 1;
            if (source_rectangle != nullptr) {
                tex_left = float(source_rectangle->x) / texture->get_width();
                tex_right = tex_left + float(source_rectangle->width) / texture->get_width();
                tex_top = float(source_rectangle->y) / texture->get_height();
                tex_bottom = tex_top + float(source_rectangle->height) / texture->get_height();
            }
            
            //Build buffer
            std::vector<float> data;
            
            add_to_buffer(Vector3(left, top, depth), Vector2(tex_left, tex_top), color, &data);
            add_to_buffer(Vector3(right, top, depth), Vector2(tex_right, tex_top), color, &data);
            add_to_buffer(Vector3(right, bottom, depth), Vector2(tex_right, tex_bottom), color, &data);
            add_to_buffer(Vector3(left, bottom, depth), Vector2(tex_left, tex_bottom), color, &data);
            
            //Draw
            gl_draw_buffer(GL_QUADS, data);
#endif
        }
    }
}
