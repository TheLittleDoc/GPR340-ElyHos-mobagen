//
// Created by elysium.hosack on 9/30/2025.
//

#include "PointHx.h"

const PointHX PointHX::NE = PointHX(1,-1,0);
const PointHX PointHX::E = PointHX(1,0,-1);
const PointHX PointHX::SE = PointHX(0,1,-1);
const PointHX PointHX::SW = PointHX(-1, 0,1);
const PointHX PointHX::W = PointHX(-1,1,0);
const PointHX PointHX::NW = PointHX(0,-1,1);
const PointHX PointHX::INFINITE = PointHX(INT16_MAX, INT16_MAX, INT16_MAX );

bool PointHX::operator==(const PointHX& rhs) const { return z == rhs.z && y == rhs.y && x == rhs.x; }

bool PointHX::operator!=(const PointHX& rhs) const { return x != rhs.x || y != rhs.y || z != rhs.z; }

PointHX& PointHX::operator=(const PointHX& rhs) {
  // Check for self-assignment
  if (this == &rhs) return *this;
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
  return *this;
}

PointHX PointHX::operator+(const PointHX& rhs) const { return {x + rhs.x, y + rhs.y, z + rhs.z}; }

PointHX PointHX::operator-(const PointHX& rhs) const { return {x - rhs.x, y - rhs.y, z - rhs.z}; }
std::string PointHX::to_string() { return "{" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}"; }
PointHX& PointHX::operator+=(const PointHX& rhs) {
  this->x += rhs.x;
  this->y += rhs.y;
  this->z += rhs.z;
  return *this;
}
PointHX& PointHX::operator-=(const PointHX& rhs) {
  this->x -= rhs.x;
  this->y -= rhs.y;
  this->z -= rhs.z;
  return *this;
}
