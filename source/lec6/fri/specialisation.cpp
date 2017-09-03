#include <iostream>
#include <cstring>

template <typename T>
T min(T a, T b) {
  std::cout << "template\n";
  return a < b ? a : b;
}

template<> const char* min<const char*>(const char* a, const char* b) {
  std::cout << "specialisation\n";
  return (strcmp(a, b) < 0) ? a : b;
}

const char* min(const char* a, const char* b) {
  std::cout << "ordinary\n";
  return (strcmp(a, b) < 0) ? a : b;
}
/*
double min(double a, double b) {
  std::cout << "double\n";
  return a < b ? a : b;
}
*/

int main() {
  const char *s = "zyx";
  const char *t = "abc";
  std::cout << min(s,t) << '\n';

  std::cout << min<const char*>(s, t) << '\n';
  std::cout << min(1, 2) << '\n';
  std::cout << min(1.1, 2.2) << '\n';
  std::cout << min<double>(1, 2.2) << '\n';
}
