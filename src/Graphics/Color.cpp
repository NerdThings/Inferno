#include "Graphics/Color.h"
#include "MathHelper.h"

namespace Inferno {
    namespace Graphics {

        //Constructors

        Color::Color(unsigned packed_value) {
            this->packed_value = packed_value;
        }

        Color::Color(float r, float g, float b, float a)
                : Color(int(r * 255), int(g * 255),
                        int(b * 255), int(a * 255)) {
        }


        Color::Color(int r, int g, int b, int a) {
            if (((r | g | b | a) & 0xFFFFFFFF00) != 0) {
                const unsigned int clamped_r = MathHelper::clamp(r, 0, 255);
                const unsigned int clamped_g = MathHelper::clamp(g, 0, 255);
                const unsigned int clamped_b = MathHelper::clamp(b, 0, 255);
                const unsigned int clamped_a = MathHelper::clamp(a, 0, 255);

                this->packed_value = (clamped_a << 24) | (clamped_b << 16) | (clamped_g << 8) | (clamped_r);
            } else {
                this->packed_value = (static_cast<unsigned int>(a) << 24) | (static_cast<unsigned int>(b) << 16) |
                                     (static_cast<unsigned int>(g) << 8) | (static_cast<unsigned int>(r));
            }
        }

        //Methods

        char Color::get_a() const {
            return char(packed_value >> 24);
        }

        char Color::get_b() const {
            return char(packed_value >> 16);
        }

        char Color::get_g() const {
            return char(packed_value >> 8);
        }

        char Color::get_r() const {
            return char(packed_value);
        }

        //Operators

        bool Color::operator==(Color *b) const {
            return packed_value == packed_value;
        }

        bool Color::operator!=(Color *b) const {
            return !(this == b);
        }

    }
}