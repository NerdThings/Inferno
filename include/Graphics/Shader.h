//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_SHADER_H
#define INFERNO_SHADER_H

#include "Inferno.h"

namespace Inferno {
    namespace Graphics {
        enum ShaderType {
            Fragment,
            Vertex
        };
        
        enum ShaderLanguage {
            GLSL,
            GLSL_ES,
            HLSL
        };
        
        struct INFERNO_API Shader {
        private:
            //Fields
            
            const char* _source;
            
        public:
            //Fields

#ifdef OPENGL
            unsigned int id;
#endif
            
            const ShaderType type;
            
            //Constructors
            
            explicit Shader(ShaderType type);
            
            //Deconstructors
            
            ~Shader();
            
            //Methods
            
            void set_source(const char* source, ShaderLanguage language);
            
            void compile();
        };
    }
}

#endif //INFERNO_SHADER_H
