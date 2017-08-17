#ifndef UB_STACK_H
#define UB_STACK_H

class UB_stack {
public:
  UB_stack();  // default constructor
  UB_stack(const UB_stack &s);  // copy constructor
  UB_stack(UB_stack &&s);  // move constructor
  ~UB_stack();  // destructor
  UB_stack& operator=(const UB_stack &s);  // copy assignment
  UB_stack& operator=(UB_stack &&s);  // move assignment
  void push(const int &item);
  void pop();
  int& top();
  const int& top() const;
  bool empty() const;
  bool full() const;
private:
  class Node;   // forward declaration of nested class
  void reverse(Node *);  // private method
  Node *head_;
  
  friend void swap(UB_stack &s1, UB_stack &s2);
};

void swap(UB_stack &s1, UB_stack &s2);

#endif /* UB_STACK_H */
