#include <iostream>
#include <string>

class Book {
public:
  Book(const std::string& name, const std::string& author, int isbn, double price): name{name}, author{author}, isbn{isbn}, price{price} {}

  // getters
  int getIsbn() const { return isbn; }
  double getPrice() const  { return price; }

  operator std::string() const;

  friend bool operator==(const Book&, const Book&);
  friend std::ostream& operator<<(std::ostream&, const Book&);
private:
  std::string name;
  std::string author;
  int isbn;
  double price;
};

bool operator!=(const Book&, const Book&);
bool operator<(const Book&, const Book&);
