//
// Created by Reece Mackie on 14/11/18.
//

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/Font.h"
#include "Inferno/Graphics/GraphicsDevice.h"
#include "Inferno/Graphics/Renderer.h"
#include "Inferno/Graphics/RenderTarget.h"
#include "Inferno/Graphics/Shader.h"
#include "Inferno/Graphics/Texture2D.h"
#include "Inferno/Rectangle.h"
#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"

#ifdef OPENGL
#include <glad/glad.h>
#endif

#ifdef SDL
#include <SDL_opengl.h>
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
            data->emplace_back(color.r());
            data->emplace_back(color.g());
            data->emplace_back(color.b());
            data->emplace_back(color.a());
        }
        
        Matrix Renderer::create_model_matrix(Vector2 origin, float rotation, float scale) {
            //Build model matrix
            Matrix model = Matrix::create_translation(Vector3(-origin, 0));
            model = model * Matrix::create_rotation_z(rotation);
            model = model * Matrix::create_scale(scale, scale, 1);
            model = model * Matrix::create_translation(Vector3(origin, 0));
            return model;
        }
        
        void Renderer::set_matrix(Vector2 origin, float rotation, float scale) {
            //Push model matrix
            _graphics_device->push_model_matrix();
            
            //Build model matrix
            Matrix model = create_model_matrix(origin, rotation, scale);
            
            //Set model matrix
            _graphics_device->set_model_matrix(model);
            
            //Get original matrix
            Matrix matrix = _graphics_device->get_complete_matrix();
            
            //Set matrix in shader
            _graphics_device->get_current_shader()->uniform_set("inf_matrix", matrix);
            
            //Pop matrix
            _graphics_device->pop_model_matrix();
        }

