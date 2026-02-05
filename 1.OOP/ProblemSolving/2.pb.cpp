#include <iostream>

using namespace std;

int main() {
  string x1, x2;
  cin >> x1 >> x2;

  for (char &x : x1) {
    if (x < 97)
      x += 32;
  }
  for (char &x : x2) {
    if (x < 97)
      x += 32;
  }

  int counter = 0;
  for (int i = 0; i < x1.size(); i++) {
    counter = (x1[i] - x2[i]);
    if (counter > 0) {
      cout << 1;
      return 0;
    } else if (counter < 0) {
      cout << -1;
      return 0;
    }
  }

  cout << 0;
  return 0;
}
