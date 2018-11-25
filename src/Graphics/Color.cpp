//
// Created by Reece Mackie on 13/11/18.
//

#include <climits>

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
        
        //Predefined colors
        
        const Color Color::transparent_black = Color(0);
        const Color Color::transparent = Color(0);
        const Color Color::alice_blue = Color(0xfffff8f0);
        const Color Color::antique_white = Color(0xffd7ebfa);
        const Color Color::aqua = Color(0xffffff00);
        const Color Color::aquamarine = Color(0xffd4ff7f);
        const Color Color::azure = Color(0xfffffff0);
        const Color Color::beige = Color(0xffdcf5f5);
        const Color Color::bisque = Color(0xffc4e4ff);
        const Color Color::black = Color(0xff000000);
        const Color Color::blanched_almond = Color(0xffcdebff);
        const Color Color::blue = Color(0xffff0000);
        const Color Color::blue_violet = Color(0xffe22b8a);
        const Color Color::brown = Color(0xff2a2aa5);
        const Color Color::burly_wood = Color(0xff87b8de);
        const Color Color::cadet_blue = Color(0xffa09e5f);
        const Color Color::chartreuse = Color(0xff00ff7f);
        const Color Color::chocolate = Color(0xff1e69d2);
        const Color Color::coral = Color(0xff507fff);
        const Color Color::cornflower_blue = Color(0xffed9564);
        const Color Color::cornsilk = Color(0xffdcf8ff);
        const Color Color::crimson = Color(0xff3c14dc);
        const Color Color::cyan = Color(0xffffff00);
        const Color Color::dark_blue = Color(0xff8b0000);
        const Color Color::dark_cyan = Color(0xff8b8b00);
        const Color Color::dark_goldenrod = Color(0xff0b86b8);
        const Color Color::dark_gray = Color(0xffa9a9a9);
        const Color Color::dark_green = Color(0xff006400);
        const Color Color::dark_khaki = Color(0xff6bb7bd);
        const Color Color::dark_magenta = Color(0xff8b008b);
        const Color Color::dark_olive_green = Color(0xff2f6b55);
        const Color Color::dark_orange = Color(0xff008cff);
        const Color Color::dark_orchid = Color(0xffcc3299);
        const Color Color::dark_red = Color(0xff00008b);
        const Color Color::dark_salmon = Color(0xff7a96e9);
        const Color Color::dark_sea_green = Color(0xff8bbc8f);
        const Color Color::dark_slate_blue = Color(0xff8b3d48);
        const Color Color::dark_slate_gray = Color(0xff4f4f2f);
        const Color Color::dark_turquoise = Color(0xffd1ce00);
        const Color Color::dark_violet = Color(0xffd30094);
        const Color Color::deep_pink = Color(0xff9314ff);
        const Color Color::deep_sky_blue = Color(0xffffbf00);
        const Color Color::dim_gray = Color(0xff696969);
        const Color Color::dodger_blue = Color(0xffff901e);
        const Color Color::firebrick = Color(0xff2222b2);
        const Color Color::floral_white = Color(0xfff0faff);
        const Color Color::forest_green = Color(0xff228b22);
        const Color Color::fuchsia = Color(0xffff00ff);
        const Color Color::gainsboro = Color(0xffdcdcdc);
        const Color Color::ghost_white = Color(0xfffff8f8);
        const Color Color::gold = Color(0xff00d7ff);
        const Color Color::goldenrod = Color(0xff20a5da);
        const Color Color::gray = Color(0xff808080);
        const Color Color::green = Color(0xff008000);
        const Color Color::green_yellow = Color(0xff2fffad);
        const Color Color::honeydew = Color(0xfff0fff0);
        const Color Color::hot_pink = Color(0xffb469ff);
        const Color Color::indian_red = Color(0xff5c5ccd);
        const Color Color::indigo = Color(0xff82004b);
        const Color Color::ivory = Color(0xfff0ffff);
        const Color Color::khaki = Color(0xff8ce6f0);
        const Color Color::lavender = Color(0xfffae6e6);
        const Color Color::lavender_blush = Color(0xfff5f0ff);
        const Color Color::lawn_green = Color(0xff00fc7c);
        const Color Color::lemon_chiffon = Color(0xffcdfaff);
        const Color Color::light_blue = Color(0xffe6d8ad);
        const Color Color::light_coral = Color(0xff8080f0);
        const Color Color::light_cyan = Color(0xffffffe0);
        const Color Color::light_goldenrod_yellow = Color(0xffd2fafa);
        const Color Color::light_gray = Color(0xffd3d3d3);
        const Color Color::light_green = Color(0xff90ee90);
        const Color Color::light_pink = Color(0xffc1b6ff);
        const Color Color::light_salmon = Color(0xff7aa0ff);
        const Color Color::light_sea_green = Color(0xffaab220);
        const Color Color::light_sky_blue = Color(0xffface87);
        const Color Color::light_slate_gray = Color(0xff998877);
        const Color Color::light_steel_blue = Color(0xffdec4b0);
        const Color Color::light_yellow = Color(0xffe0ffff);
        const Color Color::lime = Color(0xff00ff00);
        const Color Color::lime_green = Color(0xff32cd32);
        const Color Color::linen = Color(0xffe6f0fa);
        const Color Color::magenta = Color(0xffff00ff);
        const Color Color::maroon = Color(0xff000080);
        const Color Color::medium_aquamarine = Color(0xffaacd66);
        const Color Color::medium_blue = Color(0xffcd0000);
        const Color Color::medium_orchid = Color(0xffd355ba);
        const Color Color::medium_purple = Color(0xffdb7093);
        const Color Color::medium_sea_green = Color(0xff71b33c);
        const Color Color::medium_slate_blue = Color(0xffee687b);
        const Color Color::medium_spring_green = Color(0xff9afa00);
        const Color Color::medium_turquoise = Color(0xffccd148);
        const Color Color::medium_violet_red = Color(0xff8515c7);
        const Color Color::midnight_blue = Color(0xff701919);
        const Color Color::mint_cream = Color(0xfffafff5);
        const Color Color::misty_rose = Color(0xffe1e4ff);
        const Color Color::moccasin = Color(0xffb5e4ff);
        const Color Color::navajo_white = Color(0xffaddeff);
        const Color Color::navy = Color(0xff800000);
        const Color Color::old_lace = Color(0xffe6f5fd);
        const Color Color::olive = Color(0xff008080);
        const Color Color::olive_drab = Color(0xff238e6b);
        const Color Color::orange = Color(0xff00a5ff);
        const Color Color::orange_red = Color(0xff0045ff);
        const Color Color::orchid = Color(0xffd670da);
        const Color Color::pale_goldenrod = Color(0xffaae8ee);
        const Color Color::pale_green = Color(0xff98fb98);
        const Color Color::pale_turquoise = Color(0xffeeeeaf);
        const Color Color::pale_violet_red = Color(0xff9370db);
        const Color Color::papaya_whip = Color(0xffd5efff);
        const Color Color::peach_puff = Color(0xffb9daff);
        const Color Color::peru = Color(0xff3f85cd);
        const Color Color::pink = Color(0xffcbc0ff);
        const Color Color::plum = Color(0xffdda0dd);
        const Color Color::powder_blue = Color(0xffe6e0b0);
        const Color Color::purple = Color(0xff800080);
        const Color Color::red = Color(0xff0000ff);
        const Color Color::rosy_brown = Color(0xff8f8fbc);
        const Color Color::royal_blue = Color(0xffe16941);
        const Color Color::saddle_brown = Color(0xff13458b);
        const Color Color::salmon = Color(0xff7280fa);
        const Color Color::sandy_brown = Color(0xff60a4f4);
        const Color Color::sea_green = Color(0xff578b2e);
        const Color Color::sea_shell = Color(0xffeef5ff);
        const Color Color::sienna = Color(0xff2d52a0);
        const Color Color::silver  = Color(0xffc0c0c0);
        const Color Color::sky_blue  = Color(0xffebce87);
        const Color Color::slate_blue = Color(0xffcd5a6a);
        const Color Color::slate_gray = Color(0xff908070);
        const Color Color::snow = Color(0xfffafaff);
        const Color Color::spring_green = Color(0xff7fff00);
        const Color Color::steel_blue = Color(0xffb48246);
        const Color Color::tan = Color(0xff8cb4d2);
        const Color Color::teal = Color(0xff808000);
        const Color Color::thistle = Color(0xffd8bfd8);
        const Color Color::tomato = Color(0xff4763ff);
        const Color Color::turquoise = Color(0xffd0e040);
        const Color Color::violet = Color(0xffee82ee);
        const Color Color::wheat = Color(0xffb3def5);
        const Color Color::white = Color(UINT_MAX);
        const Color Color::white_smoke = Color(0xfff5f5f5);
        const Color Color::yellow = Color(0xff00ffff);
        const Color Color::yellow_green = Color(0xff32cd9a);
    }
}