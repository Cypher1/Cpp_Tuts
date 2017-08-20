#include <iostream>

void g() { throw std::string("something is wrong!"); }

void f() { 
	g(); 
	std::cout << "never executed";
}

int main() {
  try { f(); }
  catch (std::string &s) { std::cout << s << std::endl; }
  std::cout << "execution resumes from here" << std::endl; 
}
