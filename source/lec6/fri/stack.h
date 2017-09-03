#include <iterator>
#include <typeinfo>
#pragma once

#include <iostream>
#include <vector>

template <typename, typename>
class Stack;

template <typename T, typename cont>
std::ostream& operator<<(std::ostream& os, const Stack<T, cont>&);


template <typename T, typename cont=std::vector<T>>
class Stack {
public:
  Stack();
  Stack(Stack<T, cont>&&) = default;
  Stack(const Stack<T, cont>&) = default;

  template <typename cont2>
  Stack(const Stack<T, cont2>&);

  void push(const T&);
  void pop();
  T& top();
  const T& top() const;
  bool empty() const;

  ~Stack();
private:
  cont stack_;
  static unsigned nstacks;

  friend std::ostream& operator<<<T, cont>(std::ostream&, const Stack<T, cont>&);

  template <typename U, typename cont2> friend class Stack;
};

template <typename T, typename cont>
template <typename cont2>
Stack<T, cont>::Stack(const Stack<T, cont2>& s2): stack_{s2.stack_.cbegin(), s2.stack_.cend()} {
  ++nstacks;
}

template <typename T, typename cont>
Stack<T, cont>::Stack() {
  ++nstacks;
}

template <typename T, typename cont>
Stack<T, cont>::~Stack() {
  std::cout << typeid(this).name() << ": " << nstacks-- << '\n';
}

template <typename T, typename cont>
void Stack<T, cont>::push(const T& item) {
  stack_.push_back(item);
}

template <typename T, typename cont>
void Stack<T, cont>::pop() {
  stack_.pop_back();
}

template <typename T, typename cont>
T& Stack<T, cont>::top() {
  return stack_.back();
}

template <typename T, typename cont>
const T& Stack<T, cont>::top() const {
  return stack_.back();
}

template <typename T, typename cont>
bool Stack<T, cont>::empty() const {
  return stack_.empty();
}

template <typename T, typename cont>
std::ostream& operator<<(std::ostream& os, const Stack<T, cont>& s) {
  std::copy(s.stack_.cbegin(), s.stack_.cend(), std::ostream_iterator<T>(std::cout, " "));
  return os;
}

template <typename T, typename cont>
unsigned Stack<T, cont>::nstacks = 0;
