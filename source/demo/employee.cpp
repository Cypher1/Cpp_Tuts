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
#include "amcpp/employee.hpp"
#include <iomanip>
#include <iosfwd>

namespace amcpp {
   void Employee::read(std::istream& in)
   {
      if (!in.read(as_bytes(id_), sizeof(id_)))
         read_error("id");

      if (!amcpp::read(in, surname_))
         read_error("surname");

      if (!amcpp::read(in, given_name_))
         read_error("given name");

      if (!in.read(as_bytes(salary_), sizeof(salary_)))
         read_error("salary");
   }

   void Employee::get(std::istream& in)
   {
      const auto get_separator = [&in](const char separator) {
         using namespace std::string_literals;
         auto c = '\0';
         if (!in.get(c) || c != separator)
            throw std::ios_base::failure{"Could not get separator. Expected '"s + separator
               + "' received '" + c + '\''};
      };

      discard_ws(in);
      get_separator('{');

      if (!(in >> id_))
         read_error("id");

      get_separator(',');

      if (!getline(in, surname_, ','))
         read_error("surname");

      if (!getline(in, given_name_, ','))
         read_error("given names");

      if (!(in >> salary_))
         read_error("salary");

      get_separator('}');
   }

   std::ostream& operator<<(std::ostream& o, const Employee& e)
   {
      const auto f = o.flags();
      const auto p = o.precision();
      o << '{' << e.id() << ',' << e.surname() << ',' << e.given_name() << ','
         << std::fixed << std::setprecision(2) << e.salary();
      o.precision(p);
      o.flags(f);
      return o << '}';
   }

   std::istream& operator>>(std::istream& in, Employee& e)
   {
      try {
         e = Employee{in};
      }
      catch (std::ios_base::failure& e) {
         if (!in.eof())
            throw;
      }

      return in;
   }

   std::ostream& write(std::ostream& o, const Employee& e)
   {
      o.write(as_bytes(e.id()), sizeof(e.id()));
      write(o, e.surname());
      write(o, e.given_name());
      return o.write(as_bytes(e.salary()), sizeof(e.salary()));
   }

   std::istream& read(std::istream& in, Employee& e)
   {
      e = Employee{in, std::ios_base::binary};
      return in;
   }

   int Employee::id_counter = 1;
} // namespace amcpp
