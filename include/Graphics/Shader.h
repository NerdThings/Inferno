#ifndef Inferno_Graphics_Shader
#define Inferno_Graphics_Shader

#include "Inferno.h"

#include "Graphics/ShaderLanguage.h"
#include "Graphics/ShaderType.h"

namespace Inferno {
    namespace Graphics {
        
        /*
         * Shader Defaults:
         * A shader requires the following attributes:
         * vec3 inf_pos;
         * vec4 inf_color;
         * vec2 inf_texcoord;
         */
        
        struct INFERNO_API Shader {
            //Fields
            
            const char* _source;
        
        public:
            //Fields

#if OPENGL
            unsigned int shader;
#endif
        
            const ShaderType type;
            
            //Constructor
            
            Shader(ShaderType type);
            
            //Methods
            
            void set_source(const char* source, ShaderLanguage language);
            
            void compile();
        };
    }
}

#endif
