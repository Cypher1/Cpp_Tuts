#include <iostream>
#include <cstring>

template <typename T>
T min(T a, T b) {
  return a < b ? a : b;
}

typedef const char *PCC;
template<> PCC min<PCC>(PCC a, PCC b) {
   return (strcmp(a, b) < 0) ? a : b;
}

double min(double a, double b) {
	return a < b ? a : b;
}

int main() {
        const char *s = "zyx";
        const char *t = "abc";
        
        std::cout << min(1, 2) << std::endl;       // template
		std::cout << min(1.1, 2.2) << std::endl;   // ordinary
		std::cout << min(1, 2.2) << std::endl;     // ordinary
		std::cout << min(s, t) << std::endl;     // specialisation
}
