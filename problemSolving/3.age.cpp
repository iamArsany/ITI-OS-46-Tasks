#include <iostream>

using namespace std;

int main() {
  int age, rem, yr, mon;
  cin >> age;
  rem = age % 365;
  yr = (age - rem) / 365;
  age -= yr * 365;
  rem = age % 30;
  mon = (age - rem) / 30;
  age -= mon * 30;

  cout << yr << " years\n";
  cout << mon << " months\n";
  cout << age << " days\n";
  return 0;
}
