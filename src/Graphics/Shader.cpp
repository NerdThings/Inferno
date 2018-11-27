//
// Created by Reece Mackie on 13/11/18.
//

#ifdef OPENGL
#include <glad/glad.h>
#endif

#ifdef SDL
#include <SDL_opengl.h>
#endif

#include <stdexcept>

#include "Inferno/Graphics/Shader.h"
#include "Inferno/Graphics/GraphicsDevice.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
    
        Shader::Shader(ShaderType type) : type(type) {
#ifdef OPENGL
            id = glCreateShader(type == Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
#endif
        }
        
        //Deconstructors
        
        Shader::~Shader() {
#ifdef OPENGL
            //Delete OpenGL Shader
            glDeleteShader(id);
    
            //Unset shader id
            id = 0;
#endif
        }
    
        //Methods
    
        void Shader::set_source(std::string source, Inferno::Graphics::ShaderLanguage language) {
            //This makes it so that a game can have GLSL, GLSL ES and HLSL code, but only the correct code is loaded
            if (language == GLSL) {
#ifndef OPENGL_ES
#ifdef OPENGL
                _source = std::move(source);
#endif
#endif
            } else if (language == GLSL_ES) {
#ifdef OPENGL_ES
                _source = source;
#endif
            } else if (language == HLSL) {
#ifdef DIRECTX
                _source = source;
#endif
            }
        }
        
        void Shader::compile() {
#ifdef OPENGL
            const char* src = _source.c_str();
            glShaderSource(id, 1, &src, nullptr);
            glCompileShader(id);
    
    
            int result = GL_FALSE;
            int info_log_length;
    
            glGetShaderiv(id, GL_COMPILE_STATUS, &result);
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &info_log_length);
    
            if (info_log_length > 0 || result == GL_FALSE) {
                throw std::runtime_error("Shader failed to compile.");
            }
#endif
        }
    }
}
