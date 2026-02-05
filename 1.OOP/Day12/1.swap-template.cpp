#include <iostream>

using namespace std;

template <class T> void Swap(T &x, T &y) {
  T temp = x;
  x = y;
  y = temp;
}

int main() {
  int x = 5, y = 10;
  cout << x << ":" << y << endl;
  swap(x, y);
  cout << x << ":" << y << endl;

  cout << endl;
  char a = 'y', b = 'z';
  cout << a << ":" << b << endl;
  swap(a, b);
  cout << a << ":" << b << endl;
}
