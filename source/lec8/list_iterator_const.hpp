#pragma once

#include <iterator>
#include <cassert>

template <typename T> class List;

template <typename T>
struct Identity {
  using type = T;
};

template <typename Base, template <typename U> class Constness> class List_Iterator;

template <typename T, template <typename> class C>
bool operator==(const List_Iterator<T, C>& lhs, const List_Iterator<T, C>& other);

template <typename Base, template <typename U> class Constness = Identity> class List_Iterator {
  using T = typename Constness<Base>::type;
public:
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;
  using value_type = T;
  using pointer = T*;
  using reference = T&;


  reference operator*() const { return pointee_->elem_; }
  pointer operator->() const { return &(operator*()); }
  List_Iterator& operator++();

  List_Iterator(typename List<Base>::Node *pointee = nullptr) : pointee_(pointee) {}
private:
  typename List<Base>::Node *pointee_;

  friend bool operator==<>(const List_Iterator<Base, Constness>&, const List_Iterator<Base, Constness>&);
};

template <typename T, template <typename> class C>
List_Iterator<T, C>& List_Iterator<T, C>::operator++() {
  assert(pointee_ != nullptr);
  pointee_ = pointee_->next_.get();
  return *this;
}
 
template <typename T, template <typename> class C>
bool operator==(const List_Iterator<T, C>& lhs, const List_Iterator<T, C>& rhs) {
  return lhs.pointee_ == rhs.pointee_;
}

template <typename T, template <typename> class C>
bool operator!=(const List_Iterator<T, C>& lhs, const List_Iterator<T, C>& rhs) {
  return !(lhs == rhs);
}
