#include <iostream>

using namespace std;
class Stack {
  int *arr;
  int idx = -1;
  int size;

public:
  Stack(int _size) {
    size = _size;
    arr = new int[size];
  }

  ~Stack() { cout << "Destroying the stack"; }

  void Push(int x) {
    if (idx < size - 1) {
      idx++;
      arr[idx] = x;
    } else {
      cout << "Stack is Full" << endl;
    }
  }

  void Pop() {
    if (idx >= 0) {
      idx--;
      printf("\nElem %d = %d ", idx + 1, arr[idx]);
    } else {
      cout << "\nStack is Empty" << endl;
    }
  }

  int Size() {
    cout << "\nsize: " << idx + 1;
    return idx + 1;
  }

  void peek() {

    if (idx >= 0) {

      printf("\nElement %d = %d \n", idx + 1, arr[idx]);
    } else {
      printf("\nNo Elements to peek on");
    }
  }
};

void EmptyStack(Stack *st) { delete st; }

int main() {
  Stack *st = new Stack(10);
  st->peek();
  st->Push(5);
  st->peek();
  st->Push(4);
  st->peek();
  st->Push(3);
  st->peek();
  st->Push(2);
  st->peek();
  st->Push(1);
  st->peek();
  st->Push(0);
  EmptyStack(st);
  st->Pop();
  st->Pop();
  st->Size();

  return 0;
}
