#ifndef MATRICES_HPP
#define MATRICES_HPP

#include "Vector2.hpp"
#include "Vector4.hpp"
#define RAIDAN 57.2958
#define PI 3.141592653589793238

#include "Matrix4x4.hpp"
#include "Quaternion.hpp"
#include "Vector3.hpp"
inline Matrix4x4 createTranslationMatrix(Vector3 &position) {
  return Matrix4x4(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0),
                   Vector4(0, 0, 1, 0), Vector4(position, 1));
}
inline Matrix4x4 createScalingMatrix(Vector3 &scale) {
  return Matrix4x4(Vector4(scale.x, 0, 0, 0), Vector4(0, scale.y, 0, 0),
                   Vector4(0, 0, scale.z, 0), Vector4(0, 0, 0, 1));
}
Matrix4x4 createRotationMatrix(Vector3 &rotation);
Matrix4x4 createRotationMatrix(Quaternion q);
Matrix4x4 CreateMVPMatrix(Matrix4x4 &_model, Matrix4x4 &_view,
                          Matrix4x4 &_projection);
Matrix4x4 CreateMVPMatrix(Vector3 &_position, Vector3 &_rotation,
                          Vector3 &_scale);
Matrix4x4 CreateMVPMatrix(Vector3 &_position, Quaternion q, Vector3 &_scale);

Matrix4x4 CreateViewMatrix(Vector3 camPos, Vector3 u, Vector3 v, Vector3 n);
Matrix4x4 CreateProjectionMatrix(float near, float far, float fov,
                                 Vector2 windowSize);

#endif