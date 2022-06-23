#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "Common.hpp"
#include "Matrix4x4.hpp"
#include "Vector3.hpp"
#include <algorithm>

#define RAIDAN 57.2958
#define PI 3.141592653589793238

struct Quaternion {
  float w;
  Vector3 axis;
  Quaternion() {}

  // use this for calculating a quaternion
  // multiplies by cos(a/2) and sin(1/2)
  Quaternion(float _angle, Vector3 _axis) {
    w = std::cos((_angle * PI / 180) / 2);
    axis = normalize(_axis) * float(std::sin((_angle * PI / 180) / 2));
  }

  // use this for storing a quaternion
  Quaternion(Vector3 _axis, float _angle) {
    w = _angle;
    axis = _axis;
  }

  // operator * with quaternion
  Quaternion operator*(Quaternion &_quat) {
    return Quaternion(
        (axis * _quat.w + _quat.axis * w + cross(axis, _quat.axis)),
        (w * _quat.w - dot(axis, _quat.axis)));
  }
  // operator * with Vector3
  Vector3 operator*(Vector3 &vec) {
    Vector3 vcv = cross(axis, vec);
    return vec + vcv * (2 * w) + cross(axis, vcv) * 2;
  }
};

// inverse quaternion
inline Quaternion invertQuaternion(Quaternion &quat) {
  quat.axis = Vector3(-quat.axis.x, -quat.axis.y, -quat.axis.z);
  return quat;
}

// operator <<
inline std::ostream &operator<<(std::ostream &COUT, const Quaternion q) {
  COUT << q.w << "  " << q.axis.x << "  " << q.axis.y << "  " << q.axis.z
       << "\n";
  return COUT;
}
Quaternion EulerToQuaternion(Vector3 &_vec);
Matrix4x4 QuaternionToMatrix(Quaternion q);
#endif
