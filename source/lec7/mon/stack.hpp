#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>

template <typename> class Stack;

template <typename T> std::ostream& operator<< (std::ostream &os, const Stack<T> &s);

template <typename T> class Stack {
public:
  friend std::ostream& operator<<<T>(std::ostream &, const Stack<T> &);
  void push(const T &);
  void pop();
  T& top();
  const T& top() const;
  bool empty() const;
private:
  std::vector<T> stack_;
};

template <typename T>
void Stack<T>::push(const T &item) {
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
std::ostream& operator<<(std::ostream &os, const Stack<T> &s) {
  for (unsigned int i = 0; i < s.stack_.size(); i++) {
    os << s.stack_[i] << " ";
  }
  return os;
}

#endif
