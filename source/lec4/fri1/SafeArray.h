class SafeArray {
public:
  SafeArray(int s);
  SafeArray(const int v[], int s);
  ~SafeArray() { delete[] values; }
  int& operator[](int i);       // for setting via []
  int operator[](int i) const;  // for getting via []
private:
  int size;
  int* values;
};
