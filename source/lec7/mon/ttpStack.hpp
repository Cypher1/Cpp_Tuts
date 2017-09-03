#ifndef TTPSTACK_HPP
#define TTPSTACK_HPP

#include <iostream>
#include <deque>

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT> class Stack;

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT>
std::ostream& operator<<(std::ostream &, const Stack<T, CONT> &);

template <typename T, 
    template <typename U, typename alloc = std::allocator<U>> class CONT = std::deque>
  class Stack {
public:
  //friend std::ostream& operator<<<T>(std::ostream &, const Stack<T, CONT> &);
  friend std::ostream& operator<<<T, CONT>(std::ostream &, const Stack<T, CONT> &);
  void push(const T &);
  void pop();
  T& top();
  const T& top() const;
  bool empty() const;
private:
  CONT<T> stack_;
};

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT>
void Stack<T, CONT>::push(const T &item) {
  stack_.push_back(item);
}

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT>
void Stack<T, CONT>::pop() {
  stack_.pop_back();
}

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT>
T& Stack<T, CONT>::top() {
  return stack_.back();
}

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT>
const T& Stack<T, CONT>::top() const {
  return stack_.back();
}

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT>
bool Stack<T, CONT>::empty() const {
  return stack_.empty();
}

template <typename T, template <typename U, typename alloc = std::allocator<U>> class CONT>
std::ostream& operator<< (std::ostream & os, const Stack<T, CONT> & s) {
  for (unsigned int i = 0; i < s.stack_.size(); i++) {
    os << s.stack_[i] << " ";
  }
  return os;
}

#endif
