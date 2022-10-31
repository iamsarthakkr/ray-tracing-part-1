#include <iostream>

int main() {
   // Image dimensions

   const int image_width = 256;
   const int image_height = 256;

   // Render

   std::cout << "P3\n";
   std::cout << image_width << " " << image_height << "\n";
   std::cout << "255\n";

   for(int i = image_height - 1; i >= 0; --i) {
      for(int j = 0; j < image_width; j++) {
         std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
         double r = (double) i / (image_height - 1);
         double g = (double) j / (image_width - 1);
         double b = 0.15;

         int r_val = static_cast<int>(r * 255.999);
         int g_val = static_cast<int>(g * 255.999);
         int b_val = static_cast<int>(b * 255.999);

         std::cout << r_val << " " << g_val << " " << b_val << '\n';
      }
   }
   std::cerr << "\nDone.\n";
}