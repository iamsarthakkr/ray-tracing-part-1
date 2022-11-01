#include "Ray_tracing.hpp"

#include "Color.hpp"
#include "Hittable_list.hpp"
#include "Sphere.hpp"

#include <iostream>


// gives the color of a ray based on its y coordinate value
// gradient varies from white for y = 0 to cyan (24, 163, 126)
color ray_color(const Ray& ray, const Hittable_list& world) {
   Hit_record rec;
   if(world.hit(ray, 0, infinity, rec)) {
      // color based on the normal vector
      return 0.5 * (rec.normal + color(1, 1, 1));
   }
   
   // color for background
   auto unit_direction = unit_vector(ray.direction());
   auto t = 0.5 * (unit_direction.y() + 1.0);            // since y can be between [-1, 1], scaling it to be btw [0, 1]
      
   // linear interpolation : coloval = (1 - y) * initial_value + y * final_value
   return (1 - t) * Color::white + t * Color::cyan;
}

int main() {
   // Image dimensions

   const auto aspect_ratio = 16.0 / 9.0;
   const int image_height = 720;
   const int image_width = static_cast<int>(image_height * aspect_ratio);

   // World

   Hittable_list world;
   world.add(make_shared<Sphere>(point3D(0, 0, -1), 0.5));
   world.add(make_shared<Sphere>(point3D(0, -100.5, -1), 100));

   // Setting up camera position
   const auto origin = Vec3D(0, 0, 0);

   // Setting virtual viewport dimension (to pass our rays through)
   const auto viewport_height = 2.0;
   const auto viewport_width = viewport_height * aspect_ratio;
   const auto focal_length = 1.0;

   const auto horizontal = Vec3D(viewport_width, 0, 0);                                                  // vector for width
   const auto vertical = Vec3D(0, viewport_height, 0);                                                   // vector for height
   const auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3D(0, 0, focal_length);    // vector to the lower left corner of the viewport

   // Render

   std::cout << "P3\n";
   std::cout << image_width << " " << image_height << "\n";
   std::cout << "255\n";

   for(int i = image_height - 1; i >= 0; --i) {
      std::cerr << "\rScanlines remaining: " << i << ' ' << std::flush;
      for(int j = 0; j < image_width; j++) {
         auto y_offset = (double) i / (image_height - 1);
         auto x_offset = (double) j / (image_width - 1);

         auto ray_direction = lower_left_corner + x_offset * horizontal + y_offset * vertical;
         Ray ray(origin, ray_direction);
         auto pixel_color = ray_color(ray, world);
         Color::write_color(std::cout, pixel_color);
      }
   }
   std::cerr << "\nDone.\n";
}