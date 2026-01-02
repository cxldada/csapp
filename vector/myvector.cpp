#include <cstring>
#include <iostream>
#include <stdexcept>

template <class E> class MyVector {
private:
  static const size_t INIT_VECTOR_SIZE = 1;

public:
  MyVector() {
    arr = new E[INIT_VECTOR_SIZE];
    capacity = INIT_VECTOR_SIZE;
    size = 0;
  }
  MyVector(size_t cap) {
    arr = new E[cap];
    capacity = cap;
    size = 0;
  }
  ~MyVector() { delete[] arr; }

  size_t Size() {
    return size;
  }

  void Add(size_t index, const E &e) {
    CheckPositionIndex(index);

    if (size == capacity) {
      Resize(capacity * 2);
    }

    for (size_t i = size; i > index; i--) {
      arr[i] = arr[i - 1];
    }

    arr[index] = e;
    size++;
  }

  void AddToHead(const E &e) { Add(0, e); }
  void AddToTail(const E &e) { Add(size, e); }

  E Del(size_t index) {
    CheckElementIndex(index);

    if (size < (capacity / 4)) {
      Resize(capacity / 2);
    }

    for (size_t i = index; i < size; i++) {
      arr[i] = arr[i+1];
    }

    E ret = arr[index];

    arr[size] = E();
    size--;

    return ret;
  }
  E DelHead() { return Del(0); }
  E DelTair() { return Del(size - 1); }

  E &Get(size_t index) {
    CheckElementIndex(index);

    return arr[index];
  }

  void print() {
    std::cout << "capacity" << capacity << " arr[";
    for(int i = 0;i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
  }

private:
  bool CheckElementIndex(size_t index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("index error");
    }
    return true;
  }
  bool CheckPositionIndex(size_t index) {
    if (index < 0 || index > size) {
      throw std::out_of_range("index error");
    }
    return true;
  }

  void Resize(int newCap) {
    E *temp = new E[newCap];

    size_t newSize = newCap > size ? size : newCap;

    // memcpy(temp, arr, newSize*sizeof(E));

    for (size_t i = 0; i < newSize; i++) {
      temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
    capacity = newCap;
    size = newSize;
  }

private:
  E *arr;
  size_t capacity;
  size_t size;
};

int main() {
  MyVector<int> mv;

  for(int i = 0; i < 20; i++){
    mv.AddToHead(i);
    mv.AddToTail(i);
    mv.print();
  }
  for(int i = 0; i < 20; i++){
    mv.DelHead();
    mv.DelTair();
    mv.print();
  }
  return 0;
}