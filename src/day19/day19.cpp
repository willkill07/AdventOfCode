#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "io.hpp"
#include "timer.hpp"

const static std::regex PARSE { R"((\w+) => (\w+))" };

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  size_t pos { 0 }, res { 0 };
  std::string mol;
  std::smatch m;
  std::unordered_set <std::string> set;
  std::unordered_multimap <std::string, std::string> rules;
  for (const auto & line : io::by_line { std::cin } )
    if (std::regex_match (line, m, PARSE))
      rules.emplace (m.str (part2 ? 2 : 1), m.str (part2 ? 1 : 2));
    else if (line.size() > 2)
      mol = line;
  if (!part2)
    for (const auto & r : rules)
      for (pos = mol.find (r.first, 0); pos != std::string::npos; pos = mol.find (r.first, pos + 1))
        res += set.insert (std::string { mol }.replace (pos, r.first.length(), r.second)).second;
  else
    while (mol != "e")
      for (const auto & r : rules)
        if (pos = mol.find (r.first, 0), pos != std::string::npos)
          mol.replace (pos, r.first.length(), r.second), ++res;
  std::cout << res << std::endl;
  return 0;
}
