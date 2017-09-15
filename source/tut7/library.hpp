#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

// library to store objects of type T and descriptions of type U
// library<T, U> = Graph<Node = T, Edge = U>
//
// forward definition of external iterator class

template<typename T, typename U>
class LibraryItemIterator;

template<typename T, typename U>
class ConstLibraryItemIterator;

template <typename T, typename U>
class Library {
  public:
    friend class LibraryItemIterator<T, U>;
    typedef LibraryItemIterator<T, U> iterator;
    friend class ConstLibraryItemIterator<T, U>;
    typedef ConstLibraryItemIterator<T, U> const_iterator;
    // mutators to change the contents of the library
    void add(const T& item);
    unsigned int remove(const T& item);
    void addRelated(const T& from, const T& to, const U& desc);
    void printRelated(const T& from);
    bool inLibrary(const T& item);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

  private:

    // private inner class to hold objects of type T in the library.
    class ItemContainer {
      public:

        // constructor for creating a new ItemContainer to store an item
        ItemContainer(const T& item) : itemPtr{std::make_shared<T>(item)} {}

        const T& getItem() const { return *itemPtr; }
        void addRelated(const ItemContainer& to, const U& desc);
        std::shared_ptr<T> getItemPtr() const { return itemPtr; }
        void printRelated();

      private:
        // private inner class to hold information about related works.
        class RelatedWork {
          public:
            RelatedWork(const ItemContainer& link, const U& desc);
            void printItemAndDescription();
          private:
            // private data members of RelatedWork
            U relatedWorkDescription;
            std::shared_ptr<T> relatedWorkLink;
        };

        // private data members of ItemContainer
        std::shared_ptr<T> itemPtr;
        std::vector<RelatedWork> relatedWorks;
    };

    // private data member of Library Class
    std::vector<ItemContainer> items;
    auto findItem(const T& search) -> decltype(items.begin()) {
      return std::find_if(items.begin(), items.end(), [&search] (const ItemContainer& ic) {
          return search == ic.getItem();
          });
    }
};

template<typename T, typename U>
class LibraryItemIterator {
  public:
    typedef std::ptrdiff_t                     difference_type;
    typedef std::random_access_iterator_tag    iterator_category;
    typedef T                                  value_type;
    typedef std::shared_ptr<T>                 pointer;
    typedef T&                                 reference;

    typedef typename Library<T, U>::ItemContainer container;
    typedef typename std::vector<container>::iterator  IT;

    reference operator*() const;
    pointer operator->() const { return &(operator*()); }
    LibraryItemIterator& operator++();
    LibraryItemIterator& operator--();
    LibraryItemIterator& operator+=(const difference_type&);
    LibraryItemIterator& operator-=(const difference_type&);
    LibraryItemIterator operator+(const difference_type& d) const {
      LibraryItemIterator it{*this};
      return it+=d;
    }
    LibraryItemIterator operator-(const difference_type& d) const {
      LibraryItemIterator it{*this};
      return it-=d;
    }
    difference_type operator-(const LibraryItemIterator& o) const {
      return curr - o.curr;
    }

    bool operator<(const LibraryItemIterator& r) const {
      return curr < r.curr;
    }

    bool operator==(const LibraryItemIterator& other) const;
    bool operator!=(const LibraryItemIterator& other) const { return !operator==(other); }

  private:
    IT curr;

  public:
    LibraryItemIterator(IT it): curr{it} {}
};

// ---- LIBRARY ITERATOR FUNCTIONS ----

template<typename T, typename U>
LibraryItemIterator<T, U> Library<T, U>::begin() {
  LibraryItemIterator<T, U> beg{items.begin()};
  return beg;
}

template<typename T, typename U>
LibraryItemIterator<T, U> Library<T, U>::end() {
  LibraryItemIterator<T, U> end{items.end()};
  return end;
}

template<typename T, typename U>
bool LibraryItemIterator<T, U>::operator==(const LibraryItemIterator<T, U>& other) const {
  return curr == other.curr;
}

template<typename T, typename U>
LibraryItemIterator<T, U>& LibraryItemIterator<T, U>::operator++() {
  curr++;
  return *this;
}

template<typename T, typename U>
LibraryItemIterator<T, U>& LibraryItemIterator<T, U>::operator--() {
  curr--;
  return *this;
}

template<typename T, typename U>
LibraryItemIterator<T, U>& LibraryItemIterator<T, U>::operator+=(const LibraryItemIterator<T, U>::difference_type& d) {
  curr += d;
  return *this;
}

template<typename T, typename U>
LibraryItemIterator<T, U>& LibraryItemIterator<T, U>::operator-=(const LibraryItemIterator<T, U>::difference_type& d) {
  curr -= d;
  return *this;
}

template<typename T, typename U>
typename LibraryItemIterator<T, U>::reference LibraryItemIterator<T, U>::operator*() const {
  return *curr->getItemPtr();
}

// ---- LIBRARY ITERATOR FUNCTIONS ----

template<typename T, typename U>
class ConstLibraryItemIterator {
  public:
    typedef std::ptrdiff_t                     difference_type;
    typedef std::random_access_iterator_tag    iterator_category;
    typedef const T                            value_type;
    typedef std::shared_ptr<value_type>        pointer;
    typedef value_type&                        reference;

    typedef typename Library<const T, U>::ItemContainer container;
    typedef typename std::vector<container>::iterator  IT;

