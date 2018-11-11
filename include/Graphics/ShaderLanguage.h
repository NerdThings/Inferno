#ifndef Inferno_Graphics_ShaderLanguage
#define Inferno_Graphics_ShaderLanguage

#include "Inferno.h"

namespace Inferno {
    namespace Graphics {
        enum ShaderLanguage {
            //OpenGL Shader
            GLSL,
        
            //OpenGL ES Shader
            GLSL_ES,
        
            //DirectX Shader
            HLSL
        };
    }
}

#endif
