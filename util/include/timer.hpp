#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>
#include <iostream>

class
Timer
{
  using Timing = std::chrono::high_resolution_clock;
  using Point = std::chrono::time_point <Timing>;

  Point begin;

public:
  Timer() : begin { Timing::now() } { }
  ~Timer() {
    Point end { Timing::now() };
    std::cout << "timing: " << std::chrono::duration <double> { end - begin }.count() << "s" << std::endl;
  }
};

#endif
