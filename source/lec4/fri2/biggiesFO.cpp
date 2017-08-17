#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

bool check_size(const std::string &s, std::string::size_type sz) {
	return s.size() >= sz;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    std::stable_sort(words.begin(), words.end(), 
	            [](const std::string &s1, const std::string &s2) 
	              { return s1.size() < s2.size();} );

    auto wc = std::find_if(words.begin(), words.end(), 
               std::bind(check_size, std::placeholders::_1, sz));

    auto count = words.end() - wc;
    std::cout << count << '\n';
    std::for_each(wc, words.end(), 
       [](const std::string &s) { std::cout << s << " "; });
}

int main() {
    std::vector<std::string> words{"the", "quick", "red", "fox",
         "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
}
