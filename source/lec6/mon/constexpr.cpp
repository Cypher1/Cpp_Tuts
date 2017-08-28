#include <array>

// what if we want to make it anything that can be dereferenced, rather than int*
// We could use templates, or try the intuitive method of just writing auto
auto dereference(int* x) {
  return *x;
}

auto get_max_files() {
  return 20;
}

const auto get_max_files_const() {
  return 20;
}

constexpr auto get_max_files_constexpr() {
  return 20;
}

auto increment(int x) {
  /* constexpr */ auto added = x + 1;
  return added;
}

constexpr auto increment2(int x) {
  /* constexpr */ auto added = x + 1;
  return added;
}

// in C++14 this can be constexpr
constexpr auto triangle(unsigned n) {
  auto sum = 0U;
  for (auto i = 0U; i < n; ++i)
    sum += i;
  return sum;
}

/*
constexpr auto make_powers(int size, int base) {
  std::array<int, size> arr;
  arr[0] = 1;
  for (auto i = 1U; i < arr.size(); ++i)
    arr[i] = arr[i - 1] * base;
  return arr;
}


constexpr auto make_powers2(std::array<int, 10>& arr, int base) {
  arr[0] = 1;
  for (auto i = 1U; i < arr.size(); ++i)
    arr[i] = arr[i - 1] * base;
}
*/


constexpr auto make_powers3(std::array<int, 10>& arr, int base) {
  std::get<0>(arr) = 1;
  /*
  for (auto i = 1U; i < arr.size(); ++i)
    std::get<i>(arr) = std::get<i - 1>(arr) * base;
  */
}

int global;

int main() {
  constexpr std::array<int, 3> a{1, 2, 3};

  const auto max_files = 20;
  std::array<int, max_files> a1;
  constexpr auto max_files_constexpr = max_files;
  std::array<int, max_files_constexpr> a2;

  
  /*
  constexpr auto max_files_fn = get_max_files();
  constexpr auto max_files_fn2 = get_max_files_const();
  */
  
  constexpr auto max_files_fn3 = get_max_files_constexpr();
  const auto limit = max_files + 1;
  const auto staff_size = 27;

  const int *p = nullptr; // pointer to a const int
  int *const p2 = nullptr; // const pointer to int
  constexpr int *q = nullptr; // constexpr refers to top level const. This is a const pointer to int

//   constexpr auto* p1 = &staff_size;
   constexpr auto* p3 = &global;
}
