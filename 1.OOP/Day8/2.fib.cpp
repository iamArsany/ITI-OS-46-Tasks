#include <iostream>

using namespace std;

int fib(int x) {
  if (x == 1)
    return 1;
  return x * fib(x - 1);
}

int main() { cout << fib(5); }
