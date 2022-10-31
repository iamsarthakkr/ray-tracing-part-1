#include <iostream>

#include "Vec3D.hpp"
#include "Color.hpp"

int main() {
   // Image dimensions

   const int image_width = 256;
   const int image_height = 256;

   // Render

   std::cout << "P3\n";
   std::cout << image_width << " " << image_height << "\n";
   std::cout << "255\n";

   for(int i = image_height - 1; i >= 0; --i) {
      std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
      for(int j = 0; j < image_width; j++) {
         double r = (double) i / (image_height - 1);
         double g = (double) j / (image_width - 1);
         double b = 0.15;

         Color::write_color(std::cout, color(r, g, b));
      }
   }
   std::cerr << "\nDone.\n";
}