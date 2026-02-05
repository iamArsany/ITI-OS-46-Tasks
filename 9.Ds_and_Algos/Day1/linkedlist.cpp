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
  int counter = 0;

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
  void append(int id, string name, int age) {
    cout << "Here" << endl;
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

  void deleteAll() {
    Node *tmp = this->head;

    while (tmp) {
      Node *current = tmp;

      if (current != NULL)
        delete current;
      tmp = tmp->next;
    }
  }
};

int main() {
  LinkedList *ll = new LinkedList();
  ll->append(1, "asdf", 10);
  ll->append(2, "asdf", 10);
  ll->append(3, "asdf", 10);
  ll->append(4, "asdf", 10);
  int counterr = ll->count();
  cout << endl;
  cout << "counter is workingggggg: " << counterr;

  Employee *te = ll->search(4);
  cout << endl;
  cout << te->id;
  cout << te->name;
  cout << te->age;
  return 0;
}
