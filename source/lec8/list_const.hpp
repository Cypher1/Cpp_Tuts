#pragma once
#include <memory>
#include <type_traits>

#include "list_iterator_const.hpp"

template <typename T> class List {
public:
  using iterator = List_Iterator<T, Identity>;
  friend iterator;
  using const_iterator = List_Iterator<T, std::add_const>;
  friend const_iterator;

  List() : head_(nullptr), tail_(nullptr) {}

  bool isEmpty() const { return head_ == nullptr;  }
  void push_back(const T&);
  iterator begin() { return iterator(head_.get()); }
  const_iterator cbegin() const { return const_iterator(head_.get()); }
  iterator end() { return iterator(nullptr); }  
  const_iterator cend() const { return const_iterator(nullptr); }  
                                                
private:
  struct Node {
    Node(const T& t, Node *next = nullptr) : elem_(t), next_(next) {}
    T elem_;
    std::unique_ptr<Node> next_;
  };
  std::unique_ptr<Node> head_;
  Node* tail_;
};

template <typename T> 
void List<T>::push_back(const T& elem) {
  auto newNode = std::make_unique<Node>(elem);
  if (!head_) {
    head_ = std::move(newNode);
    tail_ = head_.get();
  } else {
    tail_->next_ = std::move(newNode);
    tail_ = tail_->next_.get();
  }
}
