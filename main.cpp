#include <iostream>
#include <cmath>

#include "Vec3D.hpp"
#include "Color.hpp"
#include "Ray.hpp"

double hit_sphere(const point3D& center, const double radius, const Ray& ray) {
   auto a = dot(ray.direction(), ray.direction());
   auto b = dot(2 * ray.direction(), ray.origin() - center);
   auto c = dot(ray.origin() - center, ray.origin() - center) - radius * radius;

   auto discriminent = b * b - 4 * a * c;
   if(discriminent >= 0) {
      auto t = (-b - std::sqrt(discriminent)) / (2.0 * a);
      return t;
   }
   return -1;
}

// gives the color of a ray based on its y coordinate value
// gradient varies from white for y = 0 to cyan (24, 163, 126)
color ray_color(const Ray& ray) {
   auto t = hit_sphere(point3D(0, 0, -1), 0.5, ray);
   if(t != -1) {
      auto hit_point = ray.at(t);
      // Normal vector is the vector perpendicular to the surface of the sphere at the hit point of ray
      auto normal_unit_vector = unit_vector(Vec3D(hit_point - point3D(0, 0, -1)));
      return 0.5 * color(normal_unit_vector.x() + 1, normal_unit_vector.y() + 1, normal_unit_vector.z() + 1);
   }
   
   auto unit_direction = unit_vector(ray.direction());
   t = 0.5 * (unit_direction.y() + 1.0);            // since y can be between [-1, 1], scaling it to be btw [0, 1]
      
   // linear interpolation : coloval = (1 - y) * initial_value + y * final_value
   return (1 - t) * Color::white + t * Color::cyan;
}

int main() {
   // Image dimensions

   const auto aspect_ratio = 16.0 / 9.0;
   const int image_width = 2180;
   const int image_height = static_cast<int>(image_width / aspect_ratio);

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
         auto pixel_color = ray_color(ray);
         Color::write_color(std::cout, pixel_color);
      }
   }
   std::cerr << "\nDone.\n";
}