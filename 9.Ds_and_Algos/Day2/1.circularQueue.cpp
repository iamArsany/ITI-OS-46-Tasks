#include <iostream>
using namespace std;

class myQueue {
private:
  int *arr;
  int front, size, capacity;

public:
  myQueue(int _size) {
    capacity = _size;
    arr = new int[capacity];
    front = 0;
    size = 0;
  }

  void enqueue(int x) {
    if (size == capacity) {
      cout << "Queue is full!" << endl;
      return;
    }
    int rear = (front + size) % capacity;
    arr[rear] = x;
    size++;
  }

  int dequeue() {
    if (size == 0) {
      cout << "Queue is empty!" << endl;
      return -1;
    }
    int res = arr[front];
    front = (front + 1) % capacity;
    size--;
    return res;
  }

  int getFront() {
    if (size == 0)
      return -1;
    return arr[front];
  }

  int getRear() {
    if (size == 0)
      return -1;
    int rear = (front + size - 1) % capacity;
    return arr[rear];
  }

  ~myQueue() { delete[] arr; }
};

int main() {
  cout << "Starting of circular queue" << endl;

  myQueue q(5);
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.enqueue(60);

  cout << "Front: " << q.getFront() << endl;
  cout << "Rear: " << q.getRear() << endl;

  cout << "Dequeued: " << q.dequeue() << endl;
  cout << "Front after dequeue: " << q.getFront() << endl;

  return 0;
}
