
#include <iostream>

using namespace std;

int prime(int x) {
  int counter = 0;
  for (int i = 3; i < x; i++) {

    for (int j = i - 1; j >= 2; j--) {

      if (i % j == 0) {
        counter++;
        break;
      }
    }
  }

  return counter;
}

int main() { cout << "Prime: " << prime(12); }
