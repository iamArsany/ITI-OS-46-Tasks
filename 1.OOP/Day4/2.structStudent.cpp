#include <iostream>

using namespace std;

struct Student {
  int id;
  char name[10];
  int age;
};

void printStruct(Student st) {
  cout << "\n\nStudent data: \n";
  cout << "ID: " << st.id << endl;
  cout << "Name: " << st.name << endl;
  cout << "Age: " << st.age << endl;
}

int main() {

  struct Student st1;

  cout << "Enter your ID: ";
  cin >> st1.id;

  cout << "Enter your Name: ";
  cin >> st1.name;

  cout << "Enter your Age: ";
  cin >> st1.age;

  printStruct(st1);
}
