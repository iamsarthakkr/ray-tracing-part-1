#pragma once
#define MATERIAL_H

#include "Ray_tracing.hpp"

struct Hit_Record;

class Material {
public:
   virtual void scatter(const Ray& ray_in, const Hit_Record& rec, color& attenuation, Ray& scatter) const = 0;
};
