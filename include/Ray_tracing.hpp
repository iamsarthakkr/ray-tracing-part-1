#pragma once
#define RAY_TRACING_H

#include <cmath>
#include <memory>
#include <limits>

// Common usings
using std::sqrt;
using std::shared_ptr;
using std::make_shared;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
   return degrees * pi / 180.0;
}

// Headers
#include "Vec3D.hpp"
#include "Ray.hpp"