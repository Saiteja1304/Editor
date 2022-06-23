#include <bits/chrono.h>
#include <iostream>
#ifndef DEBUG_HPP
#define DEBUG_HPP

// Includes
#include <chrono>

class Timer {
public:
  double ms;
  Timer() { d_StartTime = std::chrono::high_resolution_clock::now(); }
  ~Timer() { Stop(); }
  void Stop() {
    auto d_EndTime = std::chrono::high_resolution_clock::now();

    auto start =
        std::chrono::time_point_cast<std::chrono::microseconds>(d_StartTime)
            .time_since_epoch()
            .count();
    auto end =
        std::chrono::time_point_cast<std::chrono::microseconds>(d_EndTime)
            .time_since_epoch()
            .count();

    auto duration = end - start;
    ms = duration * 0.001;
    std::cerr << "Duration :" << ms << "ms"
              << "\n";
  }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> d_StartTime;
};

#endif