class Book {
public:
  // getters
  int getIsbn() const { return isbn; }
  double getPrice() const  { return price; }
private:
  std::string name;
  std::string author;
  int isbn;
  double price;
};
