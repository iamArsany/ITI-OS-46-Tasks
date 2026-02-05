#include <iostream>

using namespace std;

int main() {
  int x, y;
  char c;
  cin >> x >> c >> y;

  if (x > y && c == '>') {
    cout << "Right";
  } else if (x < y && c == '<') {
    cout << "Right";
  } else if (x == y && c == '=') {
    cout << "Right";
  } else {
    cout << "Wrong";
  }
  return 0;
}
