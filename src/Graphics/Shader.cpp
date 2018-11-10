#include "Graphics/Shader.h"

#ifdef OPENGL
#include "glad/glad.h"
#endif

#ifdef SDL
#include "SDL_opengl.h"
#endif

namespace Inferno {
    namespace Graphics {
        
        //Constructors
        
        Shader::Shader(ShaderType type) : _type(type) {
            _source = "";
#ifdef OPENGL
            _shader = glCreateShader(_type == Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
#endif
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
            glShaderSource(_shader, 1, &_source, nullptr);
            glCompileShader(_shader);
            
            
            int result = GL_FALSE;
            int info_log_length;
            
            glGetShaderiv(_shader, GL_COMPILE_STATUS, &result);
            glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &info_log_length);
            
            if (info_log_length > 0 || result == GL_FALSE) {
                throw "Shader failed to compile.";
            }
#endif
        }
    }
}