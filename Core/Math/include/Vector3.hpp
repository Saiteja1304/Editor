#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include "Vector2.hpp"
#include <ostream>
struct Vector3 {
  union {
    float x, r;
  };
  union {
    float g, y;
  };
  union {
    float b, z;
  };
  Vector3() {}
  Vector3(float val) { x = y = z = val; }
  Vector3(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
  }
  Vector3(Vector2 _vec2, float val) {
    x = _vec2.x;
    y = _vec2.y;
    z = val;
  }
  Vector3(float val, Vector2 _vec2) {
    x = val;
    y = _vec2.x;
    z = _vec2.y;
  }
  Vector3 operator-(const Vector3 &vec3) {
    return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
  }
  Vector3 operator+(const Vector3 &vec3) {
    return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
  }
  Vector3 operator*(const float &_val) {
    return Vector3(_val * x, _val * y, _val * z);
  }
};
inline std::ostream &operator<<(std::ostream &COUT, const Vector3 &vec) {
  COUT << vec.x << "  " << vec.y << "  " << vec.z << "\n";
  return COUT;
}

#endif