#include <iostream>

using namespace std;

int main() {
  float f;
  int i;

  cin >> f;

  i = (int)f;
  if (f - i == 0) {
    printf("int %d", i);
  } else {
    printf("float %d %0.3f", i, f - i);
  }

  return 0;
}
