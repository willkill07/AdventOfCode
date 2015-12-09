#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include "timer.hpp"

static const std::regex PARSE { "(\\d+)x(\\d+)x(\\d+)" };

int main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  int total { 0 };
  int b[3];
  std::smatch m;
  std::string line;
  while (std::getline (std::cin, line)) {
    std::regex_search (line, m, PARSE);
    std::transform (++m.begin(), m.end(), b, [] (const auto &o) { return std::stoi (o); });
    std::sort (b, b + 3);
    total += ((part2) ? (2 * (b[0] + b[1]) + (b[0] * b[1] * b[2])) : (3 * (b[0] * b[1]) + 2 * b[2] * (b[0] + b[1])));
  }
  std::cout << total << std::endl;
  return 0;
}
