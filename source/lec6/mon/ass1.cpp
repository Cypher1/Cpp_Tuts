#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using command_it = std::vector<std::string>::const_iterator;
// note: global variables are bad, global constants are not
constexpr auto n_repeat = 3U;
constexpr auto n_reverse = 5U;

void runcommand(const std::string& s) {
  if (s == "reverse") {
    std::vector<int> stack{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::reverse(stack.rbegin(), stack.rbegin() + n_reverse);
    std::copy(stack.begin(), stack.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
  } else {
    std::cout << s << '\n';
  }
}

command_it runcommands(command_it start, command_it end, unsigned times = 1) {
  for (auto i = 0U; i < times; ++i) {
    for (auto upto = start; upto != end; ++upto) {
      if (*upto == "repeat")
        upto = runcommands(upto + 1, std::find(start, end, "endrepeat"), n_repeat);
      else
        runcommand(*upto);
    }
  }
  return end;
}


int main() {
  std::ifstream in{"test.txt"};

  std::string s;
  std::vector<std::string> commands;
  while (in >> s)
    // question for you guys: what's the difference between emplace_back and push_back
    commands.emplace_back(std::move(s)); // note the std::move
  
  runcommands(commands.cbegin(), commands.cend());
}
