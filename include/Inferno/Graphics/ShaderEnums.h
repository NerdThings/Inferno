//
// Created by Reece Mackie on 14/11/18.
//

#ifndef INFERNO_SHADERENUMS_H
#define INFERNO_SHADERENUMS_H

namespace Inferno {
    namespace Graphics {
        /*
         * The type of shader
         */
        enum ShaderType {
            Fragment,
            Vertex
        };
    
        /*
         * The language a shader is written in
         */
        enum ShaderLanguage {
            GLSL,
            GLSL_ES,
            HLSL
        };
    }
}

#endif //INFERNO_SHADERENUMS_H
