#include <iostream>

using namespace std;

int inputUser(const char name[]) {
  int input;
  cout << "\nEnter " << name << ": ";
  cin >> input;

  return input;
}

int factorial(int n) {
  int res = 1;
  for (int i = n; i > 0; i--) {
    res *= i;
  }

  return res;
}

int reverseInt(int num) {

  int rem = 0, rev = 0;
  while (num) {
    int rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
  }

  return rev;
}

int power(int base, int pow) {
  int res = 1;

  for (int i = 0; i < pow; i++) {
    res *= base;
  }

  return res;
}

int main() {

  int input;
  input = inputUser("Factorial");
  int facOutput = factorial(input);
  cout << "Factorial: " << facOutput << endl;

  input = inputUser("Reverse Int");
  int reverseOutput = reverseInt(input);
  cout << "Reversed: " << reverseOutput << endl;

  int base = inputUser("base");
  int pow = inputUser("power");
  int powOutput = power(base, pow);
  printf("\npower %d for base %d is: %d", pow, base, powOutput);
}
