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
        //Private methods
        int Shader::uniform_get(std::string uniform){
#ifdef OPENGL
            return glGetUniformLocation(gl_program, uniform.c_str());
#endif
        }
        
        //Constructors
    
        Shader::Shader() {
#ifdef OPENGL
            fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
            vertex_id = glCreateShader(GL_VERTEX_SHADER);
            gl_program = glCreateProgram();
#endif
        }
        
        //Deconstructors
        
        Shader::~Shader() {
#ifdef OPENGL
            //Delete Fragment Shader
            glDeleteShader(fragment_id);
            
            //Delete Vertex Shader
            glDeleteShader(vertex_id);
            
            //Delete Program
            glDeleteProgram(gl_program);
    
            //Unset ids
            fragment_id = 0;
            vertex_id = 0;
            gl_program = 0;
#endif
        }
    
        //Methods
    
        void Shader::set_source(ShaderType type, std::string source, Inferno::Graphics::ShaderLanguage language) {
            //This makes it so that a game can have GLSL, GLSL ES and HLSL code, but only the correct code is loaded
            if (language == GLSL) {
#ifndef OPENGL_ES
#ifdef OPENGL
                type == Fragment ? _fragment_source = std::move(source) : _vertex_source = std::move(source);
#endif
#endif
            } else if (language == GLSL_ES) {
#ifdef OPENGL_ES
                type == Fragment ? _fragment_source = std::move(source) : _vertex_source = std::move(source);
#endif
            } else if (language == HLSL) {
#ifdef DIRECTX
                type == Fragment ? _fragment_source = std::move(source) : _vertex_source = std::move(source);
#endif
            }
        }
        
        void Shader::compile() {
#ifdef OPENGL
            
            //Compile fragment shader
            const char* src = _fragment_source.c_str();
            glShaderSource(fragment_id, 1, &src, nullptr);
            glCompileShader(fragment_id);
    
            int result = GL_FALSE;
            int info_log_length;
    
            glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &result);
            glGetShaderiv(fragment_id, GL_INFO_LOG_LENGTH, &info_log_length);
    
            if (info_log_length > 0 || result == GL_FALSE) {
                throw std::runtime_error("Fragment Shader failed to compile.");
            }
    
            //Compile vertex shader
            src = _vertex_source.c_str();
            glShaderSource(vertex_id, 1, &src, nullptr);
            glCompileShader(vertex_id);
            
            glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &result);
            glGetShaderiv(vertex_id, GL_INFO_LOG_LENGTH, &info_log_length);
    
            if (info_log_length > 0 || result == GL_FALSE) {
                throw std::runtime_error("Vertex Shader failed to compile.");
            }
            
            //Attach and link program
            glAttachShader(gl_program, fragment_id);
            glAttachShader(gl_program, vertex_id);
            glLinkProgram(gl_program);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, float value) {
#ifdef OPENGL
            glUniform1f(static_cast<GLuint>(uniform_get(std::move(uniform))), value);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, int value) {
#ifdef OPENGL
            glUniform1i(static_cast<GLuint>(uniform_get(std::move(uniform))), value);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, Vector2 value) {
            uniform_set(std::move(uniform), value.x, value.y);
        }
    
        void Shader::uniform_set(std::string uniform, float value1, float value2) {
#ifdef OPENGL
            glUniform2f(static_cast<GLuint>(uniform_get(std::move(uniform))), value1, value2);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, int value1, int value2) {
#ifdef OPENGL
            glUniform2i(static_cast<GLuint>(uniform_get(std::move(uniform))), value1, value2);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, Vector3 value) {
            uniform_set(std::move(uniform), value.x, value.y, value.z);
        }
    
        void Shader::uniform_set(std::string uniform, float value1, float value2, float value3) {
#ifdef OPENGL
            glUniform3f(static_cast<GLuint>(uniform_get(std::move(uniform))), value1, value2, value3);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, int value1, int value2, int value3) {
#ifdef OPENGL
            glUniform3i(static_cast<GLuint>(uniform_get(std::move(uniform))), value1, value2, value3);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, Vector4 value) {
            uniform_set(std::move(uniform), value.x, value.y, value.z, value.w);
        }
    
        void Shader::uniform_set(std::string uniform, Color value) {
            uniform_set(std::move(uniform), value.r(), value.g(), value.b(), value.a());
        }
    
        void Shader::uniform_set(std::string uniform, float value1, float value2, float value3, float value4) {
#ifdef OPENGL
            glUniform4f(static_cast<GLuint>(uniform_get(std::move(uniform))), value1, value2, value3, value4);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, int value1, int value2, int value3, int value4) {
#ifdef OPENGL
            glUniform4i(static_cast<GLuint>(uniform_get(std::move(uniform))), value1, value2, value3, value4);
#endif
        }
    
        void Shader::uniform_set(std::string uniform, Inferno::Matrix value) {
#ifdef OPENGL
            glUniformMatrix4fv(static_cast<GLuint>(uniform_get(std::move(uniform))), 1, GL_FALSE, value.to_float_vector().data());
#endif
        }
    }
}
