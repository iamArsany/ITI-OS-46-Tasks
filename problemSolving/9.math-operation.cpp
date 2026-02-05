#include <iostream>

using namespace std;

int main() {
  int x, y, z;
  char c, q;
  cin >> x >> c >> y >> q >> z;

  if (c == '+') {
    if (x + y == z) {
      cout << "Yes";
    } else {
      cout << x + y;
    }
  } else if (c == '*') {
    if (x * y == z) {
      cout << "Yes";
    } else {
      cout << x * y;
    }

  } else if (c == '-') {
    if (x - y == z) {
      cout << "Yes";
    } else {
      cout << x - y;
    }
  }
  return 0;
}
