#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;

  for (int i = 1; i < 13; i++) {
    printf("%d * %d = %d\n", x, i, x * i);
  }
  return 0;
}
