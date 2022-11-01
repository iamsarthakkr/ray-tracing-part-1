#pragma once
#define COLOR_H

#include <iostream>
#include <Vec3D.hpp>

namespace Color {
   void write_color(std::ostream& out, const color& pixel_color, const int samples_per_pixel);

   const color white(1.0, 1.0, 1.0);
   const color cyan(24 / 255.999, 163 / 255.999, 126 / 255.999);
   const color purple(103 / 255.999, 8 / 255.999, 135 / 255.999);
}
