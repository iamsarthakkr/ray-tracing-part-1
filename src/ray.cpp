#include "Vec3D.hpp"
#include "Ray.hpp"

point3D Ray::origin() { return m_origin; }
Vec3D Ray::direction() { return m_direction; }

point3D Ray::at(double t) const {
   return m_origin + t * m_direction;
}