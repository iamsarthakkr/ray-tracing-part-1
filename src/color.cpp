#include <iostream>
#include "Color.hpp"

void Color::write_color(std::ostream& out, const color& pixel_color) {
   // Translate each value to [0, 255]
   auto r = static_cast<int>(255.999 * pixel_color.x());
   auto g = static_cast<int>(255.999 * pixel_color.y());
   auto b = static_cast<int>(255.999 * pixel_color.z());

   out << r << ' ' << g << ' ' << b << '\n';
}
