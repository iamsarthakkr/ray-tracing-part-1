#pragma once
#define HITTABLE_H

#include "Ray.hpp"

// Struct to hold the info about the strike point of a ray with a hittable object
struct Hit_record {
   point3D point;
   Vec3D normal;
   double t;
};

class Hittable {
public:
   virtual bool hit(const Ray& ray, double min_t, double max_t, Hit_record& rec) const = 0;
};