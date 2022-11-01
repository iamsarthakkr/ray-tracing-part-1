#include "Ray_tracing.hpp"
#include "Color.hpp"

#include <iostream>

void Color::write_color(std::ostream& out, const color& pixel_color, const int samples_per_pixel) {
   auto r = pixel_color.x();
   auto g = pixel_color.y();
   auto b = pixel_color.z();

   auto factor = 1.0 / samples_per_pixel;
   r *= factor;
   g *= factor;
   b *= factor;

   // Translate each value to [0, 255]
   r = static_cast<int>(256 * r);
   g = static_cast<int>(256 * g);
   b = static_cast<int>(256 * b);
   
   out << r << ' ' << g << ' ' << b << '\n';
}
