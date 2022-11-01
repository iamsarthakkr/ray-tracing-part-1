#pragma once
#define MATERIAL_H

#include "Ray_tracing.hpp"

struct Hit_Record;

class Material {
public:   
   // method to check whether material scatters the incomming ray and also calculate by how much
   virtual bool scatter(const Ray& ray_in, const Hit_Record& rec, color& attenuation, Ray& scatter) const = 0;
};
