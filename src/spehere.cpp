#include "Sphere.hpp"

#include <cmath>

bool Sphere::hit(const Ray& ray, double t_min, double t_max, Hit_record& rec) const {
   Vec3D OC=ray.origin() - center;

   auto a=dot(ray.direction(), ray.direction());
   auto half_b=dot(ray.direction(), OC);
   auto c=dot(OC, OC) - radius * radius;

   auto modified_discriminent=half_b * half_b - a * c;

   if(modified_discriminent < 0) {
      return false;
   }

   auto t_1 = (-half_b - std::sqrt(modified_discriminent)) / a, t_2 = (-half_b + std::sqrt(modified_discriminent)) / a;

   double root = (-half_b - std::sqrt(modified_discriminent)) / a;
   if(root < t_min || root > t_max) {
      root = (-half_b + std::sqrt(modified_discriminent)) / a;
   }

   if(root < t_min || root > t_max) {
      return false;
   } 

   // Set the hit record
   rec.point = ray.at(root);
   rec.t = root;
   rec.normal = (rec.point - center) / radius;
   
   return true;
}

