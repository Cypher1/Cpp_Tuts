// basic_project -- a simple startup project
//
//  Copyright Christopher Di Bella 2017 -- Present
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/cjdb/basic_project.git
//
#include <algorithm>
#include "amcpp/employee.hpp"
#include "amcpp/simple_test.hpp"
#include <iostream>
#include <iterator>
#include <vector>

using amcpp::Employee;

int main()
{
   auto v = std::vector<Employee>{std::istream_iterator<Employee>{std::cin},
      std::istream_iterator<Employee>{}};

   CHECK(v.size() == 10u);

   v.emplace_back("Smith", "John", 123'456.00);
   CHECK(v.size() == 11u);

   std::sort(std::begin(v), std::end(v), [](const auto& a, const auto& b) {
         return a.salary() < b.salary(); });

   CHECK(std::lower_bound(std::begin(v), std::end(v), "Zac", [](const auto& a, const auto& b) {
      return a.given_name() < b; }) == std::end(v));

   return ::test_result();
}
