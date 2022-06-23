#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include "Vector2.hpp"
#include "Vector3.hpp"
#include <ostream>
struct Vector4 {
  union {
    float r, x;
  };
  union {
    float g, y;
  };
  union {
    float b, z;
  };
  union {
    float a, w;
  };
  Vector4() {}
  Vector4(float val) { x = y = z = w = val; }
  Vector4(float _x, float _y, float _z, float _w) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
  }
  Vector4(Vector2 _first, Vector2 _second) {
    x = _first.x;
    y = _first.y;
    z = _second.x;
    w = _second.y;
  }
  Vector4(Vector3 vec3, float val) {
    x = vec3.x;
    y = vec3.y;
    z = vec3.z;
    w = val;
  }
  Vector4(float val, Vector3 vec3) {
    x = val;
    y = vec3.x;
    z = vec3.y;
    w = vec3.z;
  }
  Vector4 operator+(const Vector4 &_vec4) {
    return Vector4(x + _vec4.x, y + _vec4.y, z + _vec4.z, w + _vec4.w);
  }
  Vector4 operator-(const Vector4 &_vec4) {
    return Vector4(x - _vec4.x, y - _vec4.y, z - _vec4.z, w - _vec4.w);
  }
  Vector4 operator/(const float _val) {
    return Vector4(x / _val, y / _val, z / _val, w / _val);
  }
};
inline std::ostream &operator<<(std::ostream &COUT, const Vector4 vec4) {
  COUT << vec4.x << "  " << vec4.y << "  " << vec4.z << "  " << vec4.w << "\n";
  return COUT;
}

#endif