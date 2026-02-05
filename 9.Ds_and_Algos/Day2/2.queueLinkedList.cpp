#include <iostream>
#include <string>

using namespace std;

struct Employee {
  int id;
  string name;
  int age;

  Employee(int _id, string _name, int _age) {
    id = _id;
    name = _name;
    age = _age;
  }
};

struct Node {
  Employee *emp;
  Node *prev;
  Node *next;
};

class LinkedList {
private:
  Node *head = new Node();
  Node *tail = new Node();

  Node *searchById(int _id) {
    if (this->head == NULL) {
      return NULL;
    }
    Node *tmp = this->head;
    while (tmp) {
      if (_id == tmp->emp->id) {
        return tmp;
      }
      tmp = tmp->next;
    }
    return NULL;
  }

public:
  LinkedList() {
    this->head = NULL;
    this->tail = NULL;
  }
  void enqueue(int id, string name, int age) {
    Employee *employee = new Employee(id, name, age);
    Node *tmp = new Node();
    tmp->emp = employee;
    tmp->next = NULL;
    if (this->head == NULL) {
      this->head = tmp;
      this->tail = tmp;
      tmp->prev = NULL;
      return;
    }
    this->tail->next = tmp;
    tmp->prev = this->tail;
    tmp->next = NULL;
    this->tail = tmp;
    return;
  }

  Employee *search(int _id) {
    Node *tmp = searchById(_id);
    if (tmp) {
      Employee *emp = tmp->emp;
      return emp;
    } else {
      return nullptr;
    }
  }

  int count() {
    int counter = 0;
    if (this->head == NULL) {
      return 0;
    }
    Node *tmp = this->head;
    while (tmp) {
      counter++;
      tmp = tmp->next;
    }

    return counter;
  }

  Employee *dequeue() {
    if (head == NULL) {
      cout << "Queue is empty!" << endl;
      return nullptr;
    }

    Node *tmp = head;
    Employee *emp = tmp->emp;

    head = head->next;

    if (head != NULL)
      head->prev = NULL;
    else
      tail = NULL;

    delete tmp;
    return emp;
  }

  void deleteAll() {
    Node *tmp = this->head;

    while (tmp) {
      Node *current = tmp;

      if (current != NULL) {
        delete current->emp;
        delete current;
      }
      tmp = tmp->next;
    }
  }
};

int main() {
  LinkedList q;

  q.enqueue(1, "a", 10);
  q.enqueue(2, "b", 20);
  q.enqueue(3, "c", 30);

  cout << "size: " << q.count() << endl;

  cout << "dequeued: " << q.dequeue()->name << endl;
  cout << "dequeued: " << q.dequeue()->name << endl;

  cout << "size: " << q.count() << endl;

  return 0;
}
