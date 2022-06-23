#ifndef VECTOR2_HPP
#define VECTOR2_HPP

struct Vector2 {
  union {
    float x, r;
  };
  union {
    float y, g;
  };
  Vector2() {}
  Vector2(float val) { x = y = val; }
  Vector2(float _val_1, float _val_2) {
    x = _val_1;
    y = _val_2;
  }
};
struct iVector2 {
  union {
    int x, r;
  };
  union {
    int y, g;
  };
  iVector2() {}
  iVector2(int val) { x = y = val; }
  iVector2(int _val_1, int _val_2) {
    x = _val_1;
    y = _val_2;
  }
};

#endif