#include <cassert>
#include "SafeArray.h"

SafeArray::SafeArray(int s) : size{s}, values{new int[size]} { }

SafeArray::SafeArray(const int v[], int s) : size{s} {
  values = new int[size];
  for (int i = 0; i < size; i++)
    values[i] = v[i];
}

int& SafeArray::operator[](int index) {
  assert((index >= 0) && (index < size));
  return values[index];
}

int SafeArray::operator[](int index) const {
  assert((index >= 0) && (index < size));
  return values[index];
}
