#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

class Num {
public:
  Num(int i): isDouble(false), iVal(i) {}
  Num(double d): isDouble(true), dVal(d) {}

  friend Num operator+(const Num& lhs, const Num& rhs) {
    if (lhs.isDouble || rhs.isDouble)
      return Num{lhs.as_double() + rhs.as_double()};
    else
      return Num{lhs.as_int() + rhs.as_int()};
  }

  friend Num operator-(const Num& lhs, const Num& rhs) {
    if (lhs.isDouble || rhs.isDouble)
      return Num{lhs.as_double() - rhs.as_double()};
    else
      return Num{lhs.as_int() - rhs.as_int()};
  }

  friend Num operator*(const Num& lhs, const Num& rhs) {
    if (lhs.isDouble || rhs.isDouble)
      return Num{lhs.as_double() * rhs.as_double()};
    else
      return Num{lhs.as_int() * rhs.as_int()};
  }

  friend Num operator/(const Num& lhs, const Num& rhs) {
    if (lhs.isDouble || rhs.isDouble)
      return Num{lhs.as_double() / rhs.as_double()};
    else
      return Num{lhs.as_int() / rhs.as_int()};
  }

  Num sqrt() {
    if (isDouble)
      return Num{isDouble};
    else
      return Num{static_cast<int>(std::sqrt(iVal))};
  }

  friend std::ostream& operator<<(std::ostream& stream, const Num& num) {
    if (num.isDouble)
      stream << num.dVal;
    else
      stream << num.iVal;
    return stream;
  }

  double as_double() const {
    if (isDouble)
      return dVal;
    else
      return static_cast<double>(iVal);
  }

  int as_int() const {
    return iVal;
  }

private:
  // If using C++17, use std::variant<int, double> instead
  bool isDouble;
  int iVal;
  double dVal;
};

using command_it = std::vector<std::string>::const_iterator;

Num top_pop(std::vector<Num>& stack) {
  auto result = std::move(stack.back());
  stack.pop_back();
  return result;
}

void runcommand(std::vector<Num>& stack, const std::string& command) {
  const auto binaryFunction = [&] (const std::function<Num(Num, Num)>& f, char c) {
    return [&] () {
      auto lhs = top_pop(stack);
      auto rhs = top_pop(stack);
      stack.push_back(f(lhs, rhs));
      std::cout << lhs << ' ' << c << ' ' << rhs << " = " << stack.back() << '\n';
    };
  };

  const std::map<std::string, std::function<void()> commands{
      {"add", binaryFunction(std::plus<Num, Num>, '+')},
      {"sub", binaryFunction(std::minus<Num, Num>, '+')},
      {"mult", binaryFunction(std::multiplies<Num, Num>, '+')},
      {"div", binaryFunction(std::divides<Num, Num>, '+')},
      {"reverse", [&] () { std::reverse(stack.rbegin(), stack.rbegin() + top_pop(stack).as_int()); }},
  };

  if (commands.find(command) != commands.end())
    commands.at(command)();
  else if (command.find(".") == std::string::npos)
    stack.push_back(Num{std::stoi(command)});
  else
    stack.push_back(Num{std::stod(command)});
}

command_it runcommands(command_it start, command_it end, std::vector<Num>& stack, unsigned times = 1) {
  for (auto i = 0U; i < times; ++i) {
    for (auto upto = start; upto != end; ++upto) {
      if (*upto == "repeat")
        upto = runcommands(upto + 1, std::find(start, end, "endrepeat"), stack, top_pop(stack).as_int());
      else
        runcommand(stack, *upto);
    }
  }
  return end;
}


int main() {
  std::ifstream in{"test.txt"};

  std::string s;
  std::vector<std::string> commands;
  std::vector<Num> stack;

  while (in >> s)
    // question for you guys: what's the difference between emplace_back and push_back
    commands.emplace_back(std::move(s)); // note the std::move
  
  runcommands(commands.cbegin(), commands.cend(), stack);
}

