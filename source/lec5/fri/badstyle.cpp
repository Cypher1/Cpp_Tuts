#include <stdexcept>

void g() {
  throw std::runtime_error{"error"};
}

int f() {
  auto x = new int;
  try {
    g();
  } catch (const std::exception&) {
    delete x;
    throw;
  }
  delete x;
}

int main() {
  f();
}
