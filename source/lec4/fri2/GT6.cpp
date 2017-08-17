#include <iostream>
#include <vector>
#include <algorithm>

bool GT6(const std::string &s) { return s.size() >= 6; }

int main() {
  std::vector<std::string> words{"function","objects","are","fun"};
	
  std::cout << std::count_if(words.begin(), words.end(), GT6)
       << " words have 6 characters or longer." << std::endl;
}
