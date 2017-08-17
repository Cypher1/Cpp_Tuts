#include <algorithm>
#include <iostream>
#include <vector>

void biggies(std::vector<std::string> &words, 
        std::vector<std::string>::size_type sz,
        std::ostream &os = std::cout, char c = ' ') {
    
    std::stable_sort(words.begin(), words.end(), 
	            [](const std::string &a, const std::string &b) 
	              { return a.size() < b.size();});

    auto wc = std::find_if(words.begin(), words.end(), 
                [sz](const std::string &a) 
	                { return a.size() >= sz; });

    auto count = words.end() - wc;
    std::cout << count << '\n';

    for_each(wc, words.end(), 
       [&os, c](const std::string &s){os << s << c;});
}

int main() {
    std::vector<std::string> words {"the", "quick", "red", "fox",
         "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
}
