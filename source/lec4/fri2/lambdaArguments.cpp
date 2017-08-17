#include <algorithm>
#include <iostream>
#include <vector>

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main() {

    std::vector<std::string> words {"the", "quick", "red", "fox",
         "jumps", "over", "the", "slow", "red", "turtle"};

    std::stable_sort(words.begin(), words.end(), 
	            [](const std::string &s1, const std::string &s2) 
	              { return s1.size() < s2.size();});
    // \alert{SAME AS}
    std::stable_sort(words.begin(), words.end(), isShorter);
}
