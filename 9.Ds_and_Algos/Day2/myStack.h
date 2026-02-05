#include <iostream>

using namespace std;

template <typename T> class myStack {
  T *arr;
  int size, index = -1;

public:
  myStack(int _size = 50) {
    if (_size <= 0)
      throw std::invalid_argument("Stack size must be positive");
    size = _size;
    arr = new T[size];
    cout << "Created stack of size :" << size
         << " and type: " << typeid(T).name() << endl;
  }
  myStack(myStack &st) {
    this->size = st.size;
    this->index = st.index;
    arr = new T[size];
    for (int i = 0; i <= index; i++) {
      this->arr[i] = st.arr[i];
    }
  }
  ~myStack() { delete[] arr; }

  bool isEmpty() { return index == -1; }
  bool isFull() { return index == (size - 1); }

  void push(T element) {
    if (isFull()) {
      throw std::overflow_error("Stack is full");
    }
    arr[++index] = element;
  }

  T pop() {
    if (isEmpty()) {
      throw std::underflow_error("Stack is empty");
    }
    return arr[index--];
  }

  T peek() {
    if (isEmpty()) {
      throw std::underflow_error("Stack is empty");
    }
    return arr[index];
  }

  int getSize() { return size; }
  int getCapacity() { return index + 1; }
  void print() {
    for (int i = 0; i <= size - 1; i++) {
      printf("\nstack[%i] = ", i);
      cout << arr[i];
    }
  }
  T top() { return arr[0]; }

  myStack operator=(myStack st) {
    this->size = st.size;
    this->index = st.index;
    arr = new T[size];
    for (int i = 0; i <= index; i++) {
      this->arr[i] = st.arr[i];
    }
    return *this;
  }

  myStack operator+(myStack st) {
    myStack result(this->size + st.size);
    for (int i = 0; i <= this->index; i++) {
      result.arr[i] = arr[i];
    }
    for (int i = 0; i <= st.index; i++) {
      result.arr[this->index + i] = st.arr[i];
    }
    result.index = this->index + st.index;

    return result;
  }
};
