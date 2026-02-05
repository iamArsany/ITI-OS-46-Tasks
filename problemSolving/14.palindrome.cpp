#include <iostream>
using namespace std;

int reverseInt(int x) {
  // 123
  int rem, res = 0;
  while (x != 0) {
    res += x % 10;
    res *= 10;
    x /= 10;
  }
  res /= 10;
  return res;
}

int main() {
  int x, rev;
  cin >> x;
  rev = reverseInt(x);
  if (x == rev) {
    cout << rev << endl;
    cout << "YES";
  } else {
    cout << rev << endl;
    cout << "NO";
  }
}
