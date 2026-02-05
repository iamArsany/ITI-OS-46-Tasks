#include <iostream>

using namespace std;
int main() {
  int x;
  while (true) {
    cin >> x;
    if (x == 1999) {
      cout << "Correct";
      break;
    } else {
      cout << "Wrong" << endl;
    }
  }

  return 0;
}
