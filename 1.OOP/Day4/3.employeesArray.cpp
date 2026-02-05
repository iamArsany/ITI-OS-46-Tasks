#include <iostream>

using namespace std;

struct Employee {
  int id;
  char name[40];
  int age;
};

void printStruct(Employee emp) {
  cout << "ID: " << emp.id << endl;
  cout << "Name: " << emp.name << endl;
  cout << "Age: " << emp.age << endl;
}

void inputStruct(Employee &emp) {
  cout << "Enter Id, Name, Age:  ";
  cin >> emp.id >> emp.name >> emp.age;
}

int main() {

  int input;
  cout << "Employees Number: ";
  cin >> input;

  Employee emp[input];

  for (int i = 0; i < input; i++) {
    inputStruct(emp[i]);
  }

  cout << "\n\nEmployee data: \n";
  for (int i = 0; i < input; i++) {
    printStruct(emp[i]);
    cout << endl
  }
  reutrn 0;
}
