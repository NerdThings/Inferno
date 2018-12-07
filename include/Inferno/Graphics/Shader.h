//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_SHADER_H
#define INFERNO_SHADER_H

#include <string>

#include "Inferno/Graphics/Color.h"
#include "Inferno/Graphics/ShaderEnums.h"
#include "Inferno/Inferno.h"
#include "Inferno/Matrix.h"
#include "Inferno/Vector2.h"
#include "Inferno/Vector3.h"
#include "Inferno/Vector4.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        
        /*
         * A shader program
         */
        struct INFERNO_API Shader {
        private:
            //Fields
            
            /*
             * The fragment shader source code
             */
            std::string _fragment_source;
            
            /*
             * The vertex shader source code
             */
            std::string _vertex_source;
            
            //Methods
            
            /*
             * Get the uniform id
             */
            int uniform_get(std::string uniform);
            
        public:
            //Fields

#ifdef OPENGL
            /*
            * The fragment shader id
            */
            unsigned int fragment_id;
            
            /*
             * The vertex shader id
             */
            unsigned int vertex_id;
            
            /*
             * The gl program
             */
            unsigned int gl_program;
#endif
            
            //Constructors
            
            /*
             * Create a new Shader
             */
            Shader();
            
            //Deconstructors
            
            /*
             * Cleanup a deleted shader
             */
            ~Shader();
            
            //Methods
            
            /*
             * Compile the shader
             */
            void compile();
            
            /*
             * Set the source
             */
            void set_source(ShaderType type, std::string source, ShaderLanguage language);
            
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, float value);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, int value);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, Vector2 value);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, float value1, float value2);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, int value1, int value2);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, Vector3 value);
            
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, Color value);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, float value1, float value2, float value3);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, int value1, int value2, int value3);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, Vector4 value);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, float value1, float value2, float value3, float value4);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, int value1, int value2, int value3, int value4);
    
            /*
             * Set a uniform value
             */
            void uniform_set(std::string uniform, Matrix value);
        };
    }
}

#endif //INFERNO_SHADER_H
