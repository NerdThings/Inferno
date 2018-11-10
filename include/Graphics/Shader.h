#ifndef Inferno_Graphics_Shader
#define Inferno_Graphics_Shader

#include "Inferno.h"

namespace Inferno {
    namespace Graphics {
        enum ShaderType {
            Fragment,
            Vertex
        };
        
        enum ShaderLanguage {
            //OpenGL Shader
            GLSL,
            
            //OpenGL ES Shader
            GLSL_ES,
            
            //DirectX Shader
            HLSL
        };
        
        struct INFERNO_API Shader {
            //Fields
            
            const char* _source;
    
            ShaderType _type;

#if OPENGL
            unsigned int _shader;
#endif
        
        public:
            //Constructor
            
            Shader(ShaderType type);
            
            //Methods
            
            void set_source(const char* source, ShaderLanguage language);
            
            void compile();
        };
    }
}

#endif
