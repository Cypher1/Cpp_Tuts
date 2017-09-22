/**
 * Create a templated value-like library class to store books, movies etc
 * Each library item has the data and a set of related works
 * Each related work object has a ptr to the related works item.
 */
#include <iostream>

#include "library.hpp"


// class to store the description of an item.
class Description {
public:
  Description(const std::string& d) : desc{d} {}
  friend std::ostream& operator<<(std::ostream&, const Description &);
private:
  std::string desc;
};

// function to print out a description object
std::ostream& operator<<(std::ostream &os, const Description &d) {
  os << d.desc;
  return os;
}

// class to store a Book
class Book {
public:
  Book(const std::string& b) : name{b} {}
  friend bool operator==(const Book&, const Book &);
  friend std::ostream& operator<<(std::ostream&, const Book &);
private:
  std::string name;
};

// method to compare books
bool operator==(const Book& a, const Book& b) {
  return a.name == b.name;
}

// method to print the book details
std::ostream& operator<<(std::ostream &os, const Book &b) {
  os << b.name;
  return os;
}

class Movie {
public:
  Movie(const std::string& _name, const std::string& _director, int _year) : name{_name}, director{_director}, year{_year} {}
  friend bool operator==(const Movie&, const Movie&);
  friend bool operator<(const Movie&, const Movie&);
  friend std::ostream& operator<<(std::ostream&, const Movie&);
private:
  std::string name;
  std::string director;
  int year;
};

// method to compare Movies
bool operator==(const Movie& a, const Movie& b) {
  return a.name == b.name && a.director == b.director, a.year == b.year;
}

// method to compare Movies
bool operator<(const Movie& a, const Movie& b) {
  return a.name < b.name;
}

// method to print the book details
std::ostream& operator<<(std::ostream &os, const Movie &b) {
  os << b.name << "(" << b.director << ", " << b.year << ")";
  return os;
}

void bookMain() {
  // create a book library
  Library<Book,Description> bookLibrary;

  // add some book objects
  Book harryPotter{"Harry Potter"};
  Book harryPotter1{"Harry Potter"};
  Book percyJackson{"Percy Jackson"};
  bookLibrary.add(harryPotter);
  bookLibrary.add(harryPotter);
  bookLibrary.add(harryPotter1);
  bookLibrary.add(percyJackson);

  // create a description and add it between the two books
  Description d{"Percy Jackson is a similar childrens book that readers of Harry Potter may like"};
  bookLibrary.addRelated(harryPotter,percyJackson,d);

  // print books related to Harry Potter
  bookLibrary.printRelated(harryPotter);

  std::cout << std::boolalpha << "confirming that Percy Jackson is in library: " << bookLibrary.inLibrary(percyJackson) << std::endl;

  // remove Percy Jackson
  std::cout << "number of items in library after removal: " << bookLibrary.remove(percyJackson) << std::endl;

  std::cout << std::boolalpha << "confirming that Percy Jackson is in library: " << bookLibrary.inLibrary(percyJackson) << std::endl;

  // print books related to Harry Potter
  bookLibrary.printRelated(harryPotter);

  // const auto& bl = bookLibrary;

  // auto it = bl.cbegin();
  // auto itEnd = bl.cend();

  Library<Book,Description>::iterator nIt = bookLibrary.begin();


  std::vector<double> vec{1,2,3,4,5};
  std::vector<double> vec2{7,3,3,3,5};

  std::fill(vec2.begin(), vec2.end(), 3);
  /// std::copy(vec.begin(), vec.end()-2, vec2.begin());
  //
  std::transform(vec.begin(), vec.end(), vec2.begin(), vec.begin(),
      [](const double& v1, const double& v2){
        return v1+v2;
      });

  std::cout << "[";
  if(vec.size() != 0) {
    std::cout << vec[0];
    std::for_each(vec.begin()+1, vec.end(), [](const auto& v) {
        std::cout << ", " << v;
    });
  }
  std::cout << "]";


  for(auto& v : vec) {
    std::cout << v << ", ";
  }
  std::cout << "\n";

  std::cout << "TOTAL = " << std::sqrt(std::accumulate(vec.begin(), vec.end(), 0, [](const auto& t, const auto& v){ return t+v*v;}));

  /*if(it != itEnd) {
    std::cout << "THERE IS SOMETHING IN THE LIBRARY\n";
  }*/
}

void movieMain() {
  // create a Movie library
  Library<Movie,Description> movieLibrary;

  // add some Movie objects
  Movie harryPotter{"Harry Potter", "Chris Columbus", 2001};
  Movie harryPotter1{"Harry Potter", "Chris Columbus", 2001};
  Movie percyJackson{"Percy Jackson", "Chris Columbus", 2010};
  movieLibrary.add(percyJackson);
  movieLibrary.add(harryPotter);
  movieLibrary.add(harryPotter);
  movieLibrary.add(harryPotter1);

  // create a description and add it between the two Movies
  Description d{"Percy Jackson is a similar childrens Movie that readers of Harry Potter may like"};
  movieLibrary.addRelated(harryPotter,percyJackson,d);

  std::cout << "UNSORTED\n";
  for(auto& i : movieLibrary) {
    std::cout << i << "\n";
  }
  std::sort(movieLibrary.begin(), movieLibrary.end());

  std::cout << "SORTED?\n";
  for(auto& i : movieLibrary) {
    std::cout << i << "\n";
  }

  // print Movies related to Harry Potter
  movieLibrary.printRelated(harryPotter);

  std::cout << std::boolalpha << "confirming that Percy Jackson is in library: " << movieLibrary.inLibrary(percyJackson) << std::endl;

  // remove Percy Jackson
  std::cout << "number of items in library after removal: " << movieLibrary.remove(percyJackson) << std::endl;

  std::cout << std::boolalpha << "confirming that Percy Jackson is in library: " << movieLibrary.inLibrary(percyJackson) << std::endl;

  // print Movies related to Harry Potter
  movieLibrary.printRelated(harryPotter);

  for(auto& i : movieLibrary) {
    std::cout << i << "\n";
  }
}

int main() {
  bookMain();
  movieMain();
}

