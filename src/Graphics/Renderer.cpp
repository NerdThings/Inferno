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
        
        void Renderer::render(RenderItem item) {
#if OPENGL

            //Save matrix
            glPushMatrix();
            
            //Apply shaders
            glAttachShader(_gl_program, item.vertex_shader->shader);
            glAttachShader(_gl_program, item.fragment_shader->shader);
            
            //Bind shader attrib locations
            glBindAttribLocation(_gl_program, 0, "inf_position");
            glBindAttribLocation(_gl_program, 1, "inf_color");
            glBindAttribLocation(_gl_program, 2, "inf_texcoord");
            
            //Finish shaders
            glLinkProgram(_gl_program);
            glUseProgram(_gl_program);
    
            //Attach the matrix
            int matLoc = glGetUniformLocation(_gl_program, "inf_projection_matrix");
            glUniformMatrix4fv(matLoc, 1, GL_FALSE, _translation_matrix.get_array());
            
            //Apply line width
            glLineWidth(item.line_width);

            //Apply origin
            //if (item->origin != nullptr)
            //    glTranslatef(-item->origin->x, -item->origin->y, 0.0f);

            //Apply rotation
            //TODO

            switch (item.type) {
                case rectangle:
                    //Get coords
                    int left = item.destination_rectangle.get_left_coord();
                    int right = item.destination_rectangle.get_right_coord();
                    int top = item.destination_rectangle.get_top_coord();
                    int bottom = item.destination_rectangle.get_bottom_coord();

                    //Build vertex array
                    std::vector<Vector2> v;
                    v.emplace_back(left, top);
                    v.emplace_back(right, top);
                    v.emplace_back(right, bottom);
                    v.emplace_back(left, bottom);
                    
                    //Convert to float array
                    float* vertexArray = this->build_array(v);
                    
                    //Send data to buffer
                    glBindBuffer(GL_ARRAY_BUFFER, _vertex_array);

                    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertexArray, GL_STATIC_DRAW);

                    glEnableVertexAttribArray(0);
                    
                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
                    
                    //Set the color attribute
                    glVertexAttrib4f(1, item.color.get_r(), item.color.get_g(), item.color.get_b(), item.color.get_a());
        
                    glDrawArrays(GL_QUADS, 0, 4);
                    
                    glDisableVertexAttribArray(0);

                    break;
            }

            //Flush
            glFlush();
            
            //Detach shaders
            glDetachShader(_gl_program, item.vertex_shader->shader);
            glDetachShader(_gl_program, item.fragment_shader->shader);

            //Restore matrix
            glPopMatrix();

#endif
        }


        //Constructor

        Renderer::Renderer(GraphicsDevice* graphics_device) : _graphics_device(graphics_device){
            _rendering = false;

#if OPENGL

            //Create vertex array
            glGenVertexArrays(1, &_vertex_array);
            glBindVertexArray(_vertex_array);
            
            //Create shader program
            _gl_program = glCreateProgram();

#endif
        }

        //Batch controls
        
        void Renderer::begin() {
            if (_rendering)
                throw "Cannot call begin before calling end!";
    
            //Clear batch
            _batch.clear();
    
            //Mark as rendering
            _rendering = true;
            
            //Build orthographic matrix
            Point window_size =_graphics_device->paired_window->get_size();
            RenderTarget* current_target = _graphics_device->get_render_target();
    
            Matrix ortho;
    
            if (current_target != nullptr) {
                ortho = Matrix::create_orthographic_off_center(0, current_target->width, current_target->height, 0, -1, 1);
            } else {
                ortho = Matrix::create_orthographic_off_center(0, window_size.x, window_size.y, 0, -1, 1);
            }
            
            //Set matrix
            _translation_matrix = ortho;
        }

        void Renderer::begin(Matrix translation_matrix) {
            //Start
            Renderer::begin();
            
            //Apply matrix
            _translation_matrix = translation_matrix * _translation_matrix;
        }

        void Renderer::end() {
            if (!_rendering)
                throw "Cannot call end before calling begin!";

            //Draw batch
            for (RenderItem batch_item : _batch)
            {
                render(batch_item);
            }

            //Mark as not rendering
            _rendering = false;
        }

        void Renderer::draw_rectangle(Rectangle rect, Color color, float depth) {
            RenderItem item = RenderItem();

            item.type = rectangle;
            item.destination_rectangle = rect;
            item.color = color;
            item.depth = depth;
            
            item.fragment_shader = _graphics_device->get_current_shader(Fragment);
            item.vertex_shader = _graphics_device->get_current_shader(Vertex);

            _batch.push_back(item);
        }

        //Draw calls

    }
}