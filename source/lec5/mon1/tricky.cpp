#include <memory>

class Foo {
public:
  Foo(std::unique_ptr<int>, std::unique_ptr<int>) {}
};


int main() {
  Foo{std::unique_ptr<int>{new int{5}}, std::unique_ptr<int>{new int{10}}};
}

/*
Argument resolution is unspecified, so the order of argument evaluation can be:
new int{5}, std::unique_ptr<int>{new int{5}}, new int{10}, std::unique_ptr<int>{new int{10}}
new int{10}, std::unique_ptr<int>{new int{10}}, new int{5}, std::unique_ptr<int>{new int{5}}
new int{5}, new int{10}, std::unique_ptr<int>{new int{5}}, std::unique_ptr<int>{new int{10}}
and so on...
*/
