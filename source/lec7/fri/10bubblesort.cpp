#include <iostream>

// function to swap two values
template<int I, int J>
struct IntSwap {
    static inline void compareAndSwap(int* data) {
        if (data[I] > data[J])
            std::swap(data[I], data[J]);
    }
};

// loop to go through array
template<int I, int J>
class IntBubbleSortLoop {
private:
    static const bool go = (J <= I-2);
public:
    static inline void loop(int* data) {
        IntSwap<J,J+1>::compareAndSwap(data);
        IntBubbleSortLoop<go ? I : 0, go ? (J+1) : 0>::loop(data);
    }
};

template <>
struct IntBubbleSortLoop<0,0> {
    static inline void loop(int*) { }
};

// recursive metafunction to keep looping until sorted
template<int N>
struct IntBubbleSort {
    static inline void sort(int* data) {
        IntBubbleSortLoop<N-1,0>::loop(data);
        IntBubbleSort<N-1>::sort(data);
    }
};

template <>
struct IntBubbleSort<1> {
    static inline void sort(int*) { }
};

int main() {
  int a[] = {3, 1, 2, 5};
  IntBubbleSort<4>::sort(a);
  for (int i = 0; i < 4; i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;
  // sort is called at runtime
  // metatemplate compiles out required templates at compile time.
  a[0] = 100;
  IntBubbleSort<4>::sort(a);
  for (int i = 0; i < 4; i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;
}
