#include <iostream>
#include <memory>
#include <vector>

struct MyClass {
  MyClass() {
    std::cout << "default constructed\n";
  }

  MyClass(const MyClass&) {
    std::cout << "copy constructed\n";
  }

  MyClass(MyClass&&) {
    std::cout << "move constructed\n";
  }
};

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args... a) {
  return std::unique_ptr<T>(new T(a...));
}

int main() {
  MyClass a;
  auto x = make_unique<MyClass>(a);
  auto y = make_unique<MyClass>(std::move(a));
}
