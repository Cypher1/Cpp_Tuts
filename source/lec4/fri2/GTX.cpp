#include <iostream>
#include <vector>
#include <algorithm>

class GTx {
public:
  GTx(size_t val = 0): bound{val} {} 
  bool operator()(const std::string &s) { return s.size() >= bound; }
private:
  std::string::size_type bound;
};

int main() {
  std::vector<std::string> words{"function","objects","are","fun"};
	
  std::cout << std::count_if(words.begin(), words.end(), GTx{6})
  << " words have 6 characters or longer; "
  << std::count_if(words.begin(), words.end(), GTx{3})
  << " words have 3 characters or longer." << std::endl;
}
