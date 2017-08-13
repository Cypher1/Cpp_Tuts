#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> sVec{"one", "two", "three"};
  std::array<int, 3> iArr{3, 2, 1};

  std::sort(sVec.begin(), sVec.end());
  std::sort(iArr.begin(), iArr.end());

  std::list<int> iList;
  std::back_insert_iterator<decltype(iList)> backInserter{iList};

  std::copy(iArr.begin(), iArr.end(), backInserter);
  iList.sort();

  std::map<std::string, unsigned> sMap;
  auto i = 0U;
  for (const auto& s : sVec)
    sMap.emplace(s, i++);

  for (const auto& p : sMap)
    std::cout << p.first << ' ' << p.second << '\n';
}
