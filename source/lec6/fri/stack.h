#include <iterator>
#pragma once

#include <iostream>
#include <vector>

template <typename>
class Stack;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>&);


template <typename T>
class Stack {
public:
  void push(const T&);
  void pop();
  T& top();
  const T& top() const;
  bool empty() const;
private:
  std::vector<T> stack_;

  friend std::ostream& operator<<<T>(std::ostream&, const Stack<T>&);
};

template <typename T>
void Stack<T>::push(const T& item) {
  stack_.push_back(item);
}

template <typename T>
void Stack<T>::pop() {
  stack_.pop_back();
}

template <typename T>
T& Stack<T>::top() {
  return stack_.back();
}

template <typename T>
const T& Stack<T>::top() const {
  return stack_.back();
}

template <typename T>
bool Stack<T>::empty() const {
  return stack_.empty();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
  std::copy(s.stack_.cbegin(), s.stack_.cend(), std::ostream_iterator<T>(std::cout, " "));
  return os;
}
