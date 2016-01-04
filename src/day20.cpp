#include <array>
#include "Solution.hpp"
#include "io.hpp"

void Day20::solve (bool part2, std::ifstream & ifs) {
  static std::array <int, 1000000> points;
  int sum { std::stoi (io::as_string (ifs)) }, weight { part2 ? 11 : 10 };
  size_t elf { 1 };
  for (; elf <= points.size(); ++elf)
    for (size_t h { elf - 1 }; h < points.size() && (part2 ? h < elf * 50 : true); h += elf)
      points [h] += elf * weight;
  for (elf = 0; points [elf++] < sum; );
  std::cout << elf << std::endl;
}
