#include <utility>

#include "UB_stack.h"

// default constructor
UB_stack::UB_stack() : head_{nullptr} { }

// nested class
class UB_stack::Node {
  // everything in this class is private by default
  friend class UB_stack;  // allow UB_stack to access private data
  Node(int i, Node *n = nullptr) : item_(i), next_(n) { }
  ~Node() { delete next_; }  // destructor cleans up the memory

  int item_;
  Node *next_;
};

// method to push an int onto the stack
void UB_stack::push(const int &item) {
  head_ = new Node (item, head_); 
}

// method to work down a given stack
// and push items onto "this" stack correctly
void UB_stack::reverse(Node *h) {
  if (h != nullptr) {
    reverse(h->next_);
    push(h->item_);
  }
}

// copy constructor
UB_stack::UB_stack(const UB_stack &s) : head_{nullptr} {
  reverse(s.head_);
}

// copy assignment operator
UB_stack& UB_stack::operator=(const UB_stack &s) {
  // if not already the same stack
  if (this != &s) {
    delete head_;	// delete this stack
    head_ = nullptr;
    reverse(s.head_); // copy data from other stack
  }
  return *this;
}

// destructor
UB_stack::~UB_stack() { 
	delete head_; 
}

// pop off the top of the stack
void UB_stack::pop() { 
  Node *t = head_; 
  head_ = head_->next_;
  t->next_ = nullptr;
  delete t;
}

// return the top of the stack
int& UB_stack::top() { return head_->item_; }
const int& UB_stack::top() const { return head_->item_; }

bool UB_stack::empty() const { return head_ == 0; }
bool UB_stack::full() const { return false; }

// move constructor
UB_stack::UB_stack(UB_stack &&s): head_{std::move(s.head_)} {
  s.head_ = nullptr;
}

// move assignment
UB_stack& UB_stack::operator=(UB_stack &&s) {
  if (this != &s) {
    delete head_;
    head_ = std::move(s.head_);
    s.head_ = nullptr;
  }
  return *this;
}

void swap(UB_stack &s1, UB_stack &s2) {
  using std::swap;
  // swap the pointers to the heads of the list only
  // much faster than swapping all the data
  swap(s1.head_, s2.head_);	// call std::swap on the pointers
}
