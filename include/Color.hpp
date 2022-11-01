#pragma once
#define COLOR_H

#include <iostream>
#include <Vec3D.hpp>

namespace Color {
   void write_color(std::ostream& out, const color& pixel_color, const int samples_per_pixel);

   const color white(1.0, 1.0, 1.0);
   const color cyan(24 / 256.0, 163 / 256.0, 126 / 256.0);
   const color purple(103 / 256.0, 8 / 256.0, 135 / 256.0);
   // const color sky_blue(60 / 256.0, 129 / 256.0, 193 / 256.0);
   const color sky_blue(132 / 256.0, 180 / 256.0, 255 / 256.0);
}
