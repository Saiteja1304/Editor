#ifndef COMMON_HPP
#define COMMON_HPP
#include "Vector3.hpp"
#include "Vector4.hpp"
#include <cmath>
inline float dot(Vector4 vec1, Vector4 vec2) {
  return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z) +
         (vec1.w * vec2.w);
}
inline float dot(Vector3 vec1, Vector3 vec2) {
  return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
}
inline Vector3 cross(Vector3 vec1, Vector3 vec2) {
  return Vector3((-(vec2.y * vec1.z) + vec1.y * vec2.z),
                 (-(vec2.x * vec1.z) + vec1.x * vec2.z),
                 (vec1.x * vec2.y - vec1.y * vec2.x));
}
inline Vector3 normalize(Vector3 &vec3) {
  // calculating denominator value and storing in denomVal
  float sumOfSqrt =
      sqrt((vec3.x * vec3.x) + (vec3.y * vec3.y) + (vec3.z * vec3.z));

  // calculating normalized vector
  vec3.x = vec3.x / sumOfSqrt;
  vec3.y = vec3.y / sumOfSqrt;
  vec3.z = vec3.z / sumOfSqrt;

  // returing normalized vector
  return vec3;
}
#endif