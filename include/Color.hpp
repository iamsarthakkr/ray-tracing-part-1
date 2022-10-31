#pragma once
#define COLOR_H

#include <iostream>
#include <Vec3D.hpp>

namespace Color {
   void write_color(std::ostream& out, const color& pixel_color);
}
