#include <iostream>
#include <memory>

// we'll talk about how to do this for generic types when we cover templates
class UP {
public:
  UP(std::string *p): ptr{p} {}
  ~UP() { delete ptr; }
  UP(const UP&) = delete;
  UP& operator=(const UP&) = delete;

  UP(UP&& other): ptr{other.ptr} {
    other.ptr = nullptr;
  }

  UP& operator=(UP&& other) {
    UP tmp{std::move(*this)};
    std::swap(other.ptr, ptr);
    return *this;
  }

  std::string& operator*() { return *ptr; }
  // define operator-> in terms of operator*
  std::string* operator->() { return &**this; }

private:
  std::string* ptr;
};

UP makeUP(const char* c) {
  return UP{new std::string(c)};
}

class SP {
public:
  SP(std::string* s): ptr{new Rep{s}} {}
  SP(const SP& other): ptr{other.ptr} {
    ++ptr->rc;
  }
  SP(SP&& other): ptr{other.ptr} {
    other.ptr = nullptr;
  }

  ~SP() {
    if (ptr)
      std::cout << "decrementing refcount for " << *ptr->s << '\n';
    if (ptr && !--ptr->rc) {
      delete ptr;
    }
  }

private:
  struct Rep {
    Rep(std::string* s): rc{1}, s{s} {}
    ~Rep() {
      std::cout << "deleted " << *s << '\n';
      delete s;
    }

    unsigned rc;
    std::string *s;
  };

  Rep* ptr;
};

struct MyType {
  int i;
  std::shared_ptr<MyType> next;
  std::weak_ptr<MyType> prev;
};

int main() {
  auto x = makeUP("hello");
  UP y{std::move(x)};
  x = std::move(y);

  SP sa{new std::string("world")};
  {
    SP sb{sa};
    std::cout << "a\n";
  }
  {
    SP sb{std::move(sa)};
    std::cout << "b\n";
  }
  std::cout << "c\n";

  auto up = std::make_unique<MyType>();

  auto s = std::make_shared<MyType>();
  s->next = std::make_shared<MyType>();
  s->next->prev = s;
  auto& p = s->next;
  if (auto prev = p->prev.lock()) {
    std::cout << "I have a reference" << '\n';
  } else {
    std::cout << "No reference :(\n";
  }

  // let's try and make the same mistakes we would with C style allocation
  // forget to free
  // double free
  // dereference already freed memory
}
