#ifndef MAT4X4_HPP
#define MAT4X4_HPP

#include "Common.hpp"
#include <ostream>

// colum major matrix
struct Matrix4x4 {
  Vector4 column[4];
  Matrix4x4() {
    column[0] = Vector4(0.0);
    column[1] = Vector4(0.0);
    column[2] = Vector4(0.0);
    column[3] = Vector4(0.0);
  }
  // creates identity matrix with the param val
  Matrix4x4(float val) {
    column[0] = Vector4(val, 0.0, 0.0, 0.0);
    column[1] = Vector4(0.0, val, 0.0, 0.0);
    column[2] = Vector4(0.0, 0.0, val, 0.0);
    column[3] = Vector4(0.0, 0.0, 0.0, val);
  }
  Matrix4x4(Vector4 col_1, Vector4 col_2, Vector4 col_3, Vector4 col_4) {
    column[0] = col_1;
    column[1] = col_2;
    column[2] = col_3;
    column[3] = col_4;
  }
  Matrix4x4 operator+(Matrix4x4 const &_mat) {
    Matrix4x4 ret_mat4;

    ret_mat4.column[0] = ret_mat4.column[0] + _mat.column[0];
    ret_mat4.column[1] = ret_mat4.column[1] + _mat.column[1];
    ret_mat4.column[2] = ret_mat4.column[2] + _mat.column[2];
    ret_mat4.column[3] = ret_mat4.column[3] + _mat.column[3];

    return ret_mat4;
  }
  Matrix4x4 operator-(Matrix4x4 const &_mat) {
    Matrix4x4 ret_mat4;

    ret_mat4.column[0] = ret_mat4.column[0] - _mat.column[0];
    ret_mat4.column[1] = ret_mat4.column[1] - _mat.column[1];
    ret_mat4.column[2] = ret_mat4.column[2] - _mat.column[2];
    ret_mat4.column[3] = ret_mat4.column[3] - _mat.column[3];

    return ret_mat4;
  }
  Matrix4x4 operator*(const Matrix4x4 &_mat4) {
    return Matrix4x4(
        Vector4(dot(Vector4(column[0].x, column[1].x, column[2].x, column[3].x),
                    _mat4.column[0]),
                dot(Vector4(column[0].y, column[1].y, column[2].y, column[3].y),
                    _mat4.column[0]),
                dot(Vector4(column[0].z, column[1].z, column[2].z, column[3].z),
                    _mat4.column[0]),
                dot(Vector4(column[0].w, column[1].w, column[2].w, column[3].w),
                    _mat4.column[0])),
        Vector4(dot(Vector4(column[0].x, column[1].x, column[2].x, column[3].x),
                    _mat4.column[1]),
                dot(Vector4(column[0].y, column[1].y, column[2].y, column[3].y),
                    _mat4.column[1]),
                dot(Vector4(column[0].z, column[1].z, column[2].z, column[3].z),
                    _mat4.column[1]),
                dot(Vector4(column[0].w, column[1].w, column[2].w, column[3].w),
                    _mat4.column[1])),
        Vector4(dot(Vector4(column[0].x, column[1].x, column[2].x, column[3].x),
                    _mat4.column[2]),
                dot(Vector4(column[0].y, column[1].y, column[2].y, column[3].y),
                    _mat4.column[2]),
                dot(Vector4(column[0].z, column[1].z, column[2].z, column[3].z),
                    _mat4.column[2]),
                dot(Vector4(column[0].w, column[1].w, column[2].w, column[3].w),
                    _mat4.column[2])),
        Vector4(dot(Vector4(column[0].x, column[1].x, column[2].x, column[3].x),
                    _mat4.column[3]),
                dot(Vector4(column[0].y, column[1].y, column[2].y, column[3].y),
                    _mat4.column[3]),
                dot(Vector4(column[0].z, column[1].z, column[2].z, column[3].z),
                    _mat4.column[3]),
                dot(Vector4(column[0].w, column[1].w, column[2].w, column[3].w),
                    _mat4.column[3])));
  }
  Vector4 operator*(const Vector4 &vec_4) {
    return Vector4(
        dot(Vector4(column[0].x, column[1].x, column[2].x, column[3].x), vec_4),
        dot(Vector4(column[0].y, column[1].y, column[2].y, column[3].y), vec_4),
        dot(Vector4(column[0].z, column[1].z, column[2].z, column[3].z), vec_4),
        dot(Vector4(column[0].w, column[1].w, column[2].w, column[3].w),
            vec_4));
  }
};
inline std::ostream &operator<<(std::ostream &COUT,
                                const Matrix4x4 _Matrix4x4) {
  COUT << _Matrix4x4.column[0].x << "\t" << _Matrix4x4.column[1].x << "\t"
       << _Matrix4x4.column[2].x << "\t" << _Matrix4x4.column[3].x << "\n";
  COUT << _Matrix4x4.column[0].y << "\t" << _Matrix4x4.column[1].y << "\t"
       << _Matrix4x4.column[2].y << "\t" << _Matrix4x4.column[3].y << "\n";
  COUT << _Matrix4x4.column[0].z << "\t" << _Matrix4x4.column[1].z << "\t"
       << _Matrix4x4.column[2].z << "\t" << _Matrix4x4.column[3].z << "\n";
  COUT << _Matrix4x4.column[0].w << "\t" << _Matrix4x4.column[1].w << "\t"
       << _Matrix4x4.column[2].w << "\t" << _Matrix4x4.column[3].w << "\n";
  return COUT;
}

#endif