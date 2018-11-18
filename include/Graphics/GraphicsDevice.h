//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_GRAPHICSDEVICE_H
#define INFERNO_GRAPHICSDEVICE_H

#include "Inferno.h"

#include <string>
#include <vector>

#include "Point.h"
#include "Matrix.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Inferno {
    class Game;
    
    namespace Graphics {
        struct Color;
        struct Shader;
        struct RenderTarget;
        struct Texture2D;
        
        class INFERNO_API GraphicsDevice {
            Shader* _current_fragment_shader = nullptr;
            Shader* _current_vertex_shader = nullptr;
            Shader* _default_fragment_shader = nullptr;
            Shader* _default_vertex_shader = nullptr;
#ifdef OPENGL
            unsigned int _gl_program;
#endif
            Game* _parent_game;
            std::vector<RenderTarget*> _queue_rendertarget;
            std::vector<Shader*> _queue_shader;
            std::vector<Texture2D*> _queue_texture2d;
            Matrix _projection_matrix;
            Matrix _view_matrix;
        public:
            //Constructors
        
            explicit GraphicsDevice(Game* game);
            
            //Deconstructors

            ~GraphicsDevice();
            
            //Methods
    
            void attach_shader(Shader* shader);
            void clear(Color color);
            void delete_render_target(RenderTarget* target);
            void delete_shader(Shader* shader);
            void delete_texture2d(Texture2D* texture);
            void end_draw();
            
            Matrix get_complete_matrix();
            Matrix get_projection_matrix();
            Matrix get_view_matrix();
            void set_render_target(RenderTarget* target);
            void set_view_matrix(Matrix view_matrix);
            
            //TEMP:
            int shader_get_attrib(std::string attrib);
            int shader_get_uniform(std::string uniform);
            
            //TODO: Implement everything below:
            
            void shader_attrib_set(std::string attrib, float value);
            void shader_attrib_set(std::string attrib, short value);
            void shader_attrib_set(std::string attrib, double value);
            void shader_attrib_set(std::string attrib, int value);
            void shader_attrib_set(std::string attrib, unsigned int value);
            void shader_attrib_set(std::string attrib, Vector2 value);
            void shader_attrib_set(std::string attrib, Point value);
            void shader_attrib_set(std::string attrib, float value1, float value2);
            void shader_attrib_set(std::string attrib, short value1, short value2);
            void shader_attrib_set(std::string attrib, double value1, double value2);
            void shader_attrib_set(std::string attrib, int value1, int value2);
            void shader_attrib_set(std::string attrib, unsigned int value1, unsigned int value2);
            void shader_attrib_set(std::string attrib, Vector3 value);
            void shader_attrib_set(std::string attrib, float value1, float value2, float value3);
            void shader_attrib_set(std::string attrib, short value1, short value2, short value3);
            void shader_attrib_set(std::string attrib, double value1, double value2, double value3);
            void shader_attrib_set(std::string attrib, int value1, int value2, int value3);
            void shader_attrib_set(std::string attrib, unsigned int value1, unsigned int value2, unsigned int value3);
            void shader_attrib_set(std::string attrib, Vector4 value);
            void shader_attrib_set(std::string attrib, float value1, float value2, float value3, float value4);
            void shader_attrib_set(std::string attrib, short value1, short value2, short value3, short value4);
            void shader_attrib_set(std::string attrib, double value1, double value2, double value3, double value4);
            void shader_attrib_set(std::string attrib, int value1, int value2, int value3, int value4);
            void shader_attrib_set(std::string attrib, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4);
            void shader_attrib_set(std::string attrib, Matrix value);
        
            void shader_uniform_set(std::string uniform, float value);
            void shader_uniform_set(std::string uniform, short value);
            void shader_uniform_set(std::string uniform, double value);
            void shader_uniform_set(std::string uniform, int value);
            void shader_uniform_set(std::string uniform, unsigned int value);
            void shader_uniform_set(std::string uniform, Vector2 value);
            void shader_uniform_set(std::string uniform, Point value);
            void shader_uniform_set(std::string uniform, float value1, float value2);
            void shader_uniform_set(std::string uniform, short value1, short value2);
            void shader_uniform_set(std::string uniform, double value1, double value2);
            void shader_uniform_set(std::string uniform, int value1, int value2);
            void shader_uniform_set(std::string uniform, unsigned int value1, unsigned int value2);
            void shader_uniform_set(std::string uniform, Vector3 value);
            void shader_uniform_set(std::string uniform, float value1, float value2, float value3);
            void shader_uniform_set(std::string uniform, short value1, short value2, short value3);
            void shader_uniform_set(std::string uniform, double value1, double value2, double value3);
            void shader_uniform_set(std::string uniform, int value1, int value2, int value3);
            void shader_uniform_set(std::string uniform, unsigned int value1, unsigned int value2, unsigned int value3);
            void shader_uniform_set(std::string uniform, Vector4 value);
            void shader_uniform_set(std::string uniform, float value1, float value2, float value3, float value4);
            void shader_uniform_set(std::string uniform, short value1, short value2, short value3, short value4);
            void shader_uniform_set(std::string uniform, double value1, double value2, double value3, double value4);
            void shader_uniform_set(std::string uniform, int value1, int value2, int value3, int value4);
            void shader_uniform_set(std::string uniform, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4);
            void shader_uniform_set(std::string uniform, Matrix value);
        };
    }
}

#endif //INFERNO_GRAPHICSDEVICE_H
