#include <cmath>
#include <iostream>

#include "Vec3D.hpp"

double Vec3D::x() const { return m_data[0]; }
double Vec3D::y() const { return m_data[1]; }
double Vec3D::z() const { return m_data[2]; }
double Vec3D::operator[] (int i) const { return m_data[i]; }
double& Vec3D::operator[] (int i) { return m_data[i]; }

Vec3D Vec3D::operator-() { return Vec3D(m_data[0], m_data[1], m_data[2]); }
Vec3D& Vec3D::operator+=(const Vec3D& v) {
   m_data[0] += v.m_data[0];
   m_data[1] += v.m_data[1];
   m_data[2] += v.m_data[2];
   return *this;
}
Vec3D& Vec3D::operator*=(const double t) {
   m_data[0] *= t;
   m_data[1] *= t;
   m_data[2] *= t;
   return *this;
}
Vec3D& Vec3D::operator/=(const double t) {
   return *this *= 1 / t;
}

double Vec3D::length() const {
   return std::sqrt(length_squared());
}
double Vec3D::length_squared() const {
   return m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2];
}
