#include <iostream>
#include <fstream>

namespace cs6771 {
    void order3ptr(int *a, int *b, int *c);
    void order3ref(unsigned int& a, unsigned int& b, unsigned int& c);
}

int main() {
    std::cout << "Please enter 3 numbers: ";

    int a, b, c;
    if (!(std::cin >> a >> b >> c))
        throw std::invalid_argument("Failed to read numbers");

    std::ofstream f{"output"};
    f << a << ' ' << b << ' ' << c << '\n';
}

namespace cs6771 {
    void order3ptr(int *a, int *b, int *c) {
        if (*a < *c) {
            int t = *a;
            *a = *c;
            *c = t;
        }
        if (*a < *b) {
            int t = *a;
            *a = *b;
            *b = t;
        }
        if (*b < *c) {
            int t = *b;
            *b = *c;
            *c = t;
        }
    }

    void order3ref(unsigned int& a, unsigned int& b, unsigned int& c) {
        if (a > c) {
            int t = a;
            a = c;
            c = t;
        }
        if (b > c) {
            int t = b;
            b = c;
            c = t;
        }
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
    }
}
