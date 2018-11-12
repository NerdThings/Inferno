#ifndef Inferno_Graphics_Color
#define Inferno_Graphics_Color

#include "Inferno.h"

namespace Inferno {
	namespace Graphics {
		struct INFERNO_API Color {
			//Fields

			unsigned int packed_value;

			//Constructors
			
			Color();

			Color(unsigned int packed_value);

			Color(float r, float g, float b, float a);

			Color(int r, int g, int b, int a);

			//Methods
			
			float get_r() const;
			float get_g() const;
			float get_b() const;
			float get_a() const;

			//Operators

			bool operator==(Color b) const;

			bool operator!=(Color b) const;
		};
	}
}

#endif