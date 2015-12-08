#include <iostream>
#include <string>
#include "md5.hpp"
#include "timer.hpp"

int main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  std::string input;
  std::cin >> input;
  int index { 1 };
  while (true) {
    std::string parse { input + std::to_string (index) };
    std::string md5sum { md5 (parse) };
    if ((!part2 && (md5sum.find ("00000") == 0)) || (part2 && (md5sum.find ("000000") == 0)))
      break;
    ++index;
  }
  std::cout << index << std::endl;
  return 0;
}
