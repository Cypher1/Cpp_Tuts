#include "book.hpp"

bool operator==(const Book& b1, const Book& b2) {
  return b1.name == b2.name && b1.author == b2.author;
}

bool operator!=(const Book& b1, const Book& b2) {
  return !(b1 == b2);
}

bool operator<(const Book& b1, const Book& b2) {
  return b1.getIsbn() < b2.getIsbn();
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
  os << b.name << ", " << b.author << ", " << b.isbn << ", " << b.price;
  return os;
}

Book::operator std::string() const {
  return author + ',' + name;
}
