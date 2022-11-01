#pragma once
#define SPHERE_H

#include "Hittable.hpp"

class Sphere : public Hittable {
public:
   Sphere() {}
   Sphere(const point3D& center, const double radius) : center(center), radius(radius) {}

   bool hit(const Ray& ray, double t_min, double t_max, Hit_record& rec) const;

public:
   point3D center;
   double radius;   
};