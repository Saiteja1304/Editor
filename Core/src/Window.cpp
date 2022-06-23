#include "Vector2.hpp"
#include <GLFW/glfw3.h>
#include <Window/Window.hpp>
#include <cstddef>
#include <iostream>

void Window::WInit() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
void Window::WCreateWindow() {
  window_handle =
      glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
  glfwMakeContextCurrent(window_handle);
}
void Window::WSetWindowSize(Vector2 windowSize) {
  glfwSetWindowSize(window_handle, windowSize.x, windowSize.y);
}
void Window::WSetWindowSize(Vector2 &windowSize) {
  glfwSetWindowSize(window_handle, windowSize.x, windowSize.y);
}
iVector2 Window::WGetWindowSize() {
  iVector2 windowsize;
  glfwGetWindowSize(window_handle, &windowsize.x, &windowsize.y);
  return windowsize;
}
void Window::WGetWindowSize(iVector2 *windowSize) {
  glfwGetWindowSize(window_handle, &windowSize->x, &windowSize->y);
}
void Window::WPollEvents() { glfwPollEvents(); }
void Window::WSwapBuffers() { glfwSwapBuffers(window_handle); }

void Window::WUpdate() {
  windowCloseFlag = glfwWindowShouldClose(window_handle);
  glfwSetWindowShouldClose(
      window_handle,
      (glfwGetKey(window_handle, bindings.windowClose) == GLFW_TRUE) &&
          (glfwGetKey(window_handle, bindings.windowClosePrimary) ==
           GLFW_TRUE));
}
void Window::WExit() {
  glfwDestroyWindow(window_handle);
  glfwTerminate();
}