#ifdef OPENGL

        void Renderer::gl_draw_buffer(int drawmode, std::vector<float> data){
            //Get shader attrib locations
            int gl_program = _graphics_device->get_current_shader()->gl_program;
            int position_loc = glGetAttribLocation(gl_program, "inf_position");
            int texcoord_loc = glGetAttribLocation(gl_program, "inf_texcoord");
            int color_loc = glGetAttribLocation(gl_program, "inf_color");
    
            //Check shaders have been configured correctly
            if (position_loc < 0 || texcoord_loc < 0 || color_loc < 0)
                throw std::runtime_error("Shaders are not correctly configured.");
            
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
            _blank_texture = new Texture2D(1, 1, Color(255, 255, 255, 255));

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
        
        void Renderer::draw_circle(Vector2 position, float radius, Color color, float depth, float rotation, bool filled, int line_width, int circle_precision, Vector2 origin) {
            //Set matrix
            set_matrix(position + origin, rotation);
            
            if (filled) {
#ifdef OPENGL
                //Bind blank texture
                glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
                //Set texture sampler
                _graphics_device->get_current_shader()->uniform_set("inf_texture", 0);
                
                float x = position.x;
                float y = position.y;
                
                std::vector<float> data;
                
                for (float i = 0; i < 2 * M_PI; i += M_PI / circle_precision)
                    add_to_buffer(Vector3(x + (cosf(i) * radius), y + (sinf(i) * radius), depth), Vector2(0, 0), color, &data);
                
                gl_draw_buffer(GL_POLYGON, data);
#endif
            } else {
#ifdef OPENGL
                //Bind blank texture
                glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
                //Set texture sampler
                _graphics_device->get_current_shader()->uniform_set("inf_texture", 0);
    
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
        
        void Renderer::draw_line(Vector2 pos_a, Vector2 pos_b, Color color, int line_width, float depth, float rotation, Vector2 origin) {
            //Set matrix
            set_matrix(origin, rotation);
            
#ifdef OPENGL
            //Bind blank texture
            glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
            //Set texture sampler
            _graphics_device->get_current_shader()->uniform_set("inf_texture", 0);
    
            //Line width
            glLineWidth(line_width);
    
            std::vector<float> data;
    
            add_to_buffer(Vector3(pos_a.x, pos_a.y, depth), Vector2(0, 0), color, &data);
            add_to_buffer(Vector3(pos_b.x, pos_b.y, depth), Vector2(0, 0), color, &data);
    
            gl_draw_buffer(GL_LINES, data);
#endif
        }
        
        void Renderer::draw_lines(std::vector<Vector2> points, Color color, int line_width, float depth, float rotation, Vector2 origin) {
            if (points.size() % 2 != 0)
                return;
            for (int i = 0; i < points.size(); i += 2) {
                draw_line(points[i], points[i + 1], color, line_width, depth, rotation, origin);
            }
        }
        
        void Renderer::draw_rectangle(Rectangle rect, Color color, bool filled, int line_width, float depth, float rotation, Vector2 origin) {
#ifdef OPENGL
            if (filled) {
                //Set matrix
                set_matrix();
                
                //Bind blank texture
                glBindTexture(GL_TEXTURE_2D, _blank_texture->id);
    
                //Set texture sampler
                _graphics_device->get_current_shader()->uniform_set("inf_texture", 0);
    
                std::vector<float> data;
    
                add_to_buffer(Vector3(rect.top_left(), depth), Vector2(0, 0), color, &data);
                add_to_buffer(Vector3(rect.top_right(), depth), Vector2(1, 0), color, &data);
                add_to_buffer(Vector3(rect.bottom_right(), depth), Vector2(1, 1), color, &data);
                add_to_buffer(Vector3(rect.bottom_left(), depth), Vector2(0, 1), color, &data);
    
                //Load buffer
                gl_draw_buffer(GL_QUADS, data);
            } else {
                std::vector<Vector2> points;
                points.emplace_back(rect.top_left());
                points.emplace_back(rect.top_right());
                points.emplace_back(rect.top_right());
                points.emplace_back(rect.bottom_right());
                points.emplace_back(rect.bottom_right());
                points.emplace_back(rect.bottom_left());
                points.emplace_back(rect.bottom_left());
                points.emplace_back(rect.top_left());
                draw_lines(points, color, line_width, depth);
            }
#endif
        }
        
        void Renderer::draw_render_target(RenderTarget* target, Vector2 pos, Rectangle* source_rectangle, float depth, float rotation, Color color) {
            draw_render_target(target, Rectangle((int) pos.x, (int) pos.y, target->width, target->height), source_rectangle, depth, rotation, color);
        }
        
        void Renderer::draw_render_target(RenderTarget* target, Rectangle destination_rectangle, Rectangle* source_rectangle, float depth, float rotation, Color color) {
#ifdef OPENGL
            //Set matrix
            set_matrix(Vector2(destination_rectangle.x, destination_rectangle.y), rotation);
    
            //Bind rendered texture
            glBindTexture(GL_TEXTURE_2D, target->rendered_texture);
    
            //Set texture sampler
            _graphics_device->get_current_shader()->uniform_set("inf_texture", 0);
            
            //Calculate source rectangle texcoords
            float tex_left = 0;
            float tex_right = 1;
            float tex_top = 1;
            float tex_bottom = 0;
            if (source_rectangle != nullptr) {
                if (source_rectangle->rotation != 0)
                    throw std::runtime_error("Cannot rotate texture source rectangle.");
                
                tex_left = source_rectangle->x / target->width;
                tex_right = tex_left + source_rectangle->width / target->width;
                tex_bottom = source_rectangle->y / target->height;
                tex_top = tex_bottom + source_rectangle->height / target->height;
            }
    
            //Build buffer
            std::vector<float> data;
            
            add_to_buffer(Vector3(destination_rectangle.top_left(), depth), Vector2(tex_left, tex_top), color, &data);
            add_to_buffer(Vector3(destination_rectangle.top_right(), depth), Vector2(tex_right, tex_top), color, &data);
            add_to_buffer(Vector3(destination_rectangle.bottom_right(), depth), Vector2(tex_right, tex_bottom), color, &data);
            add_to_buffer(Vector3(destination_rectangle.bottom_left(), depth), Vector2(tex_left, tex_bottom), color, &data);
            
            //Draw
            gl_draw_buffer(GL_QUADS, data);
#endif
        }
        
        void Renderer::draw_text(std::string text, Vector2 position, Font font, Color color, float depth, float rotation) {
            Vector2 size = font.measure_string(text);
            
            //TODO: Implement rotation
            if (rotation != 0)
                throw std::runtime_error("Cannot currently rotate text.");
            
            float tx = position.x;
            float ty = position.y;
            for (char c : text) {
                if (c == '\n') {
                    ty += font.glyphs[font.space_char].size.y + font.glyphs['A'].bearing.y;
                    tx = position.x;
                    continue;
                }
                if (c == ' ') {
                    tx += font.glyphs[font.space_char].size.x;
                    continue;
                }
                
                Glyph g = font.glyphs[c];
                
                float x = tx + g.bearing.x;
                float y = ty - g.bearing.y;
                float w = g.size.x;
                float h = g.size.y;
                
                draw_texture(g.texture, Vector2(x, y), nullptr, depth, rotation, color, Vector2());
    
                tx += g.size.x;
            }
        }
        
        void Renderer::draw_texture(Texture2D* texture, Vector2 position, Rectangle* source_rectangle, float depth, float rotation, Color color, Vector2 origin) {
            draw_texture(texture, Rectangle((int) position.x, (int) position.y, texture->width(), texture->height()), source_rectangle, depth, rotation, color, origin);
        }
        
        void Renderer::draw_texture(Texture2D* texture, Rectangle destination_rectangle, Rectangle* source_rectangle, float depth, float rotation, Color color, Vector2 origin) {
#ifdef OPENGL
            //Set matrix
            set_matrix(origin + Vector2(destination_rectangle.x, destination_rectangle.y), rotation);
            
            //Bind rendered texture
            glBindTexture(GL_TEXTURE_2D, texture->id);
            
            //Set texture sampler
            _graphics_device->get_current_shader()->uniform_set("inf_texture", 0);
            
            //Calculate source rectangle texcoords
            float tex_left = 0;
            float tex_right = 1;
            float tex_top = 0;
            float tex_bottom = 1;
            if (source_rectangle != nullptr) {
                if (source_rectangle->rotation != 0)
                    throw std::runtime_error("Cannot rotate texture source rectangle.");
                
                tex_left = float(source_rectangle->x) / texture->width();
                tex_right = tex_left + float(source_rectangle->width) / texture->width();
                tex_top = float(source_rectangle->y) / texture->height();
                tex_bottom = tex_top + float(source_rectangle->height) / texture->height();
            }
            
            //Build buffer
            std::vector<float> data;
            
            add_to_buffer(Vector3(destination_rectangle.top_left(), depth), Vector2(tex_left, tex_top), color, &data);
            add_to_buffer(Vector3(destination_rectangle.top_right(), depth), Vector2(tex_right, tex_top), color, &data);
            add_to_buffer(Vector3(destination_rectangle.bottom_right(), depth), Vector2(tex_right, tex_bottom), color, &data);
            add_to_buffer(Vector3(destination_rectangle.bottom_left(), depth), Vector2(tex_left, tex_bottom), color, &data);
            
            //Draw
            gl_draw_buffer(GL_QUADS, data);
#endif
        }
    }
}
