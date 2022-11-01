#include "Metal.hpp"
#include "Hittable.hpp"

bool Metal::scatter(const Ray& ray_in, const Hit_record& rec, color& attenuation, Ray& scattered) const {
   auto reflected = reflect(ray_in.direction(), rec.normal);
   scattered = Ray(rec.point, reflected);
   attenuation = reflectance;

   return dot(scattered.direction(), rec.normal) > 0;
}