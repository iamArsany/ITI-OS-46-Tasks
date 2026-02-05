#include <iostream>

using namespace std;

class Queue {
  int front = -1, last = -1, size;
  int *arr;

public:
  Queue(int x) {
    size = x;
    arr = new int[x];
  }

  bool isFull() { return (((last + 1) % size) == front); }

  bool isEmpty() { return front == -1; }

  void enqueue(int e) {
    if (isFull()) {
      cout << "Queue is Full" << endl;
      return;
    }

    if (isEmpty())
      front = 0;

    last = (last + 1) % size;
    arr[last] = e;
  }

  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return -1;
    }

    int value = arr[front];
    cout << value << " dequeued" << endl;

    if (front == last) {
      front = last = -1;
    } else {
      front = (front + 1) % size;
    }

    return value;
  }

  int Size() {
    if (isEmpty()) {
      cout << "Size: 0" << endl;
      return 0;
    } else if (last > front) {
      cout << "Size: " << last - front - 1 << endl;
      return last - front - 1;
    } else {
      return size - (front - last - 1);
    }
  }

  void print() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return;
    }
    cout << "Queue: ";
    int i = front;
    while (true) {
      cout << arr[i] << " ";
      if (i == last)
        break;
      i = (i + 1) % size;
    }
    cout << endl;
  }
};

int main() {
  Queue q(5);
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.enqueue(60);
  q.print();

  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();

  q.print();
}
