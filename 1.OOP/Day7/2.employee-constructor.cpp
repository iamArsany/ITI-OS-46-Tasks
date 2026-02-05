#include <cstring>
#include <iostream>

using namespace std;

class Employee {
  int id;
  char name[20];
  int age;
  int salary;

public:
  Employee(int id, const char *name) {
    setId(id);
    setName(name);
  }
  Employee(int id, const char *name, int age) {
    setId(id);
    setName(name);
    setAge(age);
  }
  Employee(int id, const char *name, int age, int salary) {
    setId(id);
    setName(name);
    setAge(age);
    setSalary(salary);
  }

  void setId(int _id) {
    if (_id > 0) {
      id = _id;
    } else {
      cout << "Invalid id" << endl;
    }
  }
  int getId() { return id; }

  void setName(const char *_name) {
    if (strlen(_name) > 3) {
      strcpy(name, _name);
    } else {
      cout << "Invalid Name" << endl;
    }
  }
  char *getName() { return name; }

  void setAge(int _age) {
    if (_age > 20 && _age < 60) {
      age = _age;
    } else {
      cout << "Invalid Age";
    }
  }
  int getAge() { return age; }

  void setSalary(int _salary) {
    if (_salary > 10000 && _salary < 2000) {
      cout << "Invalid Salary" << endl;
    } else {
      salary = _salary;
    }
  }
  int getSalary() { return salary; }

  void Print() {
    cout << "id: " << id << endl;
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "salary: " << salary << endl;
  }
};

int main() {
  // Employee e1(1000, "ahmed");
  Employee e1(1000, "ahmed", 40, 34000);

  // e1.setAge(30);
  // e1.setSalary(50000);

  e1.Print();

  return 0;
}
