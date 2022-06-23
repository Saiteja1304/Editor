#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "Vector2.hpp"
#include "Vector3.hpp"
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "Editor"

struct Window_KeyBinding {
  int windowClosePrimary = GLFW_KEY_LEFT_ALT, windowClose = GLFW_KEY_ESCAPE;
};
class Window {
public:
  Window_KeyBinding bindings;
  GLFWwindow *window_handle;
  int windowCloseFlag;
  static Window &wGetInstance() {
    static Window WInstance;
    return WInstance;
  }
  void WInit();
  void WCreateWindow();
  void WSetWindowSize(Vector2 windowSize);
  void WSetWindowSize(Vector2 &windowSize);
  void WGetWindowSize(iVector2 *windowSize);
  iVector2 WGetWindowSize();
  void WPollEvents();
  void WSwapBuffers();
  void WUpdate();
  void WExit();

private:
  Window() {}
  Window(Window const &);
  void operator=(Window const &);
};

#endif