    reference operator*() const;
    pointer operator->() const { return &(operator*()); }
    ConstLibraryItemIterator& operator++();
    ConstLibraryItemIterator& operator--();
    ConstLibraryItemIterator& operator+=(const difference_type&);
    ConstLibraryItemIterator& operator-=(const difference_type&);
    ConstLibraryItemIterator operator+(const difference_type& d) const {
      ConstLibraryItemIterator it{*this};
      return it+=d;
    }
    ConstLibraryItemIterator operator-(const difference_type& d) const {
      ConstLibraryItemIterator it{*this};
      return it-=d;
    }
    difference_type operator-(const ConstLibraryItemIterator& o) const {
      return curr - o.curr;
    }

    bool operator<(const ConstLibraryItemIterator& r) const {
      return curr < r.curr;
    }

    bool operator==(const ConstLibraryItemIterator& other) const;
    bool operator!=(const ConstLibraryItemIterator& other) const { return !operator==(other); }

  private:
    IT curr;

  public:
    ConstLibraryItemIterator(IT it): curr{it} {}
};

// ---- CONST LIBRARY ITERATOR FUNCTIONS ----

template<typename T, typename U>
ConstLibraryItemIterator<T, U> Library<T, U>::cbegin() const {
  LibraryItemIterator<T, U> beg{items.begin()};
  return beg;
}

template<typename T, typename U>
ConstLibraryItemIterator<T, U> Library<T, U>::cend() const {
  LibraryItemIterator<T, U> end{items.end()};
  return end;
}

template<typename T, typename U>
bool ConstLibraryItemIterator<T, U>::operator==(const ConstLibraryItemIterator<T, U>& other) const {
  return curr == other.curr;
}

template<typename T, typename U>
ConstLibraryItemIterator<T, U>& ConstLibraryItemIterator<T, U>::operator++() {
  curr++;
  return *this;
}

template<typename T, typename U>
ConstLibraryItemIterator<T, U>& ConstLibraryItemIterator<T, U>::operator--() {
  curr--;
  return *this;
}

template<typename T, typename U>
ConstLibraryItemIterator<T, U>& ConstLibraryItemIterator<T, U>::operator+=(const ConstLibraryItemIterator<T, U>::difference_type& d) {
  curr += d;
  return *this;
}

template<typename T, typename U>
ConstLibraryItemIterator<T, U>& ConstLibraryItemIterator<T, U>::operator-=(const ConstLibraryItemIterator<T, U>::difference_type& d) {
  curr -= d;
  return *this;
}

template<typename T, typename U>
typename ConstLibraryItemIterator<T, U>::reference ConstLibraryItemIterator<T, U>::operator*() const {
  return curr->getItem();
}

// ---- CONST LIBRARY ITERATOR FUNCTIONS ----

// method to add a new item to the library.
template <typename T, typename U>
void Library<T,U>::add(const T& item) {
  if(std::find(begin(), end(), item) == end()) {
    ItemContainer newItem{item};
    items.push_back(newItem);
    std::cout << item << " was added to the library\n";
  } else {
    std::cout << item << " is already in the library\n";
  }
}

// method to add a related works to an existing item
template <typename T, typename U>
void Library<T,U>::addRelated(const T& from, const T& to, const U& desc) {
  // Find the book 'from' which should have this description
  auto fromIC = findItem(from);
  if(fromIC == items.end()) return; // fail (we could throw here)

  // Find the book 'to' which is mentioned in the description
  auto toIC = findItem(to);
  if(toIC == items.end()) return; // fail (we could throw here)

  // add desc
  fromIC->addRelated(*toIC, desc);
}

// method to remove an item from the library.
template <typename T, typename U>
unsigned int Library<T,U>::remove(const T& t) {
  items.erase(std::remove_if(items.begin(), items.end(), [&t](const auto& i){ return i.getItem() == t;}), items.end());
  return static_cast<unsigned int>(items.size());
}

// method to print the related works for a given item.
template <typename T, typename U>
void Library<T,U>::printRelated(const T& from) {
  // find from itemContainer.
  auto fromIC = findItem(from);
  if(fromIC == items.end()) return; // fail or throw
  fromIC->printRelated();
}

// method to check if an item is already in the library
template <typename T, typename U>
bool Library<T,U>::inLibrary(const T& item) {
  return findItem(item) != items.end();
}

// method to add a related works object to the item container.
template <typename T, typename U>
void Library<T,U>::ItemContainer::addRelated(const ItemContainer& to, const U& desc) {
  RelatedWork rw{to,desc};
  relatedWorks.push_back(rw);
}

// method to print each related item in a container.
template <typename T, typename U>
void Library<T,U>::ItemContainer::printRelated() {
  for (auto related : relatedWorks) {
    related.printItemAndDescription();
  }
}

// constructor for a related works object
template <typename T, typename U>
Library<T,U>::ItemContainer::RelatedWork::RelatedWork(const ItemContainer& link, const U& desc) : relatedWorkDescription{desc} {
  relatedWorkLink = link.getItemPtr();
}

// method to print the item and description of a related work.
template <typename T, typename U>
void Library<T,U>::ItemContainer::RelatedWork::printItemAndDescription() {
  std::cout << *(relatedWorkLink) << " - " << relatedWorkDescription << std::endl;
}
