//
// Created by Reece Mackie on 13/11/18.
//

#ifndef INFERNO_SHADER_H
#define INFERNO_SHADER_H

#include "Inferno.h"

#include <string>

#include "Graphics/ShaderEnums.h"

namespace Inferno {
    namespace Graphics {
        class GraphicsDevice;
        
        struct INFERNO_API Shader {
        private:
            //Fields
            
            std::string _source;
            
        public:
            //Fields

#ifdef OPENGL
            unsigned int id;
#endif
            
            const ShaderType type;
            
            //Constructors
            
            Shader(ShaderType type);
            
            //Deconstructors
            
            ~Shader();
            
            //Methods
            
            void set_source(std::string source, ShaderLanguage language);
            
            void compile();
        };
    }
}

#endif //INFERNO_SHADER_H
