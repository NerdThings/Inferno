//
// Created by Reece Mackie on 13/11/18.
//

#include "Graphics/Color.h"
#include "MathHelper.h"

namespace Inferno {
    namespace Graphics {
        //Constructors
        
        Color::Color() : packed_value(0xFFFFFFFF) {}
        
        Color::Color(unsigned int packed_value) : packed_value(packed_value) {}
        
        Color::Color(float r, float g, float b, float a) : Color((int)(r * 255), (int)(g * 255), (int)(b * 255), (int)(a * 255)) {}
        
        Color::Color(int r, int g, int b, int a) {
            if (((r | g | b | a) & 0xFFFFFFFF00) != 0) {
                const auto clamped_r = static_cast<const unsigned int>(MathHelper::clamp(r, 0, 255));
                const auto clamped_g = static_cast<const unsigned int>(MathHelper::clamp(g, 0, 255));
                const auto clamped_b = static_cast<const unsigned int>(MathHelper::clamp(b, 0, 255));
                const auto clamped_a = static_cast<const unsigned int>(MathHelper::clamp(a, 0, 255));
        
                this->packed_value = (clamped_a << 24) | (clamped_b << 16) | (clamped_g << 8) | (clamped_r);
            } else {
                this->packed_value = ((unsigned int)(a) << 24) | ((unsigned int)(b) << 16) | ((unsigned int)(g) << 8) | ((unsigned int)(r));
            }
        }
        
        //Methods
    
        float Color::get_a() {
            return (unsigned char)(packed_value >> 24) / 255.0f;
        }
    
        float Color::get_b() {
            return (unsigned char)(packed_value >> 16) / 255.0f;
        }
    
        float Color::get_g() {
            return (unsigned char)(packed_value >> 8) / 255.0f;
        }
    
        float Color::get_r() {
            return (unsigned char)(packed_value) / 255.0f;
        }
        
        //Operators
        
        bool Color::operator==(Inferno::Graphics::Color b) {
            return packed_value == b.packed_value;
        }
        
        bool Color::operator!=(Inferno::Graphics::Color b) {
            return !(*this == b);
        }
    }
}