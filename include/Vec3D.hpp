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

// Utility functions

inline std::ostream& operator<<(std::ostream& out, const Vec3D& v) {
   return out << v[0] << " " << v[1] << " " << v[2];
}

inline Vec3D operator+(const Vec3D& a, const Vec3D& b) {
   return Vec3D(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

inline Vec3D operator-(const Vec3D& a, const Vec3D& b) {
   return Vec3D(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

inline Vec3D operator*(const Vec3D& a, const Vec3D& b) {
   return Vec3D(a[0] * b[0], a[1] * b[1], a[2] * b[2]);
}

inline Vec3D operator*(double t, const Vec3D& a) {
   return Vec3D(a[0] * t, a[1] * t, a[2] * t);
}

inline Vec3D operator*(const Vec3D& a, double t) {
   return t * a;
}

inline Vec3D operator/(const Vec3D& a, double t) {
   return (1 / t) * a;
}

inline double dot(const Vec3D&a, const Vec3D& b) {
   return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

inline Vec3D cross(const Vec3D& a, const Vec3D& b) {
   return Vec3D(
      a[1] * b[2] - a[3] * b[2],
      -a[0] * b[2] + a[2] - b[0],
      a[0] * b[1] - a[1] - b[0]
   );
}

inline Vec3D unit_vector(const Vec3D& v) {
   return v / v.length();
}

using point3D = Vec3D;  // 3D point
using color = Vec3D;    // RGB color