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
#ifndef AMCPP_EMPLOYEE_HPP
#define AMCPP_EMPLOYEE_HPP

#include <string>
#include <utility>
#include <vector>

#include "io.hpp"

namespace amcpp {
   class Employee {
   public:
      Employee() = default;

      Employee(std::string surname, std::string given_name, const double salary)
         : surname_{std::move(surname)},
           given_name_{std::move(given_name)},
           salary_{salary}
      {}

      Employee(std::istream& in, const std::ios_base::openmode open = open_text)
      {
         open == open_text ? get(in) : read(in);
      }

      auto id() const noexcept
      {
         return id_;
      }

      const auto& surname() const noexcept
      {
         return surname_;
      }

      void surname(const std::string& s)
      {
         surname_ = s;
      }

      const auto& given_name() const noexcept
      {
         return given_name_;
      }

      void given_name(const std::string& s)
      {
         given_name_ = s;
      }

      double salary() const noexcept
      {
         return salary_;
      }

      void salary(const double s)
      {
         salary_ = s;
      }
   private:
      static constexpr auto& open_text = std::ios_base::in;
      static int id_counter;

      int id_ = id_counter++;
      std::string surname_ = "<placeholder>";
      std::string given_name_ = "<placeholder>";
      double salary_ = 0.00;

      [[noreturn]] void read_error(const std::string& message)
      {
         throw std::ios_base::failure{"Unable to read employee " + message};
      }

      [[noreturn]] void write_error(const std::string& message)
      {
         throw std::ios_base::failure{"Unable to write employee " + message};
      }

      void read(std::istream& in);
      void get(std::istream& in);
   };

   inline bool operator==(const Employee& a, const Employee& b) noexcept
   {
      return a.id() == b.id();
   }

   inline bool operator!=(const Employee& a, const Employee& b) noexcept
   {
      return !(a == b);
   }

   inline bool operator<(const Employee& a, const Employee& b) noexcept
   {
      return a.surname() < b.surname();
   }

   inline bool operator>(const Employee& a, const Employee& b) noexcept
   {
      return b < a;
   }

   inline bool operator<=(const Employee& a, const Employee& b) noexcept
   {
      return !(a > b);
   }

   inline bool operator>=(const Employee& a, const Employee& b) noexcept
   {
      return !(a < b);
   }

   std::ostream& operator<<(std::ostream& o, const Employee& e);
   std::istream& operator>>(std::istream& in, Employee& e);

   std::ostream& write(std::ostream& o, const Employee& e);
   std::istream& read(std::istream& in, Employee& e);
} // namespace amcpp

namespace std {
   template <>
   struct hash<amcpp::Employee> {
      using argument_type = amcpp::Employee;
      using result_type = size_t;

      result_type operator()(const argument_type& e) const noexcept
      {
         return hash<decltype(e.id())>{}(e.id());
      }
   };
}

#endif // AMCPP_EMPLOYEE_HPP
