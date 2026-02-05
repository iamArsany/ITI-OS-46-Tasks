#include <iostream>

using namespace std;

class Math {
public:
  static int add(int x, int y) { return x + y; }
  static int sub(int x, int y) { return x - y; }
  static int mul(int x, int y) { return x * y; }
  static float div(int x, int y) { return x / y; }
};

int main() {
  cout << Math::div(20, 4) << endl;
  cout << Math::mul(20, 4) << endl;
  cout << Math::add(20, 4) << endl;
  cout << Math::sub(20, 4) << endl;
  return 0;
}
