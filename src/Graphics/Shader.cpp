//
// Created by Reece Mackie on 13/11/18.
//

#ifdef OPENGL
#include "glad/glad.h"
#endif

#ifdef SDL
#include "SDL_opengl.h"
#endif

#include "Graphics/Shader.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
    
        Shader::Shader(Inferno::Graphics::ShaderType type) : type(type) {
#ifdef OPENGL
            id = glCreateShader(type == Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
#endif
        }
        
        //Deconstructors
        
        Shader::~Shader() {
            //TODO: Destroy shader
        }
    
        //Methods
    
        void Shader::set_source(const char *source, Inferno::Graphics::ShaderLanguage language) {
            //This makes it so that a game can have GLSL, GLSL ES and HLSL code, but only the correct code is loaded
            if (language == GLSL) {
#ifndef OPENGL_ES
#ifdef OPENGL
                _source = source;
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
            glShaderSource(id, 1, &_source, nullptr);
            glCompileShader(id);
    
    
            int result = GL_FALSE;
            int info_log_length;
    
            glGetShaderiv(id, GL_COMPILE_STATUS, &result);
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &info_log_length);
    
            if (info_log_length > 0 || result == GL_FALSE) {
                throw "Shader failed to compile.";
    
            }
#endif
        }
    }
}