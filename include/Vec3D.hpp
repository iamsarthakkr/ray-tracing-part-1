#pragma once
#define VEC3D_H

#include <iostream>

class Vec3D {
public:
   Vec3D() : m_data{0, 0, 0} {}
   Vec3D(double x, double y, double z) : m_data{x, y, z} {}

   double x() const;
   double y() const;
   double z() const;
   double operator[] (int i) const;
   double& operator[] (int i);

   Vec3D operator-();
   Vec3D& operator+=(const Vec3D& v);
   Vec3D& operator*=(const double t);
   Vec3D& operator/=(const double t);

   double length() const;
   double length_squared() const;

private:
   double m_data[3];
};

using point3D = Vec3D;  // 3D point
using color = Vec3D;    // RGB color