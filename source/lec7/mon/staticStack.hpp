#ifndef STATICSTACK_HPP
#define STATICSTACK_HPP

#include <iostream>
#include <deque>
#include <typeinfo>

template <typename,typename> class Stack;

template <typename T, typename CONT> std::ostream& operator<< (std::ostream &os, const Stack<T, CONT> &s);

template <typename T, typename CONT = std::deque<T>> class Stack {
public:
  friend std::ostream& operator<<<T>(std::ostream &, const Stack<T, CONT> &);
  void push(const T &);
  void pop();
  T& top();
  const T& top() const;
  bool empty() const;
  Stack();
  ~Stack();
private:
  CONT stack_;
  static int numStacks_;  // declaration
};

template <typename T, typename CONT>
int Stack<T,CONT>::numStacks_ = 0; // definition

template <typename T, typename CONT> inline
Stack<T, CONT>::Stack() { numStacks_++; }

template <typename T, typename CONT> inline
Stack<T, CONT>::~Stack() {
  if (numStacks_)
    std::cout << typeid(this).name() << ": " << numStacks_ << std::endl;
  numStacks_ = 0;
} 

template <typename T, typename CONT>
void Stack<T, CONT>::push(const T &item) {
  stack_.push_back(item);
}

template <typename T, typename CONT>
void Stack<T, CONT>::pop() {
  stack_.pop_back();
}

template <typename T, typename CONT>
T& Stack<T, CONT>::top() {
  return stack_.back();
}

template <typename T, typename CONT>
const T& Stack<T, CONT>::top() const {
  return stack_.back();
}

template <typename T, typename CONT>
bool Stack<T, CONT>::empty() const {
  return stack_.empty();
}

template <typename T, typename CONT>
std::ostream& operator<<(std::ostream &os, const Stack<T, CONT> &s) {
  for (int i = 0; i < s.stack_.size(); i++) {
    os << s.stack_[i] << " ";
  }
  return os;
}

#endif
