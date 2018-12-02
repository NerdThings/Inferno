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
        
        struct INFERNO_API Shader {
        private:
            //Fields
            
            std::string _fragment_source;
            std::string _vertex_source;
            
            //Methods
            
            int uniform_get(std::string uniform);
            
        public:
            //Fields

#ifdef OPENGL
            unsigned int fragment_id;
            unsigned int vertex_id;
            unsigned int gl_program;
#endif
            
            //Constructors
            
            Shader();
            
            //Deconstructors
            
            ~Shader();
            
            //Methods
            
            void compile();
            void set_source(ShaderType type, std::string source, ShaderLanguage language);
            void uniform_set(std::string uniform, float value);
            void uniform_set(std::string uniform, int value);
            void uniform_set(std::string uniform, Vector2 value);
            void uniform_set(std::string uniform, float value1, float value2);
            void uniform_set(std::string uniform, int value1, int value2);
            void uniform_set(std::string uniform, Vector3 value);
            void uniform_set(std::string uniform, Color value);
            void uniform_set(std::string uniform, float value1, float value2, float value3);
            void uniform_set(std::string uniform, int value1, int value2, int value3);
            void uniform_set(std::string uniform, Vector4 value);
            void uniform_set(std::string uniform, float value1, float value2, float value3, float value4);
            void uniform_set(std::string uniform, int value1, int value2, int value3, int value4);
            void uniform_set(std::string uniform, Matrix value);
        };
    }
}

#endif //INFERNO_SHADER_H
