#ifndef MEMBERTEAMPLATESSTACK_HPP
#define MEMBERTEAMPLATESSTACK_HPP

#include <iostream>
#include <deque>

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
  
  Stack() {}
  
  template <typename T2, typename CONT2>
    Stack(const Stack<T2, CONT2>&);

    template <typename T2, typename CONT2>
    Stack(Stack<T2, CONT2> &&);

    template <typename Iter> Stack(Iter b, Iter e);

    template <typename T2, typename CONT2>     
    Stack& operator=(const Stack<T2,CONT2> &);

    template <typename T2, typename CONT2>     
    Stack& operator=(Stack<T2,CONT2> &&);

    template <typename Iter> void assign(Iter b, Iter e);
private:
  CONT stack_;
};

template <typename T, typename CONT>
template <typename T2, typename CONT2>
Stack<T,CONT>::Stack(const Stack<T2,CONT2> & s) {
  Stack<T2,CONT2> tmp(s);
  while (!tmp.empty()) {
    stack_.push_front(static_cast<T>(tmp.top()));
    tmp.pop();
  }
}

template <typename T, typename CONT>
template <typename T2, typename CONT2>
Stack<T,CONT>::Stack(Stack<T2,CONT2> && s) {
  while (!s.empty()) {
    stack_.push_front(static_cast<T>(s.top()));
    s.pop();
  }
}


template <typename T, typename CONT>
template <typename Iter>
Stack<T,CONT>::Stack(Iter b, Iter e) {
  for (; b != e; ++b)
    stack_.push_back(*b);
}

template <typename T, typename CONT>
template <typename T2, typename CONT2>
Stack<T,CONT>&
Stack<T,CONT>::operator=(const Stack<T2,CONT2> & s) {
  if ((void *)this == (void *)&s)
    return *this;

  Stack<T2,CONT2> tmp(s);
  stack_.clear();
  while (!tmp.empty()) {
    stack_.push_front(static_cast<T>(tmp.top()));
    tmp.pop();
  }
  return *this;
}


template <typename T, typename CONT>
template <typename T2, typename CONT2>
Stack<T,CONT>&
Stack<T,CONT>::operator=(Stack<T2,CONT2> && s) {
  if ((void *)this == (void *)&s)
    return *this;

  stack_.clear();
  while (!s.empty()) {
    stack_.push_front(static_cast<T>(s.top()));
    s.pop();
  }
  return *this;
}

template <typename T, typename CONT>
template <typename Iter>
void Stack<T,CONT>::assign(Iter b, Iter e) {
  stack_.clear();
  for (; b != e; ++b)
    stack_.push_back(*b);
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
  for (unsigned int i = 0; i < s.stack_.size(); i++) {
    os << s.stack_[i] << " ";
  }
  return os;
}

#endif
