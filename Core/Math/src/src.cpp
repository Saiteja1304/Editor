#include "../include/Matrices.hpp"
#include "../include/Quaternion.hpp"
#include "Matrix4x4.hpp"
#include "Vector4.hpp"
#include <math.h>

Quaternion EulerToQuaternion(Vector3 &_vec) {
  float maxAngle = std::max(_vec.x, std::max(_vec.y, _vec.z));
  return Quaternion(maxAngle, Vector3(_vec.x / maxAngle, _vec.y / maxAngle,
                                      _vec.z / maxAngle));
}
Matrix4x4 QuaternionToMatrix(Quaternion q) {
  return Matrix4x4(
      Vector4(1 - 2 * ((q.axis.y * q.axis.y) + (q.axis.z * q.axis.z)),
              2 * (q.axis.x * q.axis.y + q.w * q.axis.z),
              2 * (q.axis.x * q.axis.z - q.w * q.axis.y), 0.0),

      Vector4(2 * (q.axis.x * q.axis.y - q.w * q.axis.z),
              1 - 2 * ((q.axis.x * q.axis.x) + (q.axis.z * q.axis.z)),
              2 * (q.axis.y * q.axis.z + q.w * q.axis.x), 0.0),

      Vector4(2 * (q.axis.x * q.axis.z + q.w * q.axis.y),
              2 * (q.axis.y * q.axis.z - q.w * q.axis.x),
              1 - 2 * ((q.axis.x * q.axis.x) + (q.axis.y * q.axis.y)), 0.0),
      Vector4(0.0, 0.0, 0.0, 1.0));
}
Matrix4x4 CreateMVPMatrix(Matrix4x4 &_model, Matrix4x4 &_view,
                          Matrix4x4 &_projection) {
  return _projection * _view * _model;
}
Matrix4x4 CreateMVPMatrix(Vector3 &_position, Vector3 &_rotation,
                          Vector3 &_scale) {
  return createTranslationMatrix(_position) * createRotationMatrix(_rotation) *
         createScalingMatrix(_scale);
}
Matrix4x4 CreateMVPMatrix(Vector3 &_position, Quaternion q, Vector3 &_scale) {
  return createTranslationMatrix(_position) * QuaternionToMatrix(q) *
         createScalingMatrix(_scale);
}

Matrix4x4 createRotationMatrix(Vector3 &rotation) {
  return Matrix4x4(Vector4(cos(rotation.z * (PI / 180)),
                           sin(rotation.z * (PI / 180)), 0.0, 0.0),
                   Vector4((-sin(rotation.z * (PI / 180))),
                           cos(rotation.z * (PI / 180)), 0.0, 0.0),
                   Vector4(0.0, 0.0, 1.0, 0.0), Vector4(0.0, 0.0, 0.0, 1.0)) *
         Matrix4x4(Vector4(cos(rotation.y * (PI / 180)), 0.0,
                           (-sin(rotation.y * (PI / 180))), 0.0),
                   Vector4(0.0, 1.0, 0.0, 0.0),
                   Vector4(sin(rotation.y * (PI / 180)), 0.0,
                           cos(rotation.y * (PI / 180)), 0.0),
                   Vector4(0.0, 0.0, 0.0, 1.0)) *
         Matrix4x4(Vector4(1.0, 0.0, 0.0, 0.0),
                   Vector4(0, cos(rotation.x * (PI / 180)),
                           sin(rotation.x * (PI / 180)), 0.0),
                   Vector4(0.0, (-sin(rotation.x * (PI / 180))),
                           cos(rotation.x * (PI / 180)), 0.0),
                   Vector4(0.0, 0.0, 0.0, 1.0));
}
Matrix4x4 createRotationMatrix(Quaternion q) { return QuaternionToMatrix(q); }

Matrix4x4 CreateViewMatrix(Vector3 camPos, Vector3 u, Vector3 v, Vector3 n) {
  return Matrix4x4(Vector4(u.x, v.x, n.x, 0), Vector4(u.y, v.y, n.y, 0),
                   Vector4(u.z, v.z, n.z, 0),
                   Vector4(-camPos.x, -camPos.y, -camPos.z, 1));
}
Matrix4x4 CreateProjectionMatrix(float near, float far, float fov,
                                 Vector2 windowSize) {
  return Matrix4x4(
      Vector4((1 / tan((fov / 2) * (PI / 180))) / (windowSize.x / windowSize.y),
              0, 0, 0),
      Vector4(0, (1 / (tan(fov / 2) * (PI / 180))), 0, 0),
      Vector4(0, 0, (-far - near) / (near - far), 0),
      Vector4(0, 0, 2 * far * near / (near - far), 0));
}