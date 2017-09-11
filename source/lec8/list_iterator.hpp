#pragma once

#include <iterator>
#include <cassert>

template <typename T> class List;

template <typename T> class List_Iterator {
public:
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;
  using value_type = T;
  using pointer = T*;
  using reference = T&;

  reference operator*() const;
  pointer operator->() const { return &(operator*()); }
  List_Iterator& operator++();
  bool operator==(const List_Iterator& other) const;
  bool operator!=(const List_Iterator& other) const { return !operator==(other); }

  List_Iterator(typename List<T>::Node *pointee = nullptr) : pointee_(pointee) {}
private:
  typename List<T>::Node *pointee_;
};

template <typename T> typename List_Iterator<T>::reference 
List_Iterator<T>::operator*() const {
  return pointee_->elem_;
}

template <typename T> List_Iterator<T>& 
List_Iterator<T>::operator++() {
  assert(pointee_ != nullptr);
  pointee_ = pointee_->next_.get();
  return *this;
}
 
template <typename T>
bool List_Iterator<T>::operator==(const List_Iterator<T>& other) const {
  return this->pointee_ == other.pointee_;
